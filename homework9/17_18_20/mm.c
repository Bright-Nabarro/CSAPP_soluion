#include "mm.h"
#include "mem_stm.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// ph为指向头节点的指针
// pr为指向头尾节点指针
// pb为指向内容的指针

// 参数为头指针
#define GET_BLOCK(ph)	  ((char*)(ph) + WORD)
#define GET_PREV_TAIL(ph) ((char*)(ph) - WORD)
#define GET_SIZE(ph)	  (*(uint32_t*)(ph) & ~7)
#define GET_TAIL(ph)	  ((char*)(ph) + GET_SIZE(ph) - WORD)
#define GET_NEXT_HEAD(ph) ((char*)(ph) + GET_SIZE(ph))
#define GET_PREV_HEAD(ph) ((char*)(ph) - GET_SIZE(GET_PREV_TAIL(ph)))

// 参数为头尾指针
#define IS_ALLOCATED(pr)		  (*(uint32_t*)(pr) & 1)
#define SET_ALLOCATED(pr)		  (*(uint32_t*)(pr) |= 1)
#define SET_EMPTY(pr)			  (*(uint32_t*)(pr) &= ~1)
#define SET_MASK(pr, size, alloc) (*(uint32_t*)(pr) = ((size) | (alloc)))

// 参数为pb指针
#define BLOCK_HEAD(pb) ((char*)(pb) - WORD)

// wrong!!!
// #define BLOCK_SIZE(pb) (GET_SIZE(BLOCK_HEAD(pb)))
// #define BLOCK_TAIL(pb) (GET_HEAD(pb) + BLOCK_SIZE(pb) - WORD)

char* head_ptr; // 指向第一个块的头部
static void* extend(int incr);
static void* merge_empty(void* ph);
static void* find_fit(size_t blockSize);
static void place(void* ph, size_t blockSize);

/*
 *===interface function implement=========================================
 */
bool mm_init(void)
{
	mem_init();
	printf("Chunk size\t%dB\n", CHUNK);
	head_ptr = mem_sbrk(4 * WORD);
	if (head_ptr == NULL)
		return false;
	// 头部空块，用于pb的起始位置与DWORD对齐
	SET_MASK(head_ptr, 0, 0);
	// 序言块
	SET_MASK(head_ptr + WORD, DWORD, 1);
	SET_MASK(head_ptr + 2 * WORD, DWORD, 1);
	// 结束块
	SET_MASK(head_ptr + 3 * WORD, 0, 1);
	// head_ptr指向序言块之后，此后不会改变
	head_ptr = head_ptr + 3 * WORD;

	if (extend(CHUNK) == NULL)
		return false;
	return true;
}

void* mm_malloc(size_t size)
{
	// 向上取整到DWORD
	size_t blockSize;
	if (size == 0)
		return NULL;
	if (size <= DWORD)
		blockSize = 2 * DWORD;
	else
		blockSize = (size + DWORD + DWORD - 1) / DWORD * DWORD;

	void* ph = find_fit(blockSize);
	// 没有合适的空闲块，扩展空间
	while (ph == NULL)
	{
		if (extend(CHUNK) == NULL)
			return NULL;
		ph = find_fit(blockSize);
	}
	assert(!IS_ALLOCATED(ph));
	place(ph, blockSize);

	return GET_BLOCK(ph);
}

void mm_free(void* pb)
{
	if (pb == NULL)
		return;

	void* ph = BLOCK_HEAD(pb);
	assert(IS_ALLOCATED(ph));
	SET_EMPTY(ph);
	SET_EMPTY(GET_TAIL(ph));

	merge_empty(ph);
}

/*
 *=====static function implement=============================================
 */
static void* extend(int incr)
{
	void* sbrk = mem_sbrk(incr);
	// 空间不足以扩展新块
	if (sbrk == NULL)
		return NULL;
	void* ph = (char*)sbrk - WORD;
	if (ph == NULL)
		return NULL;

	SET_MASK(ph, incr, 0);
	SET_MASK(GET_TAIL(ph), incr, 0);

	// 重新设置结尾块
	char* pt = ph + incr;
	SET_MASK(pt, 0, 1);

	return merge_empty(ph);
}

static void* merge_empty(void* ph)
{
	// 注意，合并后内部头尾块并未清除，但无法被访问到
	void* retPh;
	void* prevPt = GET_PREV_TAIL(ph);
	void* nextPh = GET_NEXT_HEAD(ph);
	if (IS_ALLOCATED(prevPt) && IS_ALLOCATED(nextPh))
	{
		SET_EMPTY(ph);
		SET_EMPTY(GET_TAIL(ph));
		retPh = ph;
	}
	else if (IS_ALLOCATED(prevPt) && !IS_ALLOCATED(nextPh))
	{
		void* nextPt = GET_TAIL(nextPh);
		size_t emptySize = (char*)nextPt - (char*)ph + WORD;
		SET_MASK(ph, emptySize, 0);
		SET_MASK(nextPt, emptySize, 0);
		retPh = ph;
	}
	else if (!IS_ALLOCATED(prevPt) && IS_ALLOCATED(nextPh))
	{
		void* prevPh = GET_PREV_HEAD(ph);
		void* pt = GET_TAIL(ph);
		size_t emptySize = (char*)pt - (char*)prevPh + WORD;
		SET_MASK(prevPh, emptySize, 0);
		SET_MASK(pt, emptySize, 0);
		retPh = prevPh;
	}
	else
	{
		void* prevPh = GET_PREV_HEAD(ph);
		void* nextPt = GET_TAIL(nextPh);
		size_t emptySize = (char*)nextPt - (char*)prevPh + WORD;
		SET_MASK(prevPh, emptySize, 0);
		SET_MASK(nextPt, emptySize, 0);
		retPh = prevPh;
	}
	return retPh;
}

static void* find_fit(size_t blockSize)
{
	char* ph;
	for (ph = head_ptr; GET_SIZE(ph) != 0; ph = GET_NEXT_HEAD(ph))
	{
		if (!IS_ALLOCATED(ph) && blockSize <= GET_SIZE(ph))
			return ph;
	}
	return NULL;
}

static void place(void* ph, size_t blockSize)
{
	static const int sk_minSize = (1 + 2 * DWORD - 1) / DWORD * DWORD;
	size_t emptySize = GET_SIZE(ph);
	if (emptySize - blockSize < sk_minSize)
	{
		SET_ALLOCATED(ph);
		SET_ALLOCATED(GET_TAIL(ph));
		return;
	}

	// 分裂空块
	void* nextPh = (char*)ph + blockSize;
	void* pt = GET_PREV_TAIL(nextPh);
	SET_MASK(ph, blockSize, 1);
	SET_MASK(pt, blockSize, 1);
	SET_MASK(nextPh, emptySize - blockSize, 0);
	SET_MASK(GET_TAIL(nextPh), emptySize - blockSize, 0);
}
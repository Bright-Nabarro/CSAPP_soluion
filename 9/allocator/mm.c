#include <stddef.h>
#include "memlib.h"

#define WSIZE		4			//bytes
#define DSIZE		8			//double word size
#define CHUNKSIZE	(1<<12)		//一次扩展堆的大小

#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define PACK(size, alloc)	((size) | (alloc))

#define GET(p)			(*(unsigned int*)(p))
#define PUT(p, val)		(*(unsigned int*)(p) = (val))

//可以用此判断结尾标识，结尾标识大小等于0
#define GET_SIZE(p)		(GET(p) & ~0x7)
//0x2和0x4 bit位为空
#define GET_ALLOC(p)	(GET(p) & 0x1)

//bp为指向内容的指针
#define HDRP(bp)		((char*)(bp) - WSIZE)						//结构头部
#define FTRP(bp)		((char*)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)	//结构尾部

//根据`bp`计算前驱块和后继块
#define NEXT_BLKP(bp)	((char*)(bp) + GET_SIZE(((char*)(bp) - WSIZE)))
#define PREV_BLKP(bp)	((char*)(bp) - GET_SIZE(((char*)(bp) - DSIZE)))

static void* extend_heap(size_t words);
static void* coalesce(void* bp);
static void* find_fit(size_t asize);
static void place(void* bp, size_t asize);
char* heap_listp;

int mm_init(void)
{
	heap_listp = mem_sbrk(4*WSIZE);
	if (heap_listp == (void*)-1)
		return -1;

	PUT(heap_listp, 0);
	//序言块
	PUT(heap_listp + (1*WSIZE), PACK(DSIZE, 1));
	PUT(heap_listp + (2*WSIZE), PACK(DSIZE, 1));
	//结尾块
	PUT(heap_listp + (3*WSIZE), PACK(0,1));
	//指向序言块之后
	heap_listp += (2*WSIZE);

	if(extend_heap(CHUNKSIZE/WSIZE) == NULL)
		return -1;

	return 0;
}

static void* extend_heap(size_t words)
{
	char* bp;
	size_t size;

	//8字节对齐
	size = (words % 2) ? (words+1)*WSIZE : words*WSIZE;
	if((long)(bp = mem_sbrk(size)) == -1)
		return NULL;

	//将整个新分配的内存作为空闲块
	PUT(HDRP(bp), PACK(size, 0));		//覆盖原结尾块
	PUT(FTRP(bp), PACK(size, 0));
	//创建新的结尾块
	PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));

	return coalesce(bp);
}

void mm_free(void* bp)
{
	size_t size = GET_SIZE(HDRP(bp));
	PUT(HDRP(bp), PACK(size, 0));
	PUT(FTRP(bp), PACK(size, 0));
	coalesce(bp);
}

static void* coalesce(void* bp)
{
	size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
	size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
	size_t size = GET_SIZE(HDRP(bp));

	if(prev_alloc && next_alloc)
	{
		return bp;
	}
	else if(prev_alloc && !next_alloc)
	{
		size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
		PUT(HDRP(bp), PACK(size, 0));
		PUT(FTRP(bp), PACK(size, 0));

	}
	else if(!prev_alloc && next_alloc)
	{
		size += GET_SIZE(HDRP(PREV_BLKP(bp)));
		PUT(FTRP(bp), PACK(size, 0));
		bp = PREV_BLKP(bp);
	}
	else
	{
		size += GET_SIZE(HDRP(PREV_BLKP(bp))) +
			GET_SIZE(FTRP(NEXT_BLKP(bp)));
		PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
		PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));
		bp = PREV_BLKP(bp);
	}
	return bp;
}

void *mm_malloc(size_t size)
{
	size_t asize; /* Adjusted block size */
	size_t extendsize; /* Amount to extend heap if no fit */
	char *bp;

	/* Ignore spurious requests */
	if (size == 0)
		return NULL;

	/* Adjust block size to include overhead and alignment reqs. */
	if(size <= DSIZE)
		asize = 2*DSIZE;
	else
		asize = DSIZE * ((size + (DSIZE) + (DSIZE-1)) / DSIZE);

	/* Search the free list for a fit */
	if ((bp = find_fit(asize)) != NULL)
	{
		place(bp, asize);
		return bp;
	}

	/* No fit found. Get more memory and place the block */
	extendsize = MAX(asize,CHUNKSIZE);
	if ((bp = extend_heap(extendsize/WSIZE)) == NULL)
		return NULL;
	place(bp, asize);
	return bp;
}

static void* find_fit(size_t asize)
{
	//asize为计算后的隐式链表大小
	//如果查询不到，则返回NULL
	char* bp;
	for(bp = heap_listp; GET_SIZE(bp) > 0; bp = NEXT_BLKP(bp))
	{
		if(!GET_ALLOC(bp) && asize < GET_SIZE(bp))
		{
			return bp;
		}
	}
	return NULL;
}

static void place(void* bp, size_t asize)
{
	if(GET_SIZE(bp) - asize < 2*DSIZE)
	{
		PUT(HDRP(bp), PACK(asize, 1));
		PUT(FTRP(bp), PACK(asize, 1));
		return;
	}
	
}

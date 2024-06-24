#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "memlib.h"

static char* mem_heap;			//推底部
static char* mem_brk;			//堆顶部
static char* mem_max_addr;		//最大内存空间顶部

void mem_init(void)
{
	mem_heap = (char*) malloc(MAX_HEAP);
	mem_brk = (char*)mem_heap;
	mem_max_addr = (char*)(mem_heap + MAX_HEAP);
}

void* mem_sbrk(int incr)
{
	char* old_brk = mem_brk;

	if((incr < 0) || (mem_brk + incr) > mem_max_addr)
	{
		errno = ENOMEM;		//out of memory
		fprintf(stderr, 
		"ERROR: mem_sbrk failed. Ran out of memory...\n");
		return (void*) -1;
	}
	mem_brk += incr;
	return (void*) old_brk;
}
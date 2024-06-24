#include "mem_stm.h"
#include <stdio.h>
#include <stdlib.h>

static char* mem_heap;
static char* mem_brk;
static char* mem_max_addr;

void mem_init(void)
{
	mem_heap = (char*)malloc(MAX_HEAP_SIZE);
	if (mem_heap == NULL)
	{
		fprintf(stderr, "Allocate memory error\n");
		exit(1);
	}

	mem_brk = mem_heap;
	mem_max_addr = mem_heap + MAX_HEAP_SIZE;
	printf("Virtual heap memory system initial success\n");
	printf("Total size:\t%dB\n", MAX_HEAP_SIZE);
}

void* mem_sbrk(int incr)
{
	if (incr <= 0 || mem_brk + incr > mem_max_addr)
	{
		return NULL;
	}

	void* old_brk = (void*)mem_brk;
	mem_brk += incr;
	return old_brk;
}

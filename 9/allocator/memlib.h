#ifndef MEMLIB_H
#define MEMLIB_H

#define MAX_HEAP (1<<26)		//64MB(byte)

//初始化堆内存模型，大小为MAX_HEAP
void mem_init(void);

//扩展堆内存incr大小，返回旧的堆顶部指针
void* mem_sbrk(int incr);

#endif
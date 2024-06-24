#pragma once

#ifndef TEST_MEM
#define MAX_HEAP_SIZE (1 << 26) // 64MB
#else
#define MAX_HEAP_SIZE (1 << 10)
#endif

// 初始化堆
void mem_init(void);

// 扩展堆, 确保incr > 0
// 失败返回NULL
void* mem_sbrk(int incr);

#pragma once
#include <stdbool.h>
#include <stddef.h>

/*
 *	实现使用隐式空间链表
 *	目前的问题：
 *		1.如果一次性分配大块内存，不能直接进行扩展，只能在循环中一次次增加片的大小
 */
// 以字节为单位
#define WORD  4
#define DWORD 8

#ifndef TEST_MEM
#define CHUNK (1 << 12) // 一次扩展堆的大小
#else
#define CHUNK (1 << 5)
#endif

// 双字对齐, 1 word = 4 byte
bool mm_init(void);
void* mm_malloc(size_t size);
void mm_free(void* pb);
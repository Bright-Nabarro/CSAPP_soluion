#include "mm.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int BIG_ASSERT_ARRAY[1024];

// 测试基本分配和释放
void test_basic_alloc_free()
{
	void* ptr = mm_malloc(100);
	assert(ptr != NULL);
	// 写入并验证数据
	memset(ptr, 0xAA, 100);
	for (int i = 0; i < 100; ++i)
	{
		assert(((unsigned char*)ptr)[i] == 0xAA);
	}
	mm_free(ptr);
}

// 测试多次分配和释放
void test_multiple_alloc_free()
{
	int** parr;
	const int SIZE = 16;
	parr = mm_malloc(SIZE * sizeof(int*));
	int counter = 0;
	for (int i = 0; i < SIZE; i++)
	{
		parr[i] = mm_malloc((i + 1) * sizeof(int));
		if (parr[i] == NULL)
		{
			printf("Heap full, i = %d\n", i);
			return;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int k = 0; k < i + 1; k++)
		{
			parr[i][k] = BIG_ASSERT_ARRAY[counter++];
		}
	}
	counter = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int k = 0; k < i + 1; k++)
		{
			assert(parr[i][k] == BIG_ASSERT_ARRAY[counter++]);
		}
	}
	for (int i = 0; i < SIZE; i++)
		mm_free(parr[i]);
	mm_free(parr);
}

// 测试大块内存分配
void test_large_alloc()
{

	void* ptr = mm_malloc(1024 * 1024 * 1); // 1MB
	assert(ptr != NULL);
	// 写入并验证数据
	memset(ptr, 0xCC, 1024 * 1024 * 1);
	for (int i = 0; i < 1024 * 1024 * 1; ++i)
	{
		assert(((unsigned char*)ptr)[i] == 0xCC);
	}
	mm_free(ptr);
}

// 测试边界条件
void test_edge_cases()
{

	void* ptr = mm_malloc(0);
	assert(ptr == NULL);
	ptr = mm_malloc(1);
	assert(ptr != NULL);
	// 写入并验证数据
	*((unsigned char*)ptr) = 0xDD;
	assert(*((unsigned char*)ptr) == 0xDD);
	mm_free(ptr);
}

// 测试内存重用
void test_memory_reuse()
{
	void* ptr1 = mm_malloc(100);
	mm_free(ptr1);
	void* ptr2 = mm_malloc(100);
	// 检查指针是否相同（内存重用）
	assert(ptr1 == ptr2);
	// 写入并验证数据
	memset(ptr2, 0xEE, 100);
	for (int i = 0; i < 100; ++i)
	{
		assert(((unsigned char*)ptr2)[i] == 0xEE);
	}
	mm_free(ptr2);
}

// 测试错误处理
void test_error_handling()
{
	mm_free(NULL); // 不应崩溃
}

int main()
{
	mm_init();
	for (int i = 0; i < sizeof BIG_ASSERT_ARRAY / sizeof BIG_ASSERT_ARRAY[0];
		 i++)
	{
		BIG_ASSERT_ARRAY[i] = i;
	}
	test_basic_alloc_free();
	test_multiple_alloc_free();
	test_large_alloc();
	test_edge_cases();
	test_memory_reuse();
	test_error_handling();

	printf("o((>ω< ))o\n");
	return 0;
}
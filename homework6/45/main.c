#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "transpose.h"

#define DIM 8192

void test_ori(int* src, int dim)
{
	int* dst = malloc(sizeof(int) * DIM * DIM);
	struct timeval start, end;
	long seconds, useconds;
	double mtime;

	gettimeofday(&start, NULL);
	transpose_org(src, dst, dim);
	gettimeofday(&end, NULL);
	
	seconds = end.tv_sec - start.tv_sec;
	useconds = end.tv_usec - start.tv_usec;
	mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
	
	printf("b2 runs:\t%f ms\n", mtime);
	free(dst);
}

void test_b(int* src, int dim, void(*func)(int* dst, int* src, int dim), int i)
{
	int* dst = malloc(sizeof(int) * DIM * DIM);
	struct timeval start, end;
	long seconds, useconds;
	double mtime;

	gettimeofday(&start, NULL);
	func(src, dst, dim);
	gettimeofday(&end, NULL);
	
	seconds = end.tv_sec - start.tv_sec;
	useconds = end.tv_usec - start.tv_usec;
	mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
	
	printf("block%d runs:\t%f ms\n", i, mtime);
	free(dst);
}

void test_bi(int* src, int dim, int i)
{
	int* dst = malloc(sizeof(int) * DIM * DIM);
	transpose_bi(src, dst, dim, i);

	struct timeval start, end;
	long seconds, useconds;
	double mtime;

	gettimeofday(&start, NULL);
	transpose_bi(src, dst, dim, i);
	gettimeofday(&end, NULL);
	
	seconds = end.tv_sec - start.tv_sec;
	useconds = end.tv_usec - start.tv_usec;
	mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
	
	printf("blocki%d runs:\t%f ms\n", i, mtime);

	free(dst);
}

int main(void)
{
	srand(time(NULL));
	int* src = malloc(sizeof(int) * DIM * DIM);
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			src[DIM * i + j] = rand() % 1000000;
		}
	}
	test_ori(src, DIM);
	test_b(src, DIM, transpose_b2, 2);
	test_b(src, DIM, transpose_b4, 4);
	for(int i = 2; i <= 20; i++)
		test_bi(src, DIM, i);

	free(src);
}
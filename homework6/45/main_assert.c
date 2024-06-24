#include <stdio.h>
#include <assert.h>
#include "transpose.h"

#define DIM 97

void print_arr(int* src, int dim)
{
	for(int i = 0; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
		{
			printf("%d\t", src[dim*i + j]);
		}
		printf("\n");
	}
}

void assert_arr(int*src1, int* src2, int dim)
{
	for(int i = 0; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
		{
			assert(src1[i*dim + j] == src2[i*dim + j]);
		}
	}
}

int main(void)
{
	//	correctness check
	int src[DIM][DIM];
	int dst1[DIM][DIM];
	int dst2[DIM][DIM];
	int dst3[DIM][DIM];
	int dst4[DIM][DIM];
	int counter = 0;
	for(int i = 0; i < DIM; i++)
	{
		for(int j = 0; j < DIM; j++)
		{
			src[i][j] = counter++;
		}
	}
	transpose_org(dst1[0], src[0], DIM);
	transpose_bi(dst2[0], src[0], DIM, 2);
	transpose_b2(dst3[0], src[0], DIM);
	transpose_b4(dst4[0], src[0], DIM);
	assert_arr(dst2[0], dst1[0], DIM);
	assert_arr(dst3[0], dst2[0], DIM);
	assert_arr(dst4[0], dst2[0], DIM);
	//print_arr(dst2[0], DIM);
}
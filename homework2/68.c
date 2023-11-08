#include<stdio.h>
#include<assert.h>

int lower_one_mask(int n)
{
	//Assume 1 <= n <= w
	int result_0 = ((1<<(n-1))-1) << 1;
	return result_0 | 1;
}

//better solution
int lower_one_mask_better(int n)
{
	//Assume 1 <= n <= w
	int w = sizeof(int) << 3;
	return (unsigned)-1 >> (w-n);
}

int main()
{
	int (*f)(int) = lower_one_mask;			
	assert(f(32) == -1);
	assert(f(1) == 1);
	assert(f(2) == 3);
	assert(f(7) == 0x7F);
	assert(f(17) == 0x1FFFF);
}

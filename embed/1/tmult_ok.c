#include <stdio.h>

int tmult_ok_asm(long x, long y, long* dest)
{
	unsigned char b_result;
	asm(
		"imulq	%[x], %[y]\n\t"
		"movq	%[y], %[p]\n\t"
		"seto	%[ret]"
		: [ret] "=r" (b_result), [y] "+r" (y), [p] "=m" (*dest)
		: [x] "r" (x)
	);
	return b_result;
}

int tmult_ok_asm2(long x, long y, long* dest)
{
	unsigned char b_result;
	asm(
		"movq	%[x], %%rax\n\t"
		"imulq	%[y]\n\t"
		"movq	%%rax, %[p]\n\t"
		"seto	%[ret]"
		: [ret] "=r" (b_result), [p] "=m" (*dest)
		: [x] "r" (x), [y] "r" (y)
		: "%rax", "%rdx"	//%rdx used by imulq
	);
	return b_result;
}

int main(void)
{
	long x = 0xFFFFFF0FFFFFFFFF;
	long y = 0xFFFFFF0FFFFFFFFF;
	long ret;
	int overflow = tmult_ok_asm2(x, y, &ret);
	if(overflow)
	{
		printf("overflow\n");
	}
	printf("%ld\n", ret);
}
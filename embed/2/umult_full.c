#include <stdio.h>
void umult_full(unsigned long x, unsigned long y, unsigned long* dest)
{
	//mulq  [y] * %rax -> %rdx : %rax
	asm(
		"movq	%[x], %%rax		\n\t"
		"mulq	%[y]			\n\t"
		"movq	%%rax, %[p_low]	\n\t"
		"movq	%%rdx, %[p_high]\n\t"
		:[p_low] "=m" (*(dest+1)), [p_high] "=m" (*dest)
		:[x] "r" (x), [y] "r" (y)
		:"%rax", "%rdx"
	);
}

int main(void)
{
	unsigned long dest[2];
	unsigned long x = 0xFFF0FFF0FFF0FFF0;
	unsigned long y = 0xFFF0FFF0FFF0FFF0;
	umult_full(x, y, dest);
	printf("0x%lX:%lX\n", dest[1], dest[0]);
}
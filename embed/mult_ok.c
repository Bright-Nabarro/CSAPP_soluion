int tmult_ok_asm(long x, long y, long* dest)
{
	long result = x*y;
	*dest = result;
	return result > 0;
}

int umult_ok_asm(unsigned long x, unsigned long y, unsigned long* dest)
{
	unsigned char b_result;
	asm("movq	%[x], %%rax	\n\t"
		"mulq	%[y]		\n\t"
		"movq	%%rax, %[p]	\n\t"
		"setae	%[b]"
		: [b] "=r" (b_result), [p] "=m" (*dest)
		: [x] "r" (x), [y] "r" (y)
		: "%rax", "%rdx"	/*%rdx is dest*/
	);
	return b_result;
}

int main()
{
}
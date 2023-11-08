#include<stdio.h>

int A(unsigned x)
{
	return ~x;
}

int B(unsigned x)
{
	return !x;
}

int C(unsigned x)
{
	x &= 0xff;
	return !(x^0xff);
}

int D(unsigned x)
{
	unsigned shift_val = (sizeof(unsigned)-1) << 3;
	x >>= shift_val;
	return !(x|0);
}

int main(void)
{
	unsigned x;
	scanf("%X", &x);
	printf("A: %d\n", A(x));
	printf("B: %d\n", B(x));
	printf("C: %d\n", C(x));
	printf("D: %d\n", D(x));

	return 0;
}

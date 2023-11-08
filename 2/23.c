#include<stdio.h>

int fun1(unsigned word)
{
	return (int)((word << 24) >> 24);
}

int fun2(unsigned word)
{
	return ((int)word << 24) >> 24;
}

int main(void)
{
	unsigned n = 0x87654321;
	printf("%.8x\n", fun1(n));
	printf("%.8x\n", fun2(n));
	return 0;
}

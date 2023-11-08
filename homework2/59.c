#include<stdio.h>

int conbineAB(unsigned A, unsigned B)
{
	unsigned mask = 0xff;
	return (B & ~mask) | (A & mask);
}
int main(void)
{
	unsigned A = 0x89ABCDEF;
	unsigned B = 0x76543210;
	printf("%X", conbineAB(A, B));
}

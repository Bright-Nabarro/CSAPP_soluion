#include<stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
	unsigned mask = 0xff << (i<<3);
	unsigned result =  (x & ~mask) | (b << (i<<3));
	return result;
}

int main(void)
{
	printf("%X\n", replace_byte(0x12345678, 2, 0xab));
	printf("%X\n", replace_byte(0x12345678, 0, 0xab));
}

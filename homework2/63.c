#include<stdio.h>
#include<assert.h>
#include<stdint.h>

unsigned srl(unsigned x, int k)
{
	unsigned xsra = (int)x >> k;
	unsigned l = (sizeof(unsigned)<<3)-k;
	unsigned mask = (1<<l)-1;
	return xsra & mask;
}

unsigned sra(int x, int k)
{
	int xsrl = (unsigned)x >> k;
	unsigned l = (sizeof(int)<<3)-k;
	unsigned sign = xsrl & 1<<(l-1);
	unsigned mask = (1<<l)-1;
	return (~(~mask + sign+sign) & ~mask)| xsrl;
}

int main(void)
{
	unsigned ux;
	ux = 1; 
	assert(ux>>3 == srl(ux,3));
	ux = UINT32_MAX;
	assert(ux>>6 == srl(ux,6));
	ux = 0x12345678;
	assert(ux>>20 == srl(ux,20));
	int ix;
	ix = -1;
	assert(ix>>5 == sra(ix,5));
	ix = INT32_MIN;
	assert(ix>>2 == sra(ix,2));
	ix = 1;
	assert(ix>>1 == sra(ix,1));
	ix = 0xf0123456;
	assert(ix>>20 == sra(ix,20));
}


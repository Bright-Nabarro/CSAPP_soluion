#include<stdio.h>
#include<assert.h>
int odd_ones(unsigned x)
{
	//return 1 when x contains an  odd number of 1s; 0 otherwise
	//assume w=32
	x ^= x>>16;
	x ^= x>>8;
	x ^= x>>4;
	x ^= x>>2;
	x ^= x>>1;
	return x&1;
}

int main(void)
{
	assert(odd_ones(0x0000d95a) == 1);
	assert(odd_ones(0x0000595a) == 0);
	assert(odd_ones(0xffffffff) == 0);
	assert(odd_ones(0xfffffffe) == 1);
	assert(odd_ones(1) == 1);
	assert(odd_ones(2) == 1);
	assert(odd_ones(3) == 0);
	assert(odd_ones(0x02180294) == 1);
	assert(odd_ones(0x42180294) == 0);
}


#include<assert.h>

int leftmost_one(unsigned x)
{
	x |= (x>>1);
	x |= (x>>2);
	x |= (x>>4);
	x |= (x>>8);
	x |= (x>>16);
	//return ((long)x+1) >> 1;	(my answer)
	return (x >> 1) + (x && 1);
}

int main(void)
{
	assert(leftmost_one(0xFFFFFFFF) == 0x80000000);
	assert(leftmost_one(0x40080018) == 0x40000000);
	assert(leftmost_one(0x1E0C0280) == 0x10000000);
	assert(leftmost_one(0x00001C28) == 0x00001000);
	assert(leftmost_one(0x00004000) == 0x00004000);
	assert(leftmost_one(2) == 2);
	assert(leftmost_one(1) == 1);
	assert(leftmost_one(0) == 0);
}

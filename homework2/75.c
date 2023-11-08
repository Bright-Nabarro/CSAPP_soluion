#include<stdio.h>
#include<inttypes.h>

int signed_high_prod(int x, int y)
{
	int64_t result = (int64_t)x*y;
	return (result>>32);
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
	int result = signed_high_prod(x,y);
	int w = sizeof(unsigned) << 3;
	unsigned s_x = x >> (w-1);
	unsigned s_y = y >> (w-1);
	//return result + x*s_y + y*s_x + (s_x*s_y << 31);
	return result + x*s_y + y*s_x;
}

int main()
{
	unsigned x, y;
	scanf("%x %x", &x, &y);
	printf("unsigned: %.8X\n",unsigned_high_prod(x,y));
	printf("signed:   %.8X\n",signed_high_prod(x,y));
}

#include<stdio.h>

unsigned rotate_left(unsigned x, int n)
{
	//Assume 0 <= x < w;
	int w = sizeof(unsigned) << 3;
	//左边n位掩码
	int mask = ~((1 << (w-n))-1);
	//将左边n位移到最低位
	int l2r_n = (x & mask) >> (w-n);
	return (x<<n) | l2r_n;
}

int main()
{
	unsigned x;
	int n;
	scanf("%x", &x);
	scanf("%d", &n);
	printf("%.8X", rotate_left(x, n));
}

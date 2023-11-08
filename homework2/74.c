#include<stdio.h>

int tsub_ok(int x, int y)
{
	int w = sizeof(int) << 3;
	int sign_m = 1 << (w-1);
	int sum = x-y;
	int xm = x&sign_m;
	int ym = y&sign_m;
	int sm = sum&sign_m;
	return !(xm != ym && xm != sm);
}

int main(void)
{
	int x, y;
	scanf("%x %x", &x, &y);
	printf("%d\n", tsub_ok(x,y));
}

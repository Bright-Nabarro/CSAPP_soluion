#include <stdio.h>
#include <stdlib.h>
#include <time.h>

union fu
{
	float f;
	unsigned u;
};

unsigned f2u(float x)
{
	union fu n;
	n.f = x;
	return n.u;
}

float u2f(unsigned x)
{
	union fu n;
	n.u = x;
	n.u = n.u & 0XBFFFFFFF;
	return n.f;
}

int float_le(float x, float y)
{
	unsigned ux = f2u(x);
	unsigned uy = f2u(y);

	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;

	if (sx != sy)
	{
		// x<0, y>=0
		if (sx == 1)
			return -1;
		// x>0, y<=0
		return 1;
	}
	// sx == sy
	//比较阶码
	unsigned exp_mask = 0x7F800000;
	unsigned ex = ux & exp_mask;
	unsigned ey = uy & exp_mask;
	if (ex > ey)
		return 1;
	if (ex < ey)
		return -1;

	//比较尾数
	unsigned frac_mask = 0x7FFFFF;
	unsigned fx = ux & frac_mask;
	unsigned fy = uy & frac_mask;
	if (fx > fy)
		return 1;
	if (fx < fy)
		return -1;
	return 0;
}

int normal(float x, float y)
{
	if (x < y)
		return -1;
	if (x > y)
		return 1;
	return 0;
}

int main(void)
{
	float x, y;
	srandom(time(0));
	for (int i = 0; i < 10000000; i++)
	{

		x = u2f(random());
		y = u2f(random());
		int func_result = float_le(x, y);
		int answer = normal(x, y);
		if (func_result != answer)
		{
			printf("x=%f\ny=%f\n", x, y);
			return 1;
		}
	}
	printf("success\n");
}
#include <limits.h>
#include <stdio.h>
int threefourths(int x)
{
	int neg_mask = 1 << ((sizeof(x) << 3) - 1);
	int is_neg = neg_mask & x;
	is_neg && (x = -x);
	x = (x >> 1) + (x >> 2);
	is_neg && (x = -x);
	return x;
}
int threeforths_answer(int x)
{
	int is_neg = x & INT_MIN;
	int f = x & ~0x3;
	int l = x & 0x3;

	int fd4 = f >> 2;
	int fd4m3 = (fd4 << 1) + fd4;

	int lm3 = (l << 1) + l;
	int bias = (1 << 2) - 1;
	(is_neg && (lm3 += bias));
	int lm3d4 = lm3 >> 2;

	return fd4m3 + lm3d4;
}

int main()
{
	int x;
	while (1)
	{
		scanf("%d", &x);
		printf("3/4x: %d,\tthreefourths: %d", (int)(3 / (float)4 * x),
			   threefourths(x));
		printf("    x/2+x/4: %d\n", x / 2 + x / 4);
	}
}
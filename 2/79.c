#include "78.h"
#include <stdio.h>

int mul3div4(int x)
{
	int n = (x << 1) + x;
	return divide_power2(n, 2);
}

int main()
{
	int x;
	while (1)
	{
		scanf("%d", &x);
		printf("3*x/4: %d\tmul3div4: %d\n", 3 * x / 4, mul3div4(x));
	}
}
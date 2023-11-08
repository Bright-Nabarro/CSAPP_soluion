#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int x, y;
	x = 0xE000180;
	y = 0xE500080;
	printf("B\n");
	printf("%d\n", (x + y) * 16 + y - x);
	printf("%d\n", 17 * y + 15 * x);
	printf("C\n");
	printf("%d\n", ~x + ~y + 1);
	printf("%d\n", ~(x + y));
	printf("E\n");
	x = -1;
	printf("%d\n", ((x >> 2) << 2));
	printf("%d\n", x);
}
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

bool uadd_ok(unsigned x, unsigned y)
{
	unsigned s = x+y;
	return s >= x;
}

int main(void)
{
	unsigned x = 4294967291;
	unsigned y = 21;
	unsigned sum = x+y;
	if (uadd_ok(x, y))
		printf("ok");
	else
		printf("on");
	printf("\n%u", sum);
}

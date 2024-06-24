#include <stdio.h>

void f(void);

static int y = 0x123;
static int x = 0x456;

int main()
{
	f();
	printf("x = 0x%x y = 0x%x \n", x, y);
	return 0;
}
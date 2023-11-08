#include<stdio.h>

int int_shifts_are_arithmetic()
{
	int x = -1;
	unsigned w = sizeof(int)<<3;
	x >>= (w-1);
	return !~x;
}

int main(void)
{
	printf("%d\n", int_shifts_are_arithmetic());
}

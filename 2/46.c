#include<stdio.h>

int main()
{
	long double result;
	long double a10 = 1/10;
	long double z = 0x0.199998p0;
	result = a10 - z;
	printf("%.30Lf", result);
}

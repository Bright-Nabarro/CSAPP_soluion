#include<stdio.h>

int main(void)
{
	int x = -2147483646;
	for(int i=0; i<20; i++)
		printf("%d\n", x-i);
}

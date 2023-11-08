#include<stdio.h>

int div16(int x)
{
	int f = x>>31 & 0xf;
	return (x+ f) >> 4;
}

int main()
{
	int m;
	scanf("%d", &m);
	if(m/16 == div16(m))
		printf("true");
	else
		printf("false");
}

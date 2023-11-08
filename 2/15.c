#include<stdio.h>
#include<stdbool.h>

bool compare(int a, int b)
{
	return !(a^b);
}

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	if(compare(a,b))
		printf("true");
	else
		printf("false");
	return 0;
}

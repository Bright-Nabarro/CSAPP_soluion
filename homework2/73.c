#include<stdio.h>
#include<limits.h>

int saturating_add(int x, int y)
{
	int result = x + y;
	(x > 0 && y > 0) && (result < 0 && (result = INT_MAX));
	(x < 0 && y < 0) && (result >= 0 && (result = INT_MIN));
	return result;
}


int main(void)
{
	printf("%x\n",-1 + 2);
	printf("%x",saturating_add(-1,2));
}

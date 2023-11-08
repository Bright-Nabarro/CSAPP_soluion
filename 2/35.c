#include<stdio.h>
#include<stdbool.h>

bool tmult_ok(int x, int y)
{
	int p = x*y;
	return ! p/x == y;
}

int main(void)
{
	
}

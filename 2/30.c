#include<stdio.h>
#include<stdbool.h>
bool tadd_ok(int x, int y)
{
	int sum = x+y;
	bool neg_over = x<0 && y<0 && sum>=0;
	bool pos_over = x>0 && y>0 && sum<=0;
	return !neg_over && !pos_over;
}

int main(void)
{
	
}

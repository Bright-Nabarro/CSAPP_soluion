#include <stdio.h>
long switchv(long idx)
{
	long result = 0;
	switch(idx) 
	{
	case 0:
		result = 0xaaa;
		break;
	case 2:
	case 5:
		result = 0xbbb;
		break;
	case 3:
		result = 0xccc;
		break;
	default:
		result = 0xddd;
	}
	return result;
}

#define CNT 8
#define MINVAL -1

int main(void)
{
	long a = switchv(2);
	long b = switchv(6);
	long c = switchv(7);
	long d = switchv(5);
	printf("%ld%ld%ld%ld", a, b, c, d);
}
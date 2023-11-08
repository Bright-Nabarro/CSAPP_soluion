#include<stdio.h>

#define POS_INFINITY	1.0e400
#define NEG_INFINITY	-POS_INFINITY
#define NEG_ZERO		-0.0


int main(void)
{
	float i = NEG_ZERO;
	float ni = NEG_INFINITY;
	float pi = POS_INFINITY;
	printf("%f\n", pi);
	printf("%f\n", ni);
	printf("%f\n", i);
}

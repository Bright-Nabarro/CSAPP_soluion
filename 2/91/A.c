#include <math.h>
#include <stdio.h>

typedef union
{
	unsigned u;
	float f;
} U_F;

int main(void)
{
	U_F value;
	value.u = 0x40490FDB;
	printf("%f\n", value.f);
}
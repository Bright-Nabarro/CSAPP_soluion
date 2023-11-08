#include <stdio.h>

typedef union
{
	float f;
	unsigned u;
} f_u;

int main(void)
{
	f_u dd;
	dd.u = 0x7fff0000;
	printf("%f", dd.f);
}

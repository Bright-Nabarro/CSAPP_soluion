#include<stdio.h>
#include<math.h>

union d
{
	float f;
	unsigned int i;
};
int main(void)
{
	union d flt;
	flt.f = NAN;
	printf("%u", flt.i);
}

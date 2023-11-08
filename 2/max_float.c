#include<stdio.h>
#include<stdint.h>

union uflt
{
	float f;
	uint32_t i;
};

union udlt
{
	double d;
	uint64_t i;
};

int main(void)
{
	union uflt flt;
	union udlt dlt;
	flt.i = 0x00000001;
	printf("pos min: %.10e\n",flt.f);
	flt.i = 0x10000001;
	printf("neg min: %.10e\n",flt.f);
	flt.i = 0x7ffffffe;
	printf("pos max: %.10e\n",flt.f);
	flt.i = 0xfeffffff;
	printf("neg max: %.10e\n",flt.f);
	dlt.i = 0x0000000000000001;
	printf("pos min: %.20e\n",dlt.d);
	dlt.i = 0x1000000000000001;
	printf("pos min: %.20e\n",dlt.d);
	dlt.i = 0x7effffffffffffff;
	printf("pos min: %.20e\n",dlt.d);
	dlt.i = 0xfeffffffffffffff;
	printf("pos min: %.20e\n",dlt.d);
	return 0;
}

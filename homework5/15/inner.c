#include "../vec.h"
#define INITIAL (data_t)0;

void inner6_6(vec_ptr u, vec_ptr v, data_t* dest)
{
	long i;
	long length = vec_length(u);
	long limit = length - 5;
	data_t* udata = get_vec_start(u);
	data_t* vdata = get_vec_start(v);
	data_t sum = INITIAL;
	data_t sum1 = INITIAL;
	data_t sum2 = INITIAL;
	data_t sum3 = INITIAL;
	data_t sum4 = INITIAL;
	data_t sum5 = INITIAL;

	for (i = 0; i < limit; i += 6)
	{
		sum = sum + udata[i] * vdata[i];
		sum1 = sum1 + udata[i+1] * vdata[i+1];
		sum2 = sum2 + udata[i+2] * vdata[i+2];
		sum3 = sum3 + udata[i+3] * vdata[i+3];
		sum4 = sum4 + udata[i+4] * vdata[i+4];
		sum5 = sum5 + udata[i+5] * vdata[i+5];
	}

	for(; i < length; i++)
	{
		sum += udata[i] * vdata[i];
	}

	*dest = sum + sum1 + sum2 + sum3 + sum4 + sum5;
}
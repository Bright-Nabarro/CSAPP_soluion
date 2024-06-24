#include <stdio.h>
//#include <assert.h>
#include "math.h"
#include "../u2f.h"
typedef unsigned float_bits;

float_bits float_negate(float_bits f)
{
    unsigned exp =  f>>23 & 0xFF;
    unsigned frac = f     & 0x7FFFFF;
    if(exp == 0xFF && frac != 0)
        return f;
    else
        return f ^ 0x80000000;
}

int main(void)
{
    for(unsigned long long i = 0; i < 0xFFFFFFFF; ++i)
    {
        float_bits para = (float_bits)i;
        float native_float = u2f(para);
        float_bits turn_neg_float = float_negate(para);
        float neg_float = u2f(turn_neg_float);
        if(neg_float != -native_float)
        {
			if(isnan(neg_float) && isnan(native_float))
				continue;
            printf("a: %f\tn: %f\n", neg_float, native_float);
        }
    }
}

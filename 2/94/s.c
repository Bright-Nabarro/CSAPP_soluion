#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "../u2f.h"
typedef unsigned float_bits;

float_bits float_twice(float_bits f)
{
    unsigned sign = f>>31;
    unsigned exp =  f>>23 & 0xFF;
    unsigned frac = f     & 0x7FFFFF;
    if(exp == 0xFF)
    {
        return f;
    }
    if(exp == 0)
        frac <<= 1;

    exp = (exp + 1) & 0xFF;
    if (exp == 0xFF)
        return (sign << 31) | (exp << 23);
    return (sign << 31) | (exp << 23) | frac;
}

int main(void)
{
    for(unsigned long long i = 0; i < 0xFFFFFFFF; ++i)
    {
        float_bits fb = (float_bits)i;
        float native = u2f(fb) * 2;
        float turn   = u2f(float_twice(fb));
        if(isnan(native) && isnan(turn))
            continue;
        //!notice: cannot correspond completely awith the float*2
        if(native != turn)
        {
            printf("%llu\n",i);
            printf("%.28f\t%.28f\n", native, turn);
            printf("%X\n%X\n", f2u(native), f2u(turn));
        }
    }
    //float f;
    //while(scanf("%f", &f))
    //{
    //    float_bits fb = f2u(f);
    //    float result = u2f(float_twice(fb));
    //    printf("%f\n", result);
    //}
}

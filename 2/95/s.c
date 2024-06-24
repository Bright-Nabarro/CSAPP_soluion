#include <stdio.h>
#include "../u2f.h"

typedef unsigned float_bits;

float_bits float_half(float_bits f)
{
    unsigned sign = f>>31;
    unsigned exp =  f>>23 & 0xFF;
    unsigned frac = f     & 0x7FFFFF;
    if(exp == 0xFF && frac != 0)
    {
        return f;   //nan
    }
    else
    {
        exp = (exp - 1) & 0xFF;
        return (sign << 31) | (exp << 23) | frac;
    }
}

int main(void)
{
    float f;
    while(scanf("%f", &f))
    {
        float_bits fb = f2u(f);
        float result = u2f(float_half(fb));
        printf("%f\n", result);
    }
}
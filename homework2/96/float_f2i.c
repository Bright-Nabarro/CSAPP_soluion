#include <assert.h>
#include <stdio.h>

typedef union {
    unsigned u;
    float    f;
} UF;

float u2f(unsigned u)
{
    UF uf;
    uf.u = u;
    return uf.f;
}

unsigned f2u(float f)
{
    UF uf;
    uf.f = f;
    return uf.u;
}

typedef unsigned float_bits;

int float_f2i(float_bits f)
{
    unsigned sign = f>>31;
    unsigned exp =  f>>23 & 0xFF;
    unsigned frac = f     & 0x7FFFFF;
    if(exp == 0xFF && frac != 0)
        return 0x80000000;
    if((int)exp-127 < 0)
        return 0;

    int real_exp = 23-(exp-127);

    unsigned result;
    //printf("real_exp: %u\n", real_exp);

    if(real_exp > 0)
        result = (frac+(1<<23)) >> real_exp;
    else if(real_exp <= -8)     //overflow
        return 0x80000000;
    else
        result = (frac+(1<<23)) << -real_exp;

    if(sign)
        return (~result)+1;
    return result;
}

int main(void)
{
    //for(unsigned long long i = 0; i < 0xFFFFFFFF; ++i)
    //{
    //    float f = u2f(i);
    //    assert((int)f == float_f2i(i));
    //}
    float f;
    while(scanf("%f", &f))
    {
        printf("%d\n", float_f2i(f2u(f)));
    }
}
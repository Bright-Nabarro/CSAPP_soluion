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

float_bits float_i2f(int i)
{
    unsigned sign = i & 0x80000000;
    if(i < 0)
        i = -i;
    int real_exp;
    for(unsigned u = i; u != 0; u >>= 1)
    {
        ++real_exp;
    }
    real_exp = 24-real_exp;
    printf("real_exp: %d\n", real_exp);

    unsigned frac;
    if(real_exp > 0)
        frac = (i << real_exp) - (1<<23);
    else
        frac = (i >> -real_exp) - (1<<23);

    printf("frac: %u\n", frac);
    unsigned exp = 23 - real_exp + 127;

    return sign | (exp << 23) | frac;
}

int main(void)
{
    int i;
    while(scanf("%d", &i))
    {
        float_bits fb = float_i2f(i);
        float f = u2f(fb);
        printf("result: %.31f\n", f);
        printf("float: %.31f\n", (float)i);
    }
}
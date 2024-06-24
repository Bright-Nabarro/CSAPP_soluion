#include <assert.h>
#include "../u2f.h"
typedef unsigned float_bits;

float_bits float_absval(float_bits f)
{
    unsigned exp =  f>>23 & 0xFF;
    unsigned frac = f     & 0x7FFFFF;
    if(exp == 0xFF && frac != 0)
        return f;
    else
        return f & 0x7FFFFFFF;
}

int main(void)
{
    for(unsigned long long i = 0; i < 0xFFFFFFFF; ++i)
    {
        float_bits fb = (float_bits)i;
        float native = u2f(fb);
        float turn   = u2f(float_absval(fb));
        if(native > 0)
            assert(native == turn);
        else if(native < 0)
            assert(-native == turn);
    }
}

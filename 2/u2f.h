typedef union
{
    unsigned u;
    float    f;
} U_F;

inline float u2f(unsigned u)
{
    U_F ret;
    ret.u = u;
    return ret.f;
}

inline unsigned f2u(float f)
{
    U_F ret;
    ret.f = f;
    return ret.u;
}

long decode2(long x, long y, long z)
{
    y -= x;
    x = x * y;
    long temp = x << 63 >> 63;
    return temp ^ x;
}
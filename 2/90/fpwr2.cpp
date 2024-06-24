typedef union
{
    unsigned u;
    float f;
} U_F;

float u2f(unsigned u)
{
    U_F result;
    result.u = u;
    return result.f;
}

float fpwr2(int x)
{
    unsigned exp, frac;
    unsigned u;
	if(x < 0)
	{
		exp = 0;
		frac = 0;
	}
	else if(x < 0x007F'FFFF)
	{

	}
	else if(x <
	{
	}
	
}


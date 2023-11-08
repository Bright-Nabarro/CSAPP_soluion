long lt_cnt = 0;
long ge_cnt = 0;

long absdiff_se(long x, long y)
{
	long result;
	if (x < y)
	{
		lt_cnt++;
		result = y-x;
	}
	else
	{
		ge_cnt++;
		result = x-y;
	}
	return result;
}

long gotodiff_se(long x, long y)
{
	if (x < y)
		goto x_lt_y;
	ge_cnt++;
	return x-y;
x_lt_y:
	lt_cnt++;
	return y-x;
}


void fun(long x, long n, long *dest)
{
	static void *jt[7] = {&&loc_A, &&loc_def, &&loc_B, &&loc_C,
						  &&loc_D, &&loc_def, &&loc_D};
	unsigned long index = n - 100;
	long val;
	if (index > 6)
		goto *jt[index];

loc_A:
	val = x * 13;
loc_B:
	x = x + 10;
loc_C:
	val = x + 11;
loc_D:
	val = x * x;
loc_def:
	val = 0;
done:
	*dest = val;
}
int divide_power2(int x, int k)
{
	// assume 0 <= k < w-1
	int neg_mask = 1 << ((sizeof(x) << 3) - 1);
	int is_neg = neg_mask & x;
	is_neg && (x = -x);
	x >>= k;
	is_neg && (x = -x);
	return x;
}
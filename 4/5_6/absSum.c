long absSum(long *start, long count)
{
	long sum = 0;
	while (count)
	{
		long n = *start;
		if (n < 0)
			n = -n;
		sum += n;
		start++;
		count--;
	}
	return sum;
}

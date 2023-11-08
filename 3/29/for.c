long sum_even()
{
	long sum = 0;
	long i;
	for(i = 0; i < 10; i++)
	{
		if(i & 1)
			continue;
		sum += 1;
	}
	return sum;
}

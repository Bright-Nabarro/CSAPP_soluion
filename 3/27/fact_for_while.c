int fact_while(int n)
{
	int i = 2;
	int result = 1;
	while(i <= n)
	{
		result *= i;
		i++;
	}
	return result;
}

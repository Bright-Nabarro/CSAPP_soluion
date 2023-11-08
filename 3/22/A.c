int fac(int n)
{
	int result = 1;
	do
	{
		result *= n;
		n = n-1;
	}while(n > 1);
	return result;
}

int fac_goto(int n)
{
	int result = 1;
loop:
	result *= n;
	n = n-1;
	if(n > 1) goto loop;
	return result;
}


void cond(long a, long *p)
{
		if (p == 0)
			goto false;
		if (a > *p)
			goto false;
		*p = a;
	false:
		return;
}

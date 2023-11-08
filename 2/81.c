int A(int k)
{
	return -1 << k;
}

int B(int k, int j)
{
	int n1 = -1 << j;
	int mask = ~(-1 << k << j);
	return n1 & mask;
}
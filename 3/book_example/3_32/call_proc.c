void proc(long x1, long *px1, int x2, int *px2, short x3, short *px3, char x4,
		  char *px4);
long call_proc()
{
	long x1 = 1;
	int x2 = 2;
	short x3 = 3;
	char x4 = 4;
	proc(x1, &x1, x2, &x2, x3, &x3, x4, &x4);
	return (x1 + x2) * (x3 - x4);
}
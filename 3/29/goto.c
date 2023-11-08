long sum_even()
{
	long sum = 0;
	long i = 0;
	goto test;
loop:
	if(i & 1)	goto update; 
	sum += i;
update:
	i++;
test:
	if(i < 10) goto loop;

	return sum;
}

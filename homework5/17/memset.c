#include <stddef.h>
#include <stdio.h>

void* basic_memset(void* s, int c, size_t n)
{
	size_t cnt = 0;
	unsigned char* schar = s;
	while(cnt < n)
	{
		*schar++ = (unsigned char) c;
		cnt++;
	}
	return s;
}

void* opt_memset(void* s, int c, size_t n)
{
	unsigned long c_long = (unsigned char) c;
	unsigned long travel = (unsigned char) c;
	int K = sizeof(unsigned long);
	for(int i = 1; i < K; i++)
	{
		travel <<= 8;
		c_long |=  travel;
	}

	size_t cnt;
	unsigned char* schar = (unsigned char*) s;
	while(cnt < K)
	{
		if((size_t)schar % 8 == 0)
			break;
		*schar++ = (unsigned char) c;
	}

	unsigned long* slong = (unsigned long*) s;
	size_t limit = n-7;
	for(; cnt < limit; cnt += 8)
	{
		*slong++ = c_long;
	}
	unsigned char* schar = (unsigned char*) slong;
	for(; cnt < n; cnt++)
	{
		*schar++ = (unsigned char) c;
	}
	return s;
}

int main()
{
	char str1[100];
	basic_memset(str1, 'A', 25);
	char str2[100];
	basic_memset(str2, 'B', 25);
	printf("str1: %s\nstr2: %s\n", str1, str2);
}
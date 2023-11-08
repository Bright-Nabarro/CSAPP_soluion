#include<stdio.h>

int is_little_endian()
{
	unsigned u = 1;
	char* bytes_p = (char*)&u;
	return *bytes_p&1;
}

int main()
{
	if(is_little_endian())
		printf("true");
}

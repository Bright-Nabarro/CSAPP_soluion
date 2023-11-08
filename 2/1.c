#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
typedef unsigned char* byte_pointer;

void print_binary(int num)
{
	int bit;
	for(int i = 7; i >= 0; i--)
	{
		bit = (num >> i) & 1;
		printf("%d", bit);
	}
}

void show_bytes(void* p, size_t len)
{
	byte_pointer start = (byte_pointer)p;
	for(size_t i=0; i<len; i++)
	{
		print_binary(start[i]);
		printf(" ");
	}
	printf("\n");
}
int main(void)
{
	unsigned int n = 1;
	float f1 = 1;
	void* p = &n;
	show_bytes(&n, sizeof(n));
	show_bytes(&f1, sizeof(f1));
	return 0;
}


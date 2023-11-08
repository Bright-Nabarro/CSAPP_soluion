#include<stdio.h>
typedef unsigned char* byte_p;

void show_bytes(void* p, size_t len)
{
	byte_p start = (byte_p)p;
	size_t i;
	for(i = 0; i < len; i++)
		printf("%.2X ", start[i]);
	printf("\n");
}

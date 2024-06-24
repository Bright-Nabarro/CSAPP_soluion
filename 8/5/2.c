#include <stdio.h>
#include <stdlib.h>

int main()
{
	char buf[1000];
	FILE* fp = fopen("3.c", "r");
	if(fp == NULL)
	{
		perror("fopen error");
		exit(0);
	}
	if(ferror(fp))
	{
		perror("I/O ERROR");
		exit(0);
	}
	if(fgets(buf, 1000, fp) == NULL)
	{
		perror("ERROR");
		exit(0);
	}
	puts(buf);
}
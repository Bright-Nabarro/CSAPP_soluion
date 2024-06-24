#include <stdio.h>
#define SCALE 5

void func(char* a[])
{
	for(int i = 0; i < SCALE; i++)
	{
		a[i] = "abc";
	}
}

int main(void)
{
	char* a[SCALE] = {};
	func(a);
	for(int i = 0; i < SCALE; i++)
		printf("%s\n", a[i]);
}

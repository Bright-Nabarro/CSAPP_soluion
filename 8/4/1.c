#include <string.h>
#include <stdio.h>

int main(void)
{
	long long arr[10];
	memset(arr, 0, sizeof arr);
	for(size_t i = 0; i < 10; i++)
		printf("%lld ", arr[i]);
	printf("\n");
}
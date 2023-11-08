#include "78.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc <= 2)
	{
		printf("program less parampter\n");
		return 1;
	}
	int x = atoi(argv[1]);
	int k = atoi(argv[2]);
	printf("x = %d, k = %d\n", x, k);
	printf("x/2^k: %d\tdivide_power2: %d\n", x / (int)pow(2, k),
		   divide_power2(x, k));
}

#include "xshell.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char buf[256];
	if (fgets(buf, sizeof buf, stdin) == NULL)
	{
		perror("fgets");
		exit(1);
	}

	char* argv[MAXARGS];
	parseline(buf, argv);

	for (int i = 0; argv[i] != NULL; i++)
	{
		printf("[%d]:\t%s\n", i, argv[i]);
	}
}
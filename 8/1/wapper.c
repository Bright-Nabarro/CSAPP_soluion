#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pid_t Fork(void)
{
	pid_t pid;

	if((pid = fork()) < 0)
	{
		fprintf(stderr, "Fork error");
		exit(-1);
	}
	return pid;
}
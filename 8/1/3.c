#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "wapper.h"

int main(void)
{
	pid_t pid;
	if((pid = Fork()) == 0)
	{
		printf("child:\n");
		pid_t childPid;
		if((childPid = Fork()) == 0)
		{
			printf("grand child:\n");
			printf("this %d\n", getpid());
			printf("parent %d\n", getppid());
			exit(0);
		}
		wait(NULL);
		printf("this %d\n", getpid());
		printf("parent %d\n", getppid());
		exit(0);
	}
	wait(NULL);
	printf("main:\n");
	printf("this %d\n", getpid());
}
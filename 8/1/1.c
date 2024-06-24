#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errwrap.h>
#include "wapper.h"


int main(void)
{
	pid_t pid;
	if((pid = Fork()) != 0)
	{
		printf("%d\n", pid);
	}
	else
		exit(0);
	wait(NULL);
	printf("%d\n", getpid());
}
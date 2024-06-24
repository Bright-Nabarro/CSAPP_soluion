#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

bool siginted = false;

void handler(int sig)
{
	sigset_t mask, prev_mask;
	if(sigfillset(&mask) < 0)
	{
		perror("sigfillset error");
		exit(0);
	}
	if(sigprocmask(SIG_BLOCK, &mask, &prev_mask) < 0)
	{
		perror("sigpromask error");
		exit(0);
	}
	printf("SIGINT recived\n");
	siginted = true;
	sigprocmask(SIG_SETMASK, &mask, NULL);
}

int main(void)
{
	signal(SIGINT, handler);
	int count = 0;
	while(1)
	{
		printf(".");
		fflush(stdout);
		if(count++ > 2)
		{
			printf("\r    \r");
			count = 0;
		}
		struct timespec pram, ram;
		pram.tv_sec = 1; 
		pram.tv_nsec = 0;
		nanosleep(&pram, &ram);
		if(siginted)
		{
			printf("\nremains %lds, %ldms\n", ram.tv_sec, ram.tv_nsec/1000);
			exit(0);
		}
	}
}
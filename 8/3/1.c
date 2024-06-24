#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int sig)
{
	printf("caugnt sigint!\n");
	exit(0);
}

int main(void)
{
	signal(SIGINT, sigint_handler);
	pause();
}

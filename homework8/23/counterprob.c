#include <unistd.h>
#include <signal.h>
#include <errwrap.h>
#include <stdlib.h>

int counter = 0;

void handler(int sig)
{
	counter++;
	sleep(1);
	return;
}

int main(void)
{
	int i;
	Signal(SIGUSR2, handler);

	if (Fork() == 0)	//child
	{
		for(i = 0; i < 5; i++)
		{
			Kill(getppid(), SIGUSR2);
			printf("sent SIGUSR2 to parent\n");
		}
		exit(0);
	}

	Wait(NULL);
	printf("counter=%d\n", counter);
	exit(0);
}
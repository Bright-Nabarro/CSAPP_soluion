#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <errwrap.h>

#define N 2
#define LEN 100

void handler(int sig)
{
	exit(SIGSEGV);
}

int main(void)
{
	int status, i;
	pid_t pid;

//	Signal(SIGSEGV, handler);

	for(i = 0; i < N; i++)
	{
		if((pid = Fork()) == 0) /* Child */
		{
			int* p = NULL;
			*p = 1;
			exit(100+i);
		}
	}

	while((pid = waitpid(-1, &status, 0)) > 0)
	{
		if(WIFEXITED(status))
			printf("child %d terminated normally with exit status=%d\n", pid,
					WEXITSTATUS(status));
		else if(WIFSIGNALED(status))
		{
			char msg[LEN];
			sprintf(msg, "child %d terminated by signal 11:", pid);
			psignal(WTERMSIG(status), msg);
		}
		else
		{
			printf("child %d terminated abnormally\n", pid);
		}
	}

	if (errno != ECHILD)
		unix_error("waitpid error");
	
	exit(0);
}
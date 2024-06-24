#include <stdlib.h>
#include <errwrap.h>
#include <signal.h>
#include <setjmp.h>

sigjmp_buf env;

void handle(int sig)
{
	siglongjmp(env, 1);
}

char* tfgets(char* str, int n, FILE* stream)
{
	Signal(SIGALRM, handle);

	if(!sigsetjmp(env, 1))
	{
		alarm(5);
		return fgets(str, n, stream);
	}
	else
		return NULL;
}
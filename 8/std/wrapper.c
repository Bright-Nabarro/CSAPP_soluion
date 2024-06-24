#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "wrapper.h"

void unix_error(char* msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
}

char* Fgets(char* str, int n, FILE* stream)
{
	char* ret;
	ret = fgets(str, n, stream);

	if(ret == NULL)
	{
		if(feof(stdin))
			fprintf(stderr, "End of file reached unexpectedly.\n");
		else
			perror("Error reading from file");

		exit(EXIT_FAILURE);
	}

	return ret;
}

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

void Execve(const char* path, char* const argv[], char* const envp[])
{
	if(execve(path, argv, envp) < 0)
	{
		unix_error("Execve error");
	}
}
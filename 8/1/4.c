#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char* binaryPath = "/bin/ls";
	char* args[] = {"ls", "-l", NULL};
	char* env[] = {NULL};
	if(execve(binaryPath, args, env) == -1)
	{
		perror("execve");
		return -1;
	}
}
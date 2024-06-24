#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
	if(execve("/usr/bin/ls", argv, envp) == -1)
		perror("execve");
}

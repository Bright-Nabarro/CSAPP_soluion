#include <unistd.h>
#include <stdio.h>

extern char** environ;

int main(int argc, char* argv[], char* envp[])
{
	char** env1 = environ;
	char* exe_argv[4];
	exe_argv[0] = "sh";
	exe_argv[1] = "-c";
	exe_argv[2] = "pwd";
	exe_argv[3] = NULL;
	execve("/bin/sh", exe_argv, environ);
}
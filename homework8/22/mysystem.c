#include <errwrap.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 8192
#define MAXARGS 128

int mysystem(char* command);
void parse_command(char* command, char* argv[]);
extern char** environ;

int main(void)
{
	char command[MAXLINE];
	while(Fgets(command, MAXLINE, stdin) != NULL)
	{
		int ret_val = mysystem(command);
		if(ret_val)
		{
			printf("Error %d, \n", ret_val, WEXITSTATUS(ret_val));
		}
	}
}

int mysystem(char* command)
{
	int stat_loc;
	char* argv[MAXARGS];
	argv[0] = "sh";
	argv[1] = "-c";
	parse_command(command, argv);
	pid_t cpid;
	if((cpid = Fork()) == 0)
	{
		Execve("/bin/sh", argv, environ);
	}
	else
	{
		Waitpid(cpid, &stat_loc, 0);
	}
	return stat_loc;
}

void parse_command(char* command, char* argv[])
{
	char* p;
	command[strlen(command) - 1] = ' ';
	char* prev = command;
	int counter = 2;
	char* limit = command + strlen(command) - 1;
	for(p = command; *p != '\0' && p != limit; p++)
	{
		if(isspace(*p))
		{
			*p = '\0';
			argv[counter++] = prev;
			prev = p+1;
		}
	}
	*p = '\0';
	argv[counter++] = prev;
	prev = p+1;

	argv[counter] = NULL;
}
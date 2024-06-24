#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errwrap.h>
#define MAXARGS 128
#define MAXLINE 8192

void eval(char* cmdline, char* env[]);
int parseline(char* buf, char* argv[]);
int builtin_command(char* argv[]);

int main(int argc, char* argv[], char* env[])
{
	char cmdline[MAXLINE];

	while(1)
	{
		printf("> ");
		fflush(stdin);
		Fgets(cmdline, MAXLINE, stdin);
		eval(cmdline, env);
	}
}

void eval(char* cmdline, char* env[])
{
	char* argv[MAXARGS];	//Argument list execve()
	char buf[MAXLINE];		//holds modified command line
	int bg;					//if the job run in background(bg == 1)
	pid_t pid;				//process id

	strcpy(buf, cmdline);
	bg = parseline(buf, argv);
	if(!builtin_command(argv))
	{
		if((pid = Fork()) == 0)
		{
			Execve(argv[0], argv, env);
		}

		if (!bg)
		{
			int status;
			Waitpid(pid, &status, 0);
		}
		else
			printf("%d %s", pid, cmdline);
	}
}

int builtin_command(char* argv[])
{
	if(!strcmp(argv[0], "quit"))
		exit(0);
	if(!strcmp(argv[0], "&"))
		return 1;
	return 0;
}

int parseline(char* buf, char* argv[])
{
	char* delim;
	int argc;
	int bg;

	buf[strlen(buf)-1] = ' ';
	while(*buf && (*buf == ' '))
		buf++;

	argc = 0;
	while((delim = strchr(buf, ' ')))
	{
		argv[argc++] = buf;
		*delim = '\0';
		buf = delim + 1;
		while (*buf && (*buf == ' '))
			buf++;
	}

	return bg;
}

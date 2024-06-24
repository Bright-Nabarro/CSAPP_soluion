#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>
#include "xshell.h"

#ifndef TEST
static 
#endif 
int parseline(char* buf, char* argv[]);
static int builtin_command(char* argv[]);
static void parsePath(char* args, char* dest);
static int parseGround(char* argv[]);
static int findMinJob();

size_t tableCounter = 0;
IDs g_idTable[MAXJOBS];
IDs g_fgJob;

void initial(void)
{
	for(int i = 0; i < MAXJOBS; i++)
	{
		g_idTable[i].pid = 0;
		g_idTable[i].job = 0;
		g_idTable[i].path[0] = '\0';
		g_idTable[i].status = IDs_UNKOWN;
	}
}

void eval(char* cmdline)
{
	char* argv[MAXARGS];
	int bg = parseline(cmdline, argv);
	if (strcmp(argv[0], "") == 0)
		return;

	int bfgJob;
	int status;
	IDs* prog = NULL;
	switch (builtin_command(argv))
	{
	case 0:
		break;
	case 1:		//exit
		exit(0);
	case 2:		//jobs
		print_bgJobs();
		return;
	case 3: 	//bg
		bfgJob = parseGround(argv);
		if(!deal_ground(bfgJob, &prog))
		{
			fprintf(stderr, "bg: %s: no such job\n", argv[1]);
			return;
		}
		prog->status = IDs_RUNNING;
		return;
	case 4: 	//fg
		bfgJob = parseGround(argv);
		if(!deal_ground(bfgJob, &prog))
		{
			fprintf(stderr, "fg: %s: no such job\n", argv[1]);
			return;
		}
		remove_bgJob(prog->pid);
		if(waitpid(prog->pid, &status, 0) < 0)
		{
			perror("waitpid");
			exit(103);
		}
		deal_status(status);

		return;
	default:
		fprintf(stderr, "Unkown BuiltinCommand\n");
		exit(1);
	}
	
	char path[PATHLEN];
	parsePath(argv[0], path);
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(101);
	}

	sigset_t mask, prevMask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGCHLD);
	//阻塞SIGCHLD信号，防止在分配new_job前进行跳转
	if (sigprocmask(SIG_BLOCK, &mask, &prevMask) < 0)
	{
		perror("sigprocmask");
		exit(106);
	}
	if (pid == 0)
	{
		if (execve(path, argv, environ) < 0)
		{
			perror("execve");
			exit(102);
		}
	}
	else if(!bg)
	{
		int status;
		new_fgJob(pid, path);
		//恢复子进程信号
		if(sigprocmask(SIG_SETMASK, &prevMask, NULL) < 0)
		{
			perror("sigprocmask");
			exit(106);
		}
		if(waitpid(pid, &status, 0) < 0)
		{
			perror("waitpid");
			exit(103);
		}
		deal_status(status);
	}
	else
	{
		clear_fgJob();
		IDs* prog = new_bgJob(pid, path);
		//恢复子进程信号
		if(sigprocmask(SIG_SETMASK, &prevMask, NULL) < 0)
		{
			perror("sigprocmask");
			exit(106);
		}
		if(prog == NULL)
		{
			fprintf (stderr, "Job full\n");
			exit(110);
		}
		printf("[%d]\t%d\n", prog->job, prog->pid);
	}
	
}

void deal_status(int status)
{
	if(WIFEXITED(status))			//使用正常手段退出
	{
		if(WEXITSTATUS(status) != 0)
		{
			printf("Error[%d]\n", WEXITSTATUS(status));
		}
	}
	else if(WIFSIGNALED(status))	//由信号中断
	{
		printf("%s\n", strsignal(status));
	}
	else
	{
		printf("Unkown error\n");
		exit(104);
	}
}

#ifndef TEST
static 
#endif
int parseline(char* buf, char* argv[])
{
	int counter = 0;
	char* argc = buf;
	int limit = MAXARGS-2;
	for(char* pch = buf; *pch != '\0'; pch++)
	{
		if(isspace(*pch))
		{
			*pch = '\0';
			argv[counter++] = argc;
			if (counter >= limit)
			{
				*pch = '\0';
				break;
			}

			argc = pch+1;

			while(*(pch+1) != '\0' && isspace(*(pch+1)))
			{
				pch++;
				argc++;
			}
		}
	}
	argv[counter] = NULL;

	if (counter > 0 && strcmp(argv[counter-1], "&") == 0)
	{
		argv[counter-1] = NULL;
		return 1;
	}

	return 0;
}

// 内部函数 start ============================================

static int builtin_command(char* argv[])
{
	if(strcmp(argv[0], "exit") == 0)
		return 1;	

	if(strcmp(argv[0], "jobs") == 0)
		return 2;

	if(strcmp(argv[0], "bg") == 0)
		return 3;

	if(strcmp(argv[0], "fg") == 0)
		return 4;

	return 0;
}

static int parseGround(char* argv[])
{
	if(argv[1] == NULL)
	{
		return findMinJob();
	}
	
	if(argv[1][0] == '%')
	{
		return atoi(&argv[1][1]);
	}
	return 0;
}

static int findMinJob()
{
	int ret = INT_MAX;
	for(int i = 0; i < MAXJOBS; i++)
	{
		if(g_idTable[i].job == 0)
			continue;
		if(g_idTable[i].job < ret)
			ret = g_idTable[i].job;
	}

	if(ret == INT_MAX)
		return 0;

	return ret;
}

static void parsePath(char* argc, char* dest)
{
	if(argc[0] != '.' && argc[0] != '/')	//usr path
	{
		strcpy(dest, "/bin/");
		strcat(dest, argc);
	}
	else
	{
		strcpy(dest, argc);
	}
}

// 内部函数 end	===========================================

IDs* new_bgJob(pid_t pid, const char* cpath)
{
	for(int i = 0; i < MAXJOBS; i++)
	{
		if(g_idTable[i].job != 0)
			continue;
		
		g_idTable[i].job = ++tableCounter;
		g_idTable[i].pid = pid;
		strcpy(g_idTable[i].path, cpath);
		g_idTable[i].status = IDs_RUNNING;
		
		return &g_idTable[i];
	}
	return NULL;
}

IDs* find_job(pid_t pid)
{
	for(int i = 0; i < MAXJOBS; i++)
	{
		if(g_idTable[i].pid == pid)
			return &g_idTable[i];
	}
	return NULL;
}

IDs* find_pid(int job)
{
	if(job == 0)
		return NULL;
	for(int i = 0; i < MAXJOBS; i++)
	{
		if(g_idTable[i].job == 0)
			continue;
		if(g_idTable[i].job == job)
			return &g_idTable[i];
	}
	return NULL;
}

void print_bgJobs(void)
{
	for(int i = 0; i < MAXJOBS; i++)
	{
		if(g_idTable[i].job == 0)
			continue;
		printf("[%d]%s\t\t%s\n", 
			   g_idTable[i].job,
			   status_str(g_idTable[i].status),
			   g_idTable[i].path
			   );
	}
}

void remove_bgJob(pid_t pid)
{
	for(int i = 0; i < MAXJOBS; i++)
	{
		if(g_idTable[i].pid == pid)
		{
			g_idTable[i].job = 0;
			g_idTable[i].pid = 0;
			break;
		}
	}
}

void clear_jobs(void)
{
	for(int i = 0; i < MAXJOBS; i++)
	{
		if(g_idTable[i].job == 0)
			continue;
		kill(g_idTable[i].pid, SIGINT);
	}
}

void new_fgJob(pid_t pid, char* path)
{
	g_fgJob.status = IDs_RUNNING;
	strcpy(g_fgJob.path, path);
	g_fgJob.pid = pid;
	g_fgJob.job = 1;
}

void clear_fgJob(void)
{
	g_fgJob.status = IDs_UNKOWN;
	g_fgJob.path[0] = '\0';
	g_fgJob.pid = 0;
	g_fgJob.job = 0;
}

char* status_str(int status)
{
	switch(status)
	{
	case IDs_UNKOWN:
		return STR_IDs_UNKOWN;
	case IDs_RUNNING:
		return STR_IDs_RUNNING;
	case IDs_PENDING:
		return STR_IDs_PENDING;
	}
	assert(1);
	return NULL;
}

int deal_ground(int job, IDs** pprog)
{
	if(job == 0)
		return 0;
	
	*pprog = find_pid(job);
	if(*pprog == NULL)
		return 0;

	kill((*pprog)->pid, SIGCONT);
	return 1;
}

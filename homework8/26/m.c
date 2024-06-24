#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <setjmp.h>
#include "xshell.h"

sigjmp_buf env;

void handler_chd(int sig)
{
	sigset_t mask, prevMask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGCHLD);
	if (sigprocmask(SIG_BLOCK, &mask, &prevMask) < 0)
	{
		perror("sigprocmask");
		exit(106);
	}
	int olderrno = errno;
	
	int status;
	pid_t pid;
	while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
	{
		deal_status(status);
		IDs* pJob = find_job(pid);
		if (pJob == NULL)
		{
			fprintf(stderr, "Child pid mismatched\n");
			exit(111);
		}
		printf("[%d] Done\t\t%s\n", pJob->job, pJob->path);
		remove_bgJob(pid);
	}

	errno = olderrno;
	if(sigprocmask(SIG_SETMASK, &prevMask, NULL) < 0)
	{
		perror("sigprocmask");
		exit(106);
	}
}

void handler_quit(int sig)
{
	//阻塞
	sigset_t mask, prevMask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	if (sigprocmask(SIG_BLOCK, &mask, &prevMask) < 0)
	{
		perror("sigprocmask");
		exit(106);
	}
	int olderrno = errno;
	//阻塞

	for(int i = 0; i < MAXJOBS; i++)
	{
		if(g_idTable[i].job == 0)		//empty
			continue;

		kill(g_idTable[i].pid, sig);
	}

	//恢复
	errno = olderrno;
	if(sigprocmask(SIG_SETMASK, &prevMask, NULL) < 0)
	{
		perror("sigprocmask");
		exit(106);
	}
	//恢复
}

void handler_hang(int sig)
{
	//阻塞
	sigset_t mask, prevMask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGTSTP);
	if (sigprocmask(SIG_BLOCK, &mask, &prevMask) < 0)
	{
		perror("sigprocmask");
		exit(106);
	}
	int olderrno = errno;
	//阻塞

	if(g_fgJob.job == 0)
		return;
	IDs* prog = new_bgJob(g_fgJob.pid, g_fgJob.path);
	prog->status = IDs_PENDING;
	if(prog == NULL)
	{
		fprintf (stderr, "Job full\n");
		exit(110);
	}
	kill(g_fgJob.pid, sig);

	//恢复
	errno = olderrno;
	if(sigprocmask(SIG_SETMASK, &prevMask, NULL) < 0)
	{
		perror("sigprocmask");
		exit(106);
	}
	//恢复

	//跳过显示wait部分，在eval之后执行
	siglongjmp(env, 1);
}

int main(void)
{
	char cmdline[MAXLINE];
	//捕获子进程终止信号
	if(signal(SIGCHLD, handler_chd) < 0)
	{
		perror("signal");
		exit(100);
	}
	//捕获中断信号
	if(signal(SIGINT, handler_quit) < 0)
	{
		perror("signal");
		exit(100);
	}
	//捕获挂起信号
	if(signal(SIGTSTP, handler_hang) < 0)
	{
		perror("signal");
		exit(100);
	}

	initial();
	while (1)
	{
		printf("xshell> ");
		if (fgets(cmdline, MAXLINE, stdin) != NULL)
		{
			switch(sigsetjmp(env, 1))
			{
			case 0:		//正常执行
				eval(cmdline);
				break;;
			case 1:		//函数挂起
				printf("\n\n[%d]\tStopped\t\t%s\n", g_fgJob.job, g_fgJob.path);
				clear_fgJob();
				break;
			default:
				fprintf(stderr, "Unkown jmp value\t");
				exit(1);
			}
		}
		else
		{
			if (feof(stdin))
			{
				puts("");
				return 0;
			}
			else
			{
				perror("fgets");
				return 1;
			}
		}
	}
}
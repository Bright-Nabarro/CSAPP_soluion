#ifndef __XSHELL_H__
#define __XSHELL_H__
#include <unistd.h>

#define MAXARGS 128
#define MAXLINE 8192
#define MAXJOBS 16
#define PATHLEN 64

#define STR_IDs_UNKOWN "\t\tUnkown"
#define STR_IDs_RUNNING "\t\tRunning"
#define STR_IDs_PENDING "\t\tStopped"

extern char** environ;

typedef struct
{
	enum {IDs_UNKOWN, IDs_RUNNING, IDs_PENDING} status;
	char path[PATHLEN];
	pid_t pid;
	int job;
} IDs;

extern IDs g_idTable[MAXJOBS];
extern IDs g_fgJob;
extern size_t tableCounter;

void initial(void);
void eval(char* cmdline);
void deal_status(int status);
IDs* new_bgJob(pid_t pid, const char* cpath);
IDs* find_job(pid_t pid);
IDs* find_pid(int job);
void remove_bgJob(pid_t pid);
void clear_jobs(void);
void new_fgJob(pid_t pid, char* path);
void clear_fgJob(void);
char* status_str(int status);

void print_bgJobs(void);
int deal_ground(int job, IDs** pprog);

#ifdef TEST
void parseline(char* buf, char* argv[]);
#endif

#endif
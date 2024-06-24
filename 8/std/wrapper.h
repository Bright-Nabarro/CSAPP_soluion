#ifndef __WRAPPER_H__
#define __WRAPPER_H__

#include <stdio.h>
#include <stdlib.h>

void unix_error(char* msg);

char* Fgets(char* str, int n, FILE* stream);
pid_t Fork(void);

void Execve(const char* path, char* const argv[], char* const envp[]);

#endif
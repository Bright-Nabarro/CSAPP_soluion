#include <stdio.h>
#define BUF_SIZE 100

typedef enum { OK = 0, ERR = 1} STATUS;

STATUS good_echo(void)
{
    char buf[BUF_SIZE];
    char* gets_ret = fgets(buf, BUF_SIZE, stdin);
    if(gets_ret == buf)
    {
        puts(buf);
        return OK;
    }
    else
        return ERR;
}

int main(void)
{
    return good_echo();
}
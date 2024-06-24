#include "../../csapp.h"

int main(int argc, char* argv[])
{
	int n;
	rio_t rio; // read buffer
	char buf[MAXBUF];

	Rio_readinitb(&rio, STDIN_FILENO);
	while ((n = Rio_readlineb(&rio, buf, MAXBUF)))
		Rio_writen(STDOUT_FILENO, buf, n);
}
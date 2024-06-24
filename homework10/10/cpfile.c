#include "../../csapp.h"
#include <unistd.h>

int main(int argc, char* argv[])
{
	int n;
	rio_t rio; // read buffer
	char buf[MAXBUF];

	if (argc > 1)
	{
		int fd = Open(argv[1], O_RDONLY, S_IRUSR);
		Dup2(fd, STDIN_FILENO);
	}

	Rio_readinitb(&rio, STDIN_FILENO);
	while ((n = Rio_readlineb(&rio, buf, MAXBUF)))
		Rio_writen(STDOUT_FILENO, buf, n);
}
#include "../../csapp.h"

int main(int argc, char** argv)
{
	struct stat stat;
	char *type, *readok;
	if (argc < 2)
		return 1;
	int fd = atoi(argv[1]);
	Fstat(fd, &stat);
	if (S_ISREG(stat.st_mode))
		type = "regular";
	else if (S_ISDIR(stat.st_mode))
		type = "directory";
	else
		type = "other";

	if ((stat.st_mode & S_IRUSR))
		readok = "true";
	else
		readok = "false";

	printf("type: %s, rand: %s\n", type, readok);
	exit(0);
}
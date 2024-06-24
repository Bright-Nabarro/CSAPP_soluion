#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("e.txt", O_RDWR);
	struct stat sb;

	char* map = mmap(NULL, sb.st_size)
}
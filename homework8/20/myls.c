#include <unistd.h>
#include <errwrap.h>

int main(int argc, char* argv[], char* envp[])
{
	Execve("/bin/ls", argv, envp);
}
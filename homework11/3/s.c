#include "../../csapp.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
		return 1;
	struct in_addr ipBin;

	Inet_pton(AF_INET, argv[1], &ipBin.s_addr);
	uint32_t hostlong = ntohl(ipBin.s_addr);
	printf("0x%x\n", hostlong);
}
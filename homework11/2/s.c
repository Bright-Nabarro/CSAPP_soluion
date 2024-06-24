#include "../../csapp.h"
#include <netinet/in.h>

int main(int argc, char* argv[])
{
	if (argc < 2)
		return 1;
	struct in_addr ipBin;
	long hostlong;
	hostlong = strtol(argv[1], NULL, 16);
	ipBin.s_addr = htonl(hostlong);
	char ipStr[INET_ADDRSTRLEN];
	Inet_ntop(AF_INET, &ipBin, ipStr, INET_ADDRSTRLEN);
	puts(ipStr);
}
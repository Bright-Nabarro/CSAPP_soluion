#include "tfgets.h"
#define SCALE 100

int main()
{
	char buf[SCALE];
	if(tfgets(buf, sizeof(buf), stdin) != NULL)
	{
		printf("get it\n");
		printf("%s\n", buf);
	}
	else
	{
		printf("5 seconds passed\n");
	}
}
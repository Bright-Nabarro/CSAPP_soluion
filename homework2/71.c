#include<stdio.h>
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
	//bytenum为提取的第n位, 0<=n<=3
	//assum int === 32
	//>=<><=
	int l = (bytenum << 3);
	return (int)word << (24-l) >> 24;
}

int main(void)
{
	packed_t word;
	int bytenum;
	scanf("%x %d", &word, &bytenum);
	printf("%.8x\n", xbyte(word, bytenum));
	return 0;
}

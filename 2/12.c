#include<stdio.h>

int main(void)
{
	int x = 0x87654321;
	int answerA = x&0xFF;
	printf("%.8X\n", answerA);

	int answerB = x ^ ~0xFF;
	printf("%.8X\n", answerB);

	int answerC = x;
	answerC |= 0xFF;
	printf("%.8X\n", answerC);

	return 0;
}

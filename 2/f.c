#include<stdio.h>
union checkF
{
	float f;
	unsigned int i;
};

void printB(unsigned int n)
{
	for(int i=0; i<4; i++)
	{
		printf("%.2X ", n & 0xff);
		n >>= 8;
	}
	printf("\n");
}

void print_hex(unsigned int value) {
    unsigned char* byte = (unsigned char*)&value;
    for(int i = sizeof(value) - 1; i >= 0; --i) {
        printf("%02X", byte[i]);
        printf(" ");
    }
    printf("\n");
}

int main(void)
{
	union checkF flt;
	flt.i = 0x00000000;
	float fl = flt.f;
	if(fl == 0.0)
		printf("true 0\n");
	printf("%f\n", flt.f);
	//printB(flt.i);
	print_hex(flt.i);
}

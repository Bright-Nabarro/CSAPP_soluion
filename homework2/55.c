#include"show_bytes.h"

int main()
{
	int i = 42;
	double d = 42;
	float f = 42;
	show_bytes(&i, sizeof(int));
	show_bytes(&d, sizeof(double));
	show_bytes(&f, sizeof(float));
}

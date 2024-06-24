#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "opt.h"

double poly_row(double a[], double x, long degree)
{
	long i;
	double result = a[0];
	double xpwr = x;		//equals x**i at start of loop
	for(i = 1; i <= degree; i++)
	{
		result = result + a[i] * xpwr;
		xpwr = x * xpwr;
	}
	return result;
}

double poly_h_row(double a[], double x, long degree)
{
	long i;
	double result = a[degree];
	for(i = degree-1; i >= 0; i--)
	{
		result = a[i] + x*result;
	}
	return result;
}

#define SCALE	5000000
#define DEGREE	250	
#define FACTOR	100000
#define X		13

void test_cost(double a[])
{
	double p1;
	double p2;
	double p3 = 0;
	double p4 = 0;
	for(size_t s = 0; s < SCALE; s++)
	{
		for(size_t i = 0; i <= DEGREE; i++)
		{
			a[i] = rand() % FACTOR;
		}
		p4 = poly_opt2(a, X, DEGREE);
		p3 = poly_opt1(a, X, DEGREE);	
		p2 = poly_h_row(a, X, DEGREE);
		p1 = poly_row(a, X, DEGREE);
	}
	printf("%e\n%e\n%e\n", p1, p2, p3);
}

int main(void)
{
	srand(time(NULL));
	double a[DEGREE+1];
	test_cost(a);

	return 0;
}
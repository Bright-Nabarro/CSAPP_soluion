#include <stdio.h>
#include "opt.h"

//#define TEST

double poly_opt1(double a[], double x, long degree)
{
	//for 3 loop unrolling
	long i;
	double x_3 = x*x*x;
	double result1 = a[0];
	double xpwr1 = x;

	double result2 = 0;
	double xpwr2 = x*x;

	double result3 = 0;
	double xpwr3 = x_3;

	long limit = degree - 2;
	for(i = 1; i <= limit; i+=3)
	{
		result1 = result1 + a[i] * xpwr1;
		result2 = result2 + a[i+1] * xpwr2;
		result3 = result3 + a[i+2] * xpwr3;

		xpwr1 = x_3 * xpwr1;
		xpwr2 = x_3 * xpwr2;
		xpwr3 = x_3 * xpwr3;
	}
	double result = result1 + result2 + result3;

	for(; i <= degree; i++)
	{
		result = result + a[i] * xpwr1;
	}
	return result;
}

double poly_opt2(double a[], double x, long degree)
{
	//for 3 loop unrolling
	long i;
	double x_6 = x*x*x*x*x*x;
	double result1 = a[0];
	double xpwr1 = x;

	double result2 = 0;
	double xpwr2 = x*x;

	double result3 = 0;
	double xpwr3 = x*x*x;

	double result4 = 0;
	double xpwr4 = x*x*x*x;

	double result5 = 0;
	double xpwr5 = x*x*x*x*x;

	double result6 = 0;
	double xpwr6 = x_6;

	long limit = degree - 5;
	for(i = 1; i <= limit; i+=6)
	{
		result1 = result1 + a[i] * xpwr1;
		result2 = result2 + a[i+1] * xpwr2;
		result3 = result3 + a[i+2] * xpwr3;
		result4 = result4 + a[i+3] * xpwr4;
		result5 = result5 + a[i+4] * xpwr5;
		result6 = result6 + a[i+5] * xpwr6;

		xpwr1 = x_6 * xpwr1;
		xpwr2 = x_6 * xpwr2;
		xpwr3 = x_6 * xpwr3;
		xpwr4 = x_6 * xpwr4;
		xpwr5 = x_6 * xpwr5;
		xpwr6 = x_6 * xpwr6;
	}
	double result = result1 + result2 + result3;

	for(; i <= degree; i++)
	{
		result = result + a[i] * xpwr1;
	}
	return result;
}

#ifdef TEST

int main(void)
{
	double a[] = {1., 2., 3.};
	double result = poly_opt1(a, 1, 1);
	printf("%lf\n", result);
}

#endif
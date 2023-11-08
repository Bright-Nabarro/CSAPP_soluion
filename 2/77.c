#include <assert.h>
#include <stdio.h>

int A(int x)
{ // K=17
	int result = (x << 4) + x;
	return result;
}

int B(int x)
{ // K = -7
	int result = (x << 3) - x;
	return -result;
}

int C(int x)
{ // K = 60
	int result = (x << 6) - (x << 2);
	return result;
}

int D(int x)
{ // K = -112
	int result = (x << 7) - (x << 4);
	return -result;
}

int main()
{
	int x;
	scanf("%d", &x);
	assert(A(x) == 17 * x);
	assert(B(x) == -7 * x);
	assert(C(x) == 60 * x);
	assert(D(x) == -112 * x);
}
#include <endian.h>
#include <stdio.h>

int func(int mants[], int mant, int manti)
{
	int fl = 1;
	int size = 0;
	for (int i = 0; i < mant; i++, fl++)
	{
		if ((manti & 1) == 1)
			mants[size++] = fl;
	}
}

int main(void)
{
	int exp, mant;
	scanf("%d %d", &exp, &mant);
	int mants[mant];
	//默认符号位为0, 负数与正数对称
	// exp的边界位inf或nan
	int bias = (2 << (exp - 1)) - 1;
	for (int expi = 0; expi < (2 << (exp + 1)) - 1; expi++)
	{
		int index;
		if (expi == 0)
			index = 1 - bias;
		else
			index = (2 << expi) - bias;
		for (int manti = 0; manti <= (2 << (mant + 1)) - 1; manti++)
		{
			int size = func(mants, mant, manti);
			index -= mants[i - 1];
			for (int i = size - 1; i >= 0; i--)
			{
			}
		}
	}
}
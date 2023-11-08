#include <bitset>
#include <iostream>

int A(int k)
{
	return -1 << k;
}

int B(int k, int j)
{
	int n1 = -1 << j;
	int mask = ~(-1 << k << j);
	return n1 & mask;
}

int main()
{
	int k, j;
	std::cin >> k >> j;

	std::bitset<sizeof(int) * 8> bsA(A(k));
	std::bitset<sizeof(int) * 8> bsB(B(k, j));
	for (int i = sizeof(int) * 8; i >= 1; i--)
		std::cout << i % 10;
	std::cout << std::endl;
	std::cout << bsA.to_string() << std::endl;
	std::cout << bsB.to_string() << std::endl;
}
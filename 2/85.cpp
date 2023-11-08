#include <bitset>
#include <iostream>

union f_u
{
	float f;
	unsigned u;
};

int main()
{
	float Af, Bf, Cf;
	Af = 7.0;
	f_u A;
	A.f = Af;
	std::bitset<32> Abit(A.u);
	std::cout << Abit.to_string() << std::endl;
	f_u B;
	B.u = 0x7F7FFFFF;
	std::cout << B.f << std::endl;
	f_u C;
	C.u = 0x00000001;
	std::cout << C.f << ' ' << 1.0 / C.f << std::endl;
}
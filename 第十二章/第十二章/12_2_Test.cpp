#include "12_2.h"
#include <iostream>

int main()
{
	const Strblob csb{ "hello", "world", "pezy" };
	Strblob sb{ "hello", "world", "Mooophy" };

	std::cout << csb.front() << " " << csb.back() << std::endl;
	sb.back() = "pezy";
	std::cout << sb.front() << " " << sb.back() << std::endl;
	system("pause");
	return 0;
}
#include "Sales_data.h"
#include <iostream>

int main()
{
	Sales_data s1(std::cin);
	std::cout << s1 << std::endl;
	Sales_data s2("Cpp-Primer-5th", 2, 128.0);
	Sales_data s3("Cpp-Primer-5th", 1, 128.0);
	std::cout << s2 + s3 << std::endl;

	system("pause");
	return 0;
}
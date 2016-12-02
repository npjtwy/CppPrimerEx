#include "iostream"
#include <string>
#include "7_57_Account.h"

void main()
{
	Account a1("Wang");
	
	a1.initamount(std::cin, a1);	
	a1.calculate();
	std::cout << "³õÊ¼ÀûÂÊ£º " << a1.balance() << std::endl;

	a1.rate(0.035);
	a1.initamount(std::cin, a1);
	a1.calculate();
	std::cout << a1.balance() << std::endl;

	Account a2("Yang", 999);
	std::cout << a2.rate() << std::endl;

	a2.calculate();
	std::cout << a2.balance() << std::endl;

	system("pause");
}
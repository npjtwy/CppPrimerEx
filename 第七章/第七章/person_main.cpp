#include "iostream"
#include <string>
#include "Person.h"

using  namespace std;

void main()
{
	Person p1("Tom","xiaoyuanroad-999");
	
	print(std::cout, p1);
	std::cout << endl;

	system("pause");
}
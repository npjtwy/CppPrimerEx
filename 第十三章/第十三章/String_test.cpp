#include "String.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	String s("hello");
	cout << *s.begin() << endl;
	for (auto i : s)
	{
		cout << i  ;
	}
	

	String s1("world");
	s1 = s;
	for (auto i : s1)
	{
		cout << i  ;
	}
	

	String s2(s);
	for (auto i : s2)
	{ 
		cout << i  ;
	}
	

	String s3 = std::move(s1);
	for (auto i : s3)
	{
		cout << i  ;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}
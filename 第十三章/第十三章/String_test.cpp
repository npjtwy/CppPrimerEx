#include "String.h"
#include <iostream>
using namespace std;
int main()
{
	String s("hello");
	cout << *s.begin() << endl;
	for (auto i : s)
	{
		cout << i << " ";
	}
	cout << endl;

	String s1("world");
	s1 = s;
	for (auto i : s1)
	{
		cout << i << " ";
	}
	cout << endl;

	String s2(s);
	for (auto i : s2)
	{
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
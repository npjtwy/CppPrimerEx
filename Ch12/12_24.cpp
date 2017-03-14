#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
#include <memory>
using  namespace std;
namespace Classfoo
{
	void Ex12_24()
	{
		string str;
		while (cin >> str);
		int sz = str.size();
		char *p = new char [sz + 1];	
		char *q = p;
		for (auto it = str.begin(); it != str.end(); ++q, ++it)
		{
			*q = *it;
		}
		*q = '\0';
		cout << p << endl;
		delete []p;
		/*
		char *str = new char[strcmp.size()]();
		char *p = str;
		for(auto it = strcmp.begin(); it != strcmp.end(); ++p, ++it )
		{
			*p = *it;
		}
		cout << str << endl;
		delete []str;
	*/

	}

}
void Ex12_23_2()
{
	string str1 = "hello";
	string str2 = "world";
	string strcmp = str1 + str2;
	/*
	用 new 分配的内存并不是一个数组类型 所以不能将用于数组类型的方法用于 new 分配的内存！！！
	*/

	char *str = new char[strcmp.size() + 1]();
	char *p = str;
	for (auto it = strcmp.begin(); it != strcmp.end(); ++p, ++it)
	{
		*p = *it;
	}
	*p = '\0';
	cout << str << endl;
	delete[]str;

}

int main()
{
	Ex12_23_2();
	Classfoo::Ex12_24();
	
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <deque>
#include <list>
#include <vector>
using  namespace std;
//打印函数
template<typename T>
void PrintFunc(const T &t)
{
	for (auto i : t)
	{
		cout << i << " ";
	}
}
//9_18 向deque中存入string 并打印
void Prgm9_18()
{
	deque<string> d_str;
	string str;
	while (cin >> str)
	{
		d_str.push_back(str);
	}
	//打印
	PrintFunc(d_str);
	cout << endl;
}
//9_19 用list代替deque
void Prgm9_19()
{
	list<string> l_str;
	string str;
	while (cin >> str)
	{
		l_str.push_back(str);
	}
	//打印
	PrintFunc(l_str);
	cout << endl;
}

int main()
{
	Prgm9_19();
	
	system("pause");
	return 0;
}
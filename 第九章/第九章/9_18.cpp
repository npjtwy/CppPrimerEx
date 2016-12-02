#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <deque>
#include <list>
#include <vector>
using  namespace std;
//��ӡ����
template<typename T>
void PrintFunc(const T &t)
{
	for (auto i : t)
	{
		cout << i << " ";
	}
}
//9_18 ��deque�д���string ����ӡ
void Prgm9_18()
{
	deque<string> d_str;
	string str;
	while (cin >> str)
	{
		d_str.push_back(str);
	}
	//��ӡ
	PrintFunc(d_str);
	cout << endl;
}
//9_19 ��list����deque
void Prgm9_19()
{
	list<string> l_str;
	string str;
	while (cin >> str)
	{
		l_str.push_back(str);
	}
	//��ӡ
	PrintFunc(l_str);
	cout << endl;
}

int main()
{
	Prgm9_19();
	
	system("pause");
	return 0;
}
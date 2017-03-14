#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <deque>
#include <list>
using  namespace std;

template<typename T>
void PrintFunc(const T &t)
{
	for (auto i : t)
	{
		cout << i << " ";
	}
}

void Exc9_20()
{
	deque<int> lst;
	int n;
	while (cin >> n)
	{
		lst.push_back(n);
	}
	//¥Ú”°
	PrintFunc(lst);
	cout << endl;

	deque<int> odd_dque, eve_dque;
	for (auto &i : lst)
	{
		if (i%2 == 0)
		{
			eve_dque.push_back(i);
		}
		else odd_dque.push_back(i);
	}

	PrintFunc(odd_dque);
	cout << endl;
	PrintFunc(eve_dque);
	cout << endl;

}



int main()
{
	Exc9_20();
	
	system("pause");
	return 0;
}
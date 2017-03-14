#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <forward_list>
#include <list>
#include <vector>
using  namespace std;
template<typename T>
void PrintFunc(const T &t)
{
	for (auto i : t)
	{
		cout << i << " ";
	}
}
int main()
{
	forward_list<int> iflist = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto pre = iflist.before_begin();
	auto curr = iflist.begin();
	while (curr != iflist.end())
	{
		if (*curr % 2)
		{
			iflist.insert_after(pre, *curr);
			pre = curr;
			++curr;
		}
		else
		{
			curr = iflist.erase_after(pre);
		}
	}
	PrintFunc(iflist);
	cout << endl;

	system("pause");
	return 0;
}
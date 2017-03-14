#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <forward_list>
using  namespace std;
template<typename T>
void PrintFunc(const T &t)
{
	for (auto i : t)
	{
		cout << i << " ";
	}
}
//9_27 ���Ҳ�ɾ��forward_list<int>�е�����Ԫ��
void Exc9_27()
{
	forward_list<int> flist = { 1, 4, 3, 7, 9, 45, 56, 23, 66 };
	PrintFunc(flist);
	cout << endl;
	auto pre = flist.before_begin();
	auto curr = flist.begin();

	while (curr != flist.end())
	{
		if (*curr % 2 != 0)
		{
			curr = flist.erase_after(pre);
		}
		else
		{
			pre = curr;
			++curr;
		}
	}
	PrintFunc(flist);
	cout << endl;
}
//9_28 ��д���� ������������ forward_list������string �������в��ҵ�һ��string�����ڶ���string�������λ�ã�����һ��
//stringû�ڣ��򽫵ڶ���string���뵽����ĩβ
void Exc9_28(forward_list<string> &fl_str, const string first_str, const string second_str)
{
	auto pre = fl_str.before_begin();
	auto curr = fl_str.begin();
	int flag = 0;

	while (curr != fl_str.end())
	{
		if (*curr == first_str)
		{
			curr = fl_str.insert_after(curr, second_str);
			flag = 1;
		}
		else
		{
			pre = curr;
			++curr;
		}
	}
	if (flag == 0)
	{
		fl_str.insert_after(pre, second_str);
	}
}

int main()
{
	forward_list<string> fl_str = {"hello", "haha", "nima", "adad", "hello", "string"};
	string first = "aaa";
	string second = "world";
	Exc9_28(fl_str, first, second);
	PrintFunc(fl_str);
	cout << endl;
	system("pause");
	return 0;
}
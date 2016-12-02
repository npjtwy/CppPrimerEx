#include "iostream"
#include <string>

using  namespace std;
//读取单词，当出现两个连续出现的单词跳出循环，并输出出现两次的单词或者说明没有连续的单词出现
void main()
{
	string str;
	string perstr = "\0";
	int cnt = 0;
	
	while (cin >> str)
	{
		if (str == perstr)
		{
			cnt = 1;
			cout << perstr << endl;
			break;
		}
		perstr = str;
	}

	if (!cnt)
	{
		cout << "没有连续出现的单词" << endl;
	}

	system("pause");
}
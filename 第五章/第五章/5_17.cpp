#include "iostream"
#include <string>
#include <vector>
using  namespace std;
//检验两个vector对象中的一个是否是另一个的前缀
void main()
{
	vector<int> v1 = { 0, 1, 2, 1, 5, 6, 8, 9, 7 };
	vector<int> v2 = { 0, 1, 2, 1 };
	vector<int> &v_short = (v1.size() < v2.size()) ? v1 : v2; 
	vector<int> &v_long = (v2.size() < v1.size()) ? v1 : v2;
	string flag;
	auto & i = v_short.begin();
	auto & j = v_long.begin();

	while (i != v_short.end())
	{
		if (*i != *j)
			break;
		++i; ++j;
	}

	if (i == v_short.end())
	{
		flag = "true";
	}
	else
	{
		flag = "false";
	}

	cout << flag << endl;
	system("pause");
}
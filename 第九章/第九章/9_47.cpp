#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
using  namespace std;
//查找“ab2c3d7R4E6”中的每个柱子字符  然后查找每个字母字符
void ex9_47()
{
	string str = "ab2c3d7R4E6";
	string numbers = "1234567890";
	string::size_type pos = 0;
	while ((pos = str.find_first_not_of(numbers, pos)) != string::npos)
	{
		cout << str[pos] << " ";
		++pos;
	}
	cout << endl;
}


int main()
{
	ex9_47();
	
	system("pause");
	return 0;
}
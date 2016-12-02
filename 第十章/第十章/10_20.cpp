#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <algorithm>
#include <vector>
using  namespace std;
/*
	Ex10_20 统计 vector 中长度大于5 的 string 个数
*/

void Ex10_20(vector<string> &words, string::size_type sz)
{
	int cnt = count_if(words.begin(), words.end(), [=](const string &s){return s.size() > sz; });
	cout << cnt << endl;
}
int main()
{
	vector<string> words = { "hello", "string", "the", "if", "else", "void", "vector", "algorithm" };

	Ex10_20(words, 5);
	
	system("pause");
	return 0;
}
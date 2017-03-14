/*
	Ex10_13
	partition 算法 接受一个谓词 对容器的内容进行划分 使谓词为true的在前半部分 谓词为false的在后半部分
	返回一个指向最后一个使谓词为true的元素之后的迭代器 
	编写函数 接受一个 string 返回 bool 值，指出string是否有5个或者更多的字符， 使用此函数划分 words  打印长度大于5的元素
*/

#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
#include <algorithm>
using  namespace std;
bool isLonger(const string &str)
{
	return str.size() < 5 ? false : true;
}
void sortWords(vector<string> &svec)
{
	auto it = partition(svec.begin(), svec.end(), isLonger);
	for (auto i = svec.begin(); i != it; ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
}
int main()
{
	vector<string> words = { "hello", "string", "the", "if", "else", "void", "vector", "algorithm" };
	sortWords(words);
	
	system("pause");
	return 0;
}
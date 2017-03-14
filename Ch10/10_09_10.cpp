#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
#include <algorithm>
using  namespace std;

/*
	sort 算法
	unique 算法 将序列重排，将重复的元素挪到序列最后， 返回指向不重复序列的最后一个元素的后一个位置
*/
//Ex10_09 对 vector<string> 排序 删掉重复的元素

void elimDups(vector<string> &word)
{
	sort(word.begin(), word.end());
	//unique 重新排列 返回指向不重复区域的后一个位置的迭代器
	auto end_unique = unique(word.begin(), word.end());
	//删除最后的重复单词
	word.erase(end_unique, word.end());
}
//=======================================================================================
//Ex10_11 使用 stable_sort 将 vector<string> 按照元素大小排序 大小相同的按照字典排序
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
void advElimDups(vector<string> &word)
{
	stable_sort(word.begin(), word.end(), isShorter);
	auto end_unique = unique(word.begin(), word.end());
	word.erase(end_unique, word.end());
}
//====================================================================================
/*
Ex 10_10
	算法不能改变容器大小的原因是什么？
	算法直接关联的是迭代器 迭代器来进行对容器的改变大小的操作  这么做可以使算法有更好的通用性 容器很多种  迭代器种类很少
*/
int main()
{
	vector<string> strv = { "hello", "world", "string", "the", "hello", "vector", "unique", "algorithm" };
	//elimDups(strv);
	advElimDups(strv);
	for (auto &i : strv)
	{
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
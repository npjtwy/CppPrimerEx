#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
#include <algorithm>

using  namespace std;
//Ex10_18 用 partition 重写 “ Ex10_16  找到 vector<string> 中 string 长度大于等于 5 的元素 并打印 ”
void elimDups(vector<string> &word)
{
	sort(word.begin(), word.end());
	//unique 重新排列 返回指向不重复区域的后一个位置的迭代器
	auto end_unique = unique(word.begin(), word.end());
	//删除最后的重复单词
	word.erase(end_unique, word.end());
}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);//排序 然后删除重复的单词

	auto wc = partition(words.begin(), words.end(),
		[sz](const string &s) {return s.size() >= sz; });

	//打印
	for_each(words.begin(), wc, [](const string &s){ cout << s << " "; });
	cout << endl;
}
//==============================================================================
/*
	Ex10_19 用 stable_partition 重写 Ex10_18 使得划分后仍能保持原来的元素顺序

*/
void biggies2(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);//排序 然后删除重复的单词
	//按长度排序
	stable_sort(words.begin(), words.end(),
		[](const string &a, const string &b) {return a.size() < b.size(); });

	auto wc = stable_partition(words.begin(), words.end(),
		[sz](const string &s) {return s.size() >= sz; });

	//打印
	for_each(words.begin(), wc, [](const string &s){ cout << s << " "; });
	cout << endl;
}
//======================================================================================
int main()
{
	vector<string> words = { "hello", "string", "the", "if", "else", "void", "vector", "algorithm" };
	biggies2(words, 5);

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
#include <algorithm>
/*
	lambda  形式 [捕获列表] (参数列表) -> return type {function body}
	捕获列表可以捕获lambda所在函数内的非 static 变量
	lambda可以直接使用捕获列表和lambda所在函数之外的变量
*/
/*
Ex10_14		[](const int a, const int b) {return a + b;}
Ex10-15		void func(int a){
...
[a] (int b) {return a + b}
...
}
*/
using  namespace std;
//Ex10_16  找到 vector<string> 中 string 长度大于等于 5 的元素 并打印
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

	//在按照字符串长度进行排序
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	
	//返回指向第一个长度大于等于 sz 的 string的迭代器
	auto wc = find_if(words.begin(), words.end(), [sz](const string &s){return s.size() >= sz; });
	auto count = words.end() - wc;	//统计长度大于等于sz的string个数
	
	//打印
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}


int main()
{
	vector<string> words = { "hello", "string", "the", "if", "else", "void", "vector", "algorithm" };
	biggies(words, 5);
	
	system("pause");
	return 0;
}
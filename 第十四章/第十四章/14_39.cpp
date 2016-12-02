#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
using  namespace std;
class CompLenth
{
public:
	CompLenth(size_t n) : sz(n) {}		//初始化接受两个参数 确定一个单词长度的范围

	bool operator()(const std::string &str)		
	{
		return (str.size() >= sz);
	}
private:
	size_t sz;
};
class Comp		//按照从大到小排序时使用
{
public:
	bool operator()(const string &s1, const string  &s2)
	{
		return (s1.size() < s2.size());
	}
private:
};
// 复数后面加 s
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &words)		//将单词排序 并删除重复的单词
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &word, vector<string>::size_type sz)
{
	elimDups(word);
	
	stable_sort(word.begin(), word.end(), Comp());		//将单词按照长度由小到大排序

	auto wc = find_if(word.begin(), word.end(), CompLenth(sz));		//找到第一个长度大于sz的单词所在位置
	auto count = word.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") 
		<< " of length " << sz << " or longer" << endl;

	for_each(wc, word.end(), [](const string& s) { cout << s << " "; });
	cout << endl;
}
int main()
{
	vector<string> svec;
	ifstream input("input_short_file.txt");
	string word;
	while (input >> word)
	{
		string new_word;

		remove_copy_if(word.begin(), word.end(), back_inserter(new_word), ispunct);
		svec.push_back(new_word);
	}

	biggies(svec, 5);

	
	system("pause");
	return 0;
}
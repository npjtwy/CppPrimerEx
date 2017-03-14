#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <iterator>
using  namespace std;

class CompLenth
{
public:
	CompLenth(size_t l, size_t u) : lower(l), upper(u) {}		//初始化接受两个参数 确定一个单词长度的范围

	bool operator()(pair<const size_t, int> p)
	{
		return (p.first <= upper && p.first>= lower);
	}
private:
	size_t lower;
	size_t upper;
};

int main()
{
	fstream input("input_file.txt");
	map<size_t, int> ret;		//key 用来表示单词长度 value 表示符合长度的单词个数

	string line;		//存储一行，包括空格，标点
	while (getline(input, line))
	{
		istringstream linetxt(line);		//将一行文本分解成单词
		string word;
		while (linetxt >> word)
		{
			string new_word;
			//将单词中的标点去掉后存入 new_word
			remove_copy_if(word.begin(), word.end(), back_inserter(new_word), ispunct);
			if (new_word.size() > 0)
			{
				ret[new_word.size()] += 1;		//表示当前单词长度 的数量 +1
			}
		}
	}
	
	CompLenth test19(1, 9);
	CompLenth test10(10, 1000);
	int count9 = 0;
	int count10 = 0;

	for (auto i : ret)
	{
		if (test19(i))
		{
			count9 += i.second;		// 单词长度在1~9的数量
		}
		else
		{
			count10 += i.second;
		}
	}

	cout << count9 <<" " <<count10 << endl;

	for (auto i : ret)
	{
		cout << i.first << "\t" << i.second << endl;
	}
	system("pause");
	return 0;
}
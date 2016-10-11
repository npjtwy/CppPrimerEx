#pragma once
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;
/*
	文本查询程序完成以下的任务：
		当程序读取输入文件时，必须记住单词出现的每一行，因此 需要逐行读取输入文件 并将每一行分解为独立的单词
		程序输出时
			必须提取每个单词所关联的行号
			行号必须升序出现且无重复
			必须打印给定行号的文本
	***************************************************
	使用标准库：
		使用 vector<string> 保存整个输入文件的拷贝 每行保存为一个元素 可用行号作为下标来提取行文本
		使用 istringstream 将每行分解为单个单词
		使用 set 保存行号 确保行号只出现一次 以及升序保存
		使用 map 保存单词和对应的行号set  map<word, set<int>>

		还会使用 shared_ptr
*/
/*
	定义一个类 包含一个 vector 和 map
	还有一个 读取给定输入文件的构造函数和一个执行查询的操作
	查询：  查找map 检查给定单词是否出现
			一旦查找到单词 需要返回 出现次数， 出现的行号 和 每行的文本  
			将这些返回值定义成一个类 QueryResult 还包括一个 print 函数来打印结果
	两个类之间要共享数据 使用 shared_ptr

*/

using Mymap = map<string, set<unsigned int>>;
class QueryResult;

class TextQuery
{
public:
	friend class QueryResult;

public:
	TextQuery(ifstream &infile)
	{
		string line;
		auto text_lin = BuildVector(line, infile);		//获取每一行元素并保存到 vector
		SaveWord(text_lin, line);						//将每个单词保存到 map 中 并将对应行号保存到 set
	}
	/*void BuildSet(vector<string>& text_lin, map<string, set<size_t>> &mp)		//创建单词的 行号set
	{
		auto vit = text_lin.begin();								//遍历 vector 中的每一行 同时使用 line 迭代行号
		unsigned int line = 1;
		for (; vit != text_lin.end(); ++vit, ++line)
		{
			auto mpit = mp.begin();									//遍历 map 中的 word
			for (; mpit != mp.end(); ++mpit)
			{
				if (vit->find((*mpit).first) != string::npos)		//如果在某行找到 word 将行号存入word对应的 set
					mpit->second.insert(line);
			}
		}
	}*/
	//此函数实现向 m_mp 中添加 word 的同时 更新word对应的 set
	void InsertMap(map<string, set<unsigned int>> &mp,string &word, unsigned int &lineNo)
	{//此函数实现向 m_mp 中添加 word 的同时 更新word对应的 set
		set <unsigned int> tmp = {};
		auto p = mp.emplace(pair<string, set<unsigned int>>(word, tmp));	//p是一个 pair<mp::iterator,bool>
		(p.first)->second.insert(lineNo);							//p中的迭代器指向新插入的元素或者已经存在的元素
	}

	//用于保存单词到 map
	void SaveWord(vector<string>& text_lin, string &line)		//用于保存单词到 map
	{
		unsigned int lineNo = 0;			//设置行号迭代
		for (auto &lin : text_lin)
		{
			++lineNo;
			istringstream stream_in(line);
			string word;
			stream_in >> word;				//保存每个单词
			InsertMap(m_mp, word, lineNo);
		}
	}

	//将每行文本存入 vector
	vector<string>& BuildVector(string &line, ifstream &infile)
	{
		while (getline(infile, line))
		{
			m_vc_txt.push_back(line);			//将每行文本存入 vector
		}
		return m_vc_txt;
	}

	//执行查询的操作
	TextQuery& QueryWord(string &s) { QueryResult(*this, s); }

	
private:
	vector<string>		m_vc_txt;
	Mymap				m_mp;
};

class QueryResult
{
public:
	QueryResult() { ; }
	QueryResult(TextQuery &textqury, string &s)
	{ 
		m_word = s;
		//确定出现次数
		m_count = 0;
		for (auto &vit : textqury.m_vc_txt)
		{
			m_count += count(vit.begin(), vit.end(), s);
		}

	}

	//打印查询结果
	ostream& print(ostream &os, TextQuery &query)
	{
		os << m_word << "occurs" << m_count <<  (m_count > 1 ? "times" : "time") << endl;
		for (auto & lineNO : query.m_mp[m_word])
		{
			os << "(line " << lineNO << ")\t" << query.m_vc_txt[lineNO-1]<< endl;
		}
		return os;
	}

private:
	int					m_count;
	set<unsigned int>	m_line;
	string				m_word;

};
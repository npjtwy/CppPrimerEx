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

/*

class QueryResult;
class TextQuery
{
public:
	using lineNo = vector<string>::size_type;
	using mymap = map<string, set<lineNo>>;
	QueryResult QueryWord(string &s);
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
		lineNo line = 1;
		for (; vit != text_lin.end(); ++vit, ++line)
		{
			auto mpit = mp.begin();									//遍历 map 中的 word
			for (; mpit != mp.end(); ++mpit)
			{
				if (vit->find((*mpit).first) != string::npos)		//如果在某行找到 word 将行号存入word对应的 set
					mpit->second.insert(line);
			}
		}
	}

	//此函数实现向 m_mp 中添加 word 的同时 更新word对应的 set
	void InsertMap(mymap &mp,string &word, lineNo &line_No)
	{//此函数实现向 m_mp 中添加 word 的同时 更新word对应的 set
		set <unsigned int> tmp = {};
		auto p = mp.emplace(pair<string, set<lineNo>>(word, tmp));	//p是一个 pair<mp::iterator,bool>
		(p.first)->second.insert(line_No);							//p中的迭代器指向新插入的元素或者已经存在的元素
	}
	
	//用于保存单词到 map
	void SaveWord(vector<string>& text_lin, string &line)		//用于保存单词到 map
	{
		lineNo line_No = 0;			//设置行号迭代
		for (auto &lin : text_lin)
		{
			++line_No;
			istringstream stream_in(line);
			string word;
			stream_in >> word;				//保存每个单词
			InsertMap(m_mp, word, line_No);
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

	
	
private:
	vector<string>		m_vc_txt;
	mymap				m_mp;
};

//执行查询的操作
QueryResult TextQuery::QueryWord(string &s)
{
	int cnt = 0;
	for (auto &i : m_vc_txt)
	{
		cnt += count(i.begin(), i.end(), s);
	}
	static set<vector<string>::size_type> nodata{};		//空 set 表示没有找到单词
	auto loc = m_mp.find(s);
	if (loc == m_mp.end())
	{
		return	QueryResult(m_vc_txt, nodata, s, cnt);
	}
	else
		return QueryResult(m_vc_txt, loc->second, s, cnt);
}


class QueryResult
{
public:
	friend ostream& print(ostream &os, QueryResult &query);
public:
	QueryResult(vector<string> &txt, set<vector<string>::size_type> &line_no, string &s, int &cnt) :
		m_word(s),
		m_line(line_no),
		m_text(txt),
		m_count(cnt){}
private:
	vector<string>					m_text;
	set<vector<string>::size_type>	m_line;
	string							m_word;
	int								m_count;

};
//打印查询结果
ostream& print(ostream &os, QueryResult &query)
{
	os << query.m_word << "occurs" << query.m_count << (query.m_count > 1 ? "times" : "time") << endl;
	for (auto & line : query.m_line)
	{
		os << "\t(line " << line << ")\t" << *((query.m_text).begin() + line -1) << endl;
	}
	return os;
}
*/
using line_no = std::set<std::vector<std::string>>::size_type;

class QueryResult;
class TextQuery
{
public:
	TextQuery(std::ifstream &infile);	//构造函数
	QueryResult query(const std::string &s) const;
private:
	std::shared_ptr<std::vector<std::string>>						m_file;	//保存输入文件
	std::map<std::string, std::shared_ptr<std::set<line_no>>>		m_mp;	//保存单词和 对应行号的 set
};

class QueryResult
{
public:
	friend std::ostream& print(std::ostream&, const QueryResult&);
	QueryResult(const std::string& s, std::shared_ptr<std::set<line_no>> set,
		std::shared_ptr<std::vector<std::string>> v, int &cnt)
		: m_word(s), m_line(set), m_qr_file(v), m_count(cnt)
	{}
private:
	std::string									m_word;		//记录要查询的单词
	std::shared_ptr<std::vector<std::string>>	m_qr_file;	
	std::shared_ptr<std::set<line_no>>			m_line;		//行号 set
	int											m_count;	//单词出现的次数
};
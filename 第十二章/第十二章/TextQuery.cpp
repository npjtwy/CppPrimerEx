#include "TextQuery.h"
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
TextQuery::TextQuery(std::ifstream &infile) : m_file(new std::vector<std::string>)
{
	std::string linetxt;
	while (getline(infile, linetxt))
	{
		m_file->push_back(linetxt);		//整行文本存入 vector
		line_no n = m_file->size();		//当前行号
		istringstream line(linetxt);	//将一行文本分解为单词
		string word;
		string new_word;
		while (line >> word)
		{
			//检查 word 中是否包含标点 如果有 去掉后再保存
			remove_copy_if(word.begin(), word.end(), back_inserter(new_word), ispunct);

			auto &line_set = m_mp[new_word];		// line_set 指向当前 word 的set 如果 第一次插入word 则 line_set 为空
			if (!line_set)
				line_set.reset(new set<line_no>);		//当 word 第一次出现时 分配一个 set
			line_set->insert(n);					//将当前行号存入 set

			new_word.clear();
		}
	}
}
//拷贝构造
/*
TextQuery::TextQuery(const TextQuery &obj)
{
	m_file = obj.m_file;
	m_mp = obj.m_mp
}*/


//查询 单词
QueryResult TextQuery::query(const std::string &s) const
{
	int cnt = 0;		//单词出现次数
	
	static shared_ptr<set<line_no>> nodata(new set<line_no>);		//空 set 表示没有找到单词
	auto loc = m_mp.find(s);		//指向 s 
	if (loc != m_mp.end())
	{
		/*char *str;
		char *p = str;
		for (auto &ch : s)
		{
			*p++ = ch;
		}
		*p = '\0';

		for (auto i = m_file->begin(); i != m_file->end(); ++i)
		{
			auto it = i->find_first_of(str, i->begin());
		}
		//*/
		cnt = (*(loc->second)).size();
		return QueryResult(s, loc->second, m_file, cnt);
	}
	else
	{
		return QueryResult(s, nodata, m_file, cnt);
	}
}

ostream& print(std::ostream& os, const QueryResult &ret) {
	os << ret.m_word << " occurs in " << ret.m_count << (ret.m_count > 1 ? " lines" : " lines") << endl;
	for (auto line : *ret.m_line)
	{
		os << "\t(line " << line << ") " << ret.m_qr_file->at(line - 1) << endl;
	}
	return os;
}
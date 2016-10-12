#include "ex12_27.h"
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
		while (line >> word)
		{
			auto &line_set = m_mp[word];		// line_set 指向当前 word 的set 如果 第一次插入word 则 line_set 为空
			if (!line_set)
				line_set.reset(new set<line_no>);		//当 word 第一次出现时 分配一个 set
			line_set->insert(n);					//将当前行号存入 set
		}
	}
}
//查询 单词
QueryResult TextQuery::query(const std::string &s) const
{
	int cnt = 0;		//单词出现次数
	
	static shared_ptr<set<line_no>> nodata(new set<line_no>);		//空 set 表示没有找到单词
	auto loc = m_mp.find(s);		//指向 s 
	if (loc != m_mp.end())
	{
		/*for (auto i : *m_file)
		{
			cnt += count(i.begin(), i.end(), s);
		}*/
		cnt = (*(loc->second)).size();
		return QueryResult(s, loc->second, m_file, cnt);
	}
	else
	{
		return QueryResult(s, nodata, m_file, cnt);
	}
}

ostream& print(std::ostream& os, const QueryResult &ret) {
	os << ret.m_word << " occurs " << ret.m_count << (ret.m_count > 1 ? " times" : " time") << endl;
	for (auto line : *ret.m_line)
	{
		os << "\t(line " << line << ")\t" << ret.m_qr_file->at(line - 1) << endl;
	}
	return os;
}
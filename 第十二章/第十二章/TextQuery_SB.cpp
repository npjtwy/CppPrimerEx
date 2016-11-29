#include "TextQuery_SB.h"
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;
TextQuery::TextQuery(std::ifstream &infile) : m_file(StrBlob())
{
	std::string linetxt;
	while (getline(infile, linetxt))
	{
		m_file.push_back(linetxt);		//整行文本存入 vector
		line_no n = m_file.size() - 1;		//当前行号 - 1  即当前行号在 StrBlob 中的下标
		istringstream line(linetxt);	//将一行文本分解为单词
		string word;
		string new_word;
		while (line >> word)
		{
			//检查 word 中是否包含标点 如果有 去掉后再保存
			remove_copy_if(word.begin(), word.end(), back_inserter(new_word), ispunct);

			// line_set 指向当前 word 的set 如果 第一次插入word 则 line_set 为空
			auto &line_set = m_mp[new_word];
			if (!line_set)
				line_set.reset(new set<line_no>);		//当 word 第一次出现时 分配一个 set
			line_set->insert(n);					//将当前行号存入 set

			new_word.clear();
		}
	}
}

//查询 单词
QueryResult TextQuery::query(const std::string &s) const
{

	static shared_ptr<set<line_no>> nodata(new set<line_no>);		//空 set 表示没有找到单词
	auto loc = m_mp.find(s);		//指向 s 
	if (loc != m_mp.end())
	{
		
		return QueryResult(s, loc->second, m_file);
	}
	else
	{
		return QueryResult(s, nodata, m_file);
	}
}

ostream& print(std::ostream& os, const QueryResult &ret) {
	os << ret.m_word << " occurs in " << ret.m_line->size() << 
		(ret.m_line->size() > 1 ? " times" : " time") << endl;
	for (auto line : *ret.m_line)
	{
		os << "\t(line " << line + 1 << ") " ;

		auto file = ret.m_qr_file;
		const StrBlobPtr wp(file, line);

		os << wp.deref() << endl;
	}
	return os;
}
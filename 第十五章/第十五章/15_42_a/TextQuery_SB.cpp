#include "TextQuery_SB.h"
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

TextQuery::TextQuery(std::ifstream &infile) : m_file(StrBlob())
{
	std::string linetxt;
	line_no n = 1;
	string new_line = "";
	while (getline(infile, linetxt))
	{
		istringstream line_word(linetxt);	//将一行文本分解为单词
		string word, new_word;
		
		while (line_word >> word)
		{
			//检查 word 中是否包含标点 如果有 去掉后再保存
			remove_copy_if(word.begin(), word.end(), back_inserter(new_word), ispunct);
			auto &word_line_set = m_mp[new_word];
			if (!word_line_set)
				word_line_set.reset(new set<line_no>);		//当 word 第一次出现时 分配一个 set
			word_line_set->insert(n);		//将当前行号存入 set

				auto it = find_if(word.begin(), word.end(), 
					[](const char &a) {return a == '.'; });
				if (it == word.end())		//遇到单词中不包含 '.' 时直接加到后面
				{
					new_line =new_line + word + " ";
				}
				else    //单词中包含 '.' 即一句话末尾
				{
					new_line = new_line + word + " ";		//new_line 已经存入完整的一句话
					m_file.push_back(new_line);		//整句话存入 StrBlob 中
					++n;		//行号递增
					new_line.clear();		//清空 new_line 准备保存下一句话
				}
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
		os << "\t(sentence " << line << ") " ;

		auto file = ret.m_qr_file;
		const StrBlobPtr wp(file, line-1);

		os << wp.deref() << endl;
	}
	return os;
}
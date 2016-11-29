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
		m_file.push_back(linetxt);		//�����ı����� vector
		line_no n = m_file.size() - 1;		//��ǰ�к� - 1  ����ǰ�к��� StrBlob �е��±�
		istringstream line(linetxt);	//��һ���ı��ֽ�Ϊ����
		string word;
		string new_word;
		while (line >> word)
		{
			//��� word ���Ƿ������� ����� ȥ�����ٱ���
			remove_copy_if(word.begin(), word.end(), back_inserter(new_word), ispunct);

			// line_set ָ��ǰ word ��set ��� ��һ�β���word �� line_set Ϊ��
			auto &line_set = m_mp[new_word];
			if (!line_set)
				line_set.reset(new set<line_no>);		//�� word ��һ�γ���ʱ ����һ�� set
			line_set->insert(n);					//����ǰ�кŴ��� set

			new_word.clear();
		}
	}
}

//��ѯ ����
QueryResult TextQuery::query(const std::string &s) const
{

	static shared_ptr<set<line_no>> nodata(new set<line_no>);		//�� set ��ʾû���ҵ�����
	auto loc = m_mp.find(s);		//ָ�� s 
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
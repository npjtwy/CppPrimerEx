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
		m_file->push_back(linetxt);		//�����ı����� vector
		line_no n = m_file->size();		//��ǰ�к�
		istringstream line(linetxt);	//��һ���ı��ֽ�Ϊ����
		string word;
		string new_word;
		while (line >> word)
		{
			//��� word ���Ƿ������� ����� ȥ�����ٱ���
			remove_copy_if(word.begin(), word.end(), back_inserter(new_word), ispunct);

			auto &line_set = m_mp[new_word];		// line_set ָ��ǰ word ��set ��� ��һ�β���word �� line_set Ϊ��
			if (!line_set)
				line_set.reset(new set<line_no>);		//�� word ��һ�γ���ʱ ����һ�� set
			line_set->insert(n);					//����ǰ�кŴ��� set

			new_word.clear();
		}
	}
}
//��������
/*
TextQuery::TextQuery(const TextQuery &obj)
{
	m_file = obj.m_file;
	m_mp = obj.m_mp
}*/


//��ѯ ����
QueryResult TextQuery::query(const std::string &s) const
{
	int cnt = 0;		//���ʳ��ִ���
	
	static shared_ptr<set<line_no>> nodata(new set<line_no>);		//�� set ��ʾû���ҵ�����
	auto loc = m_mp.find(s);		//ָ�� s 
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
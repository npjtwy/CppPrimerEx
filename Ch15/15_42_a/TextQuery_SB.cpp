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
		istringstream line_word(linetxt);	//��һ���ı��ֽ�Ϊ����
		string word, new_word;
		
		while (line_word >> word)
		{
			//��� word ���Ƿ������� ����� ȥ�����ٱ���
			remove_copy_if(word.begin(), word.end(), back_inserter(new_word), ispunct);
			auto &word_line_set = m_mp[new_word];
			if (!word_line_set)
				word_line_set.reset(new set<line_no>);		//�� word ��һ�γ���ʱ ����һ�� set
			word_line_set->insert(n);		//����ǰ�кŴ��� set

				auto it = find_if(word.begin(), word.end(), 
					[](const char &a) {return a == '.'; });
				if (it == word.end())		//���������в����� '.' ʱֱ�Ӽӵ�����
				{
					new_line =new_line + word + " ";
				}
				else    //�����а��� '.' ��һ�仰ĩβ
				{
					new_line = new_line + word + " ";		//new_line �Ѿ�����������һ�仰
					m_file.push_back(new_line);		//���仰���� StrBlob ��
					++n;		//�кŵ���
					new_line.clear();		//��� new_line ׼��������һ�仰
				}
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
		os << "\t(sentence " << line << ") " ;

		auto file = ret.m_qr_file;
		const StrBlobPtr wp(file, line-1);

		os << wp.deref() << endl;
	}
	return os;
}
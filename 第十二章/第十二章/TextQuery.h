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
	�ı���ѯ����������µ�����
		�������ȡ�����ļ�ʱ�������ס���ʳ��ֵ�ÿһ�У���� ��Ҫ���ж�ȡ�����ļ� ����ÿһ�зֽ�Ϊ�����ĵ���
		�������ʱ
			������ȡÿ���������������к�
			�кű���������������ظ�
			�����ӡ�����кŵ��ı�
	***************************************************
	ʹ�ñ�׼�⣺
		ʹ�� vector<string> �������������ļ��Ŀ��� ÿ�б���Ϊһ��Ԫ�� �����к���Ϊ�±�����ȡ���ı�
		ʹ�� istringstream ��ÿ�зֽ�Ϊ��������
		ʹ�� set �����к� ȷ���к�ֻ����һ�� �Լ����򱣴�
		ʹ�� map ���浥�ʺͶ�Ӧ���к�set  map<word, set<int>>

		����ʹ�� shared_ptr
*/
/*
	����һ���� ����һ�� vector �� map
	����һ�� ��ȡ���������ļ��Ĺ��캯����һ��ִ�в�ѯ�Ĳ���
	��ѯ��  ����map �����������Ƿ����
			һ�����ҵ����� ��Ҫ���� ���ִ����� ���ֵ��к� �� ÿ�е��ı�  
			����Щ����ֵ�����һ���� QueryResult ������һ�� print ��������ӡ���
	������֮��Ҫ�������� ʹ�� shared_ptr

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
		auto text_lin = BuildVector(line, infile);		//��ȡÿһ��Ԫ�ز����浽 vector
		SaveWord(text_lin, line);						//��ÿ�����ʱ��浽 map �� ������Ӧ�кű��浽 set
	}
	/*void BuildSet(vector<string>& text_lin, map<string, set<size_t>> &mp)		//�������ʵ� �к�set
	{
		auto vit = text_lin.begin();								//���� vector �е�ÿһ�� ͬʱʹ�� line �����к�
		lineNo line = 1;
		for (; vit != text_lin.end(); ++vit, ++line)
		{
			auto mpit = mp.begin();									//���� map �е� word
			for (; mpit != mp.end(); ++mpit)
			{
				if (vit->find((*mpit).first) != string::npos)		//�����ĳ���ҵ� word ���кŴ���word��Ӧ�� set
					mpit->second.insert(line);
			}
		}
	}

	//�˺���ʵ���� m_mp ����� word ��ͬʱ ����word��Ӧ�� set
	void InsertMap(mymap &mp,string &word, lineNo &line_No)
	{//�˺���ʵ���� m_mp ����� word ��ͬʱ ����word��Ӧ�� set
		set <unsigned int> tmp = {};
		auto p = mp.emplace(pair<string, set<lineNo>>(word, tmp));	//p��һ�� pair<mp::iterator,bool>
		(p.first)->second.insert(line_No);							//p�еĵ�����ָ���²����Ԫ�ػ����Ѿ����ڵ�Ԫ��
	}
	
	//���ڱ��浥�ʵ� map
	void SaveWord(vector<string>& text_lin, string &line)		//���ڱ��浥�ʵ� map
	{
		lineNo line_No = 0;			//�����кŵ���
		for (auto &lin : text_lin)
		{
			++line_No;
			istringstream stream_in(line);
			string word;
			stream_in >> word;				//����ÿ������
			InsertMap(m_mp, word, line_No);
		}
	}

	//��ÿ���ı����� vector
	vector<string>& BuildVector(string &line, ifstream &infile)
	{
		while (getline(infile, line))
		{
			m_vc_txt.push_back(line);			//��ÿ���ı����� vector
		}
		return m_vc_txt;
	}

	
	
private:
	vector<string>		m_vc_txt;
	mymap				m_mp;
};

//ִ�в�ѯ�Ĳ���
QueryResult TextQuery::QueryWord(string &s)
{
	int cnt = 0;
	for (auto &i : m_vc_txt)
	{
		cnt += count(i.begin(), i.end(), s);
	}
	static set<vector<string>::size_type> nodata{};		//�� set ��ʾû���ҵ�����
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
//��ӡ��ѯ���
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
	TextQuery(std::ifstream &infile);	//���캯��
	QueryResult query(const std::string &s) const;
private:
	std::shared_ptr<std::vector<std::string>>						m_file;	//���������ļ�
	std::map<std::string, std::shared_ptr<std::set<line_no>>>		m_mp;	//���浥�ʺ� ��Ӧ�кŵ� set
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
	std::string									m_word;		//��¼Ҫ��ѯ�ĵ���
	std::shared_ptr<std::vector<std::string>>	m_qr_file;	
	std::shared_ptr<std::set<line_no>>			m_line;		//�к� set
	int											m_count;	//���ʳ��ֵĴ���
};
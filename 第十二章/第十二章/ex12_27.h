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
		auto text_lin = BuildVector(line, infile);		//��ȡÿһ��Ԫ�ز����浽 vector
		SaveWord(text_lin, line);						//��ÿ�����ʱ��浽 map �� ������Ӧ�кű��浽 set
	}
	/*void BuildSet(vector<string>& text_lin, map<string, set<size_t>> &mp)		//�������ʵ� �к�set
	{
		auto vit = text_lin.begin();								//���� vector �е�ÿһ�� ͬʱʹ�� line �����к�
		unsigned int line = 1;
		for (; vit != text_lin.end(); ++vit, ++line)
		{
			auto mpit = mp.begin();									//���� map �е� word
			for (; mpit != mp.end(); ++mpit)
			{
				if (vit->find((*mpit).first) != string::npos)		//�����ĳ���ҵ� word ���кŴ���word��Ӧ�� set
					mpit->second.insert(line);
			}
		}
	}*/
	//�˺���ʵ���� m_mp ����� word ��ͬʱ ����word��Ӧ�� set
	void InsertMap(map<string, set<unsigned int>> &mp,string &word, unsigned int &lineNo)
	{//�˺���ʵ���� m_mp ����� word ��ͬʱ ����word��Ӧ�� set
		set <unsigned int> tmp = {};
		auto p = mp.emplace(pair<string, set<unsigned int>>(word, tmp));	//p��һ�� pair<mp::iterator,bool>
		(p.first)->second.insert(lineNo);							//p�еĵ�����ָ���²����Ԫ�ػ����Ѿ����ڵ�Ԫ��
	}

	//���ڱ��浥�ʵ� map
	void SaveWord(vector<string>& text_lin, string &line)		//���ڱ��浥�ʵ� map
	{
		unsigned int lineNo = 0;			//�����кŵ���
		for (auto &lin : text_lin)
		{
			++lineNo;
			istringstream stream_in(line);
			string word;
			stream_in >> word;				//����ÿ������
			InsertMap(m_mp, word, lineNo);
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

	//ִ�в�ѯ�Ĳ���
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
		//ȷ�����ִ���
		m_count = 0;
		for (auto &vit : textqury.m_vc_txt)
		{
			m_count += count(vit.begin(), vit.end(), s);
		}

	}

	//��ӡ��ѯ���
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
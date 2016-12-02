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
#include "StrBlob.h"


class QueryResult;

class TextQuery
{
public:
	typedef StrBlob::size_type line_no;

	TextQuery(std::ifstream &infile);	//构造函数
	QueryResult query(const std::string &s) const;
private:
	StrBlob															m_file;	//保存输入文件
	std::map<std::string, std::shared_ptr<std::set<line_no>>>		m_mp;	//保存单词和 对应行号的 set
};

class QueryResult
{
public:
	friend std::ostream& print(std::ostream&, const QueryResult&);
	QueryResult(const std::string& s, std::shared_ptr<std::set<TextQuery::line_no>> set,
		StrBlob v)
		: m_word(s), m_line(set), m_qr_file(v)	{}

	 const StrBlob get_file() const { return m_qr_file; }

	std::set<TextQuery::line_no>::iterator
		begin() { return m_line->begin(); }

	std::set<TextQuery::line_no>::iterator
		end() { return m_line->end(); }

private:
	std::string									m_word;		//记录要查询的单词
	StrBlob										m_qr_file;	//保存文件
	std::shared_ptr<std::set<TextQuery::line_no>>	
												m_line;		//行号 set
};
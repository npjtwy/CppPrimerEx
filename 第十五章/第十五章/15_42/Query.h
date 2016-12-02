#pragma once
#include "TextQuery_SB.h"

class Query_base
{
protected:
	friend class Query;
	virtual ~Query_base() = default;
private:
	//eval 返回当前 Query 匹配的 QueryResult
	virtual QueryResult eval(const TextQuery&) const = 0;
	//rep 是一个表示查询语句的 string
	virtual std::string rep() const = 0;
};

class Query
{
	friend Query operator~(const Query&);
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
public:
	Query(const std::string&);		//创建一个新的 WordQuery 对象
	//接口函数：调用对应的 Query_base 操作
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }

	std::string rep() const 
	{
		return q->rep(); 
	}
private:
	Query(std::shared_ptr<Query_base> query) : q(query) {}
	std::shared_ptr<Query_base> q;
};
inline
std::ostream& operator<<(std::ostream &os, const Query& query)
{
	return os << query.rep();
}


class WordQuery : public Query_base
{
	friend class Query;
private:
	WordQuery(const std::string &s) : query_word(s) 
	{ }

	QueryResult eval(const TextQuery &t) const { return t.query(query_word); }

	std::string rep() const 
	{
		return query_word; ;
	}
	std::string query_word;
};

//定义 Query 的构造函数
inline
Query::Query(const std::string &s) : q(new WordQuery(s))
{}

class NotQuery : public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) { }

	std::string rep() const {
		return "~(" + query.rep() + ")"; 
	}

	QueryResult eval(const TextQuery&) const;
	Query query;
};


class BinaryQrery : public Query_base
{
protected:
	BinaryQrery(const Query &l, const Query &r, std::string s):
		lhs(l), rhs(r), opSym(s)
	{	}

	// BinaryQuery 不定义 eval ，因此 BinaryQuery 也是一个抽象基类
	std::string rep() const 
	{
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; 
	}

	Query lhs, rhs;		//左右运算对象
	std::string opSym;		//运算符名字
};

//AndQuery 和 OrQuery
class AndQuery : public BinaryQrery
{
friend Query operator&(const Query&, const Query&);

private:
	AndQuery(const Query &left, const Query &right) : 
		BinaryQrery(left, right, "&")
	{}

	// 继承 eval 函数， 但是覆盖了 rep 函数
	QueryResult eval(const TextQuery&) const;
};



class OrQuery : public BinaryQrery
{
private:
	friend Query operator|(const Query&, const Query&);

	OrQuery(const Query& left, const Query& right) :
		BinaryQrery(left, right, "|")
	{}

	QueryResult eval(const TextQuery&) const;
};

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

inline Query operator&(const Query &left, const Query &right)
{
	return std::shared_ptr<Query_base>(new AndQuery(left, right));
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}




#pragma once
#include "TextQuery_SB.h"

class Query_base
{
protected:
	friend class Query;
	virtual ~Query_base() = default;
private:
	//eval ���ص�ǰ Query ƥ��� QueryResult
	virtual QueryResult eval(const TextQuery&) const = 0;
	//rep ��һ����ʾ��ѯ���� string
	virtual std::string rep() const = 0;
};

class Query
{
	friend Query operator~(const Query&);
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
public:
	Query(const std::string&);		//����һ���µ� WordQuery ����
	//�ӿں��������ö�Ӧ�� Query_base ����
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

//���� Query �Ĺ��캯��
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

	// BinaryQuery ������ eval ����� BinaryQuery Ҳ��һ���������
	std::string rep() const 
	{
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; 
	}

	Query lhs, rhs;		//�����������
	std::string opSym;		//���������
};

//AndQuery �� OrQuery
class AndQuery : public BinaryQrery
{
friend Query operator&(const Query&, const Query&);

private:
	AndQuery(const Query &left, const Query &right) : 
		BinaryQrery(left, right, "&")
	{}

	// �̳� eval ������ ���Ǹ����� rep ����
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




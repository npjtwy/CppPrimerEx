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

	~Query()
	{
		if (--*use == 0)
		{
			delete	q;
			delete use;
		}
	}

	Query(const Query& rhs) : q(rhs.q), use(rhs.use)
	{
			++*use;
	}
	Query& operator=(const Query& rhs);
	
	//�ӿں��������ö�Ӧ�� Query_base ����
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }

	std::string rep() const
	{
		cout << "[Query::rep]" << endl;
		return q->rep();
	}
private:
	Query(Query_base *query) : q(query), use(new std::size_t(1)) {}   //
	Query_base *q;
	std::size_t *use;		//���ü���
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
	{ 
		cout << "WordQuery constructor" << endl; 
	}

	QueryResult eval(const TextQuery &t) const { return t.query(query_word); }

	std::string rep() const 
	{
		cout << "[WordQuery::rep]" << endl;
		return query_word; ;
	}
	std::string query_word;
};

//���� Query �Ĺ��캯��
inline
Query::Query(const std::string &s) : q(new WordQuery(s)), use(new std::size_t(1))
{ 
	std::cout << "Query constructor" << endl; 
}

class NotQuery : public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) { }

	std::string rep() const {
		cout << "[NotQuery::rep]" << endl;
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
	{
		std::cout << "BinaryQrery constructor" << endl;
	}

	// BinaryQuery ������ eval ����� BinaryQuery Ҳ��һ���������
	std::string rep() const 
	{
		cout << "[BinQuery::rep]" << endl;
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
	{
		std::cout << "AndQuery constructor" << endl;
	}

	// �̳� eval ������ ���Ǹ����� rep ����
	QueryResult eval(const TextQuery&) const;
};



class OrQuery : public BinaryQrery
{
private:
	friend Query operator|(const Query&, const Query&);

	OrQuery(const Query& left, const Query& right) :
		BinaryQrery(left, right, "|")
	{
		std::cout << "OrQuery constructor" << endl;
	}

	QueryResult eval(const TextQuery&) const;
};

inline Query operator~(const Query &operand)
{
	return new NotQuery(operand);
}

inline Query operator&(const Query &left, const Query &right)
{
	return new AndQuery(left, right);
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return new OrQuery(lhs, rhs);
}




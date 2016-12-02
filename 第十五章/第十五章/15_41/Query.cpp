#include "Query.h"
#include <iterator>
#include "TextQuery_SB.h"


Query& Query::operator=(const Query& rhs)
{
	++*rhs.use;
	if (--*use == 0 )
	{
		delete q;
		delete use;
	}
	q = rhs.q;
	use = rhs.use;
	return *this;
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
	//通过 Query 成员 lhs 和 rhs 进行的虚调用
	//调用 eval 返回每个运算对象的 QueryResult
	auto right = rhs.eval(text), left = lhs.eval(text);
	//将左侧运算对象的行号拷贝到结果 set 中
	auto ret_lines =
		make_shared<set<TextQuery::line_no>>(left.begin(), left.end());

	//插入右侧运算对象的行号
	ret_lines->insert(right.begin(), right.end());

	//返回一个新的 QueryResult, 它表示 lhs 和 rhs 的并集
	return QueryResult(rep(), ret_lines, left.get_file());
}



QueryResult AndQuery::eval(const TextQuery &text) const
{
	//通过 Query 运算对象进行的虚调用， 以获得运算对象的查询结果 set
	auto  left = lhs.eval(text), right = rhs.eval(text);

	auto ret_lines =
		make_shared<set<TextQuery::line_no>>();

	set_intersection(left.begin(), left.end(), right.begin(), right.end(),
		inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
	auto result = query.eval(text);
	auto ret_lines = make_shared<set<TextQuery::line_no>>();
	auto beg = result.begin(), end = result.end();

	StrBlob::size_type sz = result.get_file().size();
	for (size_t n = 0; n != sz; ++n)
	{
		if (beg == end || *beg != n)
		{
			ret_lines->insert(n);
		}
		else if (beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

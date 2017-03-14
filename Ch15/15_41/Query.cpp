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
	//ͨ�� Query ��Ա lhs �� rhs ���е������
	//���� eval ����ÿ���������� QueryResult
	auto right = rhs.eval(text), left = lhs.eval(text);
	//��������������кſ�������� set ��
	auto ret_lines =
		make_shared<set<TextQuery::line_no>>(left.begin(), left.end());

	//�����Ҳ����������к�
	ret_lines->insert(right.begin(), right.end());

	//����һ���µ� QueryResult, ����ʾ lhs �� rhs �Ĳ���
	return QueryResult(rep(), ret_lines, left.get_file());
}



QueryResult AndQuery::eval(const TextQuery &text) const
{
	//ͨ�� Query ���������е�����ã� �Ի���������Ĳ�ѯ��� set
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

#pragma once
#include "Quote.h"
#include <set>
using namespace std;
class Basket
{
public:
	//将书本添加到购物篮
	void add_item(const Quote& sale)
	{
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote && sale)
	{
		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
	}
	//打印购物篮书籍价格总和
	double total_receipt(std::ostream&) const;
private:
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs)
		{ return lhs->isbn() < rhs->isbn(); }
	std::multiset<shared_ptr<Quote>, decltype(compare) *> items{ compare};
};

double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;
	//upper_bound 返回一个迭代器，指向一批相同元素之后的位置
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	{
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;

	return sum;
}
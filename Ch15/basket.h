#pragma once
#include "Quote.h"
#include <set>
using namespace std;
class Basket
{
public:
	//���鱾��ӵ�������
	void add_item(const Quote& sale)
	{
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote && sale)
	{
		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
	}
	//��ӡ�������鼮�۸��ܺ�
	double total_receipt(std::ostream&) const;
private:
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs)
		{ return lhs->isbn() < rhs->isbn(); }
	std::multiset<shared_ptr<Quote>, decltype(compare) *> items{ compare};
};

double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;
	//upper_bound ����һ����������ָ��һ����ͬԪ��֮���λ��
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	{
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;

	return sum;
}
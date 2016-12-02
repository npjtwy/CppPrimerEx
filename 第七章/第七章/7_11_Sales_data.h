#ifndef CP7_ex7_11_h
#define CP7_ex7_11_h

#include <string>
#include <iostream>

//为Sales_data类添加构造函数  编写程序用到每一个构造函数


struct Sales_data {
	//新增构造函数
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p * n) {}
	Sales_data(std::istream &is);

	//已有成员
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

double Sales_data::avg_price() const
{
	if (units_sold)
	{
		return revenue / units_sold;
	}
	else
	{
		return 0;
	}
}

Sales_data& Sales_data::combine(const Sales_data& item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

std::ostream& print(std::ostream& os, const Sales_data& item)
{
	os << item.bookNo << ' ' << item.units_sold << ' ' << item.revenue << ' ' << item.avg_price();
	return os;
}

std::istream& read(std::istream& is, Sales_data& item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum;
	sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}
#endif //CP7_ex7_11_h
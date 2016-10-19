#include "Sales_data.h"

Sales_data::Sales_data(const std::string &s, unsigned n, double p) :
	bookNo(s), units_sold(n), revenue(p * n) { }

Sales_data::Sales_data() : Sales_data("", 0, 0) {  }
Sales_data::Sales_data(std::string s) : Sales_data(s, 0, 0) {}

Sales_data::Sales_data(std::istream &is) : Sales_data()
{
	is >> *this;
}
//拷贝构造函数
Sales_data::Sales_data(const Sales_data &orig) :
	bookNo(orig.bookNo),
	units_sold(orig.units_sold),
	revenue(orig.revenue)
{	}

Sales_data& Sales_data::operator=(const Sales_data& rhs)
{
	bookNo = rhs.bookNo;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;
	return *this;
}

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

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
//重载输出 << 运算符
std::ostream& operator<<(std::ostream &os, const Sales_data &rhs)
{
	os << rhs.bookNo << ' ' << rhs.units_sold << ' ' << rhs.revenue << ' ' << rhs.avg_price();
	return os;
}
//重载输入 >> 运算符
std::istream& operator>>(std::istream &is, Sales_data &rhs)
{
	double price;
	is >> rhs.bookNo >> rhs.units_sold >> price;
	rhs.revenue = price * rhs.units_sold;
	return is;
}
//重载 + 运算符
Sales_data operator+(Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum;
	sum = lhs;
	sum.combine(rhs);
	return sum;
}

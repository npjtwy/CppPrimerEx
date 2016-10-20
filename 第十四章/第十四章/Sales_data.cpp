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

Sales_data & Sales_data::operator+=(const Sales_data & rhs)
{
	this->revenue += rhs.revenue;// TODO: 在此处插入 return 语句
	this->units_sold += rhs.units_sold;
	return *this;
}

Sales_data & Sales_data::operator=(const std::string & str_isbn)
{
	//this->bookNo = str_isbn;  错的 应该创建一个新对象？？？
	*this = Sales_data(str_isbn);
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
	if (is)		//检出输入是否成功
	{
		rhs.revenue = price * rhs.units_sold;
	}
	else
	{
		std::cout << "input failed. The object is a default value." << std::endl;
		rhs = Sales_data();		//输入失败时 对象被赋予默认的状态
	}
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
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.bookNo	== rhs.bookNo &&
		lhs.units_sold	== rhs.revenue &&
		lhs.units_sold	== rhs.units_sold;
}
bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(rhs == lhs);
}
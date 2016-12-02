#ifndef CP7_ex7_41_h
#define CP7_ex7_41_h

#include <string>
#include <iostream>

//了解委托构造函数的委托过程

class Sales_data
{
	/*friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
	friend Sales_data add(const Sales_data&, const Sales_data&);*/
	friend std::istream& read(std::istream&, Sales_data&);

public:
	//构造函数
	Sales_data(const std::string &s, unsigned n, double p) :
			bookNo(s), units_sold(n), revenue(p * n) 
		{
			std::cout << "三参数委托" << std::endl;
		}

	//委托构造函数
	Sales_data() : Sales_data("", 0, 0) { std::cout << "Sales_data()委托" << std::endl; }
	Sales_data(std::string s) : Sales_data(s, 0, 0) 
		{ std::cout << "Sales_data(std::string s)委托" << std::endl; }
	Sales_data(std::istream &is);

	//拷贝构造函数
	Sales_data(const Sales_data &orig) :
		bookNo(orig.bookNo),
		units_sold(orig.units_sold),
		revenue(orig.revenue)
		{	}

	//重载赋值运算符
	Sales_data& operator=(const Sales_data& rhs);
	
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

	~Sales_data() {};

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data::Sales_data(std::istream &is) : Sales_data()
{
	read(is, *this);
	std::cout << "Sales_data(std::istream &is)委托" << std::endl;
}

Sales_data& Sales_data::operator=(const Sales_data& rhs)
{
	bookNo = rhs.bookNo;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;
	return *this;
}
/*
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
*/
std::istream& read(std::istream& is, Sales_data& item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

/*
Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
	std::cout << "Sales_data(std::istream &is)委托" << std::endl;
}*/
#endif //CP7_ex7_11_h
#include "Sales_data.h"

Sales_data::Sales_data(const std::string &s, unsigned n, double p) :
	bookNo(s), units_sold(n), revenue(p * n) { }
Sales_data::Sales_data() : Sales_data("", 0, 0) {  }
Sales_data::Sales_data(std::string s) : Sales_data(s, 0, 0) {}
Sales_data::Sales_data(std::istream &is) : Sales_data()
{
	is >> *this;
}

//�������캯��
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
	this->revenue += rhs.revenue;// TODO: �ڴ˴����� return ���
	this->units_sold += rhs.units_sold;
	return *this;
}

Sales_data & Sales_data::operator=(const std::string & str_isbn)
{
	//this->bookNo = str_isbn;  ��� Ӧ�ô���һ���¶��󣿣���
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
//������� << �����
std::ostream& operator<<(std::ostream &os, const Sales_data &rhs)
{
	os << rhs.bookNo << ' ' << rhs.units_sold << ' ' << rhs.revenue << ' ' << rhs.avg_price();
	return os;
}
//�������� >> �����
std::istream& operator>>(std::istream &is, Sales_data &rhs)
{
	double price;
	is >> rhs.bookNo >> rhs.units_sold >> price;
	if (is)		//��������Ƿ�ɹ�
	{
		rhs.revenue = price * rhs.units_sold;
	}
	else
	{
		std::cout << "input failed. The object is a default value." << std::endl;
		rhs = Sales_data();		//����ʧ��ʱ ���󱻸���Ĭ�ϵ�״̬
	}
	return is;
}
//���� + �����
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
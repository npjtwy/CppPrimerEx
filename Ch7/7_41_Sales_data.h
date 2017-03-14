#ifndef CP7_ex7_41_h
#define CP7_ex7_41_h

#include <string>
#include <iostream>

//�˽�ί�й��캯����ί�й���

class Sales_data
{
	/*friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
	friend Sales_data add(const Sales_data&, const Sales_data&);*/
	friend std::istream& read(std::istream&, Sales_data&);

public:
	//���캯��
	Sales_data(const std::string &s, unsigned n, double p) :
			bookNo(s), units_sold(n), revenue(p * n) 
		{
			std::cout << "������ί��" << std::endl;
		}

	//ί�й��캯��
	Sales_data() : Sales_data("", 0, 0) { std::cout << "Sales_data()ί��" << std::endl; }
	Sales_data(std::string s) : Sales_data(s, 0, 0) 
		{ std::cout << "Sales_data(std::string s)ί��" << std::endl; }
	Sales_data(std::istream &is);

	//�������캯��
	Sales_data(const Sales_data &orig) :
		bookNo(orig.bookNo),
		units_sold(orig.units_sold),
		revenue(orig.revenue)
		{	}

	//���ظ�ֵ�����
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
	std::cout << "Sales_data(std::istream &is)ί��" << std::endl;
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
	std::cout << "Sales_data(std::istream &is)ί��" << std::endl;
}*/
#endif //CP7_ex7_11_h
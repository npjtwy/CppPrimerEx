#ifndef CP7_ex7_21_h
#define CP7_ex7_21_h

#include <string>
#include <iostream>
//�޸�Sales_data���  ʹ������ʵ�ֵ�ϸ��

class Sales_data 
{
friend std::ostream& print(std::ostream&, const Sales_data& );
friend std::istream& read(std::istream&, Sales_data&);
friend Sales_data add(const Sales_data&, const Sales_data&);

public:
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

//��Ա����
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



#endif //CP7_ex7_21_h
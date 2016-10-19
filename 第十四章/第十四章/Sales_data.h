#pragma once
#include <string>
#include <iostream>

//�˽�ί�й��캯����ί�й���

class Sales_data
{

	//������� << �����
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	//�������� >> �����
	friend std::istream& operator>>(std::istream&, Sales_data&);
	//���� + �����
	friend Sales_data operator+(Sales_data &lhs, const Sales_data &rhs);

public:
	//���캯��
	Sales_data(const std::string &s, unsigned n, double p);
	//ί�й��캯��
	Sales_data();
	Sales_data(std::string s);
	Sales_data(std::istream &is);
	//�������캯��
	Sales_data(const Sales_data &orig); 
	~Sales_data() {};
	
	//���������
	Sales_data& operator=(const Sales_data& rhs);

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};




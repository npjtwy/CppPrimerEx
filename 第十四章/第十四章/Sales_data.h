#pragma once
#include <string>
#include <iostream>

//了解委托构造函数的委托过程

class Sales_data
{

	//重载输出 << 运算符
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	//重载输入 >> 运算符
	friend std::istream& operator>>(std::istream&, Sales_data&);
	//重载 + 运算符
	friend Sales_data operator+(Sales_data &lhs, const Sales_data &rhs);

public:
	//构造函数
	Sales_data(const std::string &s, unsigned n, double p);
	//委托构造函数
	Sales_data();
	Sales_data(std::string s);
	Sales_data(std::istream &is);
	//拷贝构造函数
	Sales_data(const Sales_data &orig); 
	~Sales_data() {};
	
	//重载运算符
	Sales_data& operator=(const Sales_data& rhs);

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};




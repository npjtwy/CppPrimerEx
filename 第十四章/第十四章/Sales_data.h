#pragma once
#include <string>
#include <iostream>

class Sales_data
{

	//重载输出 << 运算符
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	//重载输入 >> 运算符
	friend std::istream& operator>>(std::istream&, Sales_data&);
	//重载 + 运算符
	friend Sales_data operator+(Sales_data &lhs, const Sales_data &rhs);
	//关系运算符
	friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
	friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs);
	

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
	//定义复合赋值运算符
	Sales_data& operator+=(const Sales_data& rhs);
	//将表示 ISBN 的 string 对象赋值给 Sales_data
	Sales_data& operator=(const std::string &str_isbn);
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
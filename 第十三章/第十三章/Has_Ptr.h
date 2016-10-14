#pragma once
#include <iostream>
#include <string>
class HasPtr
{
public:
	HasPtr(const std::string &s = std::string(), int n = 0) : ps(new std::string(s)), i(n) { }
	HasPtr(const HasPtr &has);
	HasPtr& operator=(const HasPtr&has);
	~HasPtr();
public:
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);		//13_31 为 HasPtr 添加 < 运算符

	void print();
private:
	std::string *ps;
	int			i;
};
inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	std::cout << "开始交换" << std::endl;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}
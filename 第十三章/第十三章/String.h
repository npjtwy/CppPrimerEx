#pragma once
// 简化版 std::string 
#include <memory>
#include <iostream>
#include <utility> //std::move
class String
{
	friend std::ostream& operator<< (std::ostream &os, const String &str);
	friend bool operator==(const String &lhs, const String &rhs);
	friend bool operator<(const String &lhs, const String &rhs);
	friend bool operator>(const String &lhs, const String &rhs);
	friend bool operator<=(const String &lhs, const String &rhs);
	friend bool operator>=(const String &lhs, const String &rhs);
	friend bool operator!=(const String &lhs, const String &rhs);


public:
	String();
	String(const String&);
	String& operator=(const String&);
	String(char *p);
	~String();
	//添加移动构造函数
	String(String &&s);
	String& operator=(String &&s);
	char& operator[](std::size_t n);
	void free();
	char* begin()const;
	char* end()const;
	size_t size()const;
private:
	void allocate_n_copy(char *fir, char *lst);
private:
	char *elements;
	char *first_free;
	std::allocator<char> alloc;
};
#pragma once
#ifndef Ex12_2_H
#define Ex12_2_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include <utility>//std::move
#include <algorithm> 
using  namespace std;
/*Ex12_2 编写自己的 StrBlob 类
*/
class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
	friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>=(const StrBlob &lhs, const StrBlob &rhs);
public:
	typedef std::vector<std::string>::size_type size_type; 
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	StrBlobPtr begin();
	StrBlobPtr end();

public:
	StrBlob() : data(make_shared<std::vector<std::string>>()) { }
	StrBlob(std::initializer_list<std::string> il);
	
	size_type size();
	//拷贝构造和赋值构造
	StrBlob(const StrBlob& obj);
	StrBlob& operator=(const StrBlob& obj);
	std::string & operator[](std::size_t n);
	const std::string & operator[](std::size_t n) const;

	//添加和删除元素
	void push_back(const string &t) { return data->push_back(t); }
	void push_back(string &&t) { return data->push_back(std::move(t)); }
	void pop_back();
	
	//访问元素
	std::string& front();
	std::string& back();
	const std::string& front() const;
	const std::string& back()const;

private:
	std::shared_ptr<std::vector<std::string>> data;
	//检查 data[i] 是否合法， 否则抛出异常
	void check(size_type i, const std::string &msg) const;
};
//============================================================================
//StrBlob 的迭代器
class StrBlobPtr
{
	friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool  operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool  operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
	StrBlobPtr() : curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }

	string& deref() const;		//解引用
	StrBlobPtr& incr();			//前缀递增

	std::string& operator[](std::size_t n);
	const ::string& operator[](std::size_t n) const;
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	std::string& operator*()const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	std::string* operator->()const
	{
		return &this->operator*();
	}
private:
	weak_ptr<vector<string>> wptr;
	size_t curr;
	//保存string在数组中的当前位置
	shared_ptr<vector<string>> check(size_t, const string&) const;
};

#endif

//Ex12_22 
#pragma once
#ifndef Ex12_22_H
#define Ex12_22_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
using  namespace std;
/*Ex12_22 调用 const StrBlob 类
*/

class ConstStrBlobPtr;
class StrBlob
{

public:
	typedef std::vector<std::string>::size_type size_type;
	friend class ConstStrBlobPtr;
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

public:
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() { return data->size(); }
	//添加和删除元素
	void push_back(const string &t) { return data->push_back(t); }
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
//两个构造函数
StrBlob::StrBlob() : data(make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(make_shared<std::vector<std::string>>(il)) {}
//检查是否越界
void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
	{
		throw out_of_range(msg);
	}
}


void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

const string& StrBlob::front() const{
	check(0, "pop_back on empty StrBlob");
	return data->front();
}

const std::string& StrBlob::back() const{
	check(0, "pop_back on empty StrBlob");
	return data->back();
}

string& StrBlob::front() {
	check(0, "pop_back on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back() {
	check(0, "pop_back on empty StrBlob");
	return data->back();
}

class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr() : curr(0) { }
	// 参数前加 const
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
public:
	//返回值 加 const 因為返回的是 const StrBlob  的元素
	const string& deref() const{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}		//解引用

	ConstStrBlobPtr& incr(){
		check(curr, "increment past end of ConstStrBlobPtr");
		++curr;
		return *this;
	}//前缀递增

	bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }

private:
	const weak_ptr<vector<string>> wptr;
	size_t curr;
	//保存string在数组中的当前位置
	shared_ptr<vector<string>> check(size_t, const string&) const;
};
shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();			//判断 wptr 所指的对象是否还在
	if (!ret)
	{
		throw std::runtime_error("unbound ConstStrBlobPtr");
	}
	if (i >= ret->size())
	{
		throw out_of_range(msg);
	}
	return ret;						//返回指向 vector 的 shared_ptr
}

#endif
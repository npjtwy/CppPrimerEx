
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
/*Ex12_22 ���� const StrBlob ��
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
	//��Ӻ�ɾ��Ԫ��
	void push_back(const string &t) { return data->push_back(t); }
	void pop_back();

	//����Ԫ��
	std::string& front();
	std::string& back();
	const std::string& front() const;
	const std::string& back()const;

private:
	std::shared_ptr<std::vector<std::string>> data;
	//��� data[i] �Ƿ�Ϸ��� �����׳��쳣
	void check(size_type i, const std::string &msg) const;
};
//�������캯��
StrBlob::StrBlob() : data(make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(make_shared<std::vector<std::string>>(il)) {}
//����Ƿ�Խ��
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
	// ����ǰ�� const
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
public:
	//����ֵ �� const ��鷵�ص��� const StrBlob  ��Ԫ��
	const string& deref() const{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}		//������

	ConstStrBlobPtr& incr(){
		check(curr, "increment past end of ConstStrBlobPtr");
		++curr;
		return *this;
	}//ǰ׺����

	bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }

private:
	const weak_ptr<vector<string>> wptr;
	size_t curr;
	//����string�������еĵ�ǰλ��
	shared_ptr<vector<string>> check(size_t, const string&) const;
};
shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();			//�ж� wptr ��ָ�Ķ����Ƿ���
	if (!ret)
	{
		throw std::runtime_error("unbound ConstStrBlobPtr");
	}
	if (i >= ret->size())
	{
		throw out_of_range(msg);
	}
	return ret;						//����ָ�� vector �� shared_ptr
}

#endif
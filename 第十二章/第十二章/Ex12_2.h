#pragma once
#ifndef Ex12_2_H
#define Ex12_2_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
using  namespace std;
/*Ex12_2 ��д�Լ��� StrBlob ��
*/
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob
{

public:
	
	typedef std::vector<std::string>::size_type size_type; 
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	StrBlobPtr begin();
	StrBlobPtr end();

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

class StrBlobPtr
{
public:
	StrBlobPtr() : curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }

	string& deref() const;		//������
	StrBlobPtr& incr();			//ǰ׺����
	bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
private:
	weak_ptr<vector<string>> wptr;
	size_t curr;
	//����string�������еĵ�ǰλ��
	shared_ptr<vector<string>> check(size_t, const string&) const;
};
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();			//�ж� wptr ��ָ�Ķ����Ƿ���
	if (!ret)
	{
		throw std::runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size())
	{
		throw out_of_range(msg);
	}
	return ret;						//����ָ�� vector �� shared_ptr
}

string& StrBlobPtr::deref() const{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}
//���ص�����Ķ��������
StrBlobPtr& StrBlobPtr::incr(){
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
#endif
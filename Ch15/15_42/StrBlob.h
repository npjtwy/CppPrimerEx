#pragma once

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include <utility>//std::move
#include <algorithm> 
using  namespace std;
/*Ex12_2 ��д�Լ��� StrBlob ��
*/
class StrBlobPtr;

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
	
	const size_type size() const { return data->size(); }
	//��������͸�ֵ����
	StrBlob(const StrBlob& obj);
	StrBlob& operator=(const StrBlob& obj);
	std::string & operator[](std::size_t n);
	const std::string & operator[](std::size_t n) const;

	//���Ӻ�ɾ��Ԫ��
	void push_back(const string &t) { return data->push_back(t); }
	void push_back(string &&t) { return data->push_back(std::move(t)); }
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
//============================================================================
//StrBlob �ĵ�����
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

	string& deref() const;		//������  ���� vector ��Ա
	StrBlobPtr& incr();			//ǰ׺����

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
	weak_ptr<vector<string>>	wptr;
	size_t						curr;
	//����string�������еĵ�ǰλ��
	shared_ptr<vector<string>> check(size_t, const string&) const;
};
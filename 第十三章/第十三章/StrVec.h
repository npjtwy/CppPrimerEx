#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
//�򻯰� vector �� ֻ��ȡ string Ԫ��

class StrVec
{
	friend bool operator==(const StrVec &lhs, const StrVec &rhs);
	friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
	friend bool operator< (const StrVec &lhs, const StrVec &rhs);
	friend bool operator> (const StrVec &lhs, const StrVec &rhs);
	friend bool operator<=(const StrVec &lhs, const StrVec &rhs);
	friend bool operator>=(const StrVec &lhs, const StrVec &rhs);
public:
	StrVec(std::initializer_list<std::string> l);
	StrVec () : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec &operator=(const StrVec&);
	~StrVec();
	//�ƶ����캯��
	StrVec(StrVec&&) noexcept;
	StrVec &operator=( StrVec && rhs) noexcept;
	//����һ�� initializer_list ��ֵ�����
	StrVec& operator=(std::initializer_list<std::string> il);
	std::string& operator[](std::size_t n);
	const std::string& operator[](std::size_t n) const;

	//����Ԫ��
	void push_back(const std::string&);	
	//�ƶ�Ԫ�ذ汾
	void push_back(std::string &&);
	//��ǰ������Ԫ�ظ���
	size_t size() const;
	//��ǰ�����������
	size_t capacity() const;
	std::string *begin()const;
	std::string *end()const;
	void resize(size_t  t, std::string s);		//�ı�������Ԫ�صĶ���
	void reserve(size_t &t);		//�����󳬹���ǰ����ʱ��ı�������С
	
private:
	static std::allocator<std::string> alloc;		//����Ԫ��
	void chk_n_alloc();								//���ߺ��� ���������ƺ�����ʹ��
	void free();		//����Ԫ�ز��ͷ��ڴ�
	void reallocate();	//���ڴ治���� ��ȡ�����ڴ沢�������е�Ԫ��
	
	std::pair<std::string*, std::string*> alloc_n_copy
		(const std::string*, const std::string*);		//�����ڴ� �������ƶ���Χ�ڵ�Ԫ��
	//alloc_n_copy ���ƶ�����汾  ʹ���ƶ�����Ԫ��
	std::string *elements;		//ָ��������Ԫ�ص�ָ��
	std::string *first_free;	//ָ�������һ������Ԫ�ص�ָ��
	std::string *cap;			//ָ������β���ָ��
};

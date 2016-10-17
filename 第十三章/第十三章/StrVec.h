#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <memory>
#include <utility>
//�򻯰� vector �� ֻ��ȡ string Ԫ��

class StrVec
{
public:
	StrVec () : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec &operator=(const StrVec&);
	~StrVec();
	//����Ԫ��
	void push_back(const std::string&);		
	//��ǰ������Ԫ�ظ���
	size_t size() const;
	//��ǰ�����������
	size_t capacity() const;
	std::string *begin()const;
	std::string *end()const;
private:
	static std::allocator<std::string> alloc;		//����Ԫ��
	void chk_n_alloc();								//���ߺ��� ���������ƺ�����ʹ��
	void free();		//����Ԫ�ز��ͷ��ڴ�
	void reallocate();	//���ڴ治���� ��ȡ�����ڴ沢�������е�Ԫ��
	std::pair<std::string*, std::string*> alloc_n_copy
		(const std::string*, const std::string*);		//�����ڴ� �������ƶ���Χ�ڵ�Ԫ��
	std::string *elements;		//ָ��������Ԫ�ص�ָ��
	std::string *first_free;	//ָ�������һ������Ԫ�ص�ָ��
	std::string *cap;			//ָ������β���ָ��
};

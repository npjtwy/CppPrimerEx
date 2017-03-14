#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
//简化版 vector 类 只存取 string 元素

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
	//移动构造函数
	StrVec(StrVec&&) noexcept;
	StrVec &operator=( StrVec && rhs) noexcept;
	//定义一个 initializer_list 赋值运算符
	StrVec& operator=(std::initializer_list<std::string> il);
	std::string& operator[](std::size_t n);
	const std::string& operator[](std::size_t n) const;

	//拷贝元素
	void push_back(const std::string&);	
	//移动元素版本
	void push_back(std::string &&);
	//当前数组中元素个数
	size_t size() const;
	//当前数组最大容量
	size_t capacity() const;
	std::string *begin()const;
	std::string *end()const;
	void resize(size_t  t, std::string s);		//改变容器中元素的多少
	void reserve(size_t &t);		//当需求超过当前容量时会改变容器大小
	
private:
	static std::allocator<std::string> alloc;		//分配元素
	void chk_n_alloc();								//工具函数 被拷贝控制函数所使用
	void free();		//销毁元素并释放内存
	void reallocate();	//当内存不够用 获取更多内存并拷贝已有的元素
	
	std::pair<std::string*, std::string*> alloc_n_copy
		(const std::string*, const std::string*);		//分配内存 并拷贝制定范围内的元素
	//alloc_n_copy 的移动构造版本  使用移动构造元素
	std::string *elements;		//指向数组首元素的指针
	std::string *first_free;	//指向数组第一个空闲元素的指针
	std::string *cap;			//指向数组尾后的指针
};

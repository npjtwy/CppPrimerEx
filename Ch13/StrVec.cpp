#include "StrVec.h"
#include <algorithm>
#include <iostream>
std::allocator<std::string> StrVec::alloc;
StrVec::StrVec(std::initializer_list<std::string> l)		//接受 initializer_list 参数构造函数
{
	auto p = alloc_n_copy(l.begin(), l.end());		//开辟新的内存
	this->elements = p.first;
	this->first_free = p.second;
	this->cap = p.second;
}
StrVec::StrVec(const StrVec &sv) {
	auto p = alloc_n_copy(sv.begin(), sv.end());		//开辟新的内存
	this->elements = p.first;
	this->first_free = p.second;
	this->cap = p.second;
}
StrVec& StrVec::operator=(const StrVec &rsv) {
	/*if (this->capacity() < rsv.size())		//检查左边的内存大小能不能装下右边全部的元素
	{
		//如果容量不足则重新分配内存
	}*/
	//直接重新分配左边的内存 销毁之前的元素
	auto newdata = alloc_n_copy(rsv.elements, rsv.first_free);
	free();
	this->elements		= newdata.first;
	this->first_free	= newdata.second;
	this->cap			= newdata.second;
	return *this;
}
StrVec::~StrVec()
{
	free();
}
//移动构造函数
StrVec::StrVec(StrVec &&sv) noexcept
{
	elements		= sv.elements;
	first_free		= sv.first_free;
	cap				= sv.cap;
	sv.elements		= nullptr;
	sv.first_free	= nullptr;
	sv.cap			= nullptr;
}
StrVec& StrVec::operator=(StrVec && rhs) noexcept
{
	if (this != &rhs)		//自赋值检查
	{
		system("pause");
		free();
		// 调用 move_alloc_n_copy
		elements	= rhs.elements;
		first_free	= rhs.first_free;
		cap			= rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
		std::cout << "调用了移动赋值" << std::endl;
	}
	return *this;
}
StrVec & StrVec::operator=(std::initializer_list<std::string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	elements = data.first;
	first_free = cap = data.second;
	return *this;
	// TODO: 在此处插入 return 语句
}
std::string & StrVec::operator[](std::size_t n)
{
	return elements[n];
}
const std::string & StrVec::operator[](std::size_t n) const
{
	return elements[n];
}
//拷贝元素
void StrVec::push_back(const std::string &s)
{
	//调用 chk_n_alloc 来确保有空间容纳新元素
	chk_n_alloc();
	//然后创建新元素
	alloc.construct(first_free++, s);
}
void StrVec::push_back(std::string &&s)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}
//工具函数 被拷贝控制函数所使用
//分配内存 并拷贝制定范围内的元素
std::pair<std::string*, std::string*> StrVec::alloc_n_copy
(const std::string *beg, const std::string *ed)
{
	//分配空间保存给定范围中的元素  data 指向新分配的内存开始位置
	auto data = alloc.allocate(ed - beg);
	//初始化并返回一个 Pair 该 pair 由 data 和 uninitialized_copy 的返回值(指向最后一个构造元素之后的位置)构成
	return{ data, uninitialized_copy(beg, ed, data) };
}
/*
std::pair<std::string*, std::string*> StrVec::move_alloc_n_copy
( const std::string *beg, const std::string *ed)
{
	auto data = alloc.allocate(ed - beg);
	return{ data, uninitialized_copy(make_move_iterator(beg), make_move_iterator(ed), data) };
}*/// 有问题问题 参数加 const 移动赋值调用报错
/*
1 > xutility(1970) : error C2440 : “return” : 
无法从“const std::basic_string<char, std::char_traits<char>, std::allocator<char>>”
转换为“std::basic_string<char, std::char_traits<char>, std::allocator<char>> &&”
*/

//当前数组中元素个数
size_t StrVec::size() const { return first_free - elements; }
//当前数组最大容量
size_t StrVec::capacity() const { return cap - elements; }
std::string* StrVec::begin() const { return elements; }
std::string* StrVec::end() const { return first_free; }
void StrVec::reserve(size_t &t)
{
	if (t > capacity())		//当需求容量超过当前容量时分配内存
	{
		auto newcapacity = t;
		//分配新的内存
		auto newdata = alloc.allocate(newcapacity);
		//将数据从旧内存移动到新的内存
		auto dest = newdata;		//指向新数组中下一个空闲的位置
		auto elem = elements;		//指向旧数组中的下一个元素 用于迭代
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	}
}
//检查当前容量  在添加元素时使用
void StrVec::chk_n_alloc()								
{
	if (size() == capacity()) reallocate();
}
//销毁元素并释放内存
void StrVec::free()
{
	if (elements)
	{
		
/*
		for (auto p = first_free; p != elements; )
		{
			alloc.destroy(--p);		//销毁元素
		}
		alloc.deallocate(elements, cap - elements);		//释放内存
		*/

		std::for_each(this->begin(), this->end(),
			[](std::string p) {alloc.destroy(&p); });
		alloc.deallocate(elements, cap - elements);		//释放内存
	}
}
//当内存不够用 获取更多内存并拷贝已有的元素
/*
void StrVec::reallocate()
{
	//每次分配当前空间两倍大小的新空间
	auto newcapacity = size() ? 2 * size() : 1;
	//分配新的内存
	auto newdata = alloc.allocate(newcapacity);
	//将数据从旧内存移动到新的内存
	auto dest = newdata;		//指向新数组中下一个空闲的位置
	auto elem = elements;		//指向旧数组中的下一个元素 用于迭代
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
*/
// 使用移动迭代器 将源对象的元素移动构造到新分配的内存 避免了拷贝操作提升性能
void StrVec::reallocate()
{
	//每次分配当前空间两倍大小的新空间
	auto newcapacity = size() ? 2 * size() : 1;
	//分配新的内存
	auto first = alloc.allocate(newcapacity);
	// 移动元素
	auto last = uninitialized_copy(make_move_iterator(begin()),
		make_move_iterator(end()),first);		
	/*make_move_iterator()将普通的迭代器转换成移动迭代器 使得 uninitialized_copy 函数
	   对序列的每个元素调用 construct 时采用移动构造*/

	free();
	elements = first;
	first_free = last;
	cap = elements + newcapacity;
}

void StrVec::resize(size_t t, std::string s = "")
{
	if (t > size())		//resize 大于先存元素个数
	{
		if (t > capacity())		//resize 大于当前容量 则要重新分配内存
		{
			reallocate();
		}
		//再构造元素
		for (auto i = first_free; size() < t; ++i)
		{
			alloc.construct(i, s);
			++first_free;
		}
	}
	else if (t < size())
	{
		for (auto i = first_free; size() > t;)		//从后向前销毁元素
		{
			alloc.destroy(--i);
			--first_free;
		}
	}
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
	if (lhs.size() != rhs.size()) return false;
	for (auto i = lhs.begin(), j = rhs.begin(); i != lhs.end(); ++i, ++j)
	{
		if (*i != *j)	return false;
	}
	return true;
}
bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}
bool operator< (const StrVec &lhs, const StrVec &rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(),
		rhs.begin(), rhs.end());
}
bool operator> (const StrVec &lhs, const StrVec &rhs)
{
	return rhs < lhs;
}
bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs < rhs);
}
bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
	return !(rhs < lhs);
}
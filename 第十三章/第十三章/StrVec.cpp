#include "StrVec.h"

std::allocator<std::string> StrVec::alloc;
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
//拷贝元素
void StrVec::push_back(const std::string &s)
{
	//调用 chk_n_alloc 来确保有空间容纳新元素
	chk_n_alloc();
	//然后创建新元素
	alloc.construct(first_free++, s);
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
		for (auto p = first_free; p != elements; )
		{
			alloc.destroy(--p);		//销毁元素
		}
		alloc.deallocate(elements, cap - elements);		//释放内存
	}
}
//当内存不够用 获取更多内存并拷贝已有的元素
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

void StrVec::resize(size_t &t, std::string s = "")
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
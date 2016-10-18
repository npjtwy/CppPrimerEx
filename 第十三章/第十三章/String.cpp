#include "String.h"
#include <algorithm>
String::String()
{
}

String::String(char * p)
{
	size_t sz=0;
	for (auto i = p; *i != '\0'; ++i) sz++;
	sz++;		//包含 ‘\0'在内的元素个数
	elements = alloc.allocate(sz);		//elements 指向内存开始时位置
	first_free = elements;
	for (auto i = p; *i != '\0' ; ++i)
	{
		alloc.construct(first_free++, *i);
	}
	alloc.construct(first_free++, '\0');
}
String::String(const String &s)
{

	elements = alloc.allocate(s.size() + 1);
	first_free = elements;
	allocate_n_copy(s.begin(), s.end());
}

String& String::operator=(const String &rhs)
{
	auto newdata = alloc.allocate(rhs.size() + 1);
	auto first = newdata;
	for (auto i = rhs.begin(); i != rhs.end(); ++i)
	{
		alloc.construct(first++, *i);
	}
	free();
	this->elements = newdata;
	this->first_free = first;
	newdata = NULL;
	first = NULL;
	return *this;
}
String::~String()
{
	free();
}
// 构造范围内元素
void String::allocate_n_copy(char *fir, char *lst)
{
	for (auto i = fir; i!= lst; ++i)
	{
		alloc.construct(this->first_free++, *i);
	}
}
void String::free()
{
	if (elements)
	{
		std::for_each(elements, first_free,
			[this](char &ch) {alloc.destroy(&ch); });
		alloc.deallocate(elements, first_free-elements);
	}
}
char * String::begin()const
{
	return elements;
}

char * String::end()const
{
	return first_free;
}
size_t String::size()const		//size() 返回不包含 '\0' 的元素个数
{
	return end() - begin() - 1;
}

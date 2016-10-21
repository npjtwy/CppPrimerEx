#include "String.h"
#include <algorithm>
String::String()
{}

String::String(char * p)
{
	size_t sz=0;
	for (auto i = p; *i != '\0'; ++i) sz++;
	elements = alloc.allocate(sz);		//elements ָ���ڴ濪ʼʱλ��
	first_free = elements;
	for (auto i = p; *i != '\0' ; ++i)
	{
		alloc.construct(first_free++, *i);
	}
	//alloc.construct(first_free++, '\0');
}
String::String(const String &s)
{
	std::cout << "����copy����" << std::endl;
	elements = alloc.allocate(s.size());
	first_free = elements;
	allocate_n_copy(s.begin(), s.end());
}

String& String::operator=(const String &rhs)
{
	auto newdata = alloc.allocate(rhs.size());
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
String::String(String && s) : elements(s.elements), first_free(s.first_free)
{
	s.elements = s.first_free = nullptr;
	std::cout << "�����ƶ�����" << std::endl;
}
String & String::operator=(String && s)
{
	std::cout << "�����ƶ���ֵ" << std::endl;

	if (this != &s)
	{
		elements = s.elements;
		first_free = s.first_free;
		s.elements = nullptr;
		s.first_free = nullptr;
	}
	return *this;
}
char & String::operator[](std::size_t n)
{
	return elements[n];// TODO: �ڴ˴����� return ���
}

const char& String::operator[](std::size_t n) const
{
	return elements[n];
}

// ���췶Χ��Ԫ��
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
size_t String::size()const		//size() ���ز����� '\0' ��Ԫ�ظ���
{
	return end() - begin();
}

std::ostream& operator<< (std::ostream &os, const String &str)
{
	for (auto i : str) os << i;
	return os;
}

bool operator==(const String &lhs, const String &rhs)
{
	if (lhs.size() != lhs.size()) return false;
	for (auto i = lhs.begin(), j = rhs.begin(); i != lhs.end(); ++i, ++j)
	{
		if (*i != *j) return false;
	}
	return true;
}
bool operator!=(const String &lhs, const String &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const String &lhs, const String &rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(),
		rhs.begin(), rhs.end());
}
bool operator>(const String &lhs, const String &rhs)
{
	return(rhs < lhs);
}
bool operator<=(const String &lhs, const String &rhs)
{
	return !(rhs < lhs);
}
bool operator>=(const String &lhs, const String &rhs)
{
	return !(lhs < rhs);
}

#include "StrVec.h"
#include <algorithm>
#include <iostream>
std::allocator<std::string> StrVec::alloc;
StrVec::StrVec(std::initializer_list<std::string> l)		//���� initializer_list �������캯��
{
	auto p = alloc_n_copy(l.begin(), l.end());		//�����µ��ڴ�
	this->elements = p.first;
	this->first_free = p.second;
	this->cap = p.second;
}
StrVec::StrVec(const StrVec &sv) {
	auto p = alloc_n_copy(sv.begin(), sv.end());		//�����µ��ڴ�
	this->elements = p.first;
	this->first_free = p.second;
	this->cap = p.second;
}
StrVec& StrVec::operator=(const StrVec &rsv) {
	/*if (this->capacity() < rsv.size())		//�����ߵ��ڴ��С�ܲ���װ���ұ�ȫ����Ԫ��
	{
		//����������������·����ڴ�
	}*/
	//ֱ�����·�����ߵ��ڴ� ����֮ǰ��Ԫ��
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
//�ƶ����캯��
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
	if (this != &rhs)		//�Ը�ֵ���
	{
		system("pause");
		free();
		// ���� move_alloc_n_copy
		elements	= rhs.elements;
		first_free	= rhs.first_free;
		cap			= rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
		std::cout << "�������ƶ���ֵ" << std::endl;
	}
	return *this;
}
StrVec & StrVec::operator=(std::initializer_list<std::string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	elements = data.first;
	first_free = cap = data.second;
	return *this;
	// TODO: �ڴ˴����� return ���
}
std::string & StrVec::operator[](std::size_t n)
{
	return elements[n];
}
const std::string & StrVec::operator[](std::size_t n) const
{
	return elements[n];
}
//����Ԫ��
void StrVec::push_back(const std::string &s)
{
	//���� chk_n_alloc ��ȷ���пռ�������Ԫ��
	chk_n_alloc();
	//Ȼ�󴴽���Ԫ��
	alloc.construct(first_free++, s);
}
void StrVec::push_back(std::string &&s)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}
//���ߺ��� ���������ƺ�����ʹ��
//�����ڴ� �������ƶ���Χ�ڵ�Ԫ��
std::pair<std::string*, std::string*> StrVec::alloc_n_copy
(const std::string *beg, const std::string *ed)
{
	//����ռ䱣�������Χ�е�Ԫ��  data ָ���·�����ڴ濪ʼλ��
	auto data = alloc.allocate(ed - beg);
	//��ʼ��������һ�� Pair �� pair �� data �� uninitialized_copy �ķ���ֵ(ָ�����һ������Ԫ��֮���λ��)����
	return{ data, uninitialized_copy(beg, ed, data) };
}
/*
std::pair<std::string*, std::string*> StrVec::move_alloc_n_copy
( const std::string *beg, const std::string *ed)
{
	auto data = alloc.allocate(ed - beg);
	return{ data, uninitialized_copy(make_move_iterator(beg), make_move_iterator(ed), data) };
}*/// ���������� ������ const �ƶ���ֵ���ñ���
/*
1 > xutility(1970) : error C2440 : ��return�� : 
�޷��ӡ�const std::basic_string<char, std::char_traits<char>, std::allocator<char>>��
ת��Ϊ��std::basic_string<char, std::char_traits<char>, std::allocator<char>> &&��
*/

//��ǰ������Ԫ�ظ���
size_t StrVec::size() const { return first_free - elements; }
//��ǰ�����������
size_t StrVec::capacity() const { return cap - elements; }
std::string* StrVec::begin() const { return elements; }
std::string* StrVec::end() const { return first_free; }
void StrVec::reserve(size_t &t)
{
	if (t > capacity())		//����������������ǰ����ʱ�����ڴ�
	{
		auto newcapacity = t;
		//�����µ��ڴ�
		auto newdata = alloc.allocate(newcapacity);
		//�����ݴӾ��ڴ��ƶ����µ��ڴ�
		auto dest = newdata;		//ָ������������һ�����е�λ��
		auto elem = elements;		//ָ��������е���һ��Ԫ�� ���ڵ���
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	}
}
//��鵱ǰ����  �����Ԫ��ʱʹ��
void StrVec::chk_n_alloc()								
{
	if (size() == capacity()) reallocate();
}
//����Ԫ�ز��ͷ��ڴ�
void StrVec::free()
{
	if (elements)
	{
		
/*
		for (auto p = first_free; p != elements; )
		{
			alloc.destroy(--p);		//����Ԫ��
		}
		alloc.deallocate(elements, cap - elements);		//�ͷ��ڴ�
		*/

		std::for_each(this->begin(), this->end(),
			[](std::string p) {alloc.destroy(&p); });
		alloc.deallocate(elements, cap - elements);		//�ͷ��ڴ�
	}
}
//���ڴ治���� ��ȡ�����ڴ沢�������е�Ԫ��
/*
void StrVec::reallocate()
{
	//ÿ�η��䵱ǰ�ռ�������С���¿ռ�
	auto newcapacity = size() ? 2 * size() : 1;
	//�����µ��ڴ�
	auto newdata = alloc.allocate(newcapacity);
	//�����ݴӾ��ڴ��ƶ����µ��ڴ�
	auto dest = newdata;		//ָ������������һ�����е�λ��
	auto elem = elements;		//ָ��������е���һ��Ԫ�� ���ڵ���
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
*/
// ʹ���ƶ������� ��Դ�����Ԫ���ƶ����쵽�·�����ڴ� �����˿���������������
void StrVec::reallocate()
{
	//ÿ�η��䵱ǰ�ռ�������С���¿ռ�
	auto newcapacity = size() ? 2 * size() : 1;
	//�����µ��ڴ�
	auto first = alloc.allocate(newcapacity);
	// �ƶ�Ԫ��
	auto last = uninitialized_copy(make_move_iterator(begin()),
		make_move_iterator(end()),first);		
	/*make_move_iterator()����ͨ�ĵ�����ת�����ƶ������� ʹ�� uninitialized_copy ����
	   �����е�ÿ��Ԫ�ص��� construct ʱ�����ƶ�����*/

	free();
	elements = first;
	first_free = last;
	cap = elements + newcapacity;
}

void StrVec::resize(size_t t, std::string s = "")
{
	if (t > size())		//resize �����ȴ�Ԫ�ظ���
	{
		if (t > capacity())		//resize ���ڵ�ǰ���� ��Ҫ���·����ڴ�
		{
			reallocate();
		}
		//�ٹ���Ԫ��
		for (auto i = first_free; size() < t; ++i)
		{
			alloc.construct(i, s);
			++first_free;
		}
	}
	else if (t < size())
	{
		for (auto i = first_free; size() > t;)		//�Ӻ���ǰ����Ԫ��
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
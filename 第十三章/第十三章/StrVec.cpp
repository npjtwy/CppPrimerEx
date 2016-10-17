#include "StrVec.h"

std::allocator<std::string> StrVec::alloc;
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
//����Ԫ��
void StrVec::push_back(const std::string &s)
{
	//���� chk_n_alloc ��ȷ���пռ�������Ԫ��
	chk_n_alloc();
	//Ȼ�󴴽���Ԫ��
	alloc.construct(first_free++, s);
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
		for (auto p = first_free; p != elements; )
		{
			alloc.destroy(--p);		//����Ԫ��
		}
		alloc.deallocate(elements, cap - elements);		//�ͷ��ڴ�
	}
}
//���ڴ治���� ��ȡ�����ڴ沢�������е�Ԫ��
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

void StrVec::resize(size_t &t, std::string s = "")
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
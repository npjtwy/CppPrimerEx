#include "StrBlob.h"
//���캯��
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(make_shared<std::vector<std::string>>(il)) {}

//�����͸�ֵ����
StrBlob::StrBlob(const StrBlob& obj)
{
	data = make_shared<vector<string>>(*obj.data);
}
StrBlob& StrBlob::operator=(const StrBlob& obj)
{
	data = make_shared<vector<string>>(*obj.data);
	return *this;
}

StrBlob::size_type StrBlob::size() { return data->size(); }

//����Ƿ�Խ��
void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
	{
		throw out_of_range(msg);
	}
}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

const string& StrBlob::front() const {
	check(0, "pop_back on empty StrBlob");
	return data->front();
}

const std::string& StrBlob::back() const {
	check(0, "pop_back on empty StrBlob");
	return data->back();
}

string& StrBlob::front() {
	check(0, "pop_back on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back() {
	check(0, "pop_back on empty StrBlob");
	return data->back();
}

//============================================================================
bool StrBlobPtr::operator!=(const StrBlobPtr& p) { return p.curr != curr; }

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();			//�ж� wptr ��ָ�Ķ����Ƿ���
	if (!ret)
	{
		throw std::runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size())
	{
		throw out_of_range(msg);
	}
	return ret;						//����ָ�� vector �� shared_ptr
}

string& StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}
//���ص�����Ķ��������
StrBlobPtr& StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

//=====================================================================================

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}
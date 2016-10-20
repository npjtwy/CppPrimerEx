#include "StrBlob.h"
//构造函数
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(make_shared<std::vector<std::string>>(il)) {}

//拷贝和赋值构造
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

//检查是否越界
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
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) { return lhs.curr != rhs.curr; }
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs){ 
	return !(lhs != rhs);
}
bool  operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs){ 
	return lhs.curr < rhs.curr;
}
bool  operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs){ 
	return rhs < lhs;
}
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
	return !(rhs < lhs);
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs){ 
	return !(lhs < rhs);
}


shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();			//判断 wptr 所指的对象是否还在
	if (!ret)
	{
		throw std::runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size())
	{
		throw out_of_range(msg);
	}
	return ret;						//返回指向 vector 的 shared_ptr
}

string& StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}
//返回递增后的对象的引用
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

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	if (lhs.data->size() != rhs.data->size()) return false;
	for (auto i = lhs.data->begin(), j = rhs.data->begin(); i != lhs.data->end(); ++i, ++j)
	{
		if (*i != *j) return false;
	}
	return true;
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	//lexicographical_compare 按字典序比较两个序列
	return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), 
		rhs.data->begin(), rhs.data->end());
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
	return rhs < lhs;
}
bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
	return!(rhs < lhs);
}
bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(rhs < rhs);
}
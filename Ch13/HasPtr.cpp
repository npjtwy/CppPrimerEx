#define _CRT_SECURE_NO_WARNINGS
#include "Has_Ptr.h"
using  namespace std;

HasPtr::HasPtr(const HasPtr &has)
{
	ps = new string(*has.ps);
	i = has.i;
}
HasPtr& HasPtr::operator=(const HasPtr&has)
{
	auto newp = new string(*has.ps);		//通过引入 newp 可以在拷贝发生异常时保证当前对象的安全
	if (ps != nullptr)
	{
		delete ps;
		ps = newp;
	}					            	//当赋值拷贝可以用来自己给自己赋值时 说明赋值拷贝是安全
	
	else  ps = newp;
	i = has.i;
	newp = nullptr;
	return *this;
}
HasPtr::~HasPtr()
{
	if (ps != NULL)
	{
		delete ps;
		ps = NULL;
	}
}

bool operator<(const HasPtr& lhs, const HasPtr& rhs) 
{
	if (*lhs.ps < *rhs.ps)
		return true;
	else
	{
		return false;
	}
}

void HasPtr::print()
{
	cout << *ps << " " << i << endl;

}

/*
class Foo
{
public:
protected:
private:
	HasPtr h;
};

void swap(Foo &lhs, Foo &rhs)
{
	using std::swap;
	swap(lhs, rhs);			//这里using std::swap 是因为 假如HasPtr 没有定义自己的swap函数 则会调用std::swap
							// 如果 HasPtr 定义了自己的 swap 则会调用 HasPtr 的 swap 函数
}
*/

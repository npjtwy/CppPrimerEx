#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using  namespace std;
/* 增加引用计数器的HasPtr */
class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new size_t(1)) { }
	HasPtr(const HasPtr &obj);
	HasPtr& operator=(const HasPtr&obj);
	~HasPtr();
private:
	std::string *ps;
	int			i;
	size_t		*use;	//引用计数
};
HasPtr::HasPtr(const HasPtr& obj)
{
	ps = obj.ps;
	i = obj.i;
	++*obj.use;		//增加引用计数
	use = obj.use;
}
HasPtr::~HasPtr()
{
	if (--*use == 0)		//引用计数为0 释放内存
	{
		if (ps) {
			delete ps; ps = nullptr;
	}
	delete use;
	use = nullptr;
}
HasPtr& HasPtr::operator=(const HasPtr& obj)
{
	++*obj.use;			//先增加赋值等号右边对象的引用计数
	--*use;				//递减左边的引用计数
	if (*use == 0)
	{
		if(ps) delete ps;
	}
	delete use;
	ps = obj.ps;
	i = obj.i;
	use = obj.use;
	return *this;
}

int main()
{


	system("pause");
	return 0;
}
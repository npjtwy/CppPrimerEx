#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using  namespace std;
class Foo
{
public:
	Foo() { ; }
	Foo(const Foo&f) { ; }
	Foo(Foo &&f) { ; }

	Foo	sorted() && ;
	Foo sorted() const &;
private:
	vector<int> data;
};

Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	return *this;
}
Foo Foo::sorted() const &
{
	//Foo ret(*this);
	//sort(ret.data.begin(), ret.data.end());
	//return ret;
	return Foo(*this).sorted();		
	/*
		*this 是一个 cosnt 的 Foo 对象 在return 语句中 又通过 Foo(const Foo&f) 
		构造了一个普通的 Foo 对象 this，这时再调用 sorted 会调用 Foo	sorted() && 版本
		因此不会产生递归
	*/
}

int main()
{
	Foo f1;
	f1.sorted();
	
	system("pause");
	return 0;
}


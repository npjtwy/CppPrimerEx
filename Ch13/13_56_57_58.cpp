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
		*this ��һ�� cosnt �� Foo ���� ��return ����� ��ͨ�� Foo(const Foo&f) 
		������һ����ͨ�� Foo ���� this����ʱ�ٵ��� sorted ����� Foo	sorted() && �汾
		��˲�������ݹ�
	*/
}

int main()
{
	Foo f1;
	f1.sorted();
	
	system("pause");
	return 0;
}


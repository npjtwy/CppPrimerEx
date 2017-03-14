#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using  namespace std;
class Test
{
public:
	Test() { cout << "Test()" << endl; }
	Test(const int aa) { Test::a= aa; cout << "Test(const int aa=)" << aa<< endl; }
	Test(const Test&) { cout << "Test(const Test&)" << endl; }
	~Test() { cout << "析构函数 ~Test()" << " a="<<a<< endl; }
private:
	static int a;
};
int Test::a = 0;

void func(const Test &t1, const Test &t2)
{
	cout << "func 引用 调用 t1 t2" << endl;
}
void func2(const Test t1, const Test t2)
{
	cout << "func 非引用调用 t1 t2" << endl;
}

int main3()
{
	vector<Test> tvec;
	Test T1(1);
	Test T2(2);
	cout << "vector 添加元素" << endl;
	tvec.push_back(T1);
	tvec.push_back(T2);
	cout << "make_shared " << endl;
	auto p = make_shared<Test>(Test(3));
	cout << "普通指针 用T1直接初始化" << endl;
	Test *t = new Test(T1);
	cout << "delete " << endl;
	delete t;
	cout << "func 函数调用" << endl;
	func(T1, T2);
	cout << "func2 函数调用" << endl;

	func2(T1, T2);
	
	system("pause");
	return 0;
}
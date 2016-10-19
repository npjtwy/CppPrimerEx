#include "String.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	String s1("h");
	String s2("he");
	String s3("hel");
	String s4("hell");
	String s5("hello");
	vector<String> Sv;
	cout << Sv.capacity() << endl;
	Sv.push_back(s1);//0
	cout << Sv.capacity() << endl;
	Sv.reserve(9);
	Sv.push_back(s2);//1
	cout << Sv.capacity() << endl;
	Sv.push_back(s3);//2
	cout << Sv.capacity() << endl;
	Sv.push_back(s4);//3

	cout << Sv.capacity() << endl;
	Sv.push_back(s5);//4
	/*
		当vector内存足够时 只会调用 copy 构造函数来构造元素 
		而当 vector 内存不足时 会分配内存 然后调用移动构造将元素移到新的内存 再调用拷贝构造
		也就是说 vector 实际上只调用拷贝构造来构造新的元素
	*/

	cout << s5 << endl;
	system("pause");
	return 0;
}
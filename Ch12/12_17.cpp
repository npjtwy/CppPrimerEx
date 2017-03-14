#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using  namespace std;

int main()
{
	unique_ptr<string> s1(new string("hello"));
	//unique_ptr<string> s2 = s1;
	//unique_ptr<string> s2(s1);	//unique_ptr 不支持拷贝和赋值
	unique_ptr<string> p1(s1.release());	//所有权转移
	unique_ptr<string> p2(new string("world"));
	p1.reset(p2.release());					//p2 置空 p1 指向 “world”
	
	typedef unique_ptr<int> IntP;
	int ix = 1024, *pi = &ix, *pi2 = new int(122); 
	{
		//IntP p0(ix);
		IntP p1(pi);
		IntP p2(pi2);
		IntP p3(&ix);
		IntP p4(new int(2048));
		//IntP p5(pi2.get());
	}

	cout << "ix: " << ix << endl;
	cout << "*pi: " << *pi << endl;
	cout << "pi2: " << *pi2 << endl;
	system("pause");
	return 0;
}
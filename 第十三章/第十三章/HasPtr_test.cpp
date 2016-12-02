#define _CRT_SECURE_NO_WARNINGS
#include "Has_Ptr.h"
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
	std::vector<HasPtr> hv;
	HasPtr h1("hello", 2);
	HasPtr h2("add", 3);
	
	HasPtr hp = h2;		//1）

	HasPtr hp1 = std::move(h2);   //2)
	/*
		13_52
		1)式中 h2 是一个左值 hp = h2 调用拷贝构造函数 调用完以后 h2 不发生任何变换
		2)式中 等号右边返回一个右值 只能调用移动构造函数 且 2) 式执行完后 h2 中元素被销毁
	*/

	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using  namespace std;

void process(std::shared_ptr<int> ptr)
{
	std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main()
{
	auto p = new int();
	auto sp = make_shared<int>();
	process(sp);	//process 中拷贝了一份 sp
	//process(new int());  不合法
	//process(p);			不合法
	process(shared_ptr<int>(p));	//合法 process 执行完 p 所指的内存会被释放
	return 0;
}
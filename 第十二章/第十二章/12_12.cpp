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
	process(sp);	//process �п�����һ�� sp
	//process(new int());  ���Ϸ�
	//process(p);			���Ϸ�
	process(shared_ptr<int>(p));	//�Ϸ� process ִ���� p ��ָ���ڴ�ᱻ�ͷ�
	return 0;
}
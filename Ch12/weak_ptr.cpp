#define _CRT_SECURE_NO_WARNINGS
#include "Ex12_2.h"
#include <fstream>
#include <iostream>
StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}
/*
void foo(){
	auto p = make_shared<int>(new int(43));
	weak_ptr<int> wp(p);					//wp 和 p 指向相同的对象 创建 wp 不会改变 p  的引用计数 wp 指向的对象可能被释放
	// 由于对象可能不存在 所以要用 lock 检查对象是否存在
	if (shared_ptr<int> np = wp.lock())
	{
		//if 中 np 与 p 共享内存
	}
}
*/

void Ex12_20()
{
	ifstream f_in("input_file.txt");
	StrBlob strblob;
	for (std::string str; std::getline(f_in, str);) strblob.push_back(str);
	for (StrBlobPtr pbeg(strblob.begin()), pend(strblob.end()); pbeg != pend;
		pbeg.incr())
		std::cout << pbeg.deref() << std::endl;

}

int main()
{
	Ex12_20();
	
	system("pause");
	return 0;
}
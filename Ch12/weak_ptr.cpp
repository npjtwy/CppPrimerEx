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
	weak_ptr<int> wp(p);					//wp �� p ָ����ͬ�Ķ��� ���� wp ����ı� p  �����ü��� wp ָ��Ķ�����ܱ��ͷ�
	// ���ڶ�����ܲ����� ����Ҫ�� lock �������Ƿ����
	if (shared_ptr<int> np = wp.lock())
	{
		//if �� np �� p �����ڴ�
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
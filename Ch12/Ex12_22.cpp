#define _CRT_SECURE_NO_WARNINGS
#include "Ex12_22.h"
#include <fstream>
#include <iostream>
ConstStrBlobPtr StrBlob::begin() const  // Ҫ���� const����� thisָ�� const StrBlob
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const  //const Ҫ����
{
	return ConstStrBlobPtr(*this, data->size());
}

void Ex12_22()
{
	ifstream f_in("input_file.txt");
	StrBlob strblob;
	for (std::string str; std::getline(f_in, str);) strblob.push_back(str);
	for (ConstStrBlobPtr pbeg(strblob.begin()), pend(strblob.end()); pbeg != pend;
		pbeg.incr())
		std::cout << pbeg.deref() << std::endl;

}

int main()
{
	Ex12_22();

	system("pause");
	return 0;
}
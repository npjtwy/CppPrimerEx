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
		��vector�ڴ��㹻ʱ ֻ����� copy ���캯��������Ԫ�� 
		���� vector �ڴ治��ʱ ������ڴ� Ȼ������ƶ����콫Ԫ���Ƶ��µ��ڴ� �ٵ��ÿ�������
		Ҳ����˵ vector ʵ����ֻ���ÿ��������������µ�Ԫ��
	*/

	cout << s5 << endl;
	system("pause");
	return 0;
}
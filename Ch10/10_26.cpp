/*
	���ֲ�������� inserter front_inserter back_inserter 
	inserter ����ָԪ��֮ǰ������Ԫ�� Ȼ�����ָ��ԭ��ɫԪ�� �����ش˵�����
	front_inserter ʼ��ָ��������λ�� ��������λ��֮ǰ������Ԫ�غ���ָ���µ���λ��
	back_inserter  ʼ��ָ��������ĩβ ��������ĩβ֮�����Ԫ��
*/

#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <list>
using  namespace std;

int main()
{
	list<int> ilst = { 1, 2, 3, 4 };
	list<int> ilst2, ilst3, ilst4;
	
	copy(ilst.begin(), ilst.end(), front_inserter(ilst2));
	copy(ilst2.begin(), ilst2.end(), ostream_iterator<int>(cout, " ")); cout << endl;

	copy(ilst.begin(), ilst.end(), inserter(ilst3, ilst3.begin()));
	copy(ilst3.begin(), ilst3.end(), ostream_iterator<int>(cout, " ")); cout << endl;

	copy(ilst.begin(), ilst.end(), back_inserter(ilst4));
	copy(ilst4.begin(), ilst4.end(), ostream_iterator<int>(cout, " ")); cout << endl;

	system("pause");
	return 0;
}
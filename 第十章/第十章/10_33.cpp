/*
	Ex10_33 ��������������� �� һ�������ļ�����������ļ���  �����ļ��б����������  ʹ����������������ȡ�ļ� 
			��������ż���ֱ�ʹ������� ����������ļ��� ����ÿ�����ֵ�����һ���ո� ÿ��ż��ռһ��
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using  namespace std;
namespace Classfoo
{
	void Ex10_33();
}
void Classfoo::Ex10_33()
{
	ifstream in("d:/numbers.txt");
	ofstream eve("d:/even.txt");
	ofstream odd("d:/odd.txt");
	ostream_iterator<int> eve_iter(eve, "\n");
	ostream_iterator<int> odd_iter(odd, " ");
	istream_iterator<int> in_iter(in), eof;
	while (in_iter != eof)
	{
		if (*in_iter%2 != 0)
		{
			odd_iter = *in_iter;
			++in_iter;
		}
		else
		{
			eve_iter = *in_iter;
			++in_iter;
		}
	}
	in.close();
	eve.close();
	odd.close();

}

int main()
{
	Classfoo::Ex10_33();
	
	system("pause");
	return 0;
}
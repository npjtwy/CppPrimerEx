#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TextQuery.h"
#include <fstream>
using  namespace std;
/*
�ı���ѯ����������µ�����
�������ȡ�����ļ�ʱ�������ס���ʳ��ֵ�ÿһ�У���� ��Ҫ���ж�ȡ�����ļ� ����ÿһ�зֽ�Ϊ�����ĵ���
�������ʱ
������ȡÿ���������������к�
�кű���������������ظ�
�����ӡ�����кŵ��ı�
***************************************************
ʹ�ñ�׼�⣺
ʹ�� vector<string> �������������ļ��Ŀ��� ÿ�б���Ϊһ��Ԫ�� �����к���Ϊ�±�����ȡ���ı�
ʹ�� istringstream ��ÿ�зֽ�Ϊ��������
ʹ�� set �����к� ȷ���к�ֻ����һ�� �Լ����򱣴�
ʹ�� map ���浥�ʺͶ�Ӧ���к�set  map<word, set<int>>

����ʹ�� shared_ptr
*/
/*
����һ���� ����һ�� vector �� map
����һ�� ��ȡ���������ļ��Ĺ��캯����һ��ִ�в�ѯ�Ĳ���
��ѯ��  ����map �����������Ƿ����
һ�����ҵ����� ��Ҫ���� ���ִ����� ���ֵ��к� �� ÿ�е��ı�
����Щ����ֵ�����һ���� QueryResult ������һ�� print ��������ӡ���
������֮��Ҫ�������� ʹ�� shared_ptr

*/


void runQueries( ifstream &infile)
{
	TextQuery tq(infile);		//�����ļ� ��������ѯ map
	//���û����� ��ʾ����Ҫ��ѯ�ĵ��� ��ɲ�ѯ����ӡ���
	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s ==	"q")  break;

		print(cout, tq.query(s)) << endl;		//��ӡ��ѯ���
	}
}

int main()
{
	ifstream infile("Alice.txt");
	runQueries(infile);

	system("pause");
	return 0;
}
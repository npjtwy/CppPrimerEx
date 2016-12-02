#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TextQuery_SB.h"
#include <fstream>
using  namespace std;

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);		//�����ļ� ��������ѯ map
								//���û����� ��ʾ����Ҫ��ѯ�ĵ��� ��ɲ�ѯ����ӡ���
	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")  break;

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
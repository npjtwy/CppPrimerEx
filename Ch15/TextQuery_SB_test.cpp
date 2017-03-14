#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TextQuery_SB.h"
#include <fstream>
using  namespace std;

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);		//保存文件 并建立查询 map
								//与用户交互 提示输入要查询的单词 完成查询并打印结果
	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")  break;

		print(cout, tq.query(s)) << endl;		//打印查询结果
	}
}

int main()
{
	ifstream infile("Alice.txt");
	runQueries(infile);

	system("pause");
	return 0;
}
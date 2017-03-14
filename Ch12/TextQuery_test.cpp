#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TextQuery.h"
#include <fstream>
using  namespace std;
/*
文本查询程序完成以下的任务：
当程序读取输入文件时，必须记住单词出现的每一行，因此 需要逐行读取输入文件 并将每一行分解为独立的单词
程序输出时
必须提取每个单词所关联的行号
行号必须升序出现且无重复
必须打印给定行号的文本
***************************************************
使用标准库：
使用 vector<string> 保存整个输入文件的拷贝 每行保存为一个元素 可用行号作为下标来提取行文本
使用 istringstream 将每行分解为单个单词
使用 set 保存行号 确保行号只出现一次 以及升序保存
使用 map 保存单词和对应的行号set  map<word, set<int>>

还会使用 shared_ptr
*/
/*
定义一个类 包含一个 vector 和 map
还有一个 读取给定输入文件的构造函数和一个执行查询的操作
查询：  查找map 检查给定单词是否出现
一旦查找到单词 需要返回 出现次数， 出现的行号 和 每行的文本
将这些返回值定义成一个类 QueryResult 还包括一个 print 函数来打印结果
两个类之间要共享数据 使用 shared_ptr

*/


void runQueries( ifstream &infile)
{
	TextQuery tq(infile);		//保存文件 并建立查询 map
	//与用户交互 提示输入要查询的单词 完成查询并打印结果
	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s ==	"q")  break;

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
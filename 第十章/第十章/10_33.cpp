/*
	Ex10_33 程序接受三个参数 ： 一个输入文件和两个输出文件名  输入文件中保存的是整数  使用输入流迭代器读取文件 
			将奇数和偶数分别使用输出流 输出到两个文件中 奇数每个输出值后面跟一个空格 每个偶数占一行
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
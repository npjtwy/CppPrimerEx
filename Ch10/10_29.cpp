#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using  namespace std;
/*
	使用流迭代器 从文件中读取 string 存入一个 vector 
*/
namespace Classfoo
{
	void Ex10_29()
	{
		ifstream in("d:/22.txt");
		istream_iterator<string> s_it(in);
		istream_iterator<string> s_eof;
		vector<string> svec;
		while (s_it != s_eof)
		{
			svec.push_back(*s_it++);
		}

		copy(svec.begin(), svec.end(), ostream_iterator<string>(cout, " "));
		cout << endl;
	}

}


int main()
{
	Classfoo::Ex10_29();
	
	system("pause");
	return 0;
}
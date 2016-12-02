#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Query.h"
#include <fstream>
using  namespace std;

int main()
{
	

	ifstream infile("Alice.txt");
	TextQuery tq(infile);

	/*while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")  break;

		s = q.rep();

		auto result = q.eval(infile);


		print(cout, result) << endl;		//打印查询结果
	}*/

	Query q = Query("fiery") & Query("bird") | Query("wind");
	print(cout, q.eval(tq));

	system("pause");
	return 0;
}
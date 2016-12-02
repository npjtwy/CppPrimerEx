#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using  namespace std;

void Ex9_49()
{

	string str = "aceimnorstuvwxz";
	ifstream ifstrm("d:\\readme.txt");
	string buf;
	for (string word; ifstrm >> word;)
		if ((word.find_first_not_of(str)==string::npos) && (word.size() > buf.size()))
		{
			buf = word;
		}
	cout << buf << endl;
}

int main()
{
	Ex9_49();
	
	system("pause");
	return 0;
}
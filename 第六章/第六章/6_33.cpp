#include "iostream"
#include <string>
#include <vector>
//µİ¹éÊä³övectorÄÚÈİ
//github answer:
using std::cout;
using std::cout;
using std::endl;
using std::vector;
using Iter = vector<int>::iterator;

void printVec(Iter beg, Iter end)
{
	if (beg != end)
	{
		printVec(std::next (beg), end);
		cout << *beg << ' ';
	}
	
}


int   main()
{
	vector<int> val = { 1, 2, 3, 4, 5, 6, 7 };
	
	printVec(val.begin(), val.end());
	cout << endl;
	system("pause");
	return   0;
}
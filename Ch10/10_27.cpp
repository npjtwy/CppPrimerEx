#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using  namespace std;
namespace Classfoo
{
	void Ex10_27()
	{
		vector<int> ivec = { 1, 1, 2, 3, 3, 5, 7, 7 };
		vector<int> ivec2;
		unique_copy(ivec.begin(), ivec.end(), inserter(ivec2, ivec2.begin()));
		copy(ivec2.begin(), ivec2.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}

int main()
{
	Classfoo::Ex10_27();
	
	system("pause");
	return 0;
}
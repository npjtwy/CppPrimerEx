#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <numeric>
#include <vector>
using  namespace std;

int main()
{
	vector<string> intv;
	for (int i = 0; i != 10; ++i)
	{
		intv.push_back("ha");
	}

	string sum = accumulate(intv.begin(), intv.end(), string(""));
	cout << sum << endl;
	system("pause");
	return 0;
}
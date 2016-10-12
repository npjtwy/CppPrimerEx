#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>
#include <set>
#include <iterator>
using  namespace std;
int main()
{
	using vc = vector<int>;
	vc ivc;
	ivc.push_back(8);
	ivc.push_back(4);
	ivc.push_back(2);
	ivc.push_back(7);
	copy(ivc.begin(), ivc.end(), ostream_iterator<int>(cout, " "));
	

	system("pause");
	return 0;
}
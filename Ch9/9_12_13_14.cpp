#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
#include <list>
using  namespace std;

int main()
{
	list<int> lst(10, 2);
	list<int>::iterator it1, it2;
	it1 = lst.begin();
	it2 = lst.end();
	--it2;
	
	vector<double> v1(it1, it2);
	vector<int> v2(10, 3);
	vector<double> v3(v2.begin(), v2.end());

	//assign
	list<char *> lst_1 = { "hello" };
	vector<string> v_str;
	v_str.assign(lst_1.begin(), lst_1.end());
	cout << *v_str.begin() << endl;

	if (*lst.begin() == v2[1]) cout << "yeah" << endl;


	list<int> ilist;
	for (size_t ix = 0; ix != 4; ++ix)
	{
		ilist.push_front(ix);
	}
	ilist.insert(ilist.end(), 10, 2);
	system("pause");
	return 0;
}
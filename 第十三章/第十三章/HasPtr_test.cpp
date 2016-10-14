#define _CRT_SECURE_NO_WARNINGS
#include "Has_Ptr.h"
#include <vector>
#include <algorithm>

int main()
{
	std::vector<HasPtr> hv;
	HasPtr h1("hello", 2);
	HasPtr h2("add", 3);
	HasPtr h3("vector", 4);
	hv.push_back(h1);
	hv.push_back(h2);
	hv.push_back(h3);

	sort(hv.begin(), hv.end());

	for (auto &i : hv)
	{
		i.print();
	}


	system("pause");
	return 0;
}

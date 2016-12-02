#include "iostream"
#include <string>
#include <vector>
using  namespace std;

void main()
{
	vector<int> socer;
	int n;

	while (cin >> n)
	{
		socer.push_back(n);
	}
	
	for (auto i : socer)
	{
		cout << i << ' ';
	}
	cout << endl;

	for (auto i : socer)
	{
		if (i > 80)
		{
			cout << "A+" << ' ';
		}
		else if (i > 70) cout << "A" << ' ';
		else if (i > 60) cout << "B" << ' ';
		else
		{
			cout << "fail" << ' ';
		}
	}
	cout << endl;
	system("pause");
}
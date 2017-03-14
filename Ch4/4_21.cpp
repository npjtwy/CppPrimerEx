#include "iostream"
#include <string>
#include <vector>
using  namespace std;

void main()
{
	vector<int> v_n = { 0, 1, 2, 3, 4, 5, 6, 7 };

	for (auto &i : v_n)
	{
		i = (i % 2 == 0) ? i : 2 * i;
		cout << i << ' ';
	}

	cout << endl;
	
	system("pause");
}
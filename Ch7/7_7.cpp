#include <iostream>
#include <string>

#include "7_6_Sales_data.h"

using namespace std;
int main()
{
	Sales_data temp;

	if (read(cin,temp))
	{
		int cnt = 1;
		Sales_data next;
		while (read(cin,next))
		{
			if (temp.isbn() == next.isbn())
			{
				temp.combine(next);
				++cnt;
			}
			else
			{
				print(cout, temp);
				cout << endl;
				temp = next;
				cnt = 1;
			}
		}
		print(cout, temp);
		cout << endl;
	}
	else
	{
		cerr << "No data ?!" << endl;
		return -1;
	}
	system("pause");
	return 0;
}
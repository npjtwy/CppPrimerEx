#include "iostream"
#include <string>

using  namespace std;

int func1(int n)
{
	if (n > 0)
		return n * func1(n - 1);
	else
	{
		return 1;
	}
}

void main()
{
	int n;
	cout << "输入n的值: " << endl;
	cin >> n;

	cout << "n的阶乘为: " << func1(n) << endl;
	
	system("pause");
}
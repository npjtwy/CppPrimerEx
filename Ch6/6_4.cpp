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
	cout << "����n��ֵ: " << endl;
	cin >> n;

	cout << "n�Ľ׳�Ϊ: " << func1(n) << endl;
	
	system("pause");
}
#include "iostream"
#include <string>
#include "ch6.h"
using  namespace std;

void func2(double n)
{
	cout << "n的绝对值为： "<< abs(n) << endl;
}
void main()
{
	double n;
	cout << "输入n的值：" << endl;
	cin >> n;

	func2(n);
	system("pause");
}
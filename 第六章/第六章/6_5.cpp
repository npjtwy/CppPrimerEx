#include "iostream"
#include <string>
#include "ch6.h"
using  namespace std;

void func2(double n)
{
	cout << "n�ľ���ֵΪ�� "<< abs(n) << endl;
}
void main()
{
	double n;
	cout << "����n��ֵ��" << endl;
	cin >> n;

	func2(n);
	system("pause");
}
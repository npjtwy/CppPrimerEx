#include "iostream"
#include <string>
#include <vector>
using  namespace std;

void main()
{
	vector<string> v_n(5);
	
	cout <<"vecotr " << sizeof(v_n) << endl;
	cout << "string "<<sizeof(string) << endl;
	cout << "char " << sizeof(char) << endl;
	cout << "int " << sizeof(int) << endl;
	cout << "double " << sizeof(double) << endl;

	system("pause");
}
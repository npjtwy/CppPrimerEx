#include "iostream"
#include <string>
#include "7_11.h"
using  namespace std;
//参考github
void main()
{
	Sales_data item1;
	cout << "item1: ";
	print(cout, item1);
	cout << endl;
	//构造函数用法
	Sales_data item2("01100110-x", 2, 3.99);//Sales_data(const std::string &s, 
											//unsigned n, double p):
	                                        //bookNo(s), units_sold(n), revenue(p * n) {}
	cout << "item2: ";
	print(cout, item2);
	cout << endl;

	Sales_data item3("01100112-x");     //Sales_data(const std::string &s) : bookNo(s) {}
	cout << "item3: ";
	print(cout, item3);
	cout << endl;

	cout << "item4: ";
	Sales_data item4(std::cin);        //Sales_data(std::istream &);
	print(cout, item4);
	cout << endl;

	system("pause");
}
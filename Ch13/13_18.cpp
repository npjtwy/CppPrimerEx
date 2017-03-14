#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using  namespace std;
class Employee 
{
public:
	static int	no;
	Employee() : employname(""), employeeNo(++no){}
	Employee(const string &s) : employname(s) { ++no; employeeNo = no; }
	Employee(const Employee &obj)
	{
		employname = obj.employname;
		employeeNo = ++no;
	}
	/*Employee& operator=(const Employee&obj)
	{
		employname = obj.employname;
	}*/
	void printE()
	{
		cout << employname << " " << employeeNo << endl;
	}
private:
	string		employname;
	int			employeeNo;
};
int	Employee::no = 10010;
void func()
{
	auto p1 = make_shared<vector<int>>((10, 2));
	auto p2 = p1;

}
int main5()
{
	Employee e1("wang");
	Employee e2(e1);
	Employee e3("Java");
	Employee e4 = e1;
	e1.printE();
	e2.printE();
	e3.printE();
	e4.printE();
	system("pause");
	return 0;
}
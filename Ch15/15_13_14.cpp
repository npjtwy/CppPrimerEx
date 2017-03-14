#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using  namespace std;

class base
{
public:
	base(string s=""): basename(s) {}
	string name() { return basename; }
	virtual void print(ostream &os) { os << basename; }
private:
	string basename;
};

class derived : public base
{
public:
	derived(int ii = 0) : i(ii), base("") { }
	void print(ostream &os) { base::print(os); os << " " << i; }
private:
	int i;
};

int main()
{
	base b1("hello");

	derived d1;

	d1.print(cout);
	
	system("pause");
	return 0;
}
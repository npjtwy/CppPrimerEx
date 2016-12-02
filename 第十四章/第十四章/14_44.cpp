#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <algorithm>
using  namespace std;
int add(int a, int b)
{
	return a + b;
}

auto  mod = [](int i, int j) {return i % j; };

struct divide
{
	int operator()(int a, int b)
	{
		return a / b;
	}

};
int main()
{
	map<string, function<int(int, int)>> binops;
	binops.insert({ "+", add });
	binops.insert({ "%", mod });
	binops.insert({ "-", std::minus<int>() });
	binops.insert({ "*", [](int a, int b) {return a*b; } });
	binops.insert({ "/", divide() });

	cout << binops["*"](2, 5) << endl;
	

	system("pause");
	return 0;
}
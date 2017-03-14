#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using  namespace std;


int main()
{
	vector<int> ive{ 2,4,8,10 };
	int n = 40;
	modulus<int> mod;
	auto predicator = [&](int i) {return 0 == mod(n, i); };
	// 对序列中的每个元素调用 predicator 若都满足，则返回值为 True
	auto is_divisible = any_of(ive.begin(), ive.end(), predicator);

	if (is_divisible)
	{
		cout << "yes!" << endl;
	}
	else cout << "No!" << endl;

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
using  namespace std;
/*
	Ex10_21 编写一个 lambda 捕获一个局部 Int 变量 并递减 直到该变量变为0， 再调用 lambda 应该不在递减变量 
	lambda 应该返回 bool 值 指出捕获的变量是否为0
*/

void Ex10_21(int n)
{
	auto foo = [&]()-> bool {if (n == 0) return true;
								else {	--n; 	return false;} 
							};
	while (!foo()) cout << n << endl;
}


int main()
{
	Ex10_21(8);
	
	system("pause");
	return 0;
}
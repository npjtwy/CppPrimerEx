#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
//6.7练习
//6_54 声明一个函数 接受两个int类型的形参  返回类型也是int 
//然后声明一个vector对象 令其元素是指向该函数的指针
using ff = int(int, int);

//6——55 编写四个函数分别对两个int值执行 加减乘除运算 在上一题创建的vector对象中保存指向这些函数的指针
int numPlus(int a, int b)
{
	return a + b;
}

int numMinus(int a, int b)
{
	return a - b;
}

int numMulti(int a, int b)
{
	return a * b;
}

int numDiv(int a, int b)
{
	return a / b;
}

void printffP(vector<ff*> ffP)
{
	for (auto i : ffP)
	{
		cout << i(3, 5) << endl;
	}
}
void main()
{
	int(*fp1)(int, int) = numPlus;
	vector<ff*> ffP = { numPlus, numMinus, numMulti, numDiv };
	printffP(ffP);

	system("pause");
}
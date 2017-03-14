#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <algorithm>
#include <vector>
using  namespace std;

int main()
{
	vector<int> vec = { 3, 5, 2, 6, 4, 8, 9 };
	fill_n(vec.begin(), vec.size(), 0);

	vector<int> vec2;
	//vec2.reserve(10);		错误， reserve 只是告诉容器准备存多少元素，并不是已经存入这么多元素，实际上容器为空
	//fill_n(vec2.begin(), 10, 0);
	cout << vec2.size() << endl;

	// Ex10_8 标准库算法不会改变他们所操作的容器的大小， 为什么使用back_inserter 不会使这句话失效？
	auto it = back_inserter(vec2);
	*it = 2;
	cout << vec2.size() << endl;
	//back_inserter 返回的是一个插入迭代器， 改变容器大小的是迭代器 不是 back_inserter

	system("pause");
	return 0;
}
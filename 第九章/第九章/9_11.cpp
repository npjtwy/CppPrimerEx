#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
using  namespace std;
//vector的6中初始化方式
int main()
{
	//1 默认初始化
	vector<int> v1;
	//2 列表初始化
	vector<int> v2 = {1, 3, 5, 7, 9};
	//3 拷贝初始化
	vector<int> v3(v2);		//或者 vector<int> v3 = v2;
	//4
	vector<int> v4(10);		//10个0
	//5
	vector<int> v5(10, 1);	//10个1
	//6 使用迭代器拷贝初始化
	vector<int>::iterator it1, it2;
	it1 = v5.begin();
	it2 = v5.end();
	--it2;
	--it2;
	vector<int> v6(it1, it2);



	system("pause");
	return 0;
}
/*
	三种插入迭代器 inserter front_inserter back_inserter 
	inserter 在所指元素之前插入新元素 然后后移指向原来色元素 并返回此迭代器
	front_inserter 始终指向容器首位置 即：在首位置之前插入新元素后又指向新的首位置
	back_inserter  始终指向容器的末尾 总在容器末尾之后插入元素
*/

#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <list>
using  namespace std;

int main()
{
	list<int> ilst = { 1, 2, 3, 4 };
	list<int> ilst2, ilst3, ilst4;
	
	copy(ilst.begin(), ilst.end(), front_inserter(ilst2));
	copy(ilst2.begin(), ilst2.end(), ostream_iterator<int>(cout, " ")); cout << endl;

	copy(ilst.begin(), ilst.end(), inserter(ilst3, ilst3.begin()));
	copy(ilst3.begin(), ilst3.end(), ostream_iterator<int>(cout, " ")); cout << endl;

	copy(ilst.begin(), ilst.end(), back_inserter(ilst4));
	copy(ilst4.begin(), ilst4.end(), ostream_iterator<int>(cout, " ")); cout << endl;

	system("pause");
	return 0;
}
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
	//vec2.reserve(10);		���� reserve ֻ�Ǹ�������׼�������Ԫ�أ��������Ѿ�������ô��Ԫ�أ�ʵ��������Ϊ��
	//fill_n(vec2.begin(), 10, 0);
	cout << vec2.size() << endl;

	// Ex10_8 ��׼���㷨����ı������������������Ĵ�С�� Ϊʲôʹ��back_inserter ����ʹ��仰ʧЧ��
	auto it = back_inserter(vec2);
	*it = 2;
	cout << vec2.size() << endl;
	//back_inserter ���ص���һ������������� �ı�������С���ǵ����� ���� back_inserter

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
using  namespace std;
//vector��6�г�ʼ����ʽ
int main()
{
	//1 Ĭ�ϳ�ʼ��
	vector<int> v1;
	//2 �б��ʼ��
	vector<int> v2 = {1, 3, 5, 7, 9};
	//3 ������ʼ��
	vector<int> v3(v2);		//���� vector<int> v3 = v2;
	//4
	vector<int> v4(10);		//10��0
	//5
	vector<int> v5(10, 1);	//10��1
	//6 ʹ�õ�����������ʼ��
	vector<int>::iterator it1, it2;
	it1 = v5.begin();
	it2 = v5.end();
	--it2;
	--it2;
	vector<int> v6(it1, it2);



	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include "Has_Ptr.h"
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
	std::vector<HasPtr> hv;
	HasPtr h1("hello", 2);
	HasPtr h2("add", 3);
	
	HasPtr hp = h2;		//1��

	HasPtr hp1 = std::move(h2);   //2)
	/*
		13_52
		1)ʽ�� h2 ��һ����ֵ hp = h2 ���ÿ������캯�� �������Ժ� h2 �������κα任
		2)ʽ�� �Ⱥ��ұ߷���һ����ֵ ֻ�ܵ����ƶ����캯�� �� 2) ʽִ����� h2 ��Ԫ�ر�����
	*/

	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
using  namespace std;
/*
	Ex10_21 ��дһ�� lambda ����һ���ֲ� Int ���� ���ݼ� ֱ���ñ�����Ϊ0�� �ٵ��� lambda Ӧ�ò��ڵݼ����� 
	lambda Ӧ�÷��� bool ֵ ָ������ı����Ƿ�Ϊ0
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
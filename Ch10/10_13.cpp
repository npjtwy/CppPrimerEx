/*
	Ex10_13
	partition �㷨 ����һ��ν�� �����������ݽ��л��� ʹν��Ϊtrue����ǰ�벿�� ν��Ϊfalse���ں�벿��
	����һ��ָ�����һ��ʹν��Ϊtrue��Ԫ��֮��ĵ����� 
	��д���� ����һ�� string ���� bool ֵ��ָ��string�Ƿ���5�����߸�����ַ��� ʹ�ô˺������� words  ��ӡ���ȴ���5��Ԫ��
*/

#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
#include <algorithm>
using  namespace std;
bool isLonger(const string &str)
{
	return str.size() < 5 ? false : true;
}
void sortWords(vector<string> &svec)
{
	auto it = partition(svec.begin(), svec.end(), isLonger);
	for (auto i = svec.begin(); i != it; ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
}
int main()
{
	vector<string> words = { "hello", "string", "the", "if", "else", "void", "vector", "algorithm" };
	sortWords(words);
	
	system("pause");
	return 0;
}
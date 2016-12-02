#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
#include <algorithm>
using  namespace std;

/*
	sort �㷨
	unique �㷨 ���������ţ����ظ���Ԫ��Ų��������� ����ָ���ظ����е����һ��Ԫ�صĺ�һ��λ��
*/
//Ex10_09 �� vector<string> ���� ɾ���ظ���Ԫ��

void elimDups(vector<string> &word)
{
	sort(word.begin(), word.end());
	//unique �������� ����ָ���ظ�����ĺ�һ��λ�õĵ�����
	auto end_unique = unique(word.begin(), word.end());
	//ɾ�������ظ�����
	word.erase(end_unique, word.end());
}
//=======================================================================================
//Ex10_11 ʹ�� stable_sort �� vector<string> ����Ԫ�ش�С���� ��С��ͬ�İ����ֵ�����
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
void advElimDups(vector<string> &word)
{
	stable_sort(word.begin(), word.end(), isShorter);
	auto end_unique = unique(word.begin(), word.end());
	word.erase(end_unique, word.end());
}
//====================================================================================
/*
Ex 10_10
	�㷨���ܸı�������С��ԭ����ʲô��
	�㷨ֱ�ӹ������ǵ����� �����������ж������ĸı��С�Ĳ���  ��ô������ʹ�㷨�и��õ�ͨ���� �����ܶ���  �������������
*/
int main()
{
	vector<string> strv = { "hello", "world", "string", "the", "hello", "vector", "unique", "algorithm" };
	//elimDups(strv);
	advElimDups(strv);
	for (auto &i : strv)
	{
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
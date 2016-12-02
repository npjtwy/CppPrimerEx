#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
#include <algorithm>

using  namespace std;
//Ex10_18 �� partition ��д �� Ex10_16  �ҵ� vector<string> �� string ���ȴ��ڵ��� 5 ��Ԫ�� ����ӡ ��
void elimDups(vector<string> &word)
{
	sort(word.begin(), word.end());
	//unique �������� ����ָ���ظ�����ĺ�һ��λ�õĵ�����
	auto end_unique = unique(word.begin(), word.end());
	//ɾ�������ظ�����
	word.erase(end_unique, word.end());
}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);//���� Ȼ��ɾ���ظ��ĵ���

	auto wc = partition(words.begin(), words.end(),
		[sz](const string &s) {return s.size() >= sz; });

	//��ӡ
	for_each(words.begin(), wc, [](const string &s){ cout << s << " "; });
	cout << endl;
}
//==============================================================================
/*
	Ex10_19 �� stable_partition ��д Ex10_18 ʹ�û��ֺ����ܱ���ԭ����Ԫ��˳��

*/
void biggies2(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);//���� Ȼ��ɾ���ظ��ĵ���
	//����������
	stable_sort(words.begin(), words.end(),
		[](const string &a, const string &b) {return a.size() < b.size(); });

	auto wc = stable_partition(words.begin(), words.end(),
		[sz](const string &s) {return s.size() >= sz; });

	//��ӡ
	for_each(words.begin(), wc, [](const string &s){ cout << s << " "; });
	cout << endl;
}
//======================================================================================
int main()
{
	vector<string> words = { "hello", "string", "the", "if", "else", "void", "vector", "algorithm" };
	biggies2(words, 5);

	system("pause");
	return 0;
}
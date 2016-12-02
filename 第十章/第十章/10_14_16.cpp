#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
#include <algorithm>
/*
	lambda  ��ʽ [�����б�] (�����б�) -> return type {function body}
	�����б���Բ���lambda���ں����ڵķ� static ����
	lambda����ֱ��ʹ�ò����б��lambda���ں���֮��ı���
*/
/*
Ex10_14		[](const int a, const int b) {return a + b;}
Ex10-15		void func(int a){
...
[a] (int b) {return a + b}
...
}
*/
using  namespace std;
//Ex10_16  �ҵ� vector<string> �� string ���ȴ��ڵ��� 5 ��Ԫ�� ����ӡ
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

	//�ڰ����ַ������Ƚ�������
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	
	//����ָ���һ�����ȴ��ڵ��� sz �� string�ĵ�����
	auto wc = find_if(words.begin(), words.end(), [sz](const string &s){return s.size() >= sz; });
	auto count = words.end() - wc;	//ͳ�Ƴ��ȴ��ڵ���sz��string����
	
	//��ӡ
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}


int main()
{
	vector<string> words = { "hello", "string", "the", "if", "else", "void", "vector", "algorithm" };
	biggies(words, 5);
	
	system("pause");
	return 0;
}
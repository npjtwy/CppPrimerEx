#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <iterator>
using  namespace std;

class CompLenth
{
public:
	CompLenth(size_t l, size_t u) : lower(l), upper(u) {}		//��ʼ�������������� ȷ��һ�����ʳ��ȵķ�Χ

	bool operator()(pair<const size_t, int> p)
	{
		return (p.first <= upper && p.first>= lower);
	}
private:
	size_t lower;
	size_t upper;
};

int main()
{
	fstream input("input_file.txt");
	map<size_t, int> ret;		//key ������ʾ���ʳ��� value ��ʾ���ϳ��ȵĵ��ʸ���

	string line;		//�洢һ�У������ո񣬱��
	while (getline(input, line))
	{
		istringstream linetxt(line);		//��һ���ı��ֽ�ɵ���
		string word;
		while (linetxt >> word)
		{
			string new_word;
			//�������еı��ȥ������� new_word
			remove_copy_if(word.begin(), word.end(), back_inserter(new_word), ispunct);
			if (new_word.size() > 0)
			{
				ret[new_word.size()] += 1;		//��ʾ��ǰ���ʳ��� ������ +1
			}
		}
	}
	
	CompLenth test19(1, 9);
	CompLenth test10(10, 1000);
	int count9 = 0;
	int count10 = 0;

	for (auto i : ret)
	{
		if (test19(i))
		{
			count9 += i.second;		// ���ʳ�����1~9������
		}
		else
		{
			count10 += i.second;
		}
	}

	cout << count9 <<" " <<count10 << endl;

	for (auto i : ret)
	{
		cout << i.first << "\t" << i.second << endl;
	}
	system("pause");
	return 0;
}
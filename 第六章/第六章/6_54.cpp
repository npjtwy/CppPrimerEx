#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
//6.7��ϰ
//6_54 ����һ������ ��������int���͵��β�  ��������Ҳ��int 
//Ȼ������һ��vector���� ����Ԫ����ָ��ú�����ָ��
using ff = int(int, int);

//6����55 ��д�ĸ������ֱ������intִֵ�� �Ӽ��˳����� ����һ�ⴴ����vector�����б���ָ����Щ������ָ��
int numPlus(int a, int b)
{
	return a + b;
}

int numMinus(int a, int b)
{
	return a - b;
}

int numMulti(int a, int b)
{
	return a * b;
}

int numDiv(int a, int b)
{
	return a / b;
}

void printffP(vector<ff*> ffP)
{
	for (auto i : ffP)
	{
		cout << i(3, 5) << endl;
	}
}
void main()
{
	int(*fp1)(int, int) = numPlus;
	vector<ff*> ffP = { numPlus, numMinus, numMulti, numDiv };
	printffP(ffP);

	system("pause");
}
#include "iostream"
#include <string>

using  namespace std;
//��ȡ���ʣ������������������ֵĵ�������ѭ����������������εĵ��ʻ���˵��û�������ĵ��ʳ���
void main()
{
	string str;
	string perstr = "\0";
	int cnt = 0;
	
	while (cin >> str)
	{
		if (str == perstr)
		{
			cnt = 1;
			cout << perstr << endl;
			break;
		}
		perstr = str;
	}

	if (!cnt)
	{
		cout << "û���������ֵĵ���" << endl;
	}

	system("pause");
}
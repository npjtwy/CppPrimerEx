#include "iostream"
#include <string>

using  namespace std;
//ͳ����������ĵ��ʳ��ֵ���ߴ���
void main()
{
	string str, max_str;
	string perstr = "\0";
	int cnt = 0, max_num = 0;
	while (cin >> str)
	{
		if ( str == perstr)
		{
			++cnt;
			if (cnt > max_num)
			{
				max_num = cnt;
				max_str = str;
			}
		}
		else
		{
			cnt = 0;
		}

		perstr = str;
	}
	
	cout << "str: " << max_str << " count: " << max_num + 1 << endl;

	system("pause");
}
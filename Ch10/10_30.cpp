#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using  namespace std;
/*
	Ex10_30 ʹ������������sort, copy �ӱ�׼�����ȡһ����������  ����  д����׼���
	Ex10_31 �޸�10����30 ֻ��ӡ���ظ���Ԫ��
*/
namespace Classfoo
{
	void Ex10_30()
	{
		istream_iterator<int> in_iter(cin);
		istream_iterator<int> eof;
		vector<int> ivec;
		while (in_iter != eof)
		{
			ivec.push_back(*in_iter++);
		}

		sort(ivec.begin(), ivec.end());
		copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		unique_copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

}

int main()
{
	Classfoo::Ex10_30();
	
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_item.h"
#include <numeric>
using  namespace std;
namespace Classfoo
{
	void Sales_data();
	void Sales_data2();
}
void Classfoo::Sales_data()
{
	istream_iterator<Sales_item> item_iter(cin), eof;
	ostream_iterator<Sales_item> out_iter(cout, "\n");
	vector<Sales_item> item_vec;
	item_vec.push_back(*item_iter++);				//���������ж�ȡ���׼�¼���� vector
	while (item_iter != eof)
	{
		vector<Sales_item>::iterator back_oter = item_vec.end();
		--back_oter;									//������ָ��vector ��������Ľ��׼�¼
		if (item_iter->isbn() == back_oter->isbn())
		{
			*back_oter += *item_iter++;				//������׼�¼һ�� �ӵ��ϴεĽ��׼�¼��
		}
		else
		{
			out_iter = *back_oter;					//������׼�¼��һ�� ��ӡ��һ����¼ ����½��׼�¼
			item_vec.push_back(*item_iter++);
		}
	}
	out_iter = *item_iter;							//��ӡ���һ����¼
	//��ӡ���м�¼
	cout << "���н��׼�¼�� " << endl;
	copy(item_vec.begin(), item_vec.end(), ostream_iterator<Sales_item>(cout, "\n"));
}
//=================================================================================================
void Classfoo::Sales_data2()
{
	istream_iterator<Sales_item> item_iter(cin), eof;
	vector<Sales_item> item_vec;
	//����������
	while (item_iter != eof)	item_vec.push_back(*item_iter++);
	//Ȼ������
	sort(item_vec.begin(), item_vec.end(),
		[](const Sales_item &s1, const Sales_item &s2) {return s1.isbn() > s2.isbn(); });
	//�ٶ���ͬ�Ľ��׼�¼�������
	for (auto beg = item_vec.begin(), end = beg; beg != item_vec.end(); beg = end)
	{
		end = find_if(beg, item_vec.end(),
			[beg](const Sales_item &item) {return item.isbn() != beg->isbn(); });
		//ͳ����ͬ���׼�¼ ����ӡ
		cout << accumulate(beg, end, Sales_item(beg->isbn())) << endl;
	}
}
int main()
{
	Classfoo::Sales_data2();
	
	system("pause");
	return 0;
}
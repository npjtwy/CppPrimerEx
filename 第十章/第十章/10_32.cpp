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
	item_vec.push_back(*item_iter++);				//从输入流中读取交易记录存入 vector
	while (item_iter != eof)
	{
		vector<Sales_item>::iterator back_oter = item_vec.end();
		--back_oter;									//迭代器指向vector 中最后存入的交易记录
		if (item_iter->isbn() == back_oter->isbn())
		{
			*back_oter += *item_iter++;				//如果交易记录一样 加到上次的交易记录上
		}
		else
		{
			out_iter = *back_oter;					//如果交易记录不一样 打印上一条记录 添加新交易记录
			item_vec.push_back(*item_iter++);
		}
	}
	out_iter = *item_iter;							//打印最后一条记录
	//打印所有记录
	cout << "所有交易记录： " << endl;
	copy(item_vec.begin(), item_vec.end(), ostream_iterator<Sales_item>(cout, "\n"));
}
//=================================================================================================
void Classfoo::Sales_data2()
{
	istream_iterator<Sales_item> item_iter(cin), eof;
	vector<Sales_item> item_vec;
	//先输入数据
	while (item_iter != eof)	item_vec.push_back(*item_iter++);
	//然后排序
	sort(item_vec.begin(), item_vec.end(),
		[](const Sales_item &s1, const Sales_item &s2) {return s1.isbn() > s2.isbn(); });
	//再对相同的交易记录进行相加
	for (auto beg = item_vec.begin(), end = beg; beg != item_vec.end(); beg = end)
	{
		end = find_if(beg, item_vec.end(),
			[beg](const Sales_item &item) {return item.isbn() != beg->isbn(); });
		//统计相同交易记录 并打印
		cout << accumulate(beg, end, Sales_item(beg->isbn())) << endl;
	}
}
int main()
{
	Classfoo::Sales_data2();
	
	system("pause");
	return 0;
}
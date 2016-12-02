#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using  namespace std;
namespace Classfoo
{
	vector<int> ivec = { 1, 4, 0, 43, 76, 2, 0, 43, 9, 10 };
	list<int> ilst = { 1, 4, 0, 43, 76, 2, 0, 43, 9 };
	void Ex10_34();
	void Ex10_35();
	void Ex10_36();
	void Ex10_37();
}
void Classfoo::Ex10_34()
{
	cout << "逆序输出vector :" << endl;
	copy(Classfoo::ivec.crbegin(), ivec.crend(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
void Classfoo::Ex10_35()
{
	cout << "使用普通迭代器逆序打印vector: " << endl;
	vector<int>::iterator itr = ivec.end();
	--itr;
	while (itr != ivec.begin())
	{
		cout << *itr-- << " ";
	}
	cout << *itr << endl;
}
void Classfoo::Ex10_36()
{
	cout << "查找list中的最后一个0：" << endl;
	int count = 0;
	list<int>::const_reverse_iterator it = find(ilst.crbegin(), ilst.crend(), 0);
	if (it != ilst.crend())
	{
		cout << "找到了" << endl;
	}
}
void Classfoo::Ex10_37()
{
	cout << "将 vector 中的3-7之间的元素逆序拷贝给lst2: " << endl;
	list<int> ist2;
	vector<int>::reverse_iterator itr = ivec.rbegin() + 3;
	vector<int>::reverse_iterator itl = ivec.rbegin() + 8;
	copy(itr, itl, back_inserter(ist2));
	copy(ist2.begin(), ist2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}

int main()
{
	Classfoo::Ex10_34();
	Classfoo::Ex10_35();
	Classfoo::Ex10_36();
	Classfoo::Ex10_37();

	
	
	system("pause");
	return 0;
}
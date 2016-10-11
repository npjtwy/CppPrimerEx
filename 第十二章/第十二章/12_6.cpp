#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using  namespace std;
namespace Classfoo
{
	
	vector<int>* alloc_vector(){
		vector<int>* p = new vector<int>;
		return p;
	}
	vector<int>* init_vector(vector<int>* &p){
		int num;
		while (cin >> num)
		{
			p->push_back(num);
		}
		return p;
	}
	void print_vector(vector<int>* &p){
		copy(p->begin(), p->end(), ostream_iterator<int>(cout, " ")); cout << endl;
		//打印完成后 释放内存
		if (p != nullptr)
		{
			delete p;
			p = nullptr;
		}
	}
	void Ex12_6()
	{
		vector<int>* ivec = nullptr;
		ivec = alloc_vector();
		ivec = init_vector(ivec);
		print_vector(ivec);
		cout << "yeah" << endl;
	}
}

int main()
{
	Classfoo::Ex12_6();
	
	system("pause");
	return 0;
}
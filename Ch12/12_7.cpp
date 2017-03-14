#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using  namespace std;
//adscasdcasdc
namespace Classfoo
{
	shared_ptr<vector<int>> init_vector(){
		auto p = make_shared<vector<int>>();
		int num;
		while (cin >> num)
		{
			p->push_back(num);
		}
		return p;
	}
	void print_vector(shared_ptr<vector<int>> &p){
		copy(p->begin(), p->end(), ostream_iterator<int>(cout, " ")); cout << endl;
	}
	void Ex12_7()
	{
		shared_ptr<vector<int>> data = init_vector();
		print_vector(data);
	}

}
bool b()
{
	int *p = new int;
	return p;
}
int main()
{
	Classfoo::Ex12_7();
	if (b()) cout << "yeah" << endl;
	system("pause");
	return 0;
}
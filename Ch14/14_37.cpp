#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using  namespace std;
template<typename T>
class Foo
{
public:
	Foo(T v) : value(v) {}
	bool operator()(T &rhs)
	{
		return (rhs == value);
	}
private:
	T value;

};

int main()
{
	{
		vector<string> ivec{ "1", "4", "6", "hello", "7", "9", "4", "90" };

		std::replace_if(ivec.begin(), ivec.end(), Foo<string>("hello"), "world");
		copy(ivec.begin(), ivec.end(), std::ostream_iterator<string>(std::cout, " "));
	}
	system("pause");
	return 0;
}
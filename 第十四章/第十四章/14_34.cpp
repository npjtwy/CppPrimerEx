#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using  namespace std;
class foo
{
public:
	const char * operator()(int a, const char *s1, const char *s2)
	{
		if (a > 0)
		{
			return s1;
		}
		else return s2;
	}
};

int main()
{
	foo f1;
	auto s = f1(-4, "yes", "No");
	std::cout << s << endl;
	system("pause");
	return 0;
}
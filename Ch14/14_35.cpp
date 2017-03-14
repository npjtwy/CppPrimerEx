#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using  namespace std;
class foo
{
public:
	std::string operator()(std::istream &is)
	{
		std::string str;
		
		if (!is)
		{
			std::string fails = "";
			return fails;
		}
		getline(is, str);		//用 getline 读取整行
		is >> str;
		return  str;
	}
private:
};

int main()
{
	foo f1;
	std::string ret = f1(std::cin);
	std::cout << ret << std::endl;
	
	system("pause");
	return 0;
}
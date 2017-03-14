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
		getline(is, str);		//用 getline 读取整行
		return  is ? str : std::string();
	}
private:
};

int main()
{
	foo f1;
	std::string ret;
	vector<std::string> vs;
	for (ret; !(ret = f1(std::cin)).empty();)
	{
		vs.push_back(ret);
	}
	for (const auto& str : vs) std::cout << str << " ";
	system("pause");
	return 0;
}
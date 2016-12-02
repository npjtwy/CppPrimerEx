#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

//! this class is a simulation for class Query used to answer ex15.32
class Foo
{
public:
	Foo(const std::vector<std::string>& t) :
		text(new std::vector<std::string>(t)) { }

private:
	std::shared_ptr<std::vector<std::string>> text;

};
int main()
{
	std::vector<std::string> v = { "alan","alan","alan","alan","alan" };

	Foo foo(v);

	Foo bar = std::move(foo);

	system("pause");
	return 0;
}


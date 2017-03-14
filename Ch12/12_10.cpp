#include <iostream>
#include <vector>
#include <string>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
	//ptr 是 p 的一个拷贝 此时 p 的引用计数为2
	std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main()
{
	std::shared_ptr<int> p(new int(42));
	process(std::shared_ptr<int>(p));
	// 函数执行完毕后 p 的引用计数减一 变为 1
	/**
	* codes below shows how the reference count change.
	*/
	std::cout << p.use_count() << "\n";
	auto q = p;
	std::cout << p.use_count() << "\n";
	std::cout << "the int p now points to is:" << *p << "\n";
	system("pause");
	return 0;
}
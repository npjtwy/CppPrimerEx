#include <iostream>
#include <vector>
#include <string>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
	//ptr �� p ��һ������ ��ʱ p �����ü���Ϊ2
	std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main()
{
	std::shared_ptr<int> p(new int(42));
	process(std::shared_ptr<int>(p));
	// ����ִ����Ϻ� p �����ü�����һ ��Ϊ 1
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
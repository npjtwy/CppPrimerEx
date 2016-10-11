#include <iostream>
#include <vector>
#include <string>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
	//ptr  和 p 指向了同一块内存
	std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main()
{
	std::shared_ptr<int> p(new int(42));

	/**
	* @brief   std::shared_ptr<int>(p.get()) construct a temporary shared_ptr
	* and copy it
	*          to the parameter.However it is not a copy of p. As a result, at
	* end of this
	*          main function p will free the memory that has been freed inside
	* process ().
	*          That's why "double freed or corruption" was generated.
	*/
	process(std::shared_ptr<int>(p.get()));

	//std::cout << p.use_count() << std::endl;  函数 process 执行完毕后 p 所指向的内存已经被释放了

	return 0;
}
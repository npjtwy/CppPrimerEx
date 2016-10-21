#include "StrBlob.h"
#include <iostream>

int main()
{
    const StrBlob csb{"hello", "world", "pezy"};
    StrBlob sb{"hello", "world", "Mooophy"};

    std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.back() = "pezy";
    std::cout << sb.front() << " " << sb.back() << std::endl;
	std::cout << (sb == csb ? "yes" : "no") << std::endl;

	std::cout << csb[2] << std::endl;

	StrBlob a1 = { "he", "she" , "now" };
	StrBlobPtr p(a1);  //p指向 a1 中的 vector
	*p = "hello";
	std::cout << p->size() << std::endl;
	std::cout << *p << std::endl;

	
    system("pause");
		return 0;
}

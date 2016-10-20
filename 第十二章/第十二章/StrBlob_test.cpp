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
    system("pause");
		return 0;
}

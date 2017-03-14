
#include "StrVec.h"
#include <iostream>
StrVec getSv(std::istream &is)
{
	std::string str;
	is >> str;
	StrVec sv{str};
	return sv;
}
int main()
{

	{
		StrVec sv{ "hell", "string" };
		sv.push_back("niam");
		StrVec sv1 = sv;
		StrVec sv2 = std::move(sv);
		StrVec sv3 = getSv(std::cin);
		StrVec sv4 = { "hell", "string", "niam" };
		if (sv1 == sv4)
		{
			std::cout << "yes" << std::endl;
		}
	}

	system("pause");
	return 0;
}
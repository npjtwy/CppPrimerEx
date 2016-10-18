
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

	}

	system("pause");
	return 0;
}
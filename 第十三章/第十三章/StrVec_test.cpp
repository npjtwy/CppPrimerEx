
#include "StrVec.h"
#include <iostream>

int main()
{
	{
		StrVec sv{ "hell", "string" };
		sv.push_back("niam");
		sv.resize(5, "aa");
		for (auto i : sv)
		{
			std::cout << i << std::endl;
		}
	}

	system("pause");
	return 0;
}
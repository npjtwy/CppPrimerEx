#include "iostream"
#include <string>

std::istream& read(std::istream& is)
{
	std::string i ;

	while (is >> i)
	{
	}
	std::cout << i << std::endl;   
	is.clear();       //ÖÃÎªÔ­ÓÐ×´Ì¬
	return is;
}
#include <iostream>

class numbered {
public:
	numbered()
	{
		static int unique = 10;
		mysn = unique++;
	}

	numbered(const numbered& n) { mysn = n.mysn + 1; std::cout <<" numbered(const numbered& n) " << std::endl; }

	int mysn;
};

void f(const numbered& s)
{
	std::cout << s.mysn << std::endl;
}

int main4()
{
	numbered a, b = a, c = b;
	std::cout << "开始调用" << std::endl;
	f(a);
	f(b);
	f(c);
	system("pause");
	return 0;
}
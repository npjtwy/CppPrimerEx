#include "iostream"
#include <string>

using  namespace std;

int have_cap(const string & s)
{
	for (const auto & i : s)
	{
		if (i >= 'A' && i <= 'Z')
		{
			return 1;
		}
	}

	return 0;
}

void s_tolower(string & s)
{
	for (auto & ch : s)
	{
		if (ch >= 'A' && ch <= 'Z')
		{
			ch = tolower(ch);
		}
	}
}


void main()
{
	string str;
	cin >> str;
	int ret = have_cap(str);

	cout << ret << endl;
	
	s_tolower(str);
	cout << str << endl;

	system("pause");
}
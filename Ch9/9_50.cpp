#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
using  namespace std;

void Ex9_50()
{
	vector<string> siv = { "123", "345", "567", "678" };
	float sum = 0.0;
	for (auto &i : siv)
	{
		sum += stof(i);
	}
	cout << sum << endl;

}

int main()
{
	Ex9_50();
	
	system("pause");
	return 0;
}
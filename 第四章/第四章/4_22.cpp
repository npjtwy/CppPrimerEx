#include "iostream"
#include <string>

using  namespace std;

void main()
{
	string finalgrade;
	int grade = 80;

	finalgrade = (grade > 90) ? "high pass" : (grade > 60 && grade < 75) ? "low pass" : (grade > 60) ? "pass" : "fail";
	cout << finalgrade << endl;

	if (grade > 90)
	{
		finalgrade = "high pass";
	}
	else if ( grade > 60 && grade < 75)
	{
		finalgrade = "low pass";
	}
	else if (grade >= 60)
	{
		finalgrade = "pass";
	}
	else
	{
		finalgrade = "fail";
	}

	cout << finalgrade << endl;
	system("pause");
}
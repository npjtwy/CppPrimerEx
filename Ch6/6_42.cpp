#include "iostream"
#include <string>

using  namespace std;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
	return (ctr == 1) ? word + ending : word;
}

void main()
{
	string succ_s;
	string fal_s;

	succ_s = make_plural(1, "success", "es");
	fal_s = make_plural(1, "failure");

	cout << succ_s << endl;
	cout << fal_s << endl;

	system("pause");
}
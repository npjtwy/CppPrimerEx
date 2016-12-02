#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
using  namespace std;

int main()
{
	using std::placeholders::_1;
	std::vector<int> ivec{ 1,2,34563,4,342,54675,56,1024,56 };
	int count = count_if(ivec.begin(), ivec.end(), std::bind(greater<int>(), _1, 1024));

	cout << count << endl;

	std::vector<string> svec{ "pooh","pooh","pooh","hellp", "pooh","world", "pooh" };
	auto count1 = find_if(svec.begin(), svec.end(), std::bind(not_equal_to<string>(), _1, "pooh"));
	cout << *count1 << endl;
	std::vector<int> ivec2;
	std::transform(ivec.begin(), ivec.end(),back_inserter(ivec2), std::bind(multiplies<int>(), _1, 2));
	for (auto i : ivec2)
	{
		cout << i << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
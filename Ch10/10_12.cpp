#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
#include <algorithm>
using  namespace std;
//class Sales_data
class Sales_data
{
	/*friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
	friend Sales_data add(const Sales_data&, const Sales_data&);*/
	friend std::istream& read(std::istream&, Sales_data&);

public:
	//���캯��
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p * n)
	{
		std::cout << "������ί��" << std::endl;
	}

	//ί�й��캯��
	Sales_data() : Sales_data("", 0, 0) { std::cout << "Sales_data()ί��" << std::endl; }

	Sales_data(std::string s) : Sales_data(s, 0, 0)
	{
		std::cout << "Sales_data(std::string s)ί��" << std::endl;
	}

	Sales_data(std::istream &is) : Sales_data()
	{
		read(is, *this);
		std::cout << "Sales_data(std::istream &is)ί��" << std::endl;
	}

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
//=============================================================
bool compareIsbn(const Sales_data &s1, const Sales_data &s2)
{
	return s1.isbn().size() < s2.isbn().size();
}
bool compareletter(const Sales_data &s1, const Sales_data &s2)
{
	return s1.isbn() < s2.isbn();
}
void sortSaleData(vector<Sales_data>& sdvec)
{
	sort(sdvec.begin(), sdvec.end(), compareletter);
	stable_sort(sdvec.begin(), sdvec.end(), compareIsbn);
	for (auto &i : sdvec)
	{
		cout << i.isbn() <<" ";
	}
	cout << endl;
}
int main()
{
	Sales_data s1("100200-x-110");
	Sales_data s2("1002110");
	Sales_data s3("1020-x");
	Sales_data s4("200200-x-110");
	Sales_data s5("200-x-1");

	vector<Sales_data> sdvec;
	sdvec.push_back(s1);
	sdvec.push_back(s2);
	sdvec.push_back(s3);
	sdvec.push_back(s4);
	sdvec.push_back(s5);

	sortSaleData(sdvec);
	system("pause");
	return 0;
}
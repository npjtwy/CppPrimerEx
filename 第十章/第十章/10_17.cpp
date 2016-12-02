#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
#include <algorithm>
using  namespace std;
/*
	Ex10_17 �� lambda ��10_12�ĳ�����д
*/
//class Sales_data
class Sales_data
{
public:
	//���캯��
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p * n) {}
	//ί�й��캯��
	Sales_data() : Sales_data("", 0, 0) { ; }
	Sales_data(std::string s) : Sales_data(s, 0, 0){}
	std::string isbn() const { return bookNo; }
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
//=============================================================

void sortSaleData(vector<Sales_data>& sdvec)
{
	//�ȶ�isbn �����ֵ�����
	sort(sdvec.begin(), sdvec.end(),
		[](const Sales_data &s1, const Sales_data &s2) {return s1.isbn() < s2.isbn(); });
	//�� ���ճ�������
	stable_sort(sdvec.begin(), sdvec.end(),
		[](const Sales_data &s1, const Sales_data &s2) {return s1.isbn().size() < s2.isbn().size(); });

	for_each(sdvec.begin(), sdvec.end(), [](const Sales_data &s) {cout << s.isbn() << endl; });
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
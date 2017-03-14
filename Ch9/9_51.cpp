#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <vector>
using  namespace std;

class Myclass
{
public:
	Myclass(const string&);
	int stoint(string &);
	void GetData();
private:
	unsigned m_year;
	unsigned m_month;
	unsigned m_day;
};

int Myclass::stoint(string &month)//用来转换月份的表示
{
	string numbers = "1234567890";
	//如果月份是数字形式的字符串 则直接转换成 int 型
	if (month.find_first_of(numbers) != month.npos) return stoi(month);
	//将月份的英文表示 转换成对应对 int 型月份
	vector<string> mon = { "January", "February", "March", "April", "May",
		"June", "July", "September", "October", "November", "December" };
	int m = 1;
	for (auto& i : mon)
	{
		if (i.find(month) != i.npos)	return m;
		else ++m;
	}
}

Myclass::Myclass(const string &str)
{
	string::size_type pos,pos2;
	string intrup = " .//,";
	string month;
	string numbers = "1234567890";
	pos = str.find_first_of(intrup);	//记录第一个分隔符号的位置
	month = str.substr(0, pos);  //从str中截取表示月份的子串
	m_month = stoint(month);	//处理月份子串
	++pos;	
	pos2 = str.find_first_of(intrup, pos); //第二个分隔符号位置
	m_day = stoi(str.substr(pos, pos2 - pos));	//取两个分隔符号中间为 day 子串
	++pos2;
	m_year = stoi(str.substr(pos2));  //从第二个分隔符 到结束为 year 子串
}

void Myclass::GetData()
{
	cout << m_month << "-" << m_day << "-" << m_year << endl;
}
int main()
{
	Myclass mydata("Mar/23/2003");
	mydata.GetData();
	system("pause");
	return 0;
}
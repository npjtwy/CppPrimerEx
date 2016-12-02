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

int Myclass::stoint(string &month)//����ת���·ݵı�ʾ
{
	string numbers = "1234567890";
	//����·���������ʽ���ַ��� ��ֱ��ת���� int ��
	if (month.find_first_of(numbers) != month.npos) return stoi(month);
	//���·ݵ�Ӣ�ı�ʾ ת���ɶ�Ӧ�� int ���·�
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
	pos = str.find_first_of(intrup);	//��¼��һ���ָ����ŵ�λ��
	month = str.substr(0, pos);  //��str�н�ȡ��ʾ�·ݵ��Ӵ�
	m_month = stoint(month);	//�����·��Ӵ�
	++pos;	
	pos2 = str.find_first_of(intrup, pos); //�ڶ����ָ�����λ��
	m_day = stoi(str.substr(pos, pos2 - pos));	//ȡ�����ָ������м�Ϊ day �Ӵ�
	++pos2;
	m_year = stoi(str.substr(pos2));  //�ӵڶ����ָ��� ������Ϊ year �Ӵ�
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
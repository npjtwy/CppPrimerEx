#define _CRT_SECURE_NO_WARNINGS
#include "Has_Ptr.h"
using  namespace std;

HasPtr::HasPtr(const HasPtr &has)
{
	ps = new string(*has.ps);
	i = has.i;
}
HasPtr& HasPtr::operator=(const HasPtr&has)
{
	auto newp = new string(*has.ps);		//ͨ������ newp �����ڿ��������쳣ʱ��֤��ǰ����İ�ȫ
	if (ps != nullptr)
	{
		delete ps;
		ps = newp;
	}					            	//����ֵ�������������Լ����Լ���ֵʱ ˵����ֵ�����ǰ�ȫ
	
	else  ps = newp;
	i = has.i;
	newp = nullptr;
	return *this;
}
HasPtr::~HasPtr()
{
	if (ps != NULL)
	{
		delete ps;
		ps = NULL;
	}
}

bool operator<(const HasPtr& lhs, const HasPtr& rhs) 
{
	if (*lhs.ps < *rhs.ps)
		return true;
	else
	{
		return false;
	}
}

void HasPtr::print()
{
	cout << *ps << " " << i << endl;

}

/*
class Foo
{
public:
protected:
private:
	HasPtr h;
};

void swap(Foo &lhs, Foo &rhs)
{
	using std::swap;
	swap(lhs, rhs);			//����using std::swap ����Ϊ ����HasPtr û�ж����Լ���swap���� ������std::swap
							// ��� HasPtr �������Լ��� swap ������ HasPtr �� swap ����
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using  namespace std;
/* �������ü�������HasPtr */
class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new size_t(1)) { }
	HasPtr(const HasPtr &obj);
	HasPtr& operator=(const HasPtr&obj);
	~HasPtr();
private:
	std::string *ps;
	int			i;
	size_t		*use;	//���ü���
};
HasPtr::HasPtr(const HasPtr& obj)
{
	ps = obj.ps;
	i = obj.i;
	++*obj.use;		//�������ü���
	use = obj.use;
}
HasPtr::~HasPtr()
{
	if (--*use == 0)		//���ü���Ϊ0 �ͷ��ڴ�
	{
		if (ps) {
			delete ps; ps = nullptr;
	}
	delete use;
	use = nullptr;
}
HasPtr& HasPtr::operator=(const HasPtr& obj)
{
	++*obj.use;			//�����Ӹ�ֵ�Ⱥ��ұ߶�������ü���
	--*use;				//�ݼ���ߵ����ü���
	if (*use == 0)
	{
		if(ps) delete ps;
	}
	delete use;
	ps = obj.ps;
	i = obj.i;
	use = obj.use;
	return *this;
}

int main()
{


	system("pause");
	return 0;
}
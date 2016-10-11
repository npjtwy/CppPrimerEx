#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory>
#include <vector>
const int n = 5;
using  namespace std;
namespace Classfoo
{
/*
	void func() {
		// allocator ��ز���
		
		allocator<string> alloc; 
		auto const p  = alloc.allocate(n);		//���� 5 ��δ��ʼ���� string 

		//allocator �������δ������ڴ� ʹ�� construct ��Ա����������Ԫ��
		auto q = p;
		alloc.construct(q++);		// *q Ϊ���ַ���
		alloc.construct(q++, 10, 'c');		// *q Ϊ cccccccccc

		//�� destroy ���ٹ����Ԫ��
		while (q != p)
		{
			alloc.destroy(--q);			//��ʼʱ q ָ��������һ��Ԫ��֮���λ��
		}

		//�� deallocate �ͷ��ڴ�
		alloc.deallocate(p, n);			//��������ڴ� �ͷŶ���

		// ���δ��ʼ�����ڴ�
		vector<int> iv{ 10, 2 };
		allocator<int> alloc1;
		//�ȷ����iv ��һ�����ڴ�
		auto pp = alloc1.allocate(iv.size() * 2);
		//����iv�е�Ԫ�� �� p ��ʼ��λ�ý������
		auto qq = uninitialized_copy(iv.begin(), iv.end(), pp);
		//ʣ�µĿռ��� 42 �������
		uninitialized_copy_n(qq, iv.size(), 42);
	}*/
	void Ex12_26()
	{
		allocator<string> alloc_str;
		auto p = alloc_str.allocate(n);
		auto q = p;
		string s;
		int cnt = n;
		//�����ַ���Ԫ��
		while (cin >> s && cnt > 0)
		{
			alloc_str.construct(q++, s);
			cnt--;
		}
		q = p;
		cnt = n;
		// ��ӡ�ַ���
		while (cnt > 0)
		{
			cout << *q << " ";
			alloc_str.destroy(q++);		//��ӡ�� Ȼ������
			cnt--;
		}
		// ����ͷ��ڴ�ռ�
		alloc_str.deallocate(p, n);
	}

}

int main()
{
	Classfoo::Ex12_26();
	
	system("pause");
	return 0;
}
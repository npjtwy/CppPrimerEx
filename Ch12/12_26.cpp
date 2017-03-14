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
		// allocator 相关操作
		
		allocator<string> alloc; 
		auto const p  = alloc.allocate(n);		//分配 5 个未初始化的 string 

		//allocator 分配的是未构造的内存 使用 construct 成员函数来构造元素
		auto q = p;
		alloc.construct(q++);		// *q 为空字符串
		alloc.construct(q++, 10, 'c');		// *q 为 cccccccccc

		//用 destroy 销毁构造的元素
		while (q != p)
		{
			alloc.destroy(--q);			//开始时 q 指向构造的最后一个元素之后的位置
		}

		//用 deallocate 释放内存
		alloc.deallocate(p, n);			//分配多少内存 释放多少

		// 填充未初始化的内存
		vector<int> iv{ 10, 2 };
		allocator<int> alloc1;
		//先分配比iv 大一倍的内存
		auto pp = alloc1.allocate(iv.size() * 2);
		//拷贝iv中的元素 从 p 开始的位置进行填充
		auto qq = uninitialized_copy(iv.begin(), iv.end(), pp);
		//剩下的空间用 42 进行填充
		uninitialized_copy_n(qq, iv.size(), 42);
	}*/
	void Ex12_26()
	{
		allocator<string> alloc_str;
		auto p = alloc_str.allocate(n);
		auto q = p;
		string s;
		int cnt = n;
		//构造字符串元素
		while (cin >> s && cnt > 0)
		{
			alloc_str.construct(q++, s);
			cnt--;
		}
		q = p;
		cnt = n;
		// 打印字符串
		while (cnt > 0)
		{
			cout << *q << " ";
			alloc_str.destroy(q++);		//打印完 然后销毁
			cnt--;
		}
		// 最后释放内存空间
		alloc_str.deallocate(p, n);
	}

}

int main()
{
	Classfoo::Ex12_26();
	
	system("pause");
	return 0;
}
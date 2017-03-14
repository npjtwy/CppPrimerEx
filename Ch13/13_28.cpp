#define _CRT_SECURE_NO_WARNINGS?#include <iostream>?#include <string>?#include <vector>?#include <algorithm>?using  namespace std;?class TreeNode?{?public:?	TreeNode() : value(string()), count(new int(1)), left(nullptr) ,right(nullptr) {}?	TreeNode(const TreeNode& t)?	{?		++*t.count;?		value = t.value;?		count = t.count;?		left = t.left;?		right = t.right;?	}?	TreeNode& operator=(const TreeNode& rhs)?	{?		++*rhs.count;?		if (--*count == 0) {?			if (left) {?				delete left;?			}?			if (right) {?				delete right;?			}?		}?		count = rhs.count; left = rhs.left; right = rhs.right; value = rhs.value;?	}?	~TreeNode()?	{?		if (--*count == 0) {?			if (left) {?				delete left;?				left = nullptr;?			}?			if (right) {?				delete right;?				right = nullptr;?			}?		}?		delete count;?		count = nullptr;?	}?private:?	std::string		value;?	int				*count;?	TreeNode		*left;?	TreeNode		*right;?};??class BinStrTree?{?public:?	BinStrTree() : root(new TreeNode()){}?	BinStrTree(const BinStrTree& bt)?	{?		root = new TreeNode(*bt.root);?	}?	BinStrTree& operator=(const BinStrTree& rbt)?	{?		auto newroot = new TreeNode(*rbt.root);?		delete root;?		root = newroot;?		return *this;?	}?	~BinStrTree() {?		delete root;?	}?private:?	TreeNode *root;?};?int main()?{?	?	system("pause");?	return 0;?}
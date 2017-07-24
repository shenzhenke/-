#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <string>
#include <vector>
class Person
{
public:
	void Display()
	{
		cout << _name << endl;
	}
private:
	string _name;
};
class Student :public Person
{
public:
	int _num;
};


class A
{
public:
	virtual void f1()
	{
		cout << "A::f1()" << endl;
		cout << endl;
	}
	virtual void f2()
	{
		cout << "A::f2()" << endl;
		cout << endl;
	}
	int _a;
};

class B :virtual public A
{
public:
	virtual void f1()
	{
		cout << "B::f1()" << endl;
		cout << endl;
	}
	virtual void f3()
	{
		cout << "B::f3()" << endl;
		cout << endl;
	}

	int _b;
};

class C :virtual public A
{
public:
	virtual void f1()
	{
		cout << "C::f1()" << endl;
		cout << endl;
	}
	virtual void f4()
	{
		cout << "C::f4()" << endl;
		cout << endl;
	}
	int _c;
};

class D :public B, public C
{
public:
	virtual void f1()
	{
		cout << "D::f1()" << endl;
		cout << endl;
	}

	virtual void f5()
	{
		cout << "D::f5()" << endl;
		cout << endl;
	}

	int _d;
};

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x)
		:val(x)
		, left(NULL)
		, right(NULL) 
	{}
};
class Solution 
{
public:
	bool IsBalanced_Solution(TreeNode* pRoot) 
	{
		return _IsBalanced_Solution(pRoot);
	}
	void Mirror(TreeNode *pRoot) 
	{
		_Mirror(pRoot);
		return;
	}
private:
	void _Mirror(TreeNode *root)
	{
		if (root == NULL)
			return;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		root->left = right;
		root->right = left;
		_Mirror(root->left);
		_Mirror(root->right);
		return;
	}
	bool _IsBalanced_Solution(TreeNode* root)
	{
		if (root == NULL)
			return true;
		int leftDepth = Depth(root->left);
		int rightDepth = Depth(root->right);
		if (abs(leftDepth - rightDepth) > 1)  //高度差大于1就不是平衡树
		{
			return false;
		}
		return _IsBalanced_Solution(root->left) && _IsBalanced_Solution(root->right);
	}
	int Depth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int leftDepth = Depth(root->left) + 1;
		int rightDepth = Depth(root->right) + 1;
		return leftDepth > rightDepth ? leftDepth : rightDepth;
	}
};

//二维数组的查找,右上角开始查找,每一行采用二分查找（m*n）
bool Find(int target, vector<vector<int> > array) 
{
	if (array.size() == 0 || array[0].size() == 0)
		return false;
	size_t m = array.size();
	size_t n = array[0].size();
	for (size_t i = 0; i < m; i++)
	{
		if (array[i][n - 1] < target)
			;  //该行最大的数据都小于要查找的数据，证明不存在
		else   //否则进行二分查找
		{
			int left = 0;
			int right = n - 1;
			while (left <= right)
			{
				int mid = (right - left) / 2 + left;
				if (array[i][mid] > target)
					right = mid - 1;
				else if (array[i][mid] < target)
					left = mid + 1;
				else
					return true;
			}
		}
	}
	return false;
}


int main()
{

	return 0;
}
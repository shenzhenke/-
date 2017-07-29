#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <stack>
#include <vector>
#include <mutex>
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x)
		: val(x)
		, left(NULL)
		, right(NULL)
	{}
};

//二叉搜索树树变成排序的双向链表, 中序线索化的变形
//void _Convert(TreeNode*  root,TreeNode*& prev)
//{
//	if (root == NULL)
//		return ;
//	_Convert(root->left, root);
//	prev->right = root;
//	root->left = prev;
//	_Convert(root->right, root);
//}
//TreeNode* Convert(TreeNode* pRootOfTree)
//{
//
//	TreeNode* prev = NULL;
//	_Convert(pRootOfTree, prev);
//	while (pRootOfTree&&pRootOfTree->left != NULL)
//	{
//		pRootOfTree = pRootOfTree->left;
//	}
//	return pRootOfTree;
//}
	
TreeNode* Convert(TreeNode* pRootOfTree)
{
	typedef TreeNode Node;
	if (pRootOfTree == NULL)
		return NULL;
	stack<Node*> s;
	vector<Node*> v;
	v.push_back(NULL);
	Node* cur = pRootOfTree;
	while (cur != NULL || !s.empty())
	{
		while (cur != NULL)
		{
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		v.push_back(cur);
		s.pop();
		cur = cur->right;
	}
	v.push_back(NULL);
	for (size_t i = 1; i < v.size() - 1; i++)
	{
		v[i]->right = v[i + 1];
		v[i]->left = v[i - 1];
	}
	return v[1];
}


//懒汉模式,类加载时不初始化,要用的时候才初始化，延时加载，实现较复杂
class Lock
{
public:
	explicit Lock(mutex& mtx)  //加锁,加explicit防止被隐式类型转换  
		:_mtx(mtx)
	{
		_mtx.lock();
	}
	~Lock()  //解锁  
	{
		_mtx.unlock();
	}
private:
	mutex& _mtx;
	Lock(Lock&);
	Lock& operator=(Lock&);
};
class Singleton
{
public:
	static Singleton* GetInstance();
protected:
	Singleton()
		:_a(0)
	{}
	Singleton(Singleton&);
	Singleton& operator=(Singleton&);
private:
	int _a;
	static Singleton* _inst;
};
Singleton*  Singleton::_inst = NULL;
Singleton* Singleton::GetInstance()
{
	mutex mtx;
	Lock a(mtx);
	if (_inst == NULL)
	{
		_inst = new Singleton();
	}
	return _inst;
}

//懒汉模式,一上来就初始化，类加载较慢，占用系统资源，但是使用时获取对象的速度快，实现简单
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return _inst;
	}
protected:
	Singleton()
		:_a(0)
	{}
private:
	int _a;
	static Singleton* _inst;
};

Singleton* Singleton::_inst = new Singleton();
int main()
{
	return 0;
}
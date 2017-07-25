#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//using namespace std;
//typedef void(*FUN) ();  //定义一个函数指针来实现对成员函数的继承
//struct _A
//{
//	int _a;
//	FUN _fun;  
//};
//struct _B
//{
//	_A _a;	//子类中定义一个父类对象实现继承
//	int _b;
//};
//void _fA()	//父类同名函数
//{
//	printf("A::FUN()\n");
//}
//void _fB()	//子类同名函数
//{
//	printf("B::FUN()\n");
//}
//
//class A
//{
//public:
//	int  _a;
//	virtual void f1()
//	{}
//	virtual void f3()
//	{}
//};
//
//class B :public A
//{
//public:
//	int _b;
//	virtual void f1()
//	{}
//	void f2()
//	{}
//};
////class C :public A
////{
////public:
////	int _c;
////	virtual void f2()
////	{}
////};
////class D :public B, public C
////{
////public:
////	int _d;
////	virtual void f1()
////	{}
////	virtual void f4()
////	{}
////};
//
//
//
//class Base
//{
//public:
//	virtual void func1()
//	{
//		cout << "Base::func1" << endl;
//	}
//
//	virtual void func2()
//	{
//		cout << "Base::func2" << endl;
//	}
//
//	/*virtual ~Base()
//	{
//		cout << "~Base" << endl;
//	}*/
//
//private:
//	int a;
//};
//
//class Derive :public Base
//{
//public:
//	virtual void func1()
//	{
//		cout << "Derive::func1" << endl;
//	}
//	//virtual ~Derive()
//	//{
//	//	cout << "~Derive" << endl;
//	//}
//private:
//	int b;
//};
//
//void Test1()
//{
//	Base* q = new Derive;
//	Base* p = new Base;
//	delete q;
//}
//
//
//int main()
//{
//	_A a;
//	_B b;
//	a._fun = _fA;  //将结构体中的函数指针初始化
//	b._a._fun = _fB;
//
//	_A* ptr = &a;
//	ptr->_fun();
//	ptr = (_A*)&b;
//	//ptr->_fun();
//	//D d;
//	//d.B::_a = 1;
//	//d._b = 2;
//	//d._c = 3;
//	//d._d = 4;
//	//
//	//B c;
//	//c._a = 1;
//	//c._b = 2;
//	//Test1();
//	return 0;
//}


#include <iostream>
using namespace std;
#include <stack>
#include <queue>
#include <unordered_map>
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

//前序非递归
void PrevOrder(TreeNode* root)
{
	if (root = NULL)
		return;
	stack<TreeNode*> s;
	TreeNode* cur = root;
	while (!s.empty() || cur != NULL)
	{
		while (cur != NULL)
		{
			cout << cur->val << " ";
			s.push(cur);
			cur = cur->left;
		}
		//访问右子树,并重新生成子问题
		cur = s.top();
		cur = cur->right;
		s.pop();
	}
	cout << endl;
	return;
}

//中序非递归
void InOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	stack<TreeNode*> s;
	TreeNode* cur = root;
	while (!s.empty() || cur != NULL)
	{
		while (cur != NULL)
		{
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		cout << cur->val << " ";
		s.pop();
		cur = cur->right;
	}
	return;
}

//后序非递归

void PostOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	stack<TreeNode*> s;
	TreeNode* cur = root;
	TreeNode* prev = NULL;
	while (!s.empty() || cur != NULL)
	{
		while (cur != NULL)
		{
			s.push(cur);
			cur = cur->left;
		}
		TreeNode* front = s.top();
		if (front->right == NULL || prev == front->right)
		{
			cout << front->val << " ";
			prev = front;
			s.pop();
		}
		else
		{
			cur = front->right;
		}
	}
	return;
}


//链表结点的结构类型定义如下：

struct node
{
	int elem;
	node* next;
	node(int x)
		:elem(x)
		, next(NULL)
	{}
};
//请完成函数
void difference(node*& LA, node* LB)
{
	if (LA == NULL || LB == NULL)
		return;
	node* cur = LA;
	node* compare = LB;
	queue<node*> q;
	while (cur != NULL)
	{
		while (compare != NULL&&cur->elem != compare->elem)
		{
			compare = compare->next;
		}
		if (compare == NULL)  //证明集合LA中的元素LB没有
		{
			q.push(cur);
			cur = cur->next;
		}
		else
		{
			node* del = cur;
			cur = cur->next;
			delete del;
			del = NULL;
		}
		compare = LB;
	}
	LA = q.front();
	cur = LA;
	q.pop();
	while (!q.empty())
	{
		cur->next = q.front();
		q.pop();
		cur = cur->next;
	}
	cur->next = NULL;
}

int main()
{
	node* LA = new node(5);
	node* LA1 = new node(10);
	node* LA2 = new node(20);
	node* LA3 = new node(15);
	node* LA4 = new node(30);
	node* LA5 = new node(25);
	LA->next = LA1;
	LA1->next = LA2;
	LA2->next = LA3;
	LA3->next = LA4;
	LA4->next = LA5;

	node* LB = new node(5);
	node* LB1 = new node(15);
	node* LB2 = new node(35);
	node* LB3 = new node(25);
	LB->next = LB1;
	LB1->next = LB2;
	LB2->next = LB3;
	difference(LA, LB);
	while (LA != NULL)
	{
		cout << LA->elem << " ";
		LA = LA->next;
	}
	cout << endl;
	return 0;
}
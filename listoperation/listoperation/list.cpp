﻿#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stack>
using namespace std;
struct ListNode
{
	ListNode* _next;
	int _value;
	ListNode(int value)
		:_next(NULL)
		, _value(value)
	{
	}
};

class List
{
	typedef ListNode Node;
public:
	List()
		:_head(NULL)
	{
	}
	Node* Push_back(int value)
	{
		if (_head == NULL)
		{
			_head = new Node(value);
			return _head;
		}
		Node* cur = _head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		Node* newNode = new Node(value);
		cur->_next = newNode;
		return newNode;
	}
	void Print()
	{
		Node* cur = _head;
		while (cur != NULL)
		{
			cout << cur->_value << " ";
			cur = cur->_next;
		}
		cout << endl;
	}
	~List()
	{
		while (_head != NULL)
		{
			Node* del = _head;
			_head = _head->_next;
			del->_next = NULL;
			delete del;
			cout << "del" << " ";
		}
		cout << endl;
	}

	//找倒数第K个结点
	Node* findLastKthNode(int lastKth)
	{
		int lastNodeIndex = 0;
		//如果倒数第K个结点不在所表示的位置超过链表的长度或小于链表的长度以返回NULL表示
		Node* lastKthNode = NULL;
	    _findLastKthNode(_head, lastKth,lastNodeIndex,lastKthNode);
		return lastKthNode;
	}
	void _findLastKthNode(Node* cur, int lastKth,int &lastNode,Node* &lastKthNode)
	{
		if (cur == NULL)
			return;
		_findLastKthNode(cur->_next, lastKth, lastNode, lastKthNode);
		lastNode++;
		if (lastNode == lastKth)
			lastKthNode = cur;
		return;
	}

	//逆置链表
	Node* reverseList()
	{
		if (_head == NULL || _head->_next == NULL)
			return _head;
		Node* cur = _head;
		Node* next = NULL;
		Node* prev = NULL;
		while (_head != NULL)
		{
			cur = _head;
			next = cur->_next;
			cur->_next = prev;
			prev = cur;
			if (next == NULL)
				break;
			_head = next;
		}
		return _head;
	}



	void removeLastKthNode(int lastKth)  //删除倒数第K个结点
	{
		Node* cur = _head;
		stack<Node*> s;
		int count = 0;
		while (cur != NULL)
		{
			s.push(cur);
			cur = cur->_next;
		}
		if (s.empty() == true)
			return;
		if (s.size() == lastKth)
		{
			Node* del = _head;
			_head = _head->_next;
			del->_next = NULL;
			delete del;
			return;
		}
		Node* next = NULL;
		while (!s.empty() && --lastKth)
		{
			next = s.top();
			s.pop();
		}
		if (lastKth > 0)
			return;
		Node* del = s.top();
		s.pop();
		cur = s.top();
		cur->_next = next;
		del->_next = NULL;
		delete del;
		return;
	}

	void removeMidNode()  //删除中间结点 采用快慢指针
	{
		if (_head == NULL || _head->_next == NULL)
			return;
		if (_head->_next->_next == NULL)
		{
			Node* del = _head;
			_head = _head->_next;
			del->_next = NULL;
			delete del;
			return;
		}
		Node* prev = _head;
		Node* cur = _head->_next->_next;
		while (cur->_next != NULL&&cur->_next->_next != NULL)
		{
			prev = prev->_next;
			cur = cur->_next->_next;
		}
		Node* del = prev->_next;
		prev->_next = prev->_next->_next;
		del->_next = NULL;
		delete del;
		return;
	}


	//返回环的长度和环的入口结点
	pair<ListNode*,int> EntryNodeOfLoop(ListNode* pHead)
	{
		Node* slow = pHead;
		Node* fast = pHead;
		Node* None = NULL;
		int count = 0;
		while (slow != NULL && fast->_next != NULL)
		{
			//利用快慢指针判环
			slow = slow->_next;
			fast = fast->_next->_next;
			if (fast == slow) //证明有环
			{
				//将快慢指针任意一个从头结点开始走,二者按一步一节点的速度相遇就是环的入口点
				slow = pHead;
				while (slow != fast)
				{
					slow = slow->_next;
					fast = fast->_next;
				}
				while (slow->_next != fast)
				{
					count++;
					slow = slow->_next;
				}
				return make_pair(fast, count + 1);
			}
		}
		return make_pair(None,0);
	}

private:
	Node* _head;
};

class Solution {
public:
	int Add(int num1, int num2)
	{
		//&取相同位，左移一位代表相加,^取不同位 
		while (num2 != 0)
		{
			int sum = (num1^num2);
			num2 = ((num1&num2) << 1);
			num1 = sum;
		}
		return num1;
	}
};
void TestList()
{
	//Solution a;
	//cout << a.Add(10, 9) << endl;
	List l;
	ListNode* pHead=l.Push_back(1);
	l.Push_back(2);
	l.Push_back(3);
	ListNode* first = l.Push_back(4);
	l.Push_back(5);
	l.Push_back(6);
	l.Push_back(7);
	ListNode* second = l.Push_back(8);
	second->_next = first;
	pair<ListNode*, int> Pair = l.EntryNodeOfLoop(pHead);
	cout << Pair.first->_value << endl;
	cout << Pair.second << endl;
	/*l.reverseList();
	l.Print();*/
	//ListNode* cur = l.findLastKthNode(8);
	//if (cur != NULL)
	//	cout << cur->_value << endl;
	/*l.removeMidNode();
	l.Print();
	l.removeMidNode();
	l.Print();
	l.removeMidNode();
	l.Print();*/
}

////将构造函数设置为私有的就可以使得该类不能被继承
//class A
//{
//private:
//	A()
//	{}
//	A~()
//	{}
//};
//
//class B :public A
//{
//public:
//	B()
//	{}
//};

//设置一个只能在堆上的类。。。
//将构造函数定义为私有,提供一个获取对象的接口,
//防止在外面通过拷贝构造（主要已有对象创建对象）和赋值运算符的重载（对象—对象）创建对象。
//class A
//{
//public:
//	static A*  createObj()
//	{
//		return new A;
//	}
//private:
//	A()
//	{}
//	~A()
//	{}
//	A(const A&);
//	A& operator=(const A&);
//};


//只有使用new运算符，对象才会建立在堆上，因此，
//只要禁用new运算符就可以实现类对象只能建立在栈上。将operator new()设为私有即可
//class A
//{
//private:
//	void* operator new(size_t t)
//	{}
//	// 注意函数的第一个参数和返回值都是固定的
//	void operator delete(void* ptr)
//	{}
//	// 重载了new就需要重载delete
//public:
//	A(){}
//   ~A(){}
//};
int main()
{
	TestList();
	return 0;
}
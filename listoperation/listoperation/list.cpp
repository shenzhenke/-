#define _CRT_SECURE_NO_WARNINGS 
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
	void Push_back(int value)
	{
		if (_head == NULL)
		{
			_head = new Node(value);
			return;
		}
		Node* cur = _head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		Node* newNode = new Node(value);
		cur->_next = newNode;
		return;
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

private:
	Node* _head;
};

void TestList()
{
	List l;
	l.Push_back(1);
	l.Push_back(2);
	l.Push_back(3);
	l.Push_back(4);
	l.Push_back(5);
	l.Push_back(6);
	l.Push_back(7);
	l.Print();
	l.removeMidNode();
	l.Print();
	l.removeMidNode();
	l.Print();
	l.removeMidNode();
	l.Print();
}
int main()
{
	TestList();
	return 0;
}
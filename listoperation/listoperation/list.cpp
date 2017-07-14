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

	//�ҵ�����K�����
	Node* findLastKthNode(int lastKth)
	{
		int lastNodeIndex = 0;
		//���������K����㲻������ʾ��λ�ó�������ĳ��Ȼ�С������ĳ����Է���NULL��ʾ
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

	//��������
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



	void removeLastKthNode(int lastKth)  //ɾ��������K�����
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

	void removeMidNode()  //ɾ���м��� ���ÿ���ָ��
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

class Solution {
public:
	int Add(int num1, int num2)
	{
		//&ȡ��ͬλ������һλ�������,^ȡ��ͬλ 
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
	Solution a;
	cout << a.Add(10, 9) << endl;
	/*List l;
	l.Push_back(1);
	l.Push_back(2);
	l.Push_back(3);
	l.Push_back(4);
	l.Push_back(5);
	l.Push_back(6);
	l.Push_back(7);
	l.Push_back(8);

	l.Print();
	l.reverseList();
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
int main()
{
	TestList();
	return 0;
}
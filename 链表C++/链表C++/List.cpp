//#define _CRT_SECURE_NO_WARNINGS
//#ifndef __List__
//#define __List__
//#include <iostream>
//using namespace std;
//typedef int DataType;
//struct ListNode
//{
//	DataType _data;
//	ListNode  *_next;
//	ListNode(const DataType d)
//	{
//		this->_next = NULL;
//		this->_data = d;
//	}
//};
//class List
//{
//	typedef ListNode Node;
//public:
//	List()
//		:_head(NULL)
//		, _len(0)
//	{
//
//	}
//
//
//	List(const List &s)  //浅拷贝会导致同一块空间被释放两次
//		:_head(NULL)
//		, _len(0)
//	{
//		Node *cur = s._head;
//		while (cur)
//		{
//			this->PushBack(cur->_data);
//			cur = cur->_next;
//		}
//	}
//
//	List& operator=( List s)
//	{
//		swap(_head, s._head);
//		swap(_len, s._len);
//		return *this;
//	}
//
//	void PushBack(DataType d) //尾插
//	{
//		if (_head == NULL)
//		{
//			_head = new Node(d);
//			_len++;
//		}
//		else
//		{
//			Node *tmp = new Node(d);
//			/*Node *cur = _head + (_len )*sizeof(DataType);
//			cur->_next = tmp;
//			_len++;*/
//			Node *cur = _head;
//			while (cur->_next)
//			{
//				cur = cur->_next;
//			}
//			cur->_next = tmp;
//			_len++;
//		}
//	}
//
//	void PopBack()  //尾删
//	{
//		if (_head == NULL)
//		{
//		}
//		else if (_head->_next == NULL)
//		{
//			delete _head;
//			_head = NULL;
//			_len--;
//		}
//		else
//		{
//			Node *cur = _head;
//			Node *del = _head;
//			while (del->_next)
//			{
//				cur = del;
//				del = del->_next;
//			}
//			delete del;
//			cur->_next = NULL;
//			_len--;
//		}
//	}
//
//	void PushFront(DataType d)  //头插
//	{
//		if (_head == NULL)
//		{
//			PushBack(d);
//		}
//		else
//		{
//			Node *tmp = new Node(d);
//			tmp->_next = _head;
//			_head = tmp;
//			_len++;
//		}
//	}
//
//	void PopFront()
//	{
//		if (_head == NULL)
//		{
//		}
//		else  if (_head->_next == NULL)
//		{
//			delete _head;
//			_head = NULL;
//			_len--;
//		}
//		else
//		{
//			Node *cur = _head;
//			_head = _head->_next;
//			delete cur;
//			cur = NULL;
//			_len--;
//		}
//	}
//
//	~List()
//	{
//		cout << "~List()" << endl;
//		Node *cur = _head;
//		while (cur)
//		{
//			Node *del = cur;
//			cur = cur->_next;
//			delete del;
//			del = NULL;
//		}
//	}
//
//	void Reverse()
//	{
//		/*if ((_head == NULL) || (_head->_next == NULL))
//		{
//			return;
//		}
//		else
//		{*/
//			Node *cur = _head;
//			List l;
//			while (cur)
//			{
//				l.PushFront(cur->_data);
//				cur = cur->_next;
//			}
//			swap(this->_head, l._head);
//			swap(this->_len, l._len);
//	//	}
//	}
//
//	void Display()
//	{
//		Node *cur = _head;
//		while (cur)
//		{
//			cout << cur->_data << " ";
//			cur = cur->_next;
//		}
//		cout << endl;
//	}
//
//	//在一个排序的链表中，存在重复的结点，
//	//请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//	//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5 
//	ListNode* deleteDuplication()
//	{
//		Node* pHead = _head;
//		Node* cur = pHead->_next;
//		if (pHead == NULL || pHead->_next == NULL)
//			return pHead;
//		while (cur->_next != NULL)
//		{
//			Node* next = cur->_next;
//			while (cur->_data == next->_data)
//			{
//				Node* del = next;
//				next = next->_next;
//				cur->_next = next;
//				del->_next = NULL;
//				delete del;
//				if (next == NULL)
//					return pHead;
//			}
//			cur = cur->_next;
//			if (cur == NULL)
//				break;
//		}
//		_head = pHead;
//		return  pHead;
//	}
//private:
//	Node *_head;
//	int _len;
//};
//
//
//#endif //__List__
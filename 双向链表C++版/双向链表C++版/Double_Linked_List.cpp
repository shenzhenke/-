#include  "Doubly_Linked_List.h"

List::List()
: _head(NULL)
, _tail(NULL)
{

}

List::List(const List &s)
{
	_head =_tail= NULL;
	//不将_tail和_head置空，可能会导致在后面调用后插时产生已经有数据的假象
	Node *cur = s._head;	
	while (cur)
	{
		PushBack(cur->_data);
		cur=cur->_next;
	}
}

List & List::operator=(List s)
{
	List tmp(s);
	swap(tmp._head, _head);
	swap(tmp._tail, _tail);
	return *this;
}



List::~List()
{
	Node *cur = _head;
	Node *del = _head;
	if (cur != NULL)
	{
		while (cur)
		{
			cur = cur->_next;
			delete del;
			del = cur;
			cout << "~List" << endl;
		}
	}
}

void List::PushBack(DataType x) //尾插
{
	//没有数据
	if (_head == NULL)
	{
		_head = _tail =new Node(x) ;
	}
	//有数据
	else
	{
		//注意_tail应该后移
		Node *tmp = new Node(x);
		_tail->_next = tmp;
		tmp->_prev = _tail;
		_tail = tmp;
	}
}

void List::PopBack() //尾删 
{

	//没有数据
	if (_head == NULL)
	{
		cout << "链表为空" << endl;
	}
	//有一个数据
	else if (_head->_next == NULL)
	{
		delete _head;
		_head = _tail = NULL;
	}
	//超过一个数据
	else
	{
		Node *del = _tail;
		_tail = _tail->_prev;
		_tail->_next = NULL;
		delete del;
	}

}

void List::PushFront(DataType x)//前插
{
	if (_head == NULL)
	{
		_head = _tail = new Node(x);
	}
	else
	{
		//注意语序，以及_head应该前移
		Node *tmp = new Node(x);
		tmp->_next = _head;
		_head->_prev = tmp;
		_head = tmp;
	}

}

void List::PopFront()  //前删
{
	if (_head == NULL)
	{
		cout << "此链表为空" << endl;
	}
	else if (_head->_next == NULL)
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node *del = _head;
		_head = _head->_next;
		_head->_prev = NULL;
		delete del;
	}
}


void List::Insert(Node * pos, DataType x)
//在指定结点前插入数据
{
	assert(pos);
	if (pos->_prev == NULL)//头插
	{
		this->PushFront(x);
	}
	else
	{
  //以pos结点为中心先解决pos->prev和tmp连接
		Node *tmp = new Node(x);
		tmp->_prev = pos->_prev;
		pos->_prev->_next = tmp;
		tmp->_next = pos;
		pos->_prev = tmp;
	}
}



void List::Erase(Node* pos)
//指定结点删除数据
{
	assert(pos);
	if (pos->_prev == NULL)  //pos为头结点
	{
		PopFront();
	}
	else if (pos->_next == NULL)//pos为尾结点
	{
		PopBack();
	}
	else
	{
		pos->_next->_prev = pos->_prev;
		pos->_prev->_next = pos->_next;
		delete pos;
	}
}

ListNode *  List::Find_Pos(DataType x)
{
		if (_head == NULL)
		{
			return NULL;
		}
		else
		{
			Node *cur = _head;
			while (cur)
			{
				if (cur->_data == x)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return NULL;
		}
}



void List::display()
{
	Node * cur1 = _head;
	Node * cur2 = _tail;
	if (_head == NULL)
	{
		cout << "此链表为空" << endl;
	}
	while (cur1)
	{
		cout << cur1->_data << " ";
		cur1 = cur1->_next;
	}
	cout << endl;
	while (cur2)
	{
		cout << cur2->_data << " ";
		cur2 = cur2->_prev;
	}
	cout << endl;
}


void List::Reverse()
{
	/*if ((_head == NULL) || (_head->_next == NULL))
	{
		return;
	}
	else
	{*/
		/*
		Node *cur = _head;
		while (cur)
		{
			swap(cur->_next, cur->_prev);
			cur = cur->_prev;
		}
		swap(_head, _tail);*/
		List l;
		Node *cur = _head;
		while (cur)
		{
			l.PushFront(cur->_data);
			cur = cur->_next;
		}
		swap(_head, l._head);
		swap(_tail, l._tail);
	//}
}

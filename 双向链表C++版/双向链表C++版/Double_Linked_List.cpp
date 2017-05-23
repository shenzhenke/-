#include  "Doubly_Linked_List.h"

List::List()
: _head(NULL)
, _tail(NULL)
{

}

List::List(const List &s)
{
	_head =_tail= NULL;
	//����_tail��_head�ÿգ����ܻᵼ���ں�����ú��ʱ�����Ѿ������ݵļ���
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

void List::PushBack(DataType x) //β��
{
	//û������
	if (_head == NULL)
	{
		_head = _tail =new Node(x) ;
	}
	//������
	else
	{
		//ע��_tailӦ�ú���
		Node *tmp = new Node(x);
		_tail->_next = tmp;
		tmp->_prev = _tail;
		_tail = tmp;
	}
}

void List::PopBack() //βɾ 
{

	//û������
	if (_head == NULL)
	{
		cout << "����Ϊ��" << endl;
	}
	//��һ������
	else if (_head->_next == NULL)
	{
		delete _head;
		_head = _tail = NULL;
	}
	//����һ������
	else
	{
		Node *del = _tail;
		_tail = _tail->_prev;
		_tail->_next = NULL;
		delete del;
	}

}

void List::PushFront(DataType x)//ǰ��
{
	if (_head == NULL)
	{
		_head = _tail = new Node(x);
	}
	else
	{
		//ע�������Լ�_headӦ��ǰ��
		Node *tmp = new Node(x);
		tmp->_next = _head;
		_head->_prev = tmp;
		_head = tmp;
	}

}

void List::PopFront()  //ǰɾ
{
	if (_head == NULL)
	{
		cout << "������Ϊ��" << endl;
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
//��ָ�����ǰ��������
{
	assert(pos);
	if (pos->_prev == NULL)//ͷ��
	{
		this->PushFront(x);
	}
	else
	{
  //��pos���Ϊ�����Ƚ��pos->prev��tmp����
		Node *tmp = new Node(x);
		tmp->_prev = pos->_prev;
		pos->_prev->_next = tmp;
		tmp->_next = pos;
		pos->_prev = tmp;
	}
}



void List::Erase(Node* pos)
//ָ�����ɾ������
{
	assert(pos);
	if (pos->_prev == NULL)  //posΪͷ���
	{
		PopFront();
	}
	else if (pos->_next == NULL)//posΪβ���
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
		cout << "������Ϊ��" << endl;
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

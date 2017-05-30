#include "Seqlist.h"
template <class T>
struct ListNode
{
	ListNode<T> *_next;
	ListNode<T> *_prev;
	T _date;
	ListNode(const T &d)
		:_next(NULL)
		, _prev(NULL)
		, _date(d)
	{}
};

template <typename T>
class List
{

public:
	typedef   ListNode<T> Node; //使用类模板需要模板参数列表
	List()
		:_head(NULL)
		, _tail(NULL)
	{
		cout << "List()" << endl;
	}

	List(const List<T> & l)
		:_head(NULL)
		, _tail(NULL)
	{
		Node *cur = l._head;
		while (cur)
		{
			Pushback(cur->_date);
			cur = cur->_next;
		}
	}

	~List()
	{
		if (_head != NULL)
		{
			Node *cur = _head;
			while (cur)
			{
				_head = _head->_next;
				delete cur;
				cur = _head;
			}
		}
		cout << "~List()" << endl;
	}
	void Pushback(T d)
	{
		if (_head == NULL)
		{
		 _head = _tail = new Node(d);
		}
		else
		{
			Node * tmp = new Node(d);
			_tail->_next = tmp;
			tmp->_prev = _tail;
			_tail = tmp;
		}
	}

	void Popback()
	{
		if (_head == NULL)
		{
			return;
		}
		else if (_head->_next == NULL)
		{
			delete _head;
			_head = _tail = NULL;
			return;
		}
		else
		{
			Node *del = _tail;
			_tail = _tail->_prev;
			_tail->_next = NULL;
			delete del;
		}
	}

	void Pushfront(T d)
	{
		if (_head == NULL)
		{
			_head = _tail = new Node(d);
		}
		else
		{
			Node *tmp = new Node(d);
			tmp->_next = _head;
			_head->_prev = tmp;
			_head = tmp;
		}
	}

	void Popfront()
	{
		if (_head == NULL)
		{
			return;
		}
		else if (_head->_next == NULL)
		{
			delete _head;
			_head = _tail = NULL;
			return;
		}
		else
		{
			Node *del = _head;
			_head = _head->_next;
			_head->_prev = NULL;
			delete del;
		}
	}
	void  Display()
	{
		if (_head)
		{
			Node *cur = _head;
			while (cur)
			{
				cout << cur->_date<<" ";
				cur = cur->_next;
			}
		}
		cout << endl;
	}
	T& Front()
	{
		assert(_head);
		return  _head->_date;
	}

	T& Back()
	{
		assert(_head);
		return _tail->_date;
	}

	size_t Size()
	{
		Node *cur = _head;
		size_t size = 0;
		while (cur)
		{
			cur = cur->_next;
			size++;
		}
		return size;
	}

	bool Empty()
	{
		return _head == NULL;
	}

protected:
	Node *_head;
	Node *_tail;
};



//适配器模式实现一个队列  (先进先出,可取队头和队尾数据)
template <class T,class Container=List<T>>
class Queue
{
public:
	void Push(const T& x)
	{
		_con.Pushback(x);
	}

	void Pop()
	{
		_con.Popfront();
	}
	T& Front()
	{
		return _con.Front();
	}

	T& Back()
	{
		return _con.Back();
	}

	size_t Size()
	{
		return _con.Size();
	}

	bool Empty()
	{
		return _con.Empty();
	}
protected:
	Container _con;
};

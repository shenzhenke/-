#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <assert.h>
using namespace std;
template <typename T>
struct __List_Node
{
	__List_Node *_next;
	__List_Node *_prev;
	T _data;
	__List_Node(const T &x)
		:_data(x)
		, _next(NULL)
		, _prev(NULL)
	{
	}
};


//T T& T*
template<class T,class Ref,class Ptr>
//迭代器——看做指向数据的指针,类似智能指针,且区间为[)
struct _List_Iterator
{
	typedef __List_Node<T> Node;
	typedef _List_Iterator<T, Ref, Ptr> Self;
	_List_Iterator( Node* node)
		:_node(node)
	{
	}

	Ref operator*()
	{
		return _node->_data;
	}

	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//出了作用域不存在的对象,不能用引用了
	Self operator++(int)
	{
		Node* tmp = _node;
		_node = _node->_next;
		return tmp;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)
	{
		Node* tmp = _node;
		_node = _node->_prev;
		return tmp;
	}

	//成员函数后面加const,保证调用这个成员函数的对象在函数内不会发生改变
    bool operator!=(const Self &s) const 
	{
		return this->_node != s._node;
	}
	bool operator==(const Self &s) const
	{
		return this->_node == s._node;
	}
	Node *_node;
};


template <class T>
//List为双向循环列表
class List
{
public:
	typedef __List_Node<T> Node;
	typedef _List_Iterator<T, T&, T*> Iterator;
	typedef _List_Iterator<T, const T&, const T*> ConstIterator;
	Node* BuyNode(const T &x)
	{
		return new Node(x);
	}
	List()
		:_head(BuyNode(T()))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}

	void PushBack(const T&x)
	{
	/*	Node* tmp = BuyNode(x);
		Node* tail = _head->_prev;
		tail->_next = tmp;
		tmp->_prev = tail;
		tmp->_next = _head;
		_head->_prev = tmp;*/
		Insert(End(), x);
	}

	void PushFront(const T&x)
	{
	/*	Node* tmp = BuyNode(x);
		Node* next = _head->_next;
		_head->_next = tmp;
		tmp->_prev = _head;
		next->_prev = tmp;
		tmp->_next = next;*/
		Insert(this->Begin(), x);
	}

	void PopBack()
	{
		 /*   assert(_head->_next != _head);
			Node* del = _head->_prev;
			Node* prev = del->_prev;
			prev->_next = _head;
			_head->_prev = prev;
			delete del;
			return;*/
		Erase(--End());
	}

	void PopFront()
	{
		   /* assert(_head->_next != _head);
			Node* del = _head->_next;
			Node* next = del->_next;
			next->_prev = _head;
			_head->_next = next;
			delete  del;
			return;*/
		Erase(this->Begin());
	}

	//指定位置之前插入
	Iterator Insert(Iterator pos,const T&x)
	{
		Node* cur = pos._node;
		Node* tmp = BuyNode(x);
		Node* prev = cur->_prev;
		prev->_next = tmp;
		tmp->_prev = prev;
		tmp->_next = cur;
		cur->_prev = tmp;
		return Iterator(tmp);
	}

	//指定位置删除
	Iterator Erase(Iterator pos)
	{
		    assert(pos != End());
			Node* del = pos._node;
			Node* prev = del->_prev;
			Node* next = del->_next;
			prev->_next = next;
			next->_prev = prev;
			delete del;
//list的实际实现
		return Iterator(next);
//要实现++it操作
//      Iterator Erase(Iterator);
//		return Iterator(prev);
	}

	//默认拷贝构造函数为浅拷贝
	~List()
	{
		cout <<"~List()"<< endl;
		Clear();
		delete _head;
		_head = NULL;
	}
	void Clear()
	{
		Iterator it=this->Begin();
		while (it != this->End())
		{
			it = this->Erase(it);
		}
		return;
	}

	Iterator Begin()
	{
		return Iterator(_head->_next);
	}
	ConstIterator Begin() const
	{
		return ConstIterator(_head->_next);
	}

	ConstIterator End() const
	{
		return ConstIterator(_head);
	}
	Iterator End()
	{
		return Iterator(_head);
	}
private:
	Node* _head;

};

template<class T>
void PrintList( List<T>& l)
{
	List<int>::Iterator it = l.Begin();
	while (it != l.End())
	{
		//(*it)++;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	/*List<int>::ConstIterator it1 = l.Begin();
	while (it1 != l.End())
	{
		(*it)++;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;*/
}
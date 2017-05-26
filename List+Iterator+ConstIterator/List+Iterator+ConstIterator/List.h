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
//��������������ָ�����ݵ�ָ��,��������ָ��,������Ϊ[)
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

	//���������򲻴��ڵĶ���,������������
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

	//��Ա���������const,��֤���������Ա�����Ķ����ں����ڲ��ᷢ���ı�
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
//ListΪ˫��ѭ���б�
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

	//ָ��λ��֮ǰ����
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

	//ָ��λ��ɾ��
	Iterator Erase(Iterator pos)
	{
		    assert(pos != End());
			Node* del = pos._node;
			Node* prev = del->_prev;
			Node* next = del->_next;
			prev->_next = next;
			next->_prev = prev;
			delete del;
//list��ʵ��ʵ��
		return Iterator(next);
//Ҫʵ��++it����
//      Iterator Erase(Iterator);
//		return Iterator(prev);
	}

	//Ĭ�Ͽ������캯��Ϊǳ����
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
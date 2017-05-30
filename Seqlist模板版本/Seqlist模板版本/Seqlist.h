#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
//template < class T >;
template <typename T>
class Seqlist
{
public:	
	Seqlist();
	Seqlist(const Seqlist<T> &l);
	Seqlist<T> & operator=(Seqlist<T> l);
	~Seqlist();
	void Checkcapacity();
	void Pushback(T d);
	void Popback();
	void Pushfront(T d); 
	void Popfront();
	void Display();
	void Erase(int pos);
	void Insert(int pos,T d);
	int Find(T d);
	const T& Back()
	{
		assert(_size > 0);
		return _a[_size - 1];
	}

	size_t Size()
	{
		return _size;
	}

	bool Empty()
	{
		return _size == 0;
	}
protected:
	T *_a;
	int _size;
	int _capacity;
};


template <class T>
Seqlist<T>::Seqlist()   //模板的类名和类型有区别
:_a(NULL)
, _capacity(0)
, _size(0)
{
	cout << "Seqlist()" << endl;
}

template <typename T>
Seqlist<T>::Seqlist(const Seqlist<T> & l)
:_a(new T [l._capacity])
, _size(l._size)
, _capacity(l._capacity)
{
	cout << "Seqlist(const Seqlist<T> & l)" << endl;
	for (int i = 0; i < _size;i++)
	{
		_a[i] = l._a[i];
	} 

}

template <class T>
Seqlist<T> & Seqlist<T>::operator=(Seqlist<T> l)
{
	swap(_a, l._a);
	swap(_size, l._size);
	swap(_capacity, l._capacity);
	return *this;
}

template <class T>
Seqlist<T>::~Seqlist()
{
	if (_a)
	{
		delete[] _a;
		_a = NULL;
		_size = _capacity = 0;
	}
	cout << "~Seqlist<T>" << endl;
}

template <class T>
void Seqlist<T>::Checkcapacity()
{
	if (_size >= _capacity)
	{
		_capacity = _capacity * 2 + 3;
		T *tmp = new T[_capacity];
		memcpy(tmp, _a, sizeof(T)*_size);//要考虑vs下string的底层实现问题
		/*if ( _a )
		{
			for (int i = 0; i < _size; i++)
			{
				tmp[i] = _a[i];
			}
			delete[] _a;
		}*/
		delete[]_a;
		_a = tmp;
	}
}


template <class T>
void Seqlist<T>::Pushback(T d)
{
	Checkcapacity();
    _a[_size] = d;
	_size++;
	return ;
}

template <class T>
void Seqlist<T>::Popback()
{
	if (_size != 0)
	{
		_size--;
	}
	return;
}

template <class T>
void Seqlist<T>::Popfront()
{
	if (_size != 0)
	{
		for (int i = 0; i < _size - 1; i++)
		{
			_a[i] = _a[i + 1];
		}
		_size--;
	}
	return;
}

template <typename T>
void Seqlist<T>::Pushfront(T d)
{
	Checkcapacity();
	for (int i = 0; i < _size; i++)
	{
		_a[_size - i] = _a[_size - 1 - i];
	}
	_a[0] = d;
	_size++;
}


template <class T>
void Seqlist<T>::Display()
{
	for (int i = 0; i < _size; i++)
	{
		cout << _a[i] << " ";
	}
	cout << endl;
}

template <class T>
void Seqlist<T>::Erase(int pos)
{
	assert(pos < _size);
	for (int i = pos; i < _size - 1; i++)
	{
		_a[i] = _a[i + 1];
	}
	_size--;
}

template <class T>
void Seqlist<T>::Insert(int pos, T d)
{
	if ((_size == 0) && (pos == 0))
	{
		Pushfront(d);
		return;
	}
	assert(pos < _size);
	Checkcapacity();
	for (int i = _size; i > pos; i--)
    {
		_a[i] = _a[i - 1];
	}
		_a[pos] = d;
		_size++;
}

template <class T>
int Seqlist<T>::Find(T d)
{
	for (int i = 0; i < _size; i++)
	{
		if (_a[i] == d)
		{
			return i;
		}
	}
	return -1;
}



//适配器实现栈，后进先出，只能取栈顶的数据
template < class T,class Container=Seqlist<T>>
class Stack
{
public:
		void Push(const T& x)
		{
			_con.Pushback(x);
		}
	
		void Pop()
		{
			_con.Popback();
		}
	
		const T& Top()
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











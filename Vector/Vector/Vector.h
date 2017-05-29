#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;
template <typename T>
class Vector
{
public:
	typedef T* Iterator;
	Vector()
		:_start(NULL)
		, _finish(NULL)
		, _end_of_storage(NULL)
	{}

	void  PushBack(const T&x)
	{
		if (_finish != _end_of_storage)
		{
			_start[this->Size()] = x;
			++_finish;
		}
		else
		{
			Expand();
			_start[this->Size()] = x;
			++_finish;
		}

	}

	void PopBack()
	{
		assert(Size() != 0);
		--_finish;
	}

	void Expand()
	{
		if (_end_of_storage == _finish)
		{
			size_t _capacity = Capacity();
			size_t _size = Size();
			//0 1 2 3 4 6 9 13
			_capacity = _capacity / 2 + _capacity;
			if (_capacity == _size)
				_capacity += 1;
			T* tmp = new T[_capacity];
			for (size_t i = 0; i < Size(); i++)
			{
				tmp[i] = _start[i];
			}
			delete[] _start;
			_start = tmp;
			_finish = _start + _size;
			_end_of_storage = _start + _capacity;
		}
	}

	Iterator Insert(Iterator pos, const T&x)
	{
		assert(pos);
			//从pos到_finish共有多少个数据
			Expand();
			size_t n = _finish - pos;
			for (size_t i = n; i >= 0; i--)
			{
				pos[i + 1] = pos[i];
			}
			_finish++;
		return pos;
	}

	Iterator Erase(Iterator pos)
	{
		assert((pos != NULL) && (Size() != 0));
		size_t n = _finish - pos;
		for (size_t i = 0; i < n - 1; i++)
		{
			pos[i] = pos[i + 1];
		}
		--_finish;
		return pos;
	}
	Iterator Begin()
	{
		return _start;
	}

	Iterator End()
	{
		return _finish;
	}

	size_t Size()
	{
		return _finish - _start;
	}

	size_t Capacity()
	{
		return _end_of_storage - _start;
	}

	~Vector()
	{
		if (_start)
		{
			delete[]_start;
			_start = _finish = _end_of_storage = NULL;
		}
	}
protected:
	Iterator _start;
	Iterator _finish; 
	//指向含有最后一个数据的下一个位置
	Iterator _end_of_storage;
	//指向最大容量的下一个位置
};

template <class T>
void PrintVector(Vector<T>&l )
{
	Vector<int>::Iterator it = l.Begin();
	 while (it != l.End())
	{
		 if (*it % 2 == 0)
		 {
			  l.Erase(it);
		 }
		 cout << *it << " ";
		 ++it;
	}
	cout << endl;
}

void TestVector()
{
	Vector<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	/*l.PopBack();
	l.PopBack();
	l.PopBack();
	l.PopBack();
	l.PopBack();*/
	PrintVector(l);
}
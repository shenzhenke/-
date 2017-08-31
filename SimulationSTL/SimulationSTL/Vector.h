#pragma once 
#include "Alloca.h"
#include "Construct.h"

template <class T,class Alloc=alloc>
class Vector
{
public:
	typedef T* Iterator;
	typedef SimpleAlloc<T, Alloc> DataAllocator;
	Vector()
		:_start(NULL)
		, _endOfStorge(NULL)
		, _finish(NULL)
	{}

	Iterator Begin()
	{
		return _start;
	}

	Iterator End()
	{
		return _finish;
	}

	~Vector()
	{
		Destroy(Begin(), End());
		DataAllocator::Deallocate(_start, Size());
	}


	void PushBack(const T& x)
	{
		CheckCapacity();

		//*_finish=x ; //T string operator=
		Construct(_finish, x);
		++_finish;
	}

	size_t Size()
	{
		return _finish - _start;
	}

	size_t Capacity()
	{
		return _endOfStorge - _start;
	}

	void CheckCapacity()
	{
		if (_finish == _endOfStorge)
		{
			size_t size = Size();
			size_t newSize = size != 0 ? 2 * size : 3;
			T* tmp = DataAllocator::Allocate(newSize);
			if (_start != NULL)
			{
				//UninitializeCopy()
				for (size_t i = 0; i < size; i++)
				{
					Construct(tmp + i, _start[i]);
				}
				Destroy(_start, _finish);
				DataAllocator::Deallocate(_start, size);
			}
			_start = tmp;
			_finish = _start + size;
			_endOfStorge = _start + newSize;
		}
	}
protected:
	Iterator _start;
	Iterator _finish;				 //标识数据所到的位置
	Iterator _endOfStorge;		//标识开辟容量所到的位置
};


void TestVector()
{

	Vector<string> v1;
	v1.PushBack("111111111111111111111111111111111111111111");
	v1.PushBack("2222");
	v1.PushBack("3333");
	v1.PushBack("4444");

	Vector<string>::Iterator it1 = v1.Begin();
	while (it1 != v1.End())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <memory>
using namespace std;
template<class T>
struct DeleteArray
{
	void operator()(T *ptr)
	{
		delete[] ptr;
	}

};

template<class T>
struct Delete
{
	void operator()(T *ptr)
	{
		delete ptr;
	}

};

struct Fclose
{
	void operator()(FILE * ptr)
	{
		fclose(ptr);
	}
};

template<class T,class Del>
class SharedPtr  
{
public:
	SharedPtr(T *ptr)
		:_ptr(ptr)
		, _reference_count(new int (1))
	{
	}
	~SharedPtr()
	{
		Clear();
	}
	void Clear()
	{
		if (--(*_reference_count) == 0)
		{
			 _del(_ptr);
			delete _reference_count;
			_reference_count = NULL;
		}

	}
	SharedPtr( SharedPtr<T,Del> & sp)
	{
		_ptr = sp._ptr;
		_reference_count = sp._reference_count;
		(*_reference_count)++;
	}

	//传统写法
	//SharedPtr& operator =(const SharedPtr<T,Del> & sp)
	//{
	//	if (this != &sp)
	//	{
	//		Clear();
	//		_ptr = sp._ptr;
	//		_reference_count = sp._reference_count;
	//		(*_reference_count)++;
	//	}
	//	return *this;
	//}

	//现代写法
	SharedPtr& operator =(SharedPtr<T,Del> sp)
	{
		swap(_ptr, sp._ptr);
		swap(_reference_count, sp._reference_count);
		return *this;
	}
	T& operator *() 
	{
		return *(this->_ptr);
	}

	T*  operator->()
	{
		return _ptr;
	}
private:
	T *_ptr;
	Del _del;
	int *_reference_count;
};


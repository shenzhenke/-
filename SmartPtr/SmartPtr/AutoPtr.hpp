#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
template <class T>
class AutoPtr  
{
public:
	AutoPtr(T *ptr)
		:_ptr(ptr)
	{
	}
	~AutoPtr()
	{
		if (_ptr != NULL)
		{
			delete _ptr;
			_ptr = NULL;
		}
	}
	AutoPtr(AutoPtr <T> & ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL; //只能有一个对象的指针指向同一块区域
	}

	T& operator *() //注意返回值问题不能返回一个临时变量,临时变量具有常性,会导致不能通过解引用更改值
	{
		return *(this->_ptr);
	}

	AutoPtr& operator=(AutoPtr &ap)
	{
		//防止自赋值
		if (this != &ap)
		{
			delete _ptr;
			this->_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}

	
	T*  operator->()
	{
		return _ptr;
	}
private:
	T *_ptr;
};


class AA
{
public:
	int _a;
	int _b;
};


#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
template<class T>
class ScopedPtr   
{
public:
	ScopedPtr(T *ptr)
		:_ptr(ptr)
	{
		cout << "ScopedPtr(T *ptr)" << endl;
	}

	~ScopedPtr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = NULL;
		}
		cout << "~ScopedPtr()" << endl;
	}

	T& operator *()
	{
		return  *(_ptr);
	}

	T* operator ->()
	{
		return _ptr;
	}
protected:
	//构造和拷贝构造只声明，不定义
	ScopedPtr& operator=(const ScopedPtr & sp);
	ScopedPtr(const ScopedPtr & sp);
public:
	T* _ptr;
};

class AA
{
public:
	int _a;
	int _b;
};
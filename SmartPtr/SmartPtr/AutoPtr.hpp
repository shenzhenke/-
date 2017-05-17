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
		ap._ptr = NULL; //ֻ����һ�������ָ��ָ��ͬһ������
	}

	T& operator *() //ע�ⷵ��ֵ���ⲻ�ܷ���һ����ʱ����,��ʱ�������г���,�ᵼ�²���ͨ�������ø���ֵ
	{
		return *(this->_ptr);
	}

	AutoPtr& operator=(AutoPtr &ap)
	{
		//��ֹ�Ը�ֵ
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


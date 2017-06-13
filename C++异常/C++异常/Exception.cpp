#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
using namespace std;

class Exception
{
public:
	Exception(int ErrId,const char* ErrMsg)
		:_ErrId(ErrId)
		,_ErrMsg(ErrMsg)
	{}

	virtual const char* What() const = 0;
protected:
	int _ErrId;      //´íÎóÂë
	string _ErrMsg;  //´íÎóÏûÏ¢
};

class BadAlloc:public Exception
{
public:
	BadAlloc(const char* msg = "")
		:Exception(1, msg)
	{
		_ErrMsg = _ErrMsg +"alloc memory failed";
	}

	virtual const char* What() const
	{
		return _ErrMsg.c_str();
	}
};

class RangError : public Exception
{
public:
	RangError(const char* msg = "")
		:Exception(2, msg)
	{
		_ErrMsg = _ErrMsg +" Rang error";
	}

	virtual const char* What() const
	{
		return _ErrMsg.c_str();
	}
};

struct AA
{
public:
	char ch[0x5fffffff];
};

template<class T>
T* New()
{
	T* p = (T*)malloc(sizeof(T));
	if (p == 0)
	{
		throw BadAlloc("New failed: ");
	}
	return new(p)T;
}

void F()
{
	int a[10];
	const int n = 20;

	if (n > 9)
	{
		throw RangError("Access failure:");
	}
	else
	{
		cout << a[n] << endl;
	}
}

int main()
{
	try
	{
		AA* p1 = New<AA>();
	}
	catch (const Exception& e)
	{
		cout<<"    "<<e.What()<<endl;
		cout << endl;
		cout << endl;

		cout << endl;
	}
	try
	{
		F();
	}
	catch (const Exception& e)
	{
		cout << "    " << e.What() << endl;
	}
	return 0;
}
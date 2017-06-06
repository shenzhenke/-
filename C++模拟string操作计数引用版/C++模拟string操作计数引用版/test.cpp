#define _CRT_SECURE_NO_WARNINGS 
//空悬指针：一个指针，指向曾经保存一个对象但现在已经释放的内存
//引用计数：(reference count) 一个计数器，记录有多少用户共享一个对象
//#include <iostream>
//using  namespace std;
//class String
//{
//public:
//	String(const char *s="")  //strlen不能给一个空指针作为参数
//		:_str(new char[strlen(s)+1] ) 
//	{
//		cout << "String(const char *s="")" << endl;
//		strcpy(_str,s);
//		reference_count ++;
//	}
//
//
//	String(const String & s)
//		:_str(s._str)
//	{
//		reference_count++;
//		cout << "String(const String & s)" << endl;
//	}
//
//
//	~String()
//	{
//		if (reference_count == 1)
//		{
//			cout << "delete[]" << endl;
//			delete[] _str;
//			_str = NULL;
//		}
//		reference_count--;
//	}
//
//private:
//	char *_str;
// static	int  reference_count ;//只能适用与所有用户共享一个对象
//};
//
// int String::reference_count = 0;//内部声明外部初始化
//int main()
//{
//	String a("abcd");
//	String b(a);
//	return 0;
//}

#include <iostream>
using namespace  std;
class  String
{
public:
	String(const char *s = "")
		:_str(new char [strlen(s)+1])
		, _reference_count(new int [1])
	{
		strcpy(_str, s);
		cout << "String(const char *s = "")" << endl;
		*_reference_count = 1;
	}

	String(const String &s)
		:_str(s._str)
		, _reference_count(s._reference_count)
	{
		(*_reference_count)++;
		cout << "String(const String &s)" << endl;
	}

	//传统写法
	/*String & operator=(const String &s)
	{
		if(this != &s)
		{
			release();
		_str = s._str;
		_reference_count = s._reference_count;
		(*_reference_count)++;
	   }
		return *this;
	}*/

	//现代写法
	String & operator=(String s)
	{
		swap(this->_str, s._str);
		swap(this->_reference_count, s._reference_count);
		//(*_reference_count)++; 因为在创建形参时是实参的一份临时拷贝已经让这个值自加一次了
		return *this;
	}

	friend ostream & operator <<(ostream& os, String& s);
	

	void release()
	{
		if (--(*_reference_count) == 0)
		{
			delete[] _reference_count;
			delete[] _str;
			cout << "~String()" << endl;
		}
	}

	~String()
	{
		release();
	}

private:
	char *_str;
	int * _reference_count;
};

ostream & operator <<(ostream& os, String& s)
{
	os << s._str;
	return os;
}

int main()
{
	String a("abcd");
	String b(a);
	//String c("abcd");
	String d(a);
	String c;
	c = a;
	return 0;
}
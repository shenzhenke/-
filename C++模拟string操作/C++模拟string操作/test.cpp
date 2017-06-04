#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include<string>
using namespace std;
class String
{
public:

	friend ostream &operator<<(ostream& os, String& s);

	//这个版本需要考虑用一个赋值String str1(str2);
	//当str2为空字符串,调用拷贝构造函数时strlen不能求空字符串的值，导致程序崩溃问题
	//String()  //默认构造函数     
	//	:_str(NULL)
	//{
	//	cout << "String()" << endl;
	//}


	//String() 
	//	:_str (new char[1])
	//{
	//	cout << "String()" << endl;
	//	*_str = '/0';
	////	*_str = "/0";
	//}

	//String(const char * s)   
	//	:_str (new char[strlen(s)+1])
	//{
	//	cout << "String(const char *s)" << endl;
	//	strcpy(_str, s);
	//}
	
	
	//将默认拷贝构造和构造函数合并
	String(const char * s="")   
		:_str (new char[strlen(s)+1])
	{
		cout << "String(const char *s)" << endl;
		strcpy(_str, s);
	}



	String(const String &s)     
		:_str(new char[strlen(s._str)+1] )  //并未考虑空指针传给strlen的问题
	{
		cout << "String(const String &s)" << endl;
			strcpy(_str,s._str);
	}


	//String & operator=(const String &s)  
	//{
	//	cout << "String & operator=(const String &s)" << endl;
	//	if (s._str != _str)   //如果不考虑自赋值问题，可能导致自身内容被销毁
	//	{
	//		delete[]_str;
	//		_str = new char[strlen(s._str) + 1];
	//		strcpy(_str, s._str);
	//	}
	//	return *this;
	//}

	//现代写法
	String & operator=( String s)  //如果是引用会导致原来申请的堆空间未释放
	{
		cout << "String & operator=(const String &s)" << endl;
		std::swap(_str, s._str);  //s是实参的一份临时拷贝，所以出了这个函数作用域，会自行销毁
		return *this;
	}
	
	~String()
	{
		cout << "~String()" << endl;
		if (_str != NULL)
		{
			delete[]_str;
		}
	}

private:
	char* _str;
};

ostream &operator<<(ostream& os, String& s)
{
	os << s._str;
	return os;
}

int main()
{
	//string str = "abcdef";
	//string str1 = str;
	String str1("abcdef");
	//String str2(str1);
	String str3("");
	str3 = str1;
	cout << str1 << endl;
	cout << str3 << endl;
	//cout << str2 << endl;
	//cout << str1 << endl;
	return 0;
}

//
//class Array
//{
//public:
//	Array(int sz = 4)
//	{
//		_sz = sz;
//		_ptr = new int[_sz];
//		cout << "Array() " << endl;
//	}
//
//	~Array()
//	{
//		cout << "~Array()" << endl;
//		if (_ptr != NULL)
//		{
//			delete[] _ptr;
//			_ptr = NULL;
//		}
//	}
//	Array(const Array&arr)
//	{
//		cout << "Array(const Array&arr)" << endl;
//		_sz = arr._sz;
//		_ptr = arr._ptr;
//	}
//private:
//	size_t _sz;
//	int *_ptr;
//};
//int main()
//{
//	Array arr1(8);
//	Array arr2(arr1);
//	return 0;
//}
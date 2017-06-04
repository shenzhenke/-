#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include<string>
using namespace std;
class String
{
public:

	friend ostream &operator<<(ostream& os, String& s);

	//����汾��Ҫ������һ����ֵString str1(str2);
	//��str2Ϊ���ַ���,���ÿ������캯��ʱstrlen��������ַ�����ֵ�����³����������
	//String()  //Ĭ�Ϲ��캯��     
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
	
	
	//��Ĭ�Ͽ�������͹��캯���ϲ�
	String(const char * s="")   
		:_str (new char[strlen(s)+1])
	{
		cout << "String(const char *s)" << endl;
		strcpy(_str, s);
	}



	String(const String &s)     
		:_str(new char[strlen(s._str)+1] )  //��δ���ǿ�ָ�봫��strlen������
	{
		cout << "String(const String &s)" << endl;
			strcpy(_str,s._str);
	}


	//String & operator=(const String &s)  
	//{
	//	cout << "String & operator=(const String &s)" << endl;
	//	if (s._str != _str)   //����������Ը�ֵ���⣬���ܵ����������ݱ�����
	//	{
	//		delete[]_str;
	//		_str = new char[strlen(s._str) + 1];
	//		strcpy(_str, s._str);
	//	}
	//	return *this;
	//}

	//�ִ�д��
	String & operator=( String s)  //��������ûᵼ��ԭ������Ķѿռ�δ�ͷ�
	{
		cout << "String & operator=(const String &s)" << endl;
		std::swap(_str, s._str);  //s��ʵ�ε�һ����ʱ���������Գ���������������򣬻���������
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
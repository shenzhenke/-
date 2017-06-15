#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//class String
//{
//public:
//	String(const char *s="")
//		:_str(new char (strlen(s)+1))
//	{
//		cout << "String(const char *s="")" << endl;
//	}
//	String(const String &s)
//		:_str(new char(strlen(s._str) + 1))
//	{
//		cout << "String(const String &s)" << endl;
//	}
//	~String()
//	{
//		if (_str != NULL)
//		{
//			delete[] _str;
//			_str = NULL;
//		}
//		cout << "~String()" << endl;
//	}
//public:
//	char *_str;
//};
//int  main()
//{
//	String s1("1234");
//	String s2(s1);
//	printf("%p\n", &s1);
//	printf("%p\n", &s2);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	string s1("1234");
//	string s2(s1);
//	printf("%p\n", &s1);
//	printf("%p\n", &s2);
//	return 0;
//}

 //#include <iostream>
 //#include <stdio.h>
 //using namespace std;
 //int main()
 //{
	//         string s1("123243435545");
	//         string s2(s1);
	//         printf("\n\n");
	//         printf("s1.c_str()_address:%p\n", s1.c_str());
	//         printf("\n\n");
	//         printf("s2.c_str()_address:%p\n", s2.c_str());
	//         printf("\n\n");
	//         s1[0] = '0';
	//         printf("s1.c_str()_address:%p\n", s1.c_str());
	//         printf("\n\n");
	//         printf("s1.c_str()_address:%p\n", s2.c_str());
	//         printf("\n\n");
	//         return 0;
	//
 //}

//����ָ�룺һ��ָ�룬ָ����������һ�����������Ѿ��ͷŵ��ڴ�
//���ü�����(reference count) һ������������¼�ж����û�����һ������
#include <iostream>
using  namespace std;
class String
{
public:
	String(const char *s="")  //strlen���ܸ�һ����ָ����Ϊ����
		:_str(new char[strlen(s)+1] ) 
	{
		cout << "String(const char *s="")" << endl;
		strcpy(_str,s);
		reference_count ++;
	}


	String(const String & s)
		:_str(s._str)
	{
		reference_count++;
		cout << "String(const String & s)" << endl;
	}


	~String()
	{
		if (reference_count == 1)
		{
			cout << "delete[]" << endl;
			delete[] _str;
			_str = NULL;
		}
		reference_count--;
	}

private:
	char *_str;
 //static	int  reference_count ;//ֻ�������������û�����һ������
	int reference_count = 0;    //���ж�������ָ��ָ��ͬһ��ռ�ʱ���ᵼ��һ��ռ䱻�ͷŶ�Ρ�
};

// int String::reference_count = 0;//�ڲ������ⲿ��ʼ��
int main()
{
	String a("abcd");
	String b(a);
	//String c("bcde");
	return 0;
}

//#include <iostream>
//#include <stdlib.h>
//using namespace  std;
//class  String
//{
//public:
//	String(const char *s = "")
//		:_str(new char[strlen(s) + 1])
//		, _reference_count(new int[1])
//	{
//		strcpy(_str, s);
//		cout << "String(const char *s = "")" << endl;
//		*_reference_count = 1;
//	}
//
//	String(const String &s)
//		:_str(s._str)
//		, _reference_count(s._reference_count)
//	{
//		(*_reference_count)++;
//		cout << "String(const String &s)" << endl;
//	}
//
//	//��ͳд��
//	/*String & operator=(const String &s)
//	{
//	if(this != &s)
//	{
//	release();
//	_str = s._str;
//	_reference_count = s._reference_count;
//	(*_reference_count)++;
//	}
//	return *this;
//	}*/
//
//	//�ִ�д��
//	String & operator=(String s)
//	{
//		swap(this->_str, s._str);
//		swap(this->_reference_count, s._reference_count);
//		//(*_reference_count)++; ��Ϊ�ڴ����β�ʱ��ʵ�ε�һ����ʱ�����Ѿ������ֵ�Լ�һ����
//		return *this;
//	}
//
//	friend ostream & operator <<(ostream& os, String& s);
//
//
//	void release()
//	{
//		if (--(*_reference_count) == 0)
//		{
//			delete[] _reference_count;
//			delete[] _str;
//			cout << "~String()" << endl;
//		}
//	}
//
//	~String()
//	{
//		release();
//	}
//
//private:
//	char *_str;
//	int * _reference_count;
//};
//
//ostream & operator <<(ostream& os, String& s)
//{
//	os << s._str;
//	return os;
//}
//
//int main()
//{
//	String a("abcd");
//	String b(a);
//	//String c("abcd");
//	String d(a);
//	String c;
//	c = a;
//	return 0;
//}
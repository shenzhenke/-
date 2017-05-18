#define _CRT_SECURE_NO_WARNINGS 
#ifndef __String__
#define __String__
#include <iostream>
#include <assert.h>
using namespace std;
class  String
{
public:
	
	friend ostream & operator <<(ostream& os, const String& s);

	String(const char *s = "");

	String(const String &s );
	
	~ String();

	size_t Capacity(const char *s);

	char& operator[] (size_t pos);

	const char& String::operator[](size_t pos)const;//��Ϊ�˷�ֹ����Ϊconst��String��Ķ����޸�

	String& operator+= (const String& str);


	String& operator+= (const char* s);
	
	String& operator+= (char c);

	void Push_Back(char c);

	String& Erase(size_t pos , size_t len );

	String Substr(size_t pos , size_t len ) const;

	String& operator= (const String& s);

	String& Insert(size_t pos, const String& str, size_t Subpos, size_t Sublen);

	int  Find(const char *s ) const;

private:
	size_t _size;      //������ʾ�ַ����ĳ���
	size_t _capacity; //������ʾ�����ٵĶ�̬�ڴ�Ĵ�С
	char *_str;
};

 
#endif // __String__




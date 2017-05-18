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

	const char& String::operator[](size_t pos)const;//是为了防止定义为const的String类的对象被修改

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
	size_t _size;      //用来表示字符串的长度
	size_t _capacity; //用来表示所开辟的动态内存的大小
	char *_str;
};

 
#endif // __String__




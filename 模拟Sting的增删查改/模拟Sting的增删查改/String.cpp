#include "String.h"
ostream & operator <<(ostream& os, const String& s)
{
	 os << s._str;
	 return os;
}

String::String(const char *s )
:_capacity(1)
,_str(new char[Capacity(s)])

{
	strcpy(_str, s);
	_size = strlen(_str);
}

String::String(const String &s)
{
	_str = new char[Capacity(s._str)+1];
	strcpy(_str, s._str);
	_size = strlen(_str);
	_capacity = s._capacity;
}

String::~String()
{
	if (_str != NULL)
	{
		delete[] _str;
		_str = NULL;
		_capacity = _size = 0;
		cout << "~String()" << endl;
	}

}

char& String::operator[](size_t pos)  //改
{
	assert(pos < _size);
	return _str[pos];

}

const char&  String::operator[](size_t pos)const
//在成员函数后⾯加const，const修饰this指针所指向的对象，也就是保证调⽤这个
//const成员函数的对象在函数内不会被改变。
{
	assert(pos < _size);
	return _str[pos];

}

String& String::operator+= (const String& str)
{
	this->operator+=(str._str);
	return *this;
}

String& String::operator+= (const char* s)
{
	_str = (char*)realloc(_str, Capacity(s));
	strcpy(_str + _size, s);
	_size = strlen(_str);
	return *this;

}

String& String::operator+= (char c)
{
	char *tmp = &c;
	char *s = tmp;
	*(++tmp) ='\0';
	this->operator+=(s);
	return *this;
}

void String::Push_Back(char c)
{
	this->operator+=(c);
}

String&  String::Erase(size_t pos, size_t len)  //从指定结点开始删除到指定长度
{
	assert(pos < _size);
	if ((pos == _size) || (len == 0))  //不删除元素或者删除'\0'或者其之后的元素
	{
		return *this;
	}
	else if ((_str + pos + len)<(_str + _size))  //_size+_str刚好指向'\0',删除的数据未超过字符串长度
	{
		//挪动数据
		while (*(_str+pos+len))
		{
			*(_str + pos) = *(_str + pos + len);
			pos++;
		}
		*(pos + _str) = *(_str + pos + len);
		_size = strlen(_str);
		return *this;
	}
	else
	{
		*(pos + _str) = *(_size + _str);
		_size = strlen(_str);
		return *this;
	}
}

String String::Substr(size_t pos, size_t len) const //从某个结点截取多长的字符串
{
	assert(pos < _size);
	String tmp;
	char *cur = _str;
	while ((*(_str + pos) !='\0') && (len != 0)&&(*cur!='\0'))
	{
		tmp += *(_str + pos);
		pos++;
		len--;
		cur++;
	}
	return tmp;
}

String& String::operator= (const String& s)
{
	_str = new char[Capacity(s._str)];
	strcpy(_str, s._str);
	_size = strlen(_str);
	return *this;
}

String& String::Insert(size_t pos, const String& str, size_t Subpos, size_t Sublen)
//指定结点，插入指定String对象的指定位置开始的指定长度字符串
//注意使用指针访问数组元素和下标访问数组元素之间的联系和区别
//注意无符号数和有符号数之间的运算会发生隐式类型提升
{
	assert(pos < _size);
	String s=str.Substr(Subpos,Sublen);
	//开辟空间
	_str = (char*)realloc(_str,Capacity(s._str)*sizeof(char));
	size_t end = strlen(_str)+strlen(s._str);
	size_t count = Sublen;

	//挪动数据
	if (pos == _size )   //从'/0'位置处插入字符串
	{
		return *this += s;
	}
	else
	{
		
		//挪出Sublen个空间
		while (count)
		{
			if ((int)_size > (int)pos-1)
			{
				*(_str + end) = *(_str + _size);
			}
			_size--;
			end--;
			count--;
		}
		//插入数据
		count = s._size;
		char *cur = s._str;
		while (count)
		{
			*(_str + pos) = *(cur);
			cur++;
			pos++;
			count--;
		}
		return *this;
	}
}


int  String::Find(const char *s) const
{
	char *cur1 = _str;
	const char *cur2 = s;
	size_t pos = 0;
	while (cur1)
	{
		//abcde  cd

		while (*cur1 == *cur2)
		{
			cur1++;
			cur2++;
		}
		if (*cur2 == '\0')
		{
			return pos;
		}
		//ab   abde
		else  if (*cur1 == '\0'&&*cur2 != '\0')
		{
			return -1;
		}
		else
		{
			pos++;
			cur2 = s;
			cur1++;
		}
	}
	return  -1;

}

size_t String::Capacity(const char *s)
{
	_capacity += strlen(s) ;  //需要多大容量就增大多少容量
	return _capacity;
}


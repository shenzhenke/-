#include "Seqlist.h"

//注意每次增元素时_size增加，每次减元素时_size减少

Seqlist::Seqlist()
: _a(NULL)
, _size(0)
, _capacity(0)
{

}

Seqlist::Seqlist(Datetype d)
: _a((Datetype*)malloc(sizeof(Datetype)))
, _size(1)
, _capacity(1)
{
	*_a = d;
}

Seqlist::Seqlist(const Seqlist &s)//拷贝构造 
{
	if (s._a)
	{
		
		_a = (Datetype*)malloc(sizeof(Datetype)*s._capacity);
		//注意开辟容量的一致性，
		_size = s._size;
		_capacity = s._capacity;
		for (size_t i = 0; i < _size; i++)
		{
			_a[i] = s._a[i];
		}
	}
	else
	{
		_a = NULL;
		_size = 0;
		_capacity = 0;
	}
}

Seqlist & Seqlist::operator=(const Seqlist &s) //赋值
{

	Seqlist tmp(s);
	swap(tmp._a, _a);
	swap(tmp._capacity, _capacity);
	swap(tmp._size, _size);
	return *this;
}

Seqlist::~Seqlist()  //析构
{ 
	if (_a)
	{
		free(_a);
		_a = NULL;
		cout << "~Seqlist()" << endl;
	}
	else
	{
		cout << "~Seqlist" << endl;
	}
}

void Seqlist::Check_Capacitty()//检查容量是否足够增加数据
{
	if (_size == _capacity)
	{
		_capacity = _capacity * 2 + 3;
		_a = (Datetype*)realloc(_a,sizeof(Datetype)*_capacity);//会释放前面申请的空间
	}
}




Seqlist  Seqlist::Push_Back(Datetype d)//尾插
{
	Check_Capacitty();
	_a[_size] = d;
	_size++;
	return *this;
}

Seqlist & Seqlist::Push_Front(Datetype d) //头插
{
	Check_Capacitty();
	for (size_t i = _size; i > 0; i--)
	{
		_a[i] = _a[i - 1];
	}
	_a[0] = d;
	_size++;
	return *this;
}

Seqlist & Seqlist::Pop_Front()  //前删
{
	if (_size)
	{
		for (size_t i = 0; i < _size - 1; i++)
		{
			_a[i] = _a[i + 1];
		}
		_size--;
		return *this;
	}
	else
	{
		cout << "顺序表为空" << endl;
		return *this;
	}
}

Seqlist & Seqlist::Pop_Back()  //尾删
{
	if (_size)
	{
		_size--;
		return *this;
	}
	else
	{
		cout << "顺序表为空" << endl;
		return *this;
	}
}


Seqlist  & Seqlist::Insert(size_t pos, Datetype d)
//指定位置插入数据
{ 
	assert(pos < _size);  //防止空顺序表和插入数据位置大于等于顺序表的长度
	Check_Capacitty();
	if (pos == _size - 1)
	{
		this->Push_Back(d);
		return *this;
	}
	else
	{
		for (size_t i = _size; i > pos + 1; i--)
		{
			_a[i] = _a[i - 1];
		}
		_a[pos + 1] = d;
		_size++;
		return *this;
	}
}


int  Seqlist::Find(Datetype d) //找指定数据的位置
{
	if (_size)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (d == _a[i])
			{
				return i;
			}
		}
	}
	cout << "该顺序表没有该数据" << endl;
	return -1;
}

Seqlist & Seqlist::Erase(size_t pos)
//删除指定位置数据
{
	assert(pos < _size);
	if (pos == 0)
	{
		 this->Pop_Front();
	}
	else if (pos == _size - 1)
	{
		 this->Pop_Back();
	}
	else
	{
		for (size_t i = pos; i <_size; i++)
		{
			_a[i] = _a[i + 1];
		}
		_size--;
	}
	return *this;
}

Seqlist & Seqlist::Remove(Datetype d)//删第一次出现数据d的结点
{
	int pos = this->Find(d);
	if (pos >= 0)
	{
		this->Erase(pos);
		return *this;
	}
	return *this;
}

Seqlist & Seqlist::Inverse() //逆序顺序表
{
	if (_size)
	{
		if (_size / 2)
		{
			Datetype tmp;
			for (size_t i = 0; i < _size / 2; i++)//注意边界条件
			{
				tmp = _a[i];
				_a[i] = _a[_size - i - 1];
				_a[_size - i - 1] = tmp;  //注意顺序表的最后一个元素
			}
			return *this;
		} 
		return *this;  //有一个元素
	}
	cout << "此顺序表为空" << endl;
	return *this;
}

Seqlist & Seqlist::Sort() //排序顺序表
{
	if (_size)
	{
		size_t i = 0;
		size_t j = 0;
		Datetype tmp;
		for (j = 0; j < _size; j++)
		{
			for (i = 0; i < _size - 1 - j; i++)
			{
				if (_a[i]>_a[i + 1])
				{
					tmp = _a[i];
					_a[i] = _a[i + 1];
					_a[i + 1] = tmp;
				}
			}
		}
		return *this;
	}
	cout << "顺序表为空" << endl;
	return *this;
}

void Seqlist::Display()//遍历顺序表
{
	if (_size == 0)
	{
		cout << "Seqlist is NULL ";
	}
	for (size_t i = 0; i < _size; i++)
	{
		cout << _a[i] <<" ";
	}
	cout << endl;
}
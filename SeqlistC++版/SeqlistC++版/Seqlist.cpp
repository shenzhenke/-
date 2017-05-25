#include "Seqlist.h"

//ע��ÿ����Ԫ��ʱ_size���ӣ�ÿ�μ�Ԫ��ʱ_size����

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

Seqlist::Seqlist(const Seqlist &s)//�������� 
{
	if (s._a)
	{
		
		_a = (Datetype*)malloc(sizeof(Datetype)*s._capacity);
		//ע�⿪��������һ���ԣ�
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

Seqlist & Seqlist::operator=(const Seqlist &s) //��ֵ
{

	Seqlist tmp(s);
	swap(tmp._a, _a);
	swap(tmp._capacity, _capacity);
	swap(tmp._size, _size);
	return *this;
}

Seqlist::~Seqlist()  //����
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

void Seqlist::Check_Capacitty()//��������Ƿ��㹻��������
{
	if (_size == _capacity)
	{
		_capacity = _capacity * 2 + 3;
		_a = (Datetype*)realloc(_a,sizeof(Datetype)*_capacity);//���ͷ�ǰ������Ŀռ�
	}
}




Seqlist  Seqlist::Push_Back(Datetype d)//β��
{
	Check_Capacitty();
	_a[_size] = d;
	_size++;
	return *this;
}

Seqlist & Seqlist::Push_Front(Datetype d) //ͷ��
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

Seqlist & Seqlist::Pop_Front()  //ǰɾ
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
		cout << "˳���Ϊ��" << endl;
		return *this;
	}
}

Seqlist & Seqlist::Pop_Back()  //βɾ
{
	if (_size)
	{
		_size--;
		return *this;
	}
	else
	{
		cout << "˳���Ϊ��" << endl;
		return *this;
	}
}


Seqlist  & Seqlist::Insert(size_t pos, Datetype d)
//ָ��λ�ò�������
{ 
	assert(pos < _size);  //��ֹ��˳���Ͳ�������λ�ô��ڵ���˳���ĳ���
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


int  Seqlist::Find(Datetype d) //��ָ�����ݵ�λ��
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
	cout << "��˳���û�и�����" << endl;
	return -1;
}

Seqlist & Seqlist::Erase(size_t pos)
//ɾ��ָ��λ������
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

Seqlist & Seqlist::Remove(Datetype d)//ɾ��һ�γ�������d�Ľ��
{
	int pos = this->Find(d);
	if (pos >= 0)
	{
		this->Erase(pos);
		return *this;
	}
	return *this;
}

Seqlist & Seqlist::Inverse() //����˳���
{
	if (_size)
	{
		if (_size / 2)
		{
			Datetype tmp;
			for (size_t i = 0; i < _size / 2; i++)//ע��߽�����
			{
				tmp = _a[i];
				_a[i] = _a[_size - i - 1];
				_a[_size - i - 1] = tmp;  //ע��˳�������һ��Ԫ��
			}
			return *this;
		} 
		return *this;  //��һ��Ԫ��
	}
	cout << "��˳���Ϊ��" << endl;
	return *this;
}

Seqlist & Seqlist::Sort() //����˳���
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
	cout << "˳���Ϊ��" << endl;
	return *this;
}

void Seqlist::Display()//����˳���
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
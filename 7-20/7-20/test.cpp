#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#include <vector>
using namespace std;
class Array
{
public:
	Array(size_t size = 10)
		: _size(size)
		, _a(0)
	{
		cout << "Array(size_t size)" << endl;
		if (_size > 0)
		{
			_a = new int[size];
		}
	}
	~Array()
	{
		cout << "~Array()" << endl;
		if (_a)
		{
			delete[] _a;
			_a = 0;
			_size = 0;
		}
	}
private:
	int*_a;
	size_t _size;
};
void Test()
{
	Array* p1 = (Array*)malloc(sizeof (Array));
	Array* p2 = new Array;
	Array* p3 = new Array(20);
	Array* p4 = new Array[10];
	free(p1);
	delete p2;
	delete p3;
	delete[] p4;
}




class String
{
public:
	String(const char* str="")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}
	/*String(const String &s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}*/

	String(String& s)
	{
		String tmp(s._str);
		swap(s._str, _str);
	}
	String& operator=(String s)
	{
		if (this != &s)
		{
			swap(s._str, _str);
		}
		return *this;
	}

	~String()
	{
		if (_str != NULL)
			delete[] _str;
		_str = NULL;
	}

private:
	char* _str;
};



//入栈合法性判断
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		if (pushV.size() == NULL || popV.size() == NULL || popV.size() != pushV.size()) //为O(1)的算法
			return false;
		stack<int> s;
		int j = 0;
		for (size_t i = 0; i < pushV.size(); i++)
		{
			s.push(pushV[i]);
			while (!s.empty() && s.top() == popV[j])
			{
				s.pop();
				j++;
			}
		}
		if (s.empty() == true)
			return true;
		return false;
	}
};
void  TestIsPopOrder()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 4, 5, 3, 2, 1 };//合法
	int arr3[] = { 1, 2, 3, 4, 5 }; 
	int arr4[] = { 4, 5, 2, 3, 1 };// 则不合法。
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for (size_t i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++)
	{
		v1.push_back(arr1[i]);
		v2.push_back(arr2[i]);
		v3.push_back(arr3[i]);
		v4.push_back(arr4[i]);
	}
	Solution a;
	cout << a.IsPopOrder(v1, v2) << endl;
	cout << a.IsPopOrder(v3, v4) << endl;
}

//一个数字有多少比特位为1
int BitIsOne(int num)
{

	int count = 0;
	while (num)
	{
		num = num&(num - 1);
		count++;
	}
	return count;
}
int main()
{
	//Test();
	//TestIsPopOrder();
	cout << BitIsOne(10) << endl;
	return 0;
}
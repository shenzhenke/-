#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//using namespace std;
//template <class t>
//class seqlist
//{
//public:
//	seqlist()
//	{
//	}
//};
//
//template <int>
//class seqlist
//{
//public:
//	seqlist()
//	{}
//	~seqlist();
//};

//class A
//{
//	void fun();
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//template <class T>
//struct ListNode
//{
//	ListNode  *_next;
//	T _date;
//	ListNode(const T& x)
//		:_next(NULL)
//		, _date(x)
//	{
//
//	}
//};
//
//template <class T>
//class List
//{
//public:
//	typedef ListNode<T> Node;
//	List()
//		:_head(NULL)
//		, _len(0)
//	{
//
//	}
//private:
//	Node *_head;
//	int _len;
//};
//
//
//int main
//{
//  
//		 
//}


//#include <iostream>
//using namespace std;
//template <class T1,class T2>
// void Test(T1 &a, T2 &b)
//{
//	cout << "原生模板<T1,T2>" << endl;
//}
// 
// //这个不属于偏特化，而是一个原生模板
//template <class T2>  
// void Test(int &a, T2 &b)
// {
//	 cout << "原生模板<T2>" << endl;
// }
//
//template <>
//void Test(int &a, int &b)
//{
//	cout << "全特化" << endl;
//}
//
////template <class T2>  
////void Test(int &a, T2 &b)
////{
////	cout << "偏特化" << endl;
////}
////只能部分特例化类模板,而不能部分特例化函数模板,导致非法使用显式模板参数
////template <class T2>  
////void Test<int ,T2>(int &a, T2 &b)
////{
////	cout << "偏特化" << endl;
////}
//int main()
//{
//	int  a = 10;
//	int  b = 10;
//	char c = 10;
//    Test(a, b);  //输出全特化
//	Test(b, c);  //输出原生模板<T2>
//	Test(c, b);  //输出原生模板<T1,T2>
//	return 0;
//}


#include <iostream>
using namespace std;
//
//
template <class T1, class T2>
void Test(T1 a, T2 b)
{
	cout << "原生模板<T1,T2>" << endl;
}

//特化的模板要放在原生模板之后
template <>
void  Test<int,int>(int a, int b)
{
	cout << "全特化" << endl;
}

template <class T2>
void  Test<int,T2>(int a,T2)
{
	cout << "偏特化" << endl;
}
//
//template <class T2>  
//void Test(int a, T2 b)
//{
//	cout << "偏特化" << endl;
//}

//template <>
//void  Test(int &a, int &b)
//{
//	cout << "全特化" << endl;
//}

int main()
{
	int  a = 10;
	int  b = 10;
	char c = 10;
    Test(a, b);  //输出原生模板<T2>
	Test(b, c);  //输出原生模板<T2>
	Test(c, b);  //输出原生模板<T1,T2>
	return 0;
}





//类型萃取
//#include <iostream>
//#include <string>
//using namespace std;
//struct _TrueType
//{
//	bool Get()
//	{
//		return true;
//	}
//};
//struct _FalseType
//{
//	bool Get()
//	{
//		return false;
//	}
//};
//
//template <class _Tp>
//struct TypeTraits
//{
//	typedef _FalseType _IsPODType;
//};
//
//template <>
//struct TypeTraits<bool>
//{
//	typedef _TrueType _IsPODType;
//};
//
//template <>
//struct TypeTraits<char>
//{
//	typedef  _TrueType _IsPODType;
//};
//
//template <>
//struct TypeTraits<unsigned char>
//{
//	typedef  _TrueType _IsPODType;
//};
//
//template <>
//struct TypeTraits<int>
//{
//	typedef  _TrueType _IsPODType;
//};
//
//template <class _Tp>
//struct TypeTraits<_Tp*>
//{
//	typedef _TrueType _IsPODType;
//};
//
//
////使用参数推导的萃取处理
//
//template <class T>
//void Copy(const T* src,  T* dst, size_t size, _FalseType)
//{
//	cout << "_FasleType: " << typeid(T).name() << endl;
//	for (size_t i = 0; i < size; i++)
//	{
//		dst[i] = src[i];
//	}
//}
//
//template <class T>
//void Copy(const T* src,  T* dst, size_t size, _TrueType)
//{
//	cout << "_FasleType: " << typeid(T).name() << endl;
//	memcpy(dst, src, size*sizeof(T));
//}
//
//
//
////使用类型萃取判断Get函数来判断其是否是POD类型
//template <class T>
//void Copy(const T* src,  T* dst, size_t size)
//{
//	cout << "_TrueType: " << typeid(T).name() << endl;
//	if (TypeTraits<T>::_IsPODType().Get())
//	{
//		memcpy(dst, src, size*sizeof(T));
//	}
//	else
//	{
//		for (size_t i = 0; i < size; i++)
//		{
//			dst[i] = src[i];
//		}
//	}
//}
//
//void Test()
//{
//	string s1[10] = { "1", "2", "3", "44444444444444444" };
//	string s2[10] = { "11", "22", "33" };
//	Copy(s1, s2, 10, TypeTraits<string>::_IsPODType());
//	Copy(s1, s2, 10);
//
//
//	int a1[10] = { 1, 2, 3 };
//	int a2[10] = { 0 };
//	Copy(a1, a2, 10, TypeTraits<int>::_IsPODType());
//	Copy(a1, a2, 10);
//}


//int main()
//{
//	Test();
//	return 0;
//}





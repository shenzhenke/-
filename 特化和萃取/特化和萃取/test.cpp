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
//	cout << "ԭ��ģ��<T1,T2>" << endl;
//}
// 
// //���������ƫ�ػ�������һ��ԭ��ģ��
//template <class T2>  
// void Test(int &a, T2 &b)
// {
//	 cout << "ԭ��ģ��<T2>" << endl;
// }
//
//template <>
//void Test(int &a, int &b)
//{
//	cout << "ȫ�ػ�" << endl;
//}
//
////template <class T2>  
////void Test(int &a, T2 &b)
////{
////	cout << "ƫ�ػ�" << endl;
////}
////ֻ�ܲ�����������ģ��,�����ܲ�������������ģ��,���·Ƿ�ʹ����ʽģ�����
////template <class T2>  
////void Test<int ,T2>(int &a, T2 &b)
////{
////	cout << "ƫ�ػ�" << endl;
////}
//int main()
//{
//	int  a = 10;
//	int  b = 10;
//	char c = 10;
//    Test(a, b);  //���ȫ�ػ�
//	Test(b, c);  //���ԭ��ģ��<T2>
//	Test(c, b);  //���ԭ��ģ��<T1,T2>
//	return 0;
//}


#include <iostream>
using namespace std;
//
//
template <class T1, class T2>
void Test(T1 a, T2 b)
{
	cout << "ԭ��ģ��<T1,T2>" << endl;
}

//�ػ���ģ��Ҫ����ԭ��ģ��֮��
template <>
void  Test<int,int>(int a, int b)
{
	cout << "ȫ�ػ�" << endl;
}

template <class T2>
void  Test<int,T2>(int a,T2)
{
	cout << "ƫ�ػ�" << endl;
}
//
//template <class T2>  
//void Test(int a, T2 b)
//{
//	cout << "ƫ�ػ�" << endl;
//}

//template <>
//void  Test(int &a, int &b)
//{
//	cout << "ȫ�ػ�" << endl;
//}

int main()
{
	int  a = 10;
	int  b = 10;
	char c = 10;
    Test(a, b);  //���ԭ��ģ��<T2>
	Test(b, c);  //���ԭ��ģ��<T2>
	Test(c, b);  //���ԭ��ģ��<T1,T2>
	return 0;
}





//������ȡ
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
////ʹ�ò����Ƶ�����ȡ����
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
////ʹ��������ȡ�ж�Get�������ж����Ƿ���POD����
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





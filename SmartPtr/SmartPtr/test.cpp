//#include "AutoPtr.hpp"
//#include "ScopedPtr.hpp"
//#include "SharePtr.hpp"


//void TestAutoPtr()
//{
//	AutoPtr<int> ap1(new int);
//	*ap1 = 10;
//	AutoPtr<int> ap2(ap1); 
//	//*ap1 = 20;  
//	//这句代码会导致程序崩溃，因为当有两个对象的成员指针指向同一块区域时，前一个对象的成员指针会被置成空指针 
//	AutoPtr<int> ap3(new int(20));
//	ap2 = ap3;
//	AutoPtr<AA> ap4(new AA);
//	ap4->_a = 10;
//	ap4->_b = 20;
//	ap2 = ap3;
//}

//void TestScopedPtr()
//{
//	
//	ScopedPtr<int> ap1(new int);
//	*ap1 = 10;
//	ScopedPtr<int> ap3(new int(10));
////	ap3 = ap1;
////	ScopedPtr<int> ap4(ap1);
//	ScopedPtr<AA> ap2(new AA);
//	ap2->_a = 10;
//	ap2->_b = 20;
//	ScopedPtr<int> ap4(new int[10]);
//	int* ptr = (int*)(&ap4);
//	cout << *(ptr - 1) << endl;
//	cout << *((int*)ap4._ptr - 4) << endl;
//}

//
//void TestSharedPtr()
//{
//	SharedPtr<int,Delete<int>> ap3(new int(10));
//	SharedPtr<int,Delete<int>> ap4(ap3);
//	SharedPtr<int,DeleteArray<int>> ap5(new int[10]);
//	SharedPtr<FILE, Fclose>ap6(fopen("text.txt", "w"));
//}
//
//struct ListNode
//{
//	shared_ptr<ListNode> _prev;
//	//shared_ptr为库文件中实现的，只需包memory即可使用  
//	shared_ptr<ListNode> _next;
//	int data;
//	ListNode(int x)
//	{
//		data = x;
//		_prev = NULL;
//		_next = NULL;
//	}
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//int main()
//{
//	//TestAutoPtr();
//	TestScopedPtr();
////	TestSharedPtr();
////	shared_ptr<int> ap5(new int(10));
////	shared_ptr<int> ap6(new int[10]);
//	//shared_ptr<ListNode> cur(new ListNode(1));
//	//shared_ptr<ListNode> next(new  ListNode(2));
//	//cur->_next = next;
//	//next->_prev = cur;
//	return 0;
//}


#include <iostream>
using namespace std;
//#include <E:\比特科技\课件\boost_1_54_0\boost_1_54_0\boost\smart_ptr\shared_ptr.hpp>
//using namespace boost;
class A
{
public:
	int* _ptr;
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{

		cout << "~A()" << endl;
	}
};

int main()
{

	A a;
	A* pt = new A();
	int *PT = (int*)pt;
	cout << *(PT-4) << endl;
	A* ptr = new A[8];
	int *p = (int*)ptr;
	cout << *(p - 1) << endl;
	cout << *(p + 1) << endl;

//	cout << *((int*)(*p)) - 1 << endl;
//	cout << *p << endl;
	delete[] ptr;
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
////#include <windows.h>
////#include <stdlib.h>
//int main()
//{
//	////同样为申请一个大小为四十字节的堆空间
//	int *p_malloc = (int *)malloc(sizeof(int));
//
//
//
//	int *p_calloc1 = (int *)calloc(10, sizeof(int*));
//
//	
//	int *p_calloc2 = (int *)calloc(10, sizeof(char));
//	
//	
//	
//	int *ptr = (int *)realloc(0, sizeof(int)*1);
//	
//	p_calloc2 = (int *)realloc(p_calloc2, sizeof(char));
//
//
//	free(p_malloc);
//	free(p_calloc1);
//	free(p_calloc2);
//
//
//	//system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	//int *p = new int[9];
//	//delete []p;
//	int* p4 = new int;
//	int* p5 = new int(3);
//	int* p6 = new int[3];
//	int* p7 = (int*)malloc(sizeof (int));
//	delete[] p4;
//	delete p5;
//	//free(p5);
//	delete p6;
//	delete p7;
//	return 0;
//}


//new new[]和delete delete[]如果不配对使用,
//对于内置类型没有多大关系，对于自定义类型会导致程序崩溃，因为析构函数只调用了一次
//二者会自动调用构造函数和析构函数初始化和清理对象


//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	int *p1 = new int[10];
//	A *p2=new A[10];
//	new (p2) int(3);  //定位new表达式： new (地址)类型（值）
//
//	//*((int *)p2 - 1) = 5;
//	delete[] p1;
//	delete[] p2;
//	return 0;
//}



//class Array
//{
//public:
//	Array(int sz= 10)
//		:_ptr(NULL)
//		, _sz(sz)
//	{
//		cout << "Array(int sz= 10)" << endl;
//		if (_sz > 0)
//		{
//			_ptr = new int[_sz];
//		}
//	}
//	~Array()
//	{
//		cout << "~Array()" << endl;
//		if (_ptr != NULL)
//		{
//			delete[]_ptr;
//		}
//	}
//private:
//	size_t _sz;
//	int *_ptr;
//};
//
//int main()
//{
//	Array *pa = new Array;
//	delete pa;
//
//	//delete——>operator  delete-->free 
//	//new-->operator new-->malloc
//
//	return 0;
//}
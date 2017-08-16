#define _CRT_SECURE_NO_WARNINGS 
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
//};
//int main()
//{
//	A* pa = new A [10];
//	delete[] pa;
//	int* pb = new int[10];
//	delete pb;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	int a;
//};
//int main()
//{
//	A* ptr = NULL;
//	ptr->a = 1;
//	return 0;
//}







#include <stdio.h>
//#include  <map>
//using namespace std;
enum Color
{
	GREEN = 1,
	RED,
}Colorval;

//#define X 3;
//#define Y X*2
//#undef X
//#define X 2
//int z = Y;
int main()
{

	//cout << z << endl;
	//int i = 0;

	//i = (1, 2 * i);     //第①个是一个赋值表达式，将一个逗号表达式的值赋给x，x的值等于0。
	//
	//cout << i << endl;
	//i = 1, 2 * i;	  //第②个是逗号表达式，它包括一个赋值表达式和一个算术表达式，x的值为1。


	//cout << i << endl;
	//cout << sizeof(Colorval) << endl;

	//char a[5] = { 'A', 'B', 'C', 'D' };
	//char(*p3)[3] = &a;
	//char(*p3)[3] = a;

	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	int *p;
	p = a[0];
	printf("%d\n", p[0]);   //p[0]的值应该为1,而不是0注意包含逗号表达式问题

	char* (*fun)(char* str);		 //函数指针
	char* (*arr[3])(char* str);    //函数指针数组
	char* (*(*arr)[3])(char* str); //函数指针数组指针 一般将名字从右往左依次解析

	return 0;
}

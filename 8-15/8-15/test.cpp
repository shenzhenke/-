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

	//i = (1, 2 * i);     //�ڢٸ���һ����ֵ���ʽ����һ�����ű��ʽ��ֵ����x��x��ֵ����0��
	//
	//cout << i << endl;
	//i = 1, 2 * i;	  //�ڢڸ��Ƕ��ű��ʽ��������һ����ֵ���ʽ��һ���������ʽ��x��ֵΪ1��


	//cout << i << endl;
	//cout << sizeof(Colorval) << endl;

	//char a[5] = { 'A', 'B', 'C', 'D' };
	//char(*p3)[3] = &a;
	//char(*p3)[3] = a;

	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	int *p;
	p = a[0];
	printf("%d\n", p[0]);   //p[0]��ֵӦ��Ϊ1,������0ע��������ű��ʽ����

	char* (*fun)(char* str);		 //����ָ��
	char* (*arr[3])(char* str);    //����ָ������
	char* (*(*arr)[3])(char* str); //����ָ������ָ�� һ�㽫���ִ����������ν���

	return 0;
}

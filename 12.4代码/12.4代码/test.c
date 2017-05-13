#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
//
//#define MYCHAR char*
//typedef char* mychar;

int main()
{
	const int a = 10;
	const int * p = &a;
	*p = 20;
	printf("%d\n", a);
	//int  a = 10;
	//int * p = &a;
	// int  * const *q = &p;
	//q = 10;
	//*q = 10;
	//**q = 10;
	//*p = 10;
	//p = 10;

	//mychar a, x; 
	//MYCHAR b, y;//char* b, y;
	//printf("%d, %d, %d, %d\n",\
		//	sizeof(a), sizeof(x), sizeof(b), sizeof(y) );
	//int **p;
	//MYINT a;
	//a = 10;
	//printf("%d\n", a);
	system("pause");
	return 0;
}

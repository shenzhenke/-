//#include <stdio.h>
//int main()
//{
//	int a = 3, b = 4;           
//	printf("a=%d b=%d\n", a, b);
//	a = a+b;                                   
//	b = a-b;   
//	a = a-b;
//	printf("a=%d b=%d", a, b);            
//	return 0;
//}


////#include <stdio.h>
//int main()
//{
//	int a = 3, b = 4;
//	printf("a=%d b=%d\n", a, b);  /*��ȡ��λ��������ʵ���������Ľ���.
//			                        ^����Ϊ������λ���.����Ϊһ;��ͬΪ��.*/
//	a = a^b;          //a=0111. �������:    0011   (����ʾΪ������)
//                     /*                    ^ 0100   ���ı�ʾΪ�����ƣ�
//	                                         0111    (����Ϊһ;��ͬΪ��)           */
//	b = a^b;                                 // b=0011
//	a = a^b;                                //  c=0100
//	printf("a=%d b=%d", a, b);
//	return 0;
//}








//
//#include<stdio.h>
//
//int main()
//{
//
//	int a, b;
//	printf("��������������");
//	scanf_s("%d,%d", &a, &b);
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("%d,%d\n", a, b);
//
//	return 0;
//}







//#include<stdio.h>
//int main()
//{
//	int x=3;
//	if (5=x)
//	{
//		printf("Hello World");
//	}
//	return 0;
//}
//
//









//#include<stdio.h>  
//int main()
//{
//	int num;
//
//	int count = 0, i = 32;
//
//	printf("������һ������:");
//
//	scanf_s("%d", &num);
//
//	while (i--)
//	{
//		if ((num & 1) == 1)//��λ��&,ͬΪ1ʱ��1  
//		{
//			count++;
//		}
//		num = num >> 1;//����1λ,�൱��num/2  
//	}
//
//	printf("��������ڶ������� 1 �ĸ���:");
//
//	printf("%d\n", count);
//
//	return 0;
//}




#include <stdio.h> 
int main()
{
	 int num = 0;
	 int count = 0;
	 printf("����һ����:");
	scanf_s("%d", &num);
	while (num != 0)
	{
		count++;
		num = num&(num - 1);
	}
	printf("count=%d\n", count);
	return 0;
}
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
//	printf("a=%d b=%d\n", a, b);  /*采取按位异或运算符实现两个数的交换.
//			                        ^符号为二进制位异或.相异为一;相同为零.*/
//	a = a^b;          //a=0111. 具体计算:    0011   (三表示为二进制)
//                     /*                    ^ 0100   （四表示为二进制）
//	                                         0111    (相异为一;相同为零)           */
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
//	printf("请输入两个数：");
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
//	printf("请输入一个数字:");
//
//	scanf_s("%d", &num);
//
//	while (i--)
//	{
//		if ((num & 1) == 1)//按位与&,同为1时出1  
//		{
//			count++;
//		}
//		num = num >> 1;//右移1位,相当于num/2  
//	}
//
//	printf("输出数字在二进制中 1 的个数:");
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
	 printf("输入一个数:");
	scanf_s("%d", &num);
	while (num != 0)
	{
		count++;
		num = num&(num - 1);
	}
	printf("count=%d\n", count);
	return 0;
}
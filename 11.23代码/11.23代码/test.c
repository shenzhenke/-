#define _CRT_SECURE_NO_WARNINGS
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？

//#include <stdio.h>
//int main()
//{
//	int a = 1999;
//	int b = 2299;
//	int i = 0;
//	int k = 0;
//	int count = 0;  // 用来统计二进制位不相同的个数
//	for (i = 0; i < 32; i++)
//	{
//		k = ((a >> i)&1) ^ ((b >> i)&1); //^按位异或,相同出零,相异出一,&按位与同一出一,其余出零
//		if (1 == k)
//		{
//			count++;
//		}
//	}
//	printf("%d\n",count);
//	return 0;
//}

//unsigned int  reverse_bit(unsigned int value);
//这个函数的返回 值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832

//#include <stdio.h>
//#include <math.h>
//double  reverse_bit(unsigned int value)
//{
//	int i = 0;
//	double sum = 0;
//	int k = 0;
//	for (i = 0; i < 32; i++)
//	{
//		k=(value >> i) & 1;
//		sum = sum + k*pow(2,31-i);
//	}
//	return sum;
//}
//int main()
//{
//	unsigned int value = 25;
//	double ret = reverse_bit(value);
//    printf("%lf\n",ret);
//	return 0;
//}

//
//4.
//一组数据中只有一个数字出现了一次。
//其他所有数字都是成对出现的。请找出这个数字。（使用位运算）
//如：
//数据：1 3 5 7 1 3 5 8这组数据中，只有7出现了一次。
//结构：找到的数就是：7.

//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1, 3, 5, 7, 1, 3, 5 };
//	int i = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	int j = 0;
//	int m = 0;
//	for (k = 0; k < i; k++)
//	{
//		for (j = 0; j < i ; j++)
//		{
//			if ((0 == (arr[k] ^ arr[j])) && (k != j))
//			{
//				m = 1;
//				break;
//			}
//			m = 0;
//		}
//		if (0 == m)
//		{
//			printf("%d\n", arr[k]);
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//
//	int arr[] = { 1, 3, 5, 7, 1, 3, 5 };
//	int i = 0;
//	int k = sizeof(arr) / sizeof(arr[0]);
//	for (i = 1; i < k; i++)
//	{
//		arr[0] = arr[0] ^ arr[i];
//		//将这组数中所有数取按位或，由于相异为1，相同为0，故位运算剩下为1的就是单数
//	}
//	printf("这个单数是：%d\n", arr[0]);
//	return 0;
//}
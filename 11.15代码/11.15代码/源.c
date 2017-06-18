#define _CRT_SECURE_NO_WARNINGS

//交换两个数组的内容
//#include <stdio.h>
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4 };
//	int arr2[] = { 5, 6, 7, 8 };
//	int temp = 0;
//	int i = 0;
//	for (i = 0; i <= 3; i++)
//	{
//		temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//	}
//	for (i = 0; i <= 3; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i <= 3;i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//void swap(int arr1[], int arr2[] ,int sz)
//{
//	int temp = 0;
//	int k = 0;
//	for (k = 0; k <= sz - 1; k++)
//	{
//		temp = arr1[k];
//		arr1[k] = arr2[k];
//		arr2[k] = temp;
//	}
//}
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[] = { 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	int  i = 0;
//	swap(arr1,arr2,sz);
//	for (i = 0; i <= sz - 1; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i <= sz - 1; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}

  //三个数按从大到小输出
//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//
//	scanf("%d%d%d",&a,&b,&c);
//	if (a > b)
//	{
//		if (a > c)
//		{
//			if (c > b)
//				printf("%d %d %d", a, c, b);
//			else
//				printf("%d %d %d", a, b, c);
//		}
//		else
//		{
//			printf("%d %d %d",c,a,b);
//		}
//	}
//	else
//	{
//		if (b > c)
//		{
//			if (c > a)
//				printf("%d %d %d", b, c, a);
//			else
//				printf("%d %d %d", b, a, c);
//		}
//		else
//		{
//			printf("%d %d %d", c, b, a);
//		}
//	}
//	return 0;
//}


////求最大公约数
//#include <stdio.h>
//int main()
//{
//	int n, m;
//	int k = 0;
//	scanf("%d%d",&n,&m);
//	while (n%m != 0)
//	{
//		k = n%m;
//		n = m;
//		m = k;
//	}
//	printf("%d",m);
//	return 0;
//}

//获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列

#include <stdio.h>
int main()
{
	int i = 0;
	int num;
	printf("请输入数据：");
	scanf("%d",&num);
	printf("奇数序列为：");
	for (i = 30; i >=0 ; i -= 2)   //按位输出
	{
		printf("%d",((num >> i)&1));
	}
	printf("\n");
	printf("偶数序列为：");
	for (i = 31; i >=1 ; i -= 2)
	{
		printf("%d",((num >> i)&1));
	}
	printf("\n");
	return 0;
}

//打印100 - 200之间的素数
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i = 0;
//	int k = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (k = 2; k <= sqrt(i); k++)
//		{
//			if (i%k == 0)
//				break;
//		}
//		if (k > sqrt(i))
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount=%d\n",count);
//	return 0;
//}


//打印乘法口诀表
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d   ", i, j, i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//判断1000 - 2000之间的闰年
//#include <stdio.h>
//int main()
//{
//	int count = 0;
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (((0 == year % 4) && (0 != year % 100)) || (0 == year % 400))
//		{
//			count++;
//			printf("%d ", year);
//		}
//	}
//	printf("\ncount=%d\n",count);
//	return 0;
//}






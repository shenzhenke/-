#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//#include <windows.h>
//int main()
//{
//	//int K, 
// //    *p=&K;  //定义的整型的数据k和整型的*p。p只是一个指针，等于一个k的地址数据，就是指向k。
//	//scanf("%d", p);
//	//char s[] = "123", *p;
//	//p = s;
//	//printf("%c\n",*p++);   //1
//	/*int a = 1;
//	int b = 0;
//	int c = 0;
//	if (a > b > c)
//	{
//		printf("qwr");
//	}*/
//	//int(*p)(void);
//	system("pause");
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string a = "hello world";  //0x00f3fe54
//	string b = a;    //0x00f3fe30
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//	string c = b;
//	c = "";
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//	a = "";
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//	return 0;
//}





//
////测试数据有多少个不相同的二进制位
//#include<iostream>
//using namespace std;
//int countBitDiff(int m, int n)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((m & (1 << i)) != (n & (1 << i)))
//			count++;
//	}
//	return count;
//}
//
//int main()
//{
//	cout << countBitDiff(1999, 2299) << endl;
//	return 0;
//}


//二维数组打印问题
//#include <iostream>
//#include <vector>
//using  namespace std;
//vector<int> arrayPrint(vector<vector<int> > arr, int n)
//{
//	vector<int> array;
//	int i = 0;
//	int j = n - 1;
//	for (int k = 0; k < n; k++)
//	{
//		i = 0;
//		j = n - k - 1;
//		array.push_back(arr[i][j]);
//		while ((++i) < n && (++j) < n)
//		{
//			array.push_back(arr[i][j]);
//		}
//	}
//	for (int k = 0; k < n - 1; k++)
//	{
//		i = k + 1;
//		j = 0;
//		array.push_back(arr[i][j]);
//		while ((++i) < n && (++j) < n)
//		{
//			array.push_back(arr[i][j]);
//		}
//	}
//	return  array;
//}
//int main()
//{ 
//	vector<vector<int> > vecInt(4, vector<int>(4));
//	int a[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
//	for (int i = 0; i < 4; i++)    //初始化二维数组，，其实这里可以不用初始化的，vector中默认初始化为0  
//	for (int j = 0; j < 4; j++)
//		vecInt[i][j] = a[i][j];
//	vector<int> arr = arrayPrint(vecInt, 4);
//	for (int i = 0; i < 16; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}



//最大直方图问题
//有一个直方图，用一个整数数组表示，其中每列的宽度为1，求所给直方图包含的最大矩形面积。
//比如，对于直方图[2, 7, 9, 4], 它所包含的最大矩形的面积为14(即[7, 9]包涵的7x2的矩形)。
//给定一个直方图A及它的总宽度n，请返回最大矩形面积。保证直方图宽度小于等于500。保证结果在int范围内

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int countArea(vector<int> A, int n)
//{
//	sort(A.begin(), A.end());
//	int Size = n;
//	for (int i = 0; i < n; i++)
//	{
//		A[i] = A[i] * Size;
//		Size--;
//	}
//	sort(A.begin(), A.end());
//	return A[n - 1];
//}
//int main()
//{
//	vector<int> A;
//	A.push_back(9);
//	A.push_back(8);
//	A.push_back(9);
//	A.push_back(4);
//	cout << countArea(A, 4) << endl;
//	return 0;
//}



//题目描述
//对于一个有序数组，我们通常采用二分查找的方式来定位某一元素，请编写二分查找的算法，
//在数组中查找指定元素。给定一个整数数组A及它的大小n，同时给定要查找的元素val，
//请返回它在数组中的位置(从0开始)，若不存在该元素，返回 - 1。若该元素出现多次，
//请返回第一次出现的位置。

//#include <iostream>
//#include <assert.h>
//#include <vector>
//using namespace std;
//int getPos(vector<int> A, int n, int val)
//{
//	assert(n > 0);
//	int left = 0;
//	int right = n;
//	int mark = -1;
//	while (left < right)
//	{
//		int mid = (left >> 1) + (right >> 1);
//		if (val > A[mid])
//		{
//			left = mid + 1;
//		}
//		else if (val < A[mid])
//		{
//			right = mid ;
//		}
//		else
//		{
//			mark = mid;
//			if (mid % 2 != 0)
//			{
//				right = mid;
//				left = 0;
//			}
//			else
//			{
//				right = mid - 1;
//				left = 0;
//			}
//		}
//	}
//	return mark;
//}
//int main()
//{
//	vector<int> A;
//	A.push_back(1);
//	A.push_back(3);
//	//A.push_back(9);
//	A.push_back(5);
//	A.push_back(7);
//	A.push_back(9);
//	A.push_back(9);
//	A.push_back(11);
//	//A.push_back(13);
//
//	cout << getPos(A, 7, 1) << endl;
//	cout << getPos(A, 7, 3) << endl;
//	cout << getPos(A, 7, 5) << endl;
//	cout << getPos(A, 7, 7) << endl;
//	cout << getPos(A, 7, 9) << endl;
//	cout << getPos(A, 7, 11) << endl;
//	cout << getPos(A, 7, 13) << endl;
//
//	/*cout << getPos(A, 8, 1) << endl;
//	cout << getPos(A, 8, 3) << endl;
//	cout << getPos(A, 8, 5) << endl;
//	cout << getPos(A, 8, 7) << endl;
//	cout << getPos(A, 8, 9) << endl;
//	cout << getPos(A, 8, 11) << endl;
//	cout << getPos(A, 8, 13) << endl;*/
//	return 0;
//}




//题目描述
//对于一个字符串，请设计一个高效算法，找到第一次重复出现的字符。
//给定一个字符串(不一定全为字母)A及它的长度n。请返回第一个重复出现的字符。
//保证字符串中有重复字符，字符串的长度小于等于500
//#include <iostream>
//#include <assert.h>
//#include <vector>
//#include <map>
//using namespace std;
//char findfirstrepeat(string a, int n)
//{
//	assert(n > 1 && n <= 500);
//	map<char, int> t;
//	for (int i = 0; i < n; i++)
//	{
//		if (t.insert(pair<char, int>(a[i], 1)).second == 0)
//			return a[i];
//	}
//	/*int num = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = num + 1; j < n ; j++)
//		{
//			if (a[i] == a[j])
//				return a[i];
//		}
//		num++;
//	}*/
//	return -1;
//}
//int main()
//{
//	string s = "012340dbcdd";
//	int n = s.size();
//	cout << findfirstrepeat(s, n) << endl;
//	return 0;
//


#include <stdio.h>
int main()
{
	int i = 0;
	int arr[100] = { 0 };    //定义一个数组来存放每个数产生的因子
	for (i = 2; i <= 1000; i++)
	{
		int m = 0;
		int k = 0;
		int j = 0;
		int sum = 0;
		for (m = 1; m < i; m++)//此处不能用<=;完数的因子不能包括它本身
		{
			if (i%m == 0)    //找出i除了他本身之外的所有因子
			{
				arr[k] = m;  //将找到的因子存放在数组中
				k++;       //用k的值来判断i共有多少个因子
			}

		}
		for (j = 0; j < k; j++)
			//此处不能用<=;因为数组的下标从0开始,并且存放因子的时候也是a[0]开始存的
		{
			sum = arr[j] + sum;   //用sum来表示它的因子相加的和
		}
		if (sum == i) //如果因子之和等于i,则将i打印出来.
		{
			for (int m = 0; m < k; m ++)
			{
				if (m == 0)
					printf("%d", arr[m]);
				else
					printf("+%d", arr[m]);
			}
			printf("=%d\n", i);
		}
	}
	return 0;
}
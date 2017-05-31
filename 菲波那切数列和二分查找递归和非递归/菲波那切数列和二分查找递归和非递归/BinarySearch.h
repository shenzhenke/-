#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//二分查找递归和非递归算法
//非递归算法
//bool BinaryFuntion(int key, int len, int *arr)
//{
//  int right = len - 1;
//	int  left = 0;
//	while (left <= right)
//	{
//		if (key == arr[(right + left) / 2])
//		{
//			return true;
//		}
//		else if (key > arr[(right + left) / 2])
//		{
//			left = (right + left) / 2 + 1;
//		}
//		else
//		{
//			right = (right + left) / 2 - 1;
//		}
//	}
//	return false;
//}

//递归算法
bool BinaryFuntion(int key, int left,int right, int *arr)
{
	int mid = (right - left) / 2 + left;
	if (left > right)
	{
		return false;
	}
	else
	{    if (arr[mid] == key)
		{
			return true;
		}
		else if (arr[mid] < key)
		{
			return BinaryFuntion(key, mid + 1, right, arr);
		}
		else
		{
			return BinaryFuntion(key, left, mid - 1, arr);
		}
	}
}

//二分法不管是否递归它的时间复杂度都为O(log2N),
//非递归的空间复杂度为O(1),递归的空间复杂度为O(log2N)
int main()
{
	int arr[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	int key = 19;
	int right = sizeof(arr) / sizeof(int)-1;
	int left = 0;
	cout << BinaryFuntion(key, left, right, arr) << endl;
	return 0;
}
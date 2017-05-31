#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//���ֲ��ҵݹ�ͷǵݹ��㷨
//�ǵݹ��㷨
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

//�ݹ��㷨
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

//���ַ������Ƿ�ݹ�����ʱ�临�Ӷȶ�ΪO(log2N),
//�ǵݹ�Ŀռ临�Ӷ�ΪO(1),�ݹ�Ŀռ临�Ӷ�ΪO(log2N)
int main()
{
	int arr[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	int key = 19;
	int right = sizeof(arr) / sizeof(int)-1;
	int left = 0;
	cout << BinaryFuntion(key, left, right, arr) << endl;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#include "arrayoperation.h"
int main()
{
	//vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(2);
	//v.push_back(2);
	//v.push_back(2);
	//v.push_back(2);
	//v.push_back(10);
	//v.push_back(3);
	//Gift gift;
	//cout << gift.getValue(v, v.size()) << endl;


	//vector<vector<int> > array(5);
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		array[i].push_back((i+1)*(j+2));
	//	}
	//}
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		cout << array[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//Solution c;
	//cout << c.Find(1, array) << endl;
	//cout << c.Find(2, array) << endl;
	//cout << c.Find(3, array) << endl;
	//cout << c.Find(4, array) << endl;
	//cout << c.Find(5, array) << endl;
	//cout << c.Find(10, array) << endl;
	//cout << c.Find(15, array) << endl;
	//cout << c.Find(4, array) << endl;
	//cout << c.Find(6, array) << endl;
	//cout << c.Find(8, array) << endl;
	//cout << c.Find(10, array) << endl;
	//cout << c.Find(12, array) << endl;
	//cout << c.Find(6, array) << endl;
	//cout << c.Find(9, array) << endl;
	//cout << c.Find(12, array) << endl;
	//cout << c.Find(15, array) << endl;
	//cout << c.Find(18, array) << endl;
	//cout << c.Find(30, array) << endl;
	//cout << c.Find(25, array) << endl;

	//Solution a;
	//int arr[] = { 1, 6, 2, 3, 4, 5, 1, 2, 1, 1 };
	//vector<int> v;
	//for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	v.push_back(arr[i]);
	//}
	//cout << a.MoreThanHalfNum_Solution(v) << endl;


//	//子数组最大和测试用用例
//	Solution a;
////	int arr[] = { -1, -6, -2, -3, -4, -5, -1, -2, -1, -10 };
//	int arr[] = { 2, -5, 4, 9, -3, 6, 8, -7, 1, 100 };
////	int arr[] = { 2, -5 };
//
//	cout << a.SubArrayMaxSum(arr, sizeof(arr) / sizeof(arr[0])) << endl;

	//子数组最大和为给定值测试用用例
		Solution a;
		int arr[] = { 6, 1, 7, 1, 2, 2, 1, 3, 1, 1, 1, 1, 1 };
	//	int arr[] = { 2, -5, 4, 9, -3, 6, 8, -7, 1, 100 };
	////	int arr[] = { 2, -5 };
	//
		cout << a.SubArrayMaxLegth(arr, sizeof(arr) / sizeof(arr[0]), 5) << endl;
	return 0;
}
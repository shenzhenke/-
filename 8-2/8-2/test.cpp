#define _CRT_SECURE_NO_WARNINGS 

//归并排序
//#include <iostream>
//using namespace std;
//void _Merge(int *arr, int * tmp, int begin1, int end1, int begin2, int end2)
//{
//	int i = begin1;
//	int index = begin1;
//	while (begin1 <= end1&&begin2 <= end2)
//	{
//		if (arr[begin1] < arr[begin2])
//		{
//			tmp[i] = arr[begin1];
//			i++;
//			begin1++;
//		}
//		else
//		{
//			tmp[i] = arr[begin2];
//			i++; 
//			begin2++;
//		}
//	}
//	if (begin1 > end1)  //证明第二部分还有数据没有合上去
//	{
//		while (begin2 <= end2)
//		{
//			tmp[i] = arr[begin2];
//			i++;
//			begin2++;
//		}
//	}else
//	{
//		while (begin1 <= end1)
//		{
//			tmp[i] = arr[begin1];
//			i++;
//			begin1++;
//		}
//	}
//	while (index < i)
//	{
//		arr[index] = tmp[index];
//		index++;
//	}
//	return;
//}
//
//void _MergeSort(int* arr, int* tmp, int begin, int end)
//{
//	if (begin >= end)
//		return;
//	int mid = (end - begin) / 2 + begin;
//	_MergeSort(arr, tmp, begin, mid);
//	_MergeSort(arr, tmp, mid + 1, end);
//	_Merge(arr, tmp, begin, mid, mid + 1, end);
//}
//void MergeSort(int *arr, int n)
//{
//	if (arr == NULL || n <= 1)
//		return;
//	int* tmp = new int[n];
//	_MergeSort(arr, tmp, 0, n - 1);
//	delete[] tmp;
//}
//int main()
//{
//	int arr[] = { -1, 2, -2, -2, -2, -4, -2, 4, 6, 8, 9 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	MergeSort(arr, n);
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}





#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int main()
{
	vector<int> numbers;
	int number;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		numbers.push_back(number);
	}
	int count = 0;
	sort(numbers.begin(), numbers.end());
	int index = 0;
	for (; index < n - 1; index++)
	{
		if (numbers[index] + numbers[index + 1] >= m)
			break;
	}
	int begin = index;
	for (; begin < n - 1; begin++)
	{
		if (numbers[begin] + numbers[0] >= m)
			break;
	}
	int mark = index;
	for (; index < n; index++)
	{
		if (index >= begin)
		{
			for (int j = 0; j < index; j++)
			{
				if ((numbers[index] ^ numbers[j])>m)
					count++;
			}
		}
		else
		{
			for (int j = mark; j < index; j++)
			{
				if ((numbers[index] ^ numbers[j])>m)
					count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}

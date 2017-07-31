#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void InsertSort(int *arr, int n)
{
	if (arr == NULL || n <= 1)
		return;
	int end = 0;
	while (end < n - 1)  //�ӿ�ʼ��end����������ģ�Ȼ��һ��һ���������,��Ҫ�����ľͽ���
	{
		int index= end;
		int tmp = arr[index + 1];
		if (tmp > arr[index])
		{
			arr[index + 1] = tmp;
		}
		else
		{
			while (index >= 0 && tmp < arr[index])
			{
				arr[index + 1] = arr[index];
				index--;
			}
			arr[index + 1] = tmp;
		}
		end++;
	}
	return;
}

void HillSort(int* arr,int n)  //����汾
{
	if (arr == NULL || n <= 1)
		return;
	int gap, i,j;
	for (gap = n / 2; gap > 0; gap /= 2)  //����ÿ��ȡһ��
	{
		for (i = 0; i < gap; i++)
		{
			for (j = i; j < n; j += gap)
			{
				int index = j - gap;
				int tmp = arr[j];
				while (index >= 0 && tmp < arr[index]) 
				//ÿ��ȥ��ǰ����û�бȵ�λ�ô������,�оͺ���
				{
					arr[index+gap]=arr[index];
					index -= gap;
				}
			}
		}
	}
	return;
}


//void ShellSort(int* arr,int n)
//{
//	if (arr == NULL || n <= 1)
//		return;
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;  //��֤gap����Ϊ1
//		for (int i = 0; i < n - gap; i++)  //��ÿ��λ����gap�����ǰ����
//		{
//			int end = i;
//			int temp = arr[end + gap];
//			for (; end >= 0; end -= gap)
//			{
//				if (temp>arr[end])
//					break;
//				arr[end + gap] = arr[end];
//			}
//			arr[end + gap] = temp;  
//		}
//	}
//	return;
//}

//#!/bin/bash
//arr = (0 8 7 4 5 - 1)
//gap = ${ #arr[@] }
//while[$gap - gt 1]
//	do
//	let  gap = $gap / 3 + 1
//	for ((i = 0; i<${ #arr[@] }-$gap; i++))
//	do
//	end = $i
//		temp = ${ arr[$end + $gap] }
//	for ((; $end >= 0; end = $end - $gap))
//	do
//	if[$temp - gt ${ arr[$end] }]
//		then
//		break
//	else
//	arr[$end + $gap] = ${ arr[$end] }
//	fi
//		done
//		arr[$end + $gap] = $temp
//		done
//		done
//		j = 0
//	while[$j - lt ${ #arr[@] }]
//		do
//		echo "arr[$j]=${arr[$j]}"
//			let j++
//		done


//void SelectSort(int *arr, int n)
//{
//	if (arr == NULL || n <= 1)
//		return;
//	for (int i = 0; i < n / 2; i++)
//	{
//		int maxIndex = i;
//		int minIndex = i;
//		for (int j = i; j < n - i; j++)
//		{
//			if (arr[j] > arr[maxIndex])
//				maxIndex = j;
//			if (arr[j] <= arr[minIndex])
//				minIndex =j;
//		}
//		swap(arr[i], arr[minIndex]);
//		swap(arr[n - i - 1], arr[maxIndex]);
//	}
//	return;
//}

void SelectSort(int *arr,int n)
{
	if (arr == NULL || n <= 1)
		return;
	int end = n - 1;
	int begin = 0;
	while (end > begin)
	{
		int cur = begin;
		int max = begin;
		int min = begin;
		while (cur <= end)
		{
			if (arr[cur] > arr[max])
				max = cur;
			if (arr[cur] < arr[min])
				min = cur;
			cur++;
		}
		swap(arr[end], arr[max]);
		swap(arr[begin], arr[min]);
		end--;
		begin++;
	}
	return;
}

void AdjustDown(int *arr, int n, int i)
{
	int parent = i;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&arr[child + 1] > arr[child])
			child = child + 1;
		if (arr[child] > arr[parent])
			swap(arr[child], arr[parent]);
		parent = child;
		child = parent * 2 + 1;
	}
	return;
}

void HeapSort(int *arr, int n)
{
	if (arr == NULL || n <= 1)
		return;
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, n, i);
	}
	int index = n;
	while (index > 0)
	{
		swap(arr[0], arr[index - 1]);
		index--;
		AdjustDown(arr, index, 0);
	}
	return;
}

void AdjustDownFruits(vector<pair<string, int>>& help, int n, int i)
//�������ֻ���������Ѷ�Ԫ�ط����仯ʱ
{
	int parent = i;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n &&help[child].second > help[child + 1].second)
			child = child + 1;
		if (help[child].second < help[parent].second)
			swap(help[child], help[parent]);
		//	pair<string, int> temp = help[child];
		parent = child;
		child = parent * 2 + 1;
	}
	return;
}


void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{
	map<string, int> countFruits;
	for (size_t i = 0; i < fruits.size(); i++)
	{
		countFruits[fruits[i]]++;
	}
	vector<pair<string, int>> help;
	map<string, int>::iterator it = countFruits.begin();
	while (it != countFruits.end())
	{
		help.push_back(make_pair(it->first, it->second));
		it++;
		k--;
		if (k == 0)
			break;
	}
	struct Compare
	{
		bool operator()(const pair<string, int> &s1,const pair<string,int> &s2)
		{
			if (s1.second >= s2.second)
				return true;
			else
				return false;
		}
	};
	make_heap(help.begin(), help.end(),Compare());
	while (it != countFruits.end())
	{
		if (help[0].second < it->second)  //֤����ǰˮ���������ȶѶ�������Ҫ��
		{
			help[0] = make_pair(it->first, it->second);
			AdjustDownFruits(help, help.size(), 0);
		}
		it++;
	}
	for (size_t i = 0; i < help.size(); i++)
	{

		string s = help[i].first;
		cout << s.c_str() << " " << endl;
	}
	return;
}

void TestGetFavoriteFruit()
{
	vector<string> v;
	v.push_back("�㽶");
	v.push_back("�㽶");
	v.push_back("�㽶");
	v.push_back("�㽶");
	v.push_back("�㽶");
	v.push_back("�㽶");
	v.push_back("����");
	v.push_back("����");
	v.push_back("����");
	v.push_back("ƻ��");
	v.push_back("ƻ��");
	v.push_back("ƻ��");
	v.push_back("ƻ��");
	v.push_back("����");
	v.push_back("����");
	GetFavoriteFruit(v, 3);
}
int main()
{
	/*int arr[] = { 1, 2, 5, 4, 0, 3, 9, 8, 6, 7, -1, 3, 3, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;*/
//	TestGetFavoriteFruit();
	int a[] = { 2, 4, 6, 8, 10 }, *p, **k;
	p = a;
	k = &p;
	printf("%d ", *(p++));  //���Ų�����ʹ��++����������ȼ���ǰ
	printf("%d\n", **k);
	return 0;
}
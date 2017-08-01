#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//#include <stack>
//#include <queue>
//using namespace std;
//
//
////冒泡排序
//void BubbleSort(int* arr,int n)
//{
//	if (arr == NULL || n <= 1)
//		return;
//	int start = 0;
//	int end = n - 1;
//	bool flagSort = true;
//	while (end > start)
//	{
//		int cur = start;
//		while (cur < end)
//		{
//			if (arr[cur] > arr[cur + 1])
//			{
//				swap(arr[cur], arr[cur + 1]);
//				flagSort = false;
//			}
//			cur++;
//		}
//		start = 0;
//		end--;
//		if (flagSort == true)
//			return;
//		flagSort = true;
//	}
//	return;
//}
//
//
////快速排序
////void _QuickSort(int *arr, int begin,int end)
////{
////	if (begin >= end)
////		return;
////	int index = end;
////	int slow = begin - 1;
////	int fast = begin;
////	while (fast < end)
////	{
////		while (fast < end&&arr[fast] > arr[index])
////		{
////			fast++;
////		}
////		slow++;
////		if (slow != fast)
////			swap(arr[slow], arr[fast]);  //(1)
////		fast++;
////	}
////	if (fast == end)  //如果fast > end,证明index在第（1）的时候已经交换到正确位置
////	{
////		slow++;
////		swap(arr[slow], arr[index]);
////	}
////	_QuickSort(arr, begin, slow - 1);
////	_QuickSort(arr, slow + 1, end);
////}
//
////快排非递归  递归——>非递归 考虑栈和队列
//void _QuickSort(int *arr, int n)
//{
//	queue<pair<int, int>> q;
//	int begin = 0;
//	int end = n - 1;
//	if (begin >= end)
//		return;
//	q.push(make_pair(begin, end));
//	while (!q.empty())
//	{
//		begin = q.front().first;
//		end = q.front().second;
//		int fast = begin;
//		int slow = begin - 1;
//		int key = end;
//		while (fast < end)
//		{
//			while (fast < end&&arr[fast] > arr[end])
//			{
//				fast++;
//			}
//			slow++;
//			if (fast != slow)
//				swap(arr[fast], arr[slow]);
//			fast++;
//		}
//		if (fast == end)
//		{
//			slow++;
//			swap(arr[key], arr[slow]);
//		}
//		if (begin < slow - 1)
//			q.push(make_pair(begin, slow - 1));
//		if (slow + 1 < end)
//			q.push(make_pair(slow + 1, end));
//		q.pop();
//	}
//	return;
//}
//void QuickSort(int *arr,int n)
//{
//	if (arr == NULL || n <= 1)
//		return;
//	_QuickSort(arr, n);
//}
//
//
//int main()
//{
//	int arr[] = { 5, 3, 4, 7, 0, -2, -3, -4, -2, -2, -2, 10, 8, 9, 6, 6, 5, 7 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	QuickSort(arr, n);
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	int _a;
//private:
//	int _c;
//};
//class B:public A
//{
//public:
//	int _a;
//private:
//	int _c;
//};
//int main()
//{
//	B b;
//	b._a = 1;
//	b.A::_a = 1;
//	cout << sizeof(B) << endl;
//	return 0;
//}
















//#include <iostream>
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	vector<int> w;
//	int m;
//	cin >> m;
//	for (int i = 0; i < m; i++)  //学生分的
//	{
//		int x;
//		scanf("%d", &x);
//		w.push_back(x);
//	}
//	sort(w.begin(), w.end());
//	vector<int> h;
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)  //月饼
//	{
//		int x;
//		scanf("%d", &x);
//		h.push_back(x);
//	}
//	sort(h.begin(), h.end());
//	int count = 0;
//	vector<int>::iterator stu = w.begin();
//	vector<int>::iterator cho = h.begin();
//	while (stu != w.end() && cho != h.end())
//	{
//		if (*stu >= *cho)
//		{
//			stu++;
//			cho++;
//			count++;
//		}
//		
//	}
//	cout << count << endl;
//	return 0;
//}




//#include <iostream>
//#include <cstdio>
//#include <vector>
//using namespace std;
//int main()
//{
//	vector<int> v;
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		scanf("%d", &x);
//		v.push_back(x);
//	}
//	int min = v[0];
//	int max = v[0];
//	for (int i = 0; i < n; i++)
//	{
//		if (v[i] < min)
//			min = v[i];
//		if (v[i]>max)
//			max = v[i];
//	}
//	if (max == 0)  //最大值为0则输出0
//	{
//		cout << max << endl;
//		return 0;
//	}
//	if (min > 0 || max < 0) //最小值都大于0或者最大值小于0都为选出三个最大的
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			int index = i;
//			for (int j = i; j < n - 1; j++)
//			{
//				if (v[j] > v[j + 1])
//					index = j;
//			}
//			swap(v[index], v[i]);
//		}
//		int maxValue = v[0] * v[1] * v[2];
//		cout << maxValue << endl;
//		return 0;
//	}
//	else  //把最小值和次小值找出
//	{
//		if (v.size() >= 6)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				int min = i;
//				int max = i;
//				for (int j = i; j < n - i; j++)
//				{
//					if (v[j] < v[min])
//						min = j;
//					if (v[j] > v[max])
//						max = j;
//				}
//				swap(v[n - 1], v[max]);
//				swap(v[i], v[min]);
//			}
//			if (v[0] * v[1]>v[n - 2] * v[n - 3])
//			{
//				cout << v[0] * v[1] * v[n-1] << endl;
//				return 0;
//			}
//			else
//			{
//				cout << v[n-1] * v[n-2] * v[n-3] << endl;
//				return 0;
//			}
//		}
//		else
//		{
//			cout << v[n - 1] * v[n - 2] * v[n-3] << endl;
//			return 0;
//		}
//	}
//}


//
//#include <iostream>
//using namespace std;
//#include <string>
//#include <vector>
//int main()
//{
//	string s1;
//	string s2;
//	cin >> s1;
//	cin >> s2;
//	int num1 = atoi(s1.c_str());
//	int num2 = atoi(s2.c_str());;
//	int num = num1*num2;
//	string s;
//	while (num)
//	{
//		int number = num % 10;
//		s.push_back(number);
//		num = num / 10;
//	}
//	cout << s << endl;
//	//vector<string> help;
//	//for (size_t i = 0; i < s1.size(); i++)
//	//{
//	//	for (size_t j = 0; j < i; j++)
//	//	{
//	//		help[i].push_back('0');
//	//	}
//	//	int front = 0;
//	//	for (size_t k = 0; k < s2.size(); k++)
//	//	{
//	//		int front = (s1[i]-'0') * (s2[k]-'0') / 10;
//	//		help[i].push_back(((s1[i] * s2[k]) % 10 + front) + '0');
//	//	}
//	//}
//	//string s = "";
//	//for (size_t i = 0; i < help.size(); i++)
//	//{
//	//	int front = '0';
//	//	int sum = 0;
//	//	for (size_t j = 0; j < help.size(); j++)
//	//	{
//	//		sum += (help[i][j] - '0');
//	//	}
//	//	s.push_back(sum % 10 + '0'+front);
//	//	front=sum/10
//	//}
//
//	return 0;
//}


#include <iostream>
#include <vector>
using namespace  std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char> >map(m);
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; i < n; j++)
		{
			char x;
			scanf("%d", &x);
			map[i].push_back(x);
		}
	}
	int begin = -1;
	for (size_t i = 0; i < m; i++)
	{
		if (map[0][i] == 2)
		{
			begin = i;
		}
	}
	if (begin == -1)
	{
		begin = 0;
		cout << begin << endl;
		return 0;
	}
	return 0;
}
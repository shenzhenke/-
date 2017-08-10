#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//void _Reverse(int begin, int end, string& str)
//{
//	while (begin < end)
//	{
//		swap(str[begin], str[end]);
//		begin++;
//		end--;
//	}
//}
//int  main()
//{
//	string str = "";
//	string s;
//	int count = 0;
//	while (getline(cin, s))
//	{
//		if (count == 0)
//		{
//			str += s;
//			count++;
//		}
//		else
//		{
//			str += " ";
//			str += s;
//		}
//	}
//	vector<int> countIndex;
//	countIndex.push_back(0);
//	int index = 0;
//	string::iterator it = str.begin();
//	while (it != str.end())
//	{
//		if (*it == ' ')
//		{
//			countIndex.push_back(index - 1);
//			countIndex.push_back(index + 1);
//		}
//		index++;
//		it++;
//	}
//	countIndex.push_back(str.size() - 1);
//	if (countIndex.size() > 2)
//	{
//		int i = 0;
//		while (i < countIndex.size()){
//			_Reverse(countIndex[i], countIndex[i + 1], str);
//			i += 2;
//		}
//		_Reverse(0, str.size() - 1, str);
//	}
//	cout << str.c_str() << endl;
//	return 0;
//}
//
//#include <iostream>
//#include <stdlib.h>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	char arr1[5];
//	char arr2[5];
//	int num1, num2;
//	int count = 0;
//	cin >> num1 >> num2;
//	_itoa(num1, arr1, 10);
//	_itoa(num2, arr2, 10);
//	string s1(arr1);
//	string s2(arr2);
//	reverse(s1.begin(), s1.end());
//	reverse(s2.begin(), s2.end());
//	num1 = atoi(s1.c_str());
//	num2 = atoi(s2.c_str());
//	int num = num1 + num2;
//	char arr[10];
//	_itoa(num, arr, 10);
//	string s(arr);
//	reverse(s.begin(), s.end());
//	num = atoi(s.c_str());
//	cout << num<< endl;
//	return 0;
//}



//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int count, num, i = 0;
//	cin >> count;
//	vector<int> v;
//	while (i < count){
//		cin >> num;
//		v.push_back(num);
//		i++;
//	}
//	int cur = 0, max = v[0];
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cur += v[i];
//		max = (max>cur ? max : cur);  //当max > cur时，需要更新max  
//		if (cur < 0)
//			cur = 0;                 //当cur < 0 时，需要将cur置0。  
//	}
//	cout << max << endl;
//	return 0;
//}




//
//#include <iostream>
//using namespace std;
//int main()
//{
//	int num;
//	cin >> num;
//	int count = 0, sum = 0;
//	while (count = num / 5){
//		sum += count;
//		num = count;
//	}
//	cout << sum << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//void  AdjustDown(vector<int> &v, int i,int k)
//{
//	int parent = i;
//	int child = parent * 2 + 1;
//	while (child < k)
//	{
//		if (child + 1 < k&&v[child] < v[child + 1]){
//			child = child + 1;
//		}
//		if (v[child]>v[parent]){
//			swap(v[child], v[parent]);
//		}
//		parent = child;
//		child = parent * 2 + 1;
//	}
//}
//
//int main()
//{
//	vector<int> v;
//	int num;
//	while (cin >> num&&num <= 30)
//	{
//		v.push_back(num);
//	}
//	int k, n = v.size();
//	cin >> k;
//	for (int i = (k - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(v, i, k);
//	}
//	for (int i = k; i < n; i++)
//	{
//		if (v[i] < v[0])
//		{
//			swap(v[0], v[i]);
//			AdjustDown(v, 0, k);
//		}
//	}
//	int count = k;
//	while (count > 0)
//	{
//		count--;
//		swap(v[0], v[count]);
//		AdjustDown(v, 0, count);
//	}
//	for (int i = 0; i < k; i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//bool Comp(const int &a, const int &b)
//{
//	return a>b;
//}
//
//int main()
//{
//	int n, k;
//	vector<int> v;
//
//	while (cin >> n)
//	{
//		k = n;
//		v.push_back(n);
//	}
//
//	v.pop_back();
//
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < k; i++)
//	if (i < k - 1)
//		cout << v[i] << " ";
//	else
//		cout << v[i] << endl;
//
//	return 0;
//}


#include <iostream>
#include <map>
#include <queue>
using namespace std;
void QuickSortThink(int *arr, int left, int right, int n)
{
	queue<pair<int, int>> q;
	q.push(make_pair(left, right));
	int objNumber = (n % 2 == 0) ? 2 : 1;
	int count = 0;
	int temp[2] = { 0 };
	while (!q.empty())
	{
		int begin = q.front().first;
		int end = q.front().second;
		int key = begin;
		int mid = (end - begin) / 2 + begin;
		if (arr[begin] > arr[end])
		{
			if (arr[mid] > arr[begin])
				key = begin;
			else
			{
				if (arr[end] > arr[mid])
					key = end;
				else
					key = mid;
			}
		}
		else
		{
			if (arr[mid] > arr[end])
				key = end;
			else
			{
				if (arr[begin] > arr[mid])
					key = begin;
				else
					key = mid;
			}
		}
		swap(arr[key], arr[end]);
		key = end;
		int slow = begin - 1;
		int fast = begin;
		while (fast < end)
		{
			while (fast < end&&arr[fast] > arr[end])
			{
				fast++;
			}
			slow++;
			if (fast != slow)
				swap(arr[slow], arr[fast]);
			fast++;
		}
		if (fast == end)
		{
			slow++;
			swap(arr[end], arr[slow]);
		}
		//根据slow的位置排除一部分
		if (objNumber == 1)
		{
			if (slow == n / 2)
			{
				cout << arr[slow] << endl;
				return;
			}
			else if (slow < n / 2)
			{
				q.push(make_pair(slow + 1, end));
			}
			else
			{
				q.push(make_pair(begin, slow - 1));
			}
		}
		else
		{
			if (slow == n / 2)
			{
				temp[1] = arr[slow];
				count++;
				if (count == objNumber)
					break;
				q.push(make_pair(begin, slow - 1));
			}
			else if (slow == n / 2 - 1)
			{
				temp[0] = arr[slow];
				count++;
				if (count == objNumber)
					break;
				q.push(make_pair(slow + 1, end));
			}
			else if (slow < n / 2 || slow < n / 2 - 1)
			{
				q.push(make_pair(slow + 1, end));
			}
			else
			{
				q.push(make_pair(begin, slow - 1));
			}
		}
		q.pop();
	}
	cout << temp[0] << " " << temp[1] << endl;
	return;
}
int arr[100];
int main()
{
	int num, n = 0;
	map<int, int> countNumber;
	while (cin >> num&&num < 10){
		countNumber[num]++;
		n++;
	}
	map<int, int>::iterator it = countNumber.begin();
	while (it != countNumber.end()){
		if (it->second >= n / 2)
		{
			cout << it->first << endl;
			break;
		}
		it++;
	}
	return 0;
}
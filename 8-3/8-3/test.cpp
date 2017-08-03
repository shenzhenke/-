#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//适用于数据重复度较集中
void HashSort(int* arr,int n)
{
	if (arr == NULL || n <= 1)
		return;
	int i = 0;
	int index = i;
	int min = arr[i];
	int max = arr[i];
	for (; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	vector<int> count(max - min + 1);
	for ( i = 0; i < n; i++)
	{
	    index = arr[i] - min;
		count[index]++;
	}
	index = 0;
	for (i = 0; i < count.size(); i++)
	{
		while (count[i] != 0)
		{
			arr[index] = min + i;
			count[i]--;
			index++;
		}
	}
	return;
}

void QuickSortThink(int *arr, int left, int right,int n)
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
			if (slow == n / 2 )
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


void FindMidNumber(int* arr, int n)
{
	if (arr == NULL)
		return;
	if (n <= 2)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	QuickSortThink(arr, 0, n - 1, n);
}

int MissNumber(int *arr, int n)
{
	int left = 0;
	int right = n;
	while (left < right)
	{
		if (arr[left] == left + 1)  //证明数据在正确的位置上
			left++;
		else if (arr[left] > right || arr[left] <= left || arr[left] == arr[arr[left] - 1])
			//越界              小值重复或越界   大值重复
		{
			arr[left] = arr[--right];
		}
		else  //在正常范围内,但是不是在正确的位置
		{
			swap(arr[left], arr[arr[left] - 1]);
		}
	}
	return left + 1;
}

int main()
{
	//int arr[] = { 12, 13, 12, 13, 19, 18, 15, 12, 15, 16, 17 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//HashSort(arr, n);
	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i] << " ";
	//}
	//cout << endl;

	int  arr[] = { 2, 5, 9, 3, 6, 8, 7, 4, 1, 0, 10, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	FindMidNumber(arr, n);

	//int arr[] = { 2, 3, 1, 4 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//cout << MissNumber(arr, n) << endl;
	return 0;
}





//#include <cstdio>
//#include  <iostream>
//#include <string>
//#include <queue>
//#include <map>
//#include <algorithm>
//using namespace std;
//const  int N = 110;
//char mz[N][N];
//bool vis[N][N][N * 10];
//int fx[4] = { 0, 0, 1, -1 };
//int fy[4] = { 0, 0, 1, -1 };
//int m, n;
//map<char, int> key;
//struct node{
//	int x, y, cnt, sta;
//	node()
//		:cnt(0)
//		, sta(0)
//	{}
//};
//
//queue<node> que;
//
//int bfs(int sx, int sy, int ex, int ey)
//{
//	while (!que.empty())
//		que.pop();
//	node tmp;
//	tmp.x = sx, tmp.y = sy;
//	while (!que.empty())
//	{
//		node p = que.front();
//		if (p.x == ex&&p.y == ey)
//		{
//			return p.cnt;
//		}
//		que.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int newx = p.x + fx[i];
//			int  newy = p.y + fy[i];
//			if (newx < 0 || newx >= m || newy < 0 || newy >= n)
//				continue;
//			if (mz[newx][newy] == '0')
//				continue;
//			int  sta = p.sta;
//			if (mz[p.x][p.y] >= 'a'&&mz[p.x][p.y] <= 'z')
//			{
//				sta |= (1 << key[mz[p.x][p.y]]);
//			}
//			if (vis[newx][newy][sta])
//				continue;
//			if (mz[newx][newy] >= 'A'&&mz[newx][newy] <= 'Z')
//			{
//				if ((sta&(1 << (key[mz[newx][newy] - 'A' + 'a']))) == 0)
//					continue;
//			}
//			vis[newx][newy][sta] = true;
//			tmp.x = newx, tmp.y = newy, tmp.cnt = p.cnt + 1, tmp.sta = sta;
//			que.push(tmp);
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	while (~scanf("%d %d", &m, &n)){
//		int sx, sy, ex, ey;
//		int cnt = 0;
//		for (int i = 0; i < m; i++)
//		{
//			scanf("%s", mz[i]);
//			for (int j = 0; j < n; j++)
//			{
//				if (mz[i][j] == '2')
//				{
//					sx = i;
//					sy = j;
//				}
//				if (mz[i][j] == '3')
//				{
//					ex = i;
//					ey = j;
//				}
//				if (mz[i][j] >= 'a'&&mz[i][j]<='z')
//				{
//					key[mz[i][j]] = cnt++;
//				}
//			}
//		}
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				for (int s = 0; s < (1<<cnt); s++)
//				{
//					vis[i][j][s] = false;
//				}
//			}
//
//		}
//		int Ans = bfs(sx, sy, ex, ey);
//		printf("%d\n", Ans);
//	}
//	return 0;
//}
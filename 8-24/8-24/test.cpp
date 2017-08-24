#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using  namespace std;

//gamemark
//unsigned int arr[32] = { 0 };
//int main()
//{
//	int m, n;
//	while (cin >> m >> n)
//	{
//		if (n<1 || n>1024 || m > 1024 || m < 1){
//			cout << -1 << endl;
//			continue;		
//		}
//		int i = (m - 1) / 32;				//m的下标
//		int j = (n - 1) / 32;				//n的下标
//		arr[i] |= (1 << ((m - 1) % 32));
//		int tmp = arr[j] & (1 << ((n - 1) % 32));
//		if (tmp == 0)
//			cout << 0 << endl;
//		else
//			cout << 1 << endl;
//	}
//	return 0;
//}





//GridWays

//int dp[11][11] = { 0 };
//int main()
//{
//	int x, y;
//	cin >> x >> y;
//	for (int i = 0; i <= y; i++)
//	{
//		dp[0][i] = 1;
//	}
//	for (int i = 0; i <= x; i++)
//	{
//		dp[i][0] = 1;
//	}
//	for (int i = 1; i <= x; i++)
//	{
//		for (int j = 1; j <= y; j++)
//		{
//			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//		}
//	}
//	cout << dp[x][y] << endl;
//	return 0;
//}

//luckNumber  十进制和二进制之和相加相等
//#include <vector>
//int main()
//{
//	int x;  //x<10000;
//	cin >> x;
//	int count = 0;
//	for (int i = 1; i <= x; i++)
//	{
//		int sum1 = 0;
//		int m = i;
//		while (m )
//		{
//			sum1 += m % 10;
//			m = m / 10;
//		}
//		m = i;
//		int sum2 = 0;
//		while (m > 0)
//		{
//			m = m&(m - 1);
//			sum2++;
//		}
//		if (sum1 == sum2)
//			count++;
//	}
//	cout << count << endl;
//	return 0;
//}

//#include <string>
//#include <map>
//int main()
//{
//	string str;
//	cin >> str;
//	map<char, int>  countChar;
//	size_t size = 0;
//	if (str.size() >= 1)
//		size = str.size() - 1;
//	for (size_t i = 0; i < size; i++)
//	{
//
//	//判断前两种情况
//		if (str[i] == str[i + 1] || str[i]>'Z' || str[i] < 'A')
//		{
//			cout << "dislike" << endl;
//			return 0;
//		}
//		countChar[str[i]]++;
//		if (countChar[str[i]] == 4)
//		{
//			cout << "dislike" << endl;
//			return 0;
//		}
//	}
//	
//	cout << "like" << endl;
//	return 0;
//}


//prime pair
#include <vector>
#include <math.h>
int main()
{
	int n;
	cin >> n;
	vector<int> number(n + 1, 0);
	number[1] = 0;
	number[2] = 1;
	for (size_t i = 3; i <= n; i++)
	{
		size_t k = sqrt(i);
		int flag = 1;
		for (size_t j = 2; j <= k; j++)
		{
			if (i%j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			number[i] = 1;
	}
	int size = number.size() / 2;
	int count = 0;
	for (size_t i = 2; i <= size; i++)
	{
		if (number[i] == 1 && number[n - i] == 1)
			count++;
	}
	cout << count << endl;
	return 0;
}

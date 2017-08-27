#define _CRT_SECURE_NO_WARNINGS 
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//	string str1;
//	cin >> str1;
//	string str2 = "ABCDE";
//	//A B C D E
//	vector<int> map(256);
//	for (size_t i = 0; i < str2.size(); i++)
//	{
//		map[str2[i]]++;
//	}
//	size_t size = str1.size();
//	int minLen = str1.size();
//	int maxLen = 0;
//	int left = 0; //表示被框住子串的左边界
//	int right = 0;//表示被框住子串的右边界
//	int match = str2.size(); //表示还差A B C D E 多少个字符
//	int mark = 0;
//	while ((right != size && mark <= 1) && left != size)
//	{
//		map[str1[right]]--;
//		if (map[str1[right]] >= 0)
//		{
//			match--;
//		}
//		if (match == 0)
//		{
//			while (left != size&&map[str1[left]] < 0)
//			{
//				map[str1[left++]]++;
//			}
//			if (left == size)
//				break;
//			if (right>left)
//				minLen = minLen > (right - left + 1) ? (right - left + 1) : minLen;
//			else
//				maxLen = maxLen > (left - right-1) ? maxLen : (left - right-1);
//			match++;
//			map[str1[left++]]++;
//
//		}
//		right++;
//		if (right >= size)
//		{
//			mark++;
//			right = right%size;
//		}
//	}
//	maxLen = maxLen > (size - minLen) ? maxLen : (size - minLen);
//	cout << maxLen << endl;
//	return 0;
//}




//a=A-B; b=B-C;c=A+B;d=B+C

//#include  <iostream>
//using namespace std;
//int main()
//{
//	int a, b, c, d;
//	cin >> a >> b >> c >> d;
//	int A, B, C;
//	if ((a + c) % 2 == 0 && (a + c) >= 0)
//	{
//		A = (a + c) / 2;
//		if ((A - a) >= 0)
//		{
//			B = A - a;
//			if ((B - b) == (d - B) && (B - b) >= 0)
//			{
//				C = B - b;
//				cout << A <<" "<< B <<" "<<C << endl;
//			}
//			else
//			{
//				cout << "No" << endl;
//			}
//		}
//		else
//		{
//			cout << "No" << endl;
//		}
//	}
//	else
//		cout << "No" << endl;
//	return 0;
//}










//判断字符串是按字典序排序还是大小排序
//
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	string str;
//	string prev = "";
//	bool isSize = true;
//	bool isDict = true;
//	while (n--&&cin >> str)
//	{
//		if (prev != "")
//		{
//			if (prev.size() > str.size())
//			{
//				isSize = false;
//			}
//			size_t i = 0, j = 0;
//			while (i < prev.size() && j < str.size())
//			{
//				if (prev[i] != str[j])
//				{
//					if (prev[i]>str[j])
//					{
//						isDict = false;
//						break;
//					}
//					else
//						break;
//				}
//				i++;
//				j++;
//			}
//			if (j == str.size() && i != prev.size())
//				isDict = false;
//		}
//		prev = str;
//	}
//
//	if (isDict == true && isSize == true)
//		cout << "both" << endl;
//	else if (isDict == true)
//		cout << "lexicographically" << endl;
//	else if (isSize == true)
//		cout << "lengths" << endl;
//	else
//		cout << "none" << endl;
//	return 0;
//}




//数列和问题

//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n, sum, num;
//	cin >> n >> sum;
//	vector<int> arr(n);  //代表数组中的数据
//	vector<int> arrSums(n);
//	int arrSum = 0;
//	vector<vector<long> > dp(n);
//	for (size_t i = 0; i < n; i++)
//	{
//		dp[i].resize(sum + 1);
//	}
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> num;
//		arr[i] = num;
//		arrSum += num;
//		arrSums[i] = arrSum;
//	}
//	for (size_t i = 0; i < n; i++)  //初始化第一列
//  	{
//		dp[i][0] = 1;
//	}
//	if (arr[0] < sum)
//	{
//		dp[0][arr[0]] = 1;
//	}
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 1; j < sum + 1; j++)
//		{
//			dp[i][j] = dp[i - 1][j];
//			dp[i][j] += (j - arr[i]) >= 0 ? dp[i - 1][j - arr[i]] : 0;
//			if (arrSums[i] < j)
//			{
//				break;
//			}
//		}
//	}
//	cout << dp[n - 1][sum] << endl;
//	return 0;
//}






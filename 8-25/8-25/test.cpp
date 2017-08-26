#define _CRT_SECURE_NO_WARNINGS

//判断回文
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{ 
//	string str, insertStr;
//	cin >> str >> insertStr;
//	int count = 0;
//	size_t size = str.size();
//	for (size_t i = 0; i <= size; i++)
//	{
//		string temp = str;
//		temp.insert(i, insertStr);
//		string tmp = temp;
//		reverse(tmp.begin(), tmp.end());
//		if (tmp == temp)
//			count++;
//	}
//	cout << count << endl;
//	return 0;
//}




//filename

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string filename;
//	cin >> filename;
//	size_t size = filename.size();
//	int pos = -1;
//	if (size == 0)
//		cout << "null" << endl;
//	else
//	{
//		for (int i = size - 1; i >= 0; i--)
//		{
//			if (filename[i] == '.')
//			{
//				pos = i;
//				break;
//			}
//		}
//		if (pos != -1)
//			cout << filename.assign(filename, pos + 1, size - pos) << endl;
//		else
//			cout << "null" << endl;
//	}
//	return 0;
//}


//#include  <iostream>
//#include <math.h>
//using namespace std;
//int main()
//{
//	double n, m;
//	while (cin >> n >> m)
//	{
//		double sum = n;
//		while (--m)
//		{
//			n = sqrt(n);
//			sum += n;
//		}
//		printf("%.2lf", sum);
//	}
//}


//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//int main()
//{
//	map<int, int> nums;
//	int n, m, num;
//	cin >> n >> m;
//	while (n--)
//	{
//		cin >> num;
//		nums[num] = 1;
//	}
//	while (m--)
//	{
//		cin >> num;
//		nums[num] = 1;
//	}
//	map<int, int>::iterator next = nums.begin();
//	map<int, int>::iterator it = next++;
//	while (next != nums.end())
//	{
//		cout << it->first << " ";
//		it++;
//		next++;
//	}
//	cout << it->first << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <set>
//using namespace std;
//int main()
//{
//	set<int> nums;
//	int n, m, num;
//	cin >> n >> m;
//	while (n--)
//	{
//		cin >> num;
//		nums.insert(num);
//	}
//	while (m--)
//	{
//		cin >> num;
//		nums.insert(num);
//	}
//	set<int, int>::iterator next = nums.begin();
//	set<int, int>::iterator it = next++;
//	while (next != nums.end())
//	{
//		cout << *it << " ";
//		it++;
//		next++;
//	}
//	cout << *it << endl;
//	return 0;
//}


//设计一个字符串加法
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string numOne, numTwo;
//	cin >> numOne >> numTwo;
//	int numOneSize = numOne.size()-1;
//	int numTwoSize = numTwo.size()-1;
//	string sum;
//	int sumSize = numOneSize > numTwoSize ? (numOneSize + 2) : (numTwoSize + 2);
//	sum.resize(sumSize);
//	int ctl = 0; //标志位
//	while (numOneSize >= 0 && numTwoSize >= 0)
//	{
//		int prev = ctl;
//		if (numOne[numOneSize]<'1' || numOne[numOneSize]>'9' || numTwo[numTwoSize] > '9' || numTwo[numTwoSize] < '1')
//		{
//			cout << "error" << endl;
//			return 0;
//		}
//		ctl = (numOne[numOneSize] + numTwo[numTwoSize] + ctl - 2 * '0') / 10;
//		if (ctl == 0)
//		{
//			sum[sumSize - 1] = numOne[numOneSize] + numTwo[numTwoSize] + prev - '0';
//		}
//		else
//		{
//			sum[sumSize - 1] = (numOne[numOneSize] + numTwo[numTwoSize] + prev - 2 * '0') % 10 + '0';
//		}
//		sumSize--;
//		numOneSize--;
//		numTwoSize--;
//	}
//	if (numOneSize < 0)
//	{
//		
//		while (numTwoSize >= 0)
//		{
//			if (numTwo[numTwoSize] > '9' || numTwo[numTwoSize] < '1')
//			{
//				cout << "error" << endl;
//				return 0;
//			}
//			int prev = ctl;
//			ctl = (numTwo[numTwoSize] + ctl - '0') / 10;
//			if (ctl == 0)
//			{
//				sum[sumSize - 1] = numTwo[numTwoSize] + prev;
//			}
//			else
//			{
//				sum[sumSize - 1] = (numTwo[numTwoSize] + prev - '0') % 10 + '0';
//			}
//			numTwoSize--;
//			sumSize--;
//		}
//	}
//	else
//	{
//		while (numOneSize >= 0)
//		{
//			if (numOne[numOneSize]<'1' || numOne[numOneSize]>'9')
//			{
//				cout << "error" << endl;
//				return 0;
//			}
//			int prev = ctl;
//			ctl = (numOne[numOneSize] + ctl - '0') / 10;
//			if (ctl == 0)
//			{
//				sum[sumSize - 1] = numOne[numOneSize] + prev;
//			}
//			else
//			{
//				sum[sumSize - 1] = (numOne[numOneSize] + prev - '0') % 10 + '0';
//			}
//			numOneSize--;
//			sumSize--;
//		}
//	}
//	if (ctl != 0)
//		sum[sumSize - 1] = ctl + '0';
//	else
//	{
//		string::iterator it = sum.begin();
//		sum.erase(it);
//	}
//	cout << sum << endl;
//	return 0;
//}



//进制转换+求和

//#include  <iostream>
//using namespace std;
//int ArySum(int num)
//{
//	int arySum = 0;
//	for (int  ary = 2; ary < num; ary++)
//	{
//		int tmp = num;
//		if (ary == 2)
//		{
//			while (tmp)
//			{
//				tmp = tmp&(tmp - 1);
//				arySum += 1;
//			}
//		}
//		else
//		{
//			
//			while (tmp)
//			{
//				arySum = arySum + tmp%ary;
//				tmp = tmp / ary;
//			}
//		}
//	}
//	return arySum;
//}
//
//int GCD(int num1, int num2)
//{
//	if (num1 < num2)
//	{
//		swap(num1, num2);
//	}
//	while (1)
//	{
//		if (num1%num2 == 0)
//		{
//			return num2;
//		}
//		else
//		{
//			int tmp = num1%num2;
//			num1 = num2;
//			num2 = tmp;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		if (num == 1 || num == 2)
//		{
//			cout << num << "/" << num << endl;
//			continue;
//		}
//		int sum = ArySum(num);
//		int gcd = GCD(sum, num - 2); //GCD求最大公约数
//		cout << sum / gcd << "/" << (num - 2) / gcd << endl;
//	}
//	return 0;
//}






//最大奇约数之和
#include <iostream>
using namespace std;
int main()
{
	long long num;
	cin >> num;
	long long sum = 0;
	for (long long i = 1; i <= num; i++)
	{
		long long  tmp = i;
		while (tmp % 2 == 0)
		{
			tmp = tmp / 2;
			while (tmp % 4 == 0)
			{
				tmp = tmp / 4;
				while (tmp % 8 == 0)
				{
					tmp = tmp / 8;
					while (tmp % 16 == 0)
					{
						tmp = tmp / 16;
						while (tmp % 32 == 0)
						{
							tmp = tmp / 32;
							while (tmp % 64 == 0)
							{
								tmp = tmp / 64;
								while (tmp % 128 == 0)
									tmp = tmp / 128;
							}
						}

					}
				}
			}
		}
		sum += tmp;
	}
	cout << sum << endl;
	return 0;
}



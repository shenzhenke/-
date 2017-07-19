#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
//将一个字符串转换成一个整数，
//要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
//class Solution {
//public:
//	int StrToInt(string str)
//	{
//		if (str.empty() == true)
//			return 0;
//		vector<int> v;
//		int count = -1;
//		size_t j = 0;
//		if (str[0] == '+' || str[0] == '-')
//			j = 1;
//		for (size_t i = j; i < str.size(); i++)
//		{
//			if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
//			{
//				v.push_back(str[i] - '0');
//				count++;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		int number = 0;
//		int  n = 0;
//		for (int i = count; i >= 0; i--)
//		{
//			number += v[i] * pow(10, n);
//			n++;
//		}
//		if (str[0] == '-')
//		{
//			number = -number;
//		}
//		return number;
//	}
//};




//请实现一个函数，将一个字符串中的空格替换成“ % 20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are % 20Happy
	//void replaceSpace(char* str, int length)
	//{
	//	string s = "";
	//	for (int i = 0; i < length; i++)
	//	{
	//		if (str[i] != ' ')
	//			s.push_back(str[i]);
	//		else
	//			s += "$$$";
	//	}
	//	for (size_t i = 0; i < s.size(); i++)
	//	{
	//		str[i] = s[i];
	//	}
	//}

//class Coder
//{
//public:
//	vector<string> findCoder(vector<string> A, int n)
//	{         // write code here
//		vector<pair<int,int>> countCoder;
//		for (size_t i = 0; i < A.size(); i++)
//		{
//			int count = 0;
//			if (A[i].size() < 5)
//				;
//			else
//			{
//				size_t j = A[i].find("Coder", 0);
//				while (j != string::npos)
//				{
//					count++;
//					j = A[i].find("Coder", j + 5);
//				}
//				j = A[i].find("coder", 0);
//				while (j != string::npos)
//				{
//					count++;
//					j = A[i].find("coder", j + 5);
//				}
//				if (count != 0)
//					countCoder.push_back(make_pair(count,i));
//			}
//		}
//		struct Compare
//		{
//		public:
//			bool operator()(const pair<int,int>& s1,const pair<int,int>& s2) const 
//			{
//				if (s1.first > s2.first)
//					return true;
//				else if (s1.first < s2.first)
//					return false;
//				else
//				{
//					if (s1.second < s2.second)
//						return true;
//					return false;
//				}
//			}
//		};
//		sort(countCoder.begin(), countCoder.end(), Compare());
//		vector<string> B;
//		for (size_t i = 0; i < countCoder.size(); i++)
//		{
//			B.push_back(A[countCoder[i].second]);
//		}
//		return B;
//	}
//};


class Solution {
public:
	char FirstRepeatingChar(string str)
	{
		if (str.size() <= 1)
			return '0';
		int hashtable[256] = { 0 };
		for (size_t i = 0; i < str.size(); i++)
		{
			hashtable[str[i]]++;
		}
		for (size_t i = 0; i < str.size(); i++)
		{
			if (hashtable[str[i]] == 2)
				return str[i];
		}
		return '0';
	}
};



int main()
{
	/*string arr[] = { "i am a crl", "Corl Corl", "Coderl" };

	vector<string> v;
	for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		v.push_back(arr[i]);
	}
	Coder a;
	a.findCoder(v, sizeof(arr) / sizeof(arr[0]));*/
	Solution a;
	cout << a.FirstRepeatingChar("abcedfabcdefabc") << endl;

	return 0;
}


//请实现一个函数用来匹配包括'.'和'*'的正则表达式。
//模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。
//在本题中，匹配是指字符串的所有字符匹配整个模式。例如，
//字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

//class Solution 
//{
//public:
//	bool match(char* str, char* pattern)
//	{
//
//	}
//};
















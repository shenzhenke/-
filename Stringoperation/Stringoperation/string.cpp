#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
//��һ���ַ���ת����һ��������
//Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
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




//��ʵ��һ����������һ���ַ����еĿո��滻�ɡ� % 20����
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are % 20Happy
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


//��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
//ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ���
//�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬
//�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��

//class Solution 
//{
//public:
//	bool match(char* str, char* pattern)
//	{
//
//	}
//};
















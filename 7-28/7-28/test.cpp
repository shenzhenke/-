#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

//字典序
//void Perm(string str, int k, int m,vector<string>& dict)
//{
//	if (k == m)
//	{
//		dict.push_back(str);
//	}
//	else
//	{
//		for (int j = k; j <= m; j++)
//		{
//			swap(str[k], str[j]);
//			Perm(str, k + 1, m,dict);
//			swap(str[k], str[j]);
//		}
//	}
//}
//vector<string> Permutation(string str)
//{
//	vector<string> dict;
//	if (str.size() == 0)
//		return dict;
//	Perm(str, 0, str.size() - 1, dict);
//	sort(dict.begin(), dict.end());
//	vector<string>::iterator next = dict.begin();
//	vector<string>::iterator it = next++;
//	while (next != dict.end())
//	{
//		if (*it == *next)
//		{
//			next= dict.erase(it);
//			it = next++;
//		}
//		else
//		{
//			it++;
//			next++;
//		}
//	}
//	return dict;
//}

//数字组合的最小值
void Perm(vector<int> numbers, int k, int m, vector<string>& dict)
{
	if (k == m)
	{
		string s = "";
		for (size_t i = 0; i < numbers.size(); i++)
		{
			s += to_string(numbers[i]);
		}
		dict.push_back(s);
	}
	else
	{
		for (int j = k; j <= m; j++)
		{
			swap(numbers[k], numbers[j]);
			Perm(numbers, k + 1, m, dict);
			swap(numbers[k], numbers[j]);
		}
	}
}
string PrintMinNumber(vector<int> numbers) 
{
	vector<string> dict;
	if (numbers.size() == 0)
		return "";
	Perm(numbers, 0, numbers.size() - 1, dict);
	sort(dict.begin(), dict.end());
	return dict[0];
}
void Test()
{
	/*string s = "abc";
	Permutation(s);*/
	vector<int> v;
	v.push_back(1);
	v.push_back(123);
	v.push_back(132);
	v.push_back(145);
	 PrintMinNumber(v);
}

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) 
		: val(x)
		, left(NULL)
		, right(NULL) 
	{}	
};


TreeNode* _reConstructBinaryTree(vector<int> pre, int preStart, int preEnd, vector<int> vin, int vinStart, int vinEnd,unordered_map<int,int>& mapTree)
{
	if (preStart > preEnd || vinStart > vinEnd)
		return NULL;
	TreeNode* root = new TreeNode(pre[preStart]);
	int obj = mapTree[pre[preStart]];
	int left = obj - vinStart;
	int right = vinEnd - obj;
	root->left = (left == 0) ? NULL : _reConstructBinaryTree(pre, preStart + 1, preStart + left, vin, vinStart, obj - 1,mapTree);
	root->right = (right == 0) ? NULL : _reConstructBinaryTree(pre, preStart + left + 1, preEnd, vin, obj + 1, vinEnd,mapTree);
	return root;
}
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	if (pre.size() == 0 || vin.size() == 0)
		return NULL;
	unordered_map<int, int> mapTree;
	for (size_t i = 0; i < vin.size(); i++)
	{
		mapTree[vin[i]] = i;
	}
	return _reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1,mapTree);
}

void TestreConstructBinaryTree()
{
	vector<int> pre;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(3);
	pre.push_back(4);
	pre.push_back(5);
	pre.push_back(6);
	vector<int> vin;
	vin.push_back(3);
	vin.push_back(2);
	vin.push_back(4);
	vin.push_back(1);
	vin.push_back(6);
	vin.push_back(5);

	TreeNode* root=reConstructBinaryTree(pre, vin);

}


//C语言模拟实现C++的继承与多态
typedef void(*_FUN)(void);
struct A
{
	_FUN fun;
	int _a;
};

struct B
{
	A a;
	int b;
};

void funA()
{
	cout << "A" << endl;
}
void funB()
{
	cout << "B" << endl;
}
void TestInherit()
{
	A a;
	a.fun = funA;

	B b;
	b.a.fun = funB;

	A* ptr = &a;
	ptr->fun();
	ptr = (A*)&b;
	ptr->fun();
}


string formatString(string A, int n, vector<char> arg, int m) 
{
	// write code here
	string::iterator it = A.begin();
	string del = "%s";
	size_t i = 0;
	size_t begin = 0;
	size_t pos = begin;
	for (; i < arg.size(); i++)
	{
		pos = A.find(del, begin);
		if (pos == string::npos)
			break;
		A.replace(pos, del.size(), 1, arg[i]);
		begin = pos + 1;
	}
	if (i <= arg.size())
	{
		while (i < arg.size())
		{
			A.push_back(arg[i]);
			i++;
		}
	}
	return A;
}



int LongestSubStr(string s1, string s2)
{
	if (s1.size() == 0 || s2.size() == 0)
		return 0;
	size_t m = s1.size();
	size_t n = s2.size();
	vector<vector<int> >v(m, vector<int>(n));
	int max = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (s1[0] != s2[i])
			v[0][i] = 0;
		else
		{
			v[0][i] = 1;
			max = 1;
		}
	}
	for (size_t i = 0; i < m; i++)
	{
		if (s1[i] != s2[0])
			v[i][0] = 0;
		else
		{
			v[i][0] = 1;
			max = 1;
		}
	}
	for (size_t i = 1; i < m; i++)
	{
		for (size_t j = 1; j < n; j++)
		{
			if (s1[i] == s2[j])
			{
				v[i][j] = v[i - 1][j - 1] + 1;
				max = max>v[i][j] ? max : v[i][j];
			}
			else
				v[i][j] = 0;
		}
	}
	return max;
}

void TestLongestSubStr()
{
	char arr1[50];
	char arr2[50];
	gets(arr1);
	gets(arr2);
	string s1(arr1);
	string s2(arr2);
	cout << LongestSubStr(s1, s2) << endl;
	return;
}
int MaxArea(vector<int> number)
{
	if (number.size() == 0)
		return 0;
	int area = 0;
	int maxArea = 0;
	for (size_t i = 0; i < number.size(); i++)
	{
		area = number[i];
		for (size_t j = i + 1; j < number.size(); j++)
		{
			if (number[j] < number[i])
			{
				break;
			}
			area += number[i];
		}
		for (int j = i - 1; j >= 0; j--)
		{
			if (number[j] < number[i])
			{
				break;
			}
			area += number[i];
		}
		maxArea = area>maxArea ? area : maxArea;
	}
	return maxArea;
}

void TestMaxArea()
{
	vector<int> v;
	int n;
	while (scanf("%d", &n) != EOF)
	{
		v.push_back(n);
	}
	//v.push_back(6);
	//v.push_back(2);
	//v.push_back(5);
	//v.push_back(4);
	//v.push_back(5);
	//v.push_back(1);
	//v.push_back(6);
	cout << MaxArea(v) << endl;
}

int MaxWays(int number)
{
	return pow(2, number - 1);
}

#include <iostream>
using namespace std;
#include <vector>
int Coins(vector<int> v, int aim)
{
	if (aim<0 || v.size() == 0)
		return 0;
	vector<vector<int> > dp(v.size(), vector<int>(aim + 1));
	for (int i = 0; i<v.size(); i++)
	{
		dp[i][0] = 1;
	}
	for (int j = 1; v[0] * j <= aim; j++){
		dp[0][v[0] * j] = 1;
	}
	int num = 0;
	for (int i = 1; i<v.size(); i++){
		for (int j = 1; j <= aim; j++){
			num = 0;
			for (int k = 0; j - v[i] * k >= 0; k++){
				num += dp[i - 1][j - v[i] * k];
			}
			dp[i][j] = num;
		}
	}
	return dp[v.size() - 1][aim];
}
void TestCoins()
{
	int numbers;
	cin >> numbers;
	vector<int> v;
	v.push_back(1);
	v.push_back(5);
	v.push_back(10);
	v.push_back(20);
	v.push_back(50);
	v.push_back(100);
	cout << Coins(v, numbers) << endl;
}
int main()
{
//	TestInherit();
//	Test();
//	TestreConstructBinaryTree();
	/*string A = "A%sC%sE";
	vector<char> arg;
	arg.push_back('B');
	arg.push_back('D');
	arg.push_back('F');

	formatString(A, A.size(), arg, arg.size());*/
	//TestLongestSubStr();
	//TestMaxArea();
	//cout << MaxWays(6) << endl;
	TestCoins();
	return 0;
}
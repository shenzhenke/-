#define _CRT_SECURE_NO_WARNINGS 

////ÕÒ¹´¹ÉÊý
//#include <iostream>
//#include <math.h>
//using namespace std;
//int main()
//{
//	int num;
//	cin >> num;
//	int count = 0;
//	int x = (int)sqrt(num);
//	if (x*x == num)
//	{
//		count += 4;
//		x -= 1;
//	}
//	for (int i = x; i>0; i--){
//		int y = (int)sqrt(num - i*i);
//		if (i*i + y*y == num)
//			count += 4;
//	}
//	cout << count << endl;
//	return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void sumValue(vector<int> &v, vector<int> &tmp)
{
	int ctl = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] + tmp[i] + ctl >= 10)
		{
			int temp = (tmp[i] + v[i] + ctl) / 10;
			tmp[i] = (tmp[i] + v[i] + ctl) % 10;
			ctl = temp;
		}
		else
		{
			tmp[i] += v[i] + ctl;
			ctl = 0;
		}
	}
	reverse(tmp.begin(), tmp.end());
	if (ctl != 0)
		tmp.push_back(ctl);
	return;
}
int main()
{

	vector<int> v1;
	vector<int> v2;
	int x, y;
	cin >> x >> y;
	while (x)
	{
		int m = x % 10;
		v1.push_back(m);
		x = x / 10;
	}
	while (y)
	{
		int m = y % 10;
		v2.push_back(m);
		y = y / 10;
	}
	int i = v1.size();
	int j = v2.size();
	vector<int> tmp;
	if (i > j)
	{
		while (i - j > 0)
		{
			tmp.push_back(0);
			i--;
		}
		for (i = 0; i <j; i++)
		{
			tmp.push_back(v2[i]);
		}
		sumValue(v1, tmp);
	}
	else
	{
		while (j - i > 0)
		{
			tmp.push_back(0);
			j--;
		}
		for (j = 0; j < i; j++)
		{
			tmp.push_back(v1[j]);
		}
		sumValue(v2, tmp);
	}
	j = 0;
	while (j < tmp.size() && tmp[j] == 0)
	{
		j++;
	}
	for (i = j; i < tmp.size() - 1; i++)
	{
		cout << tmp[i];
	}
	cout << tmp[tmp.size() - 1] << endl;
	return 0;
}
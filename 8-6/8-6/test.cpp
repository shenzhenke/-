#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
////循环右移K位,时间复杂度为O(n)
////（1）借助stl容器
//void LoopRightK(char* str, size_t n, size_t k)
//{
//	if (n == 0 || str == NULL)
//		return;
//	k = k%n;
//	if (k == 0)
//		return;
//	vector<char> v;
//	for (size_t i = n - k; i < n; i++)
//	{
//		v.push_back(str[i]);
//	}
//	size_t index = n - 1;
//	for (int i = n - k - 1; i >= 0; i--)
//	{
//		str[index] = str[i];
//		index--;
//	}
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		str[i] = v[i];
//	}
//	return;
//}
//
//
//
////（2）以k值为界限分两段翻转,最后整体翻转
//void  _ReverseStr(char* str, int begin, int end)
//{
//	while (begin < end)
//	{
//		swap(str[begin], str[end]);
//		begin++;
//		end--;
//	}
//	return;
//}
//
//void ReverseStr(char* str, size_t  n, size_t k)
//{
//	if (n == 0 || str == NULL)
//		return;
//	k = k%n;
//	if (k == 0)
//		return;
//	_ReverseStr(str, 0, n - k - 1);
//	_ReverseStr(str, n - k, n - 1);
//	_ReverseStr(str, 0, n - 1);
//	return;
//}
//
////
////void DeleteRepeatChar(string& str)
////{
////	vector<int> deleteIndex;
////	if (str.size() <= 1)
////		return;
////	int hashtable[26] = { -1 };
////	for (int i = str.size(); i >= 0; i--)
////	{
////		hashtable[str.c_str()[i] - 'a']++;
////		if (hashtable[str.c_str()[i] - 'a'] > 1)
////			deleteIndex.push_back(i);
////	}
////	sort(deleteIndex.begin(), deleteIndex.end());
////	string::iterator it = str.begin();
////	int count = 0;
////	int index = 0;
////	while (it != str.end())
////	{
////		if (count == deleteIndex[index]) //删除
////		{
////			it = str.erase(it);
////			count++;
////			index++;
////		}
////		else
////		{
////			count++;
////			it++;
////		}
////	}
////	return;
////
////}
//
//
//void DeleteRepeatChar(string& str)
//{
//	if (str.size() <= 1)
//		return;
//	vector<int> deleteIndex;
//	int hashtable[26] = { 0 };//用来标识字符出现位置
//	for (size_t i = 0; i < 26; i++)
//	{
//		hashtable[i] = -1;
//	}
//	for (size_t i = 0; i < str.size(); i++)
//	{
//		if (hashtable[str.c_str()[i] - 'a'] == -1)
//		{
//			hashtable[str.c_str()[i] - 'a'] = i;
//		}
//		else //考虑要不要覆盖
//		{
//
//			int index = str.c_str()[i] - 'a' - 1;
//			while (index >= 0)
//			{
//				if (hashtable[index] != -1)//证明前面已经有元素了
//				{
//					deleteIndex.push_back(hashtable[str.c_str()[i] - 'a']);
//					hashtable[str.c_str()[i] - 'a'] = i;
//					break;
//				}
//				index--;
//			}
//			if (hashtable[str.c_str()[i] - 'a'] != i)
//			{
//				deleteIndex.push_back(i);
//			}
//		}
//	}
//	sort(deleteIndex.begin(), deleteIndex.end());
//	string::iterator it = str.begin();
//		int count = 0;
//		int index = 0;
//		while (it != str.end())
//		{
//			if (index == deleteIndex.size())
//				break;
//			if (count == deleteIndex[index]) //删除
//			{
//				it = str.erase(it);
//				count++;
//				index++;
//			}
//			else
//			{
//				count++;
//				it++;
//			}
//		}
//		return;
//}
//
//class BitMap
//{
//public:
//	BitMap(size_t range)  //所能表示的最大范围
//	{
//		_bitMap.resize(range / 8 + 1, 0);
//	}
//	void Set(size_t value)
//	{
//		size_t index = value / 8;
//		size_t pos = value % 8;
//
//		_bitMap[index] |= (1 << pos);
//	}
//
//	void Reset(size_t value)
//	{
//		size_t index = value / 8;
//		size_t pos = value % 8;
//
//		_bitMap[index] &= (~(1 << pos));
//	}
//
//	bool Test(size_t value)
//	{
//		size_t index = value / 8;
//		size_t pos = value % 8;
//		return _bitMap[index] & (1 << pos);
//	}
//protected:
//	vector<char> _bitMap;
//};
//void TestBitMap()
//{
//	//BitMap bm(1024*1024*1024*4);
//	BitMap bm(-1);
//	bm.Set(1101);
//	bm.Set(1001);
//	bm.Set(1001111);
//	bm.Set(1002221);
//	cout << bm.Test(1101) << endl;
//	cout << bm.Test(1102) << endl;
//	cout << bm.Test(1001) << endl;
//	cout << bm.Test(1002221) << endl;
//}
//int main()
//{
//	//char str[] = "abcdef";
//	//size_t n = strlen(str);
//	//size_t k = 2;
//	//cout << str << endl;
//	////LoopRightK(str, n, k);
//	//ReverseStr(str, n, k);
//	//cout << str << endl;
//
//	/*string str = "bbcacdcww";
//	cout << str.c_str() << endl;
//	DeleteRepeatChar(str);
//	cout << str.c_str() << endl;*/
//	TestBitMap();
//	return 0;
//}



#include <iostream>
#include <assert.h>
using namespace std;
void * myMemcpy(void * destination, const void * source, size_t num)  //不保证内存重叠时答案的正确
{
	assert(destination != NULL&&source != NULL);
	char* dest = (char*)destination;
	char* src = (char*)source;
	while (num--)
	{
		*dest++ = *src++;
	}
	return destination;
}

void * myMemmove(void * destination, const void * source, size_t num)  //保证内存重叠时答案的正确
{
	assert(destination != NULL&&source != NULL);
	char* dest = (char*)destination;
	char* src = (char*)source;
	if (dest > src)
	{
		dest += num - 1;
		src += num - 1;
		while (num--)
		{
			*dest-- = *src--;
		}
	}
	else if (dest < src)
	{
		while (num--)
		{
			*dest++ = *src++;
		}
	}
	else
		;
	return destination;
}
int main()
{
	char arr1[] = "1234";
	char arr2[] = "2346";
	cout << (char*)(myMemcpy(arr1, arr2, 6)) << endl;
	cout << arr1 << endl;
	return 0;
}



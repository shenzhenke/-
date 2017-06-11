//统计一个数字在排序数组中出现的次数   
//方法一：采用算法count 时间复杂度为O(n)
//class Solution
//{
//public:
//	int GetNumberOfK(vector<int> data, int k)
//	{
//		return count(data.begin(), data.end(), k);
//	}
//};

//方法二：折半查找法，时间复杂度为O(lgN)

//class Solution
//{
//public:
//	int GetNumberOfK(vector<int> data, int k)
//	{
//		return count(data.begin(), data.end(), k);
//	}
//};



//输入n个整数，找出其中最小的K个数。
//例如输入4, 5, 1, 6, 2, 7, 3, 8这8个数字，则最小的4个数字是1, 2, 3, 4, 。
//时间复杂度为
//class Solution 
//{
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
//	{
//		vector<int> outPut;
//		make_heap(input.begin(), input.end());
//		sort_heap(input.begin(), input.end());
//		for (int i = 0; i < k; i++)
//		{
//			outPut.push_back(input[i]);
//		}
//		for (int i = 0; i < k; i++)
//		{
//			cout << input[i] << endl;
//		}
//		return outPut;
//	}
//};



//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
//使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
//并保证奇数和奇数，偶数和偶数之间的相对位置不变。

//class Solution 
//{
//public:
//	void reOrderArray(vector<int> &array)
//	{
//		int arraySize = array.size();
//		vector<int> arrMark;
//		for (int i = 0; i<arraySize; i++)
//		{
//			if (array[i] % 2 == 0)
//				arrMark.push_back(0);
//			else
//				arrMark.push_back(1);
//		}
//		for (int i = 0; i<arraySize; i++)
//		{
//			if (arrMark[i] == 0)
//			{
//				int mark = i;
//				while (arrMark[mark] == 0)
//				{
//					mark++;
//					if (arraySize == mark)
//						return;
//				}
//				swap(array[i], array[mark]);
//				swap(arrMark[i], arrMark[mark]);
//				int markNum = array[mark];
//				for (int k = mark; k > i + 1; k--)
//				{
//					array[k] = array[k - 1];
//				}
//				array[i+1] = markNum;
//			}
//		}
//
//	}
//};
//
//
//
//
//
//class Solution1 {
//public:
//
//	void reOrderArray(vector<int> &array) {
//		if (array.size() == 0) return;
//		int change;
//		for (int j = array.size() - 1; j > 0; j--)
//		{
//			for (int i = 0; i < j; i++)
//			{
//				if (!(array[i] & 1) && (array[i + 1] & 1))
//				{
//					change = array[i];
//					array[i] = array[i + 1];
//					array[i + 1] = change;
//				}
//			}
//		}
//	}
//};






//春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，
//某个红包金额出现的次数超过了红包总数的一半。请帮小明找到该红包金额。
//写出具体算法思路和代码实现，要求算法尽可能高效。
//给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。
//若没有金额超过总数的一半，返回0。

class Gift 
{
public:
	int getValue(vector<int> gifts, int n)
	{
		// write code here
		map<int, int> countGifts;
		int giftsNumber = gifts.size();
		for (int i = 0; i<giftsNumber; i++)
		{
			countGifts[gifts[i]]++;
		}
		int m = n / 2;
		map<int, int>::iterator it = countGifts.begin();
		while (it != countGifts.end())
		{
			if ((it->second)>m)
				return it->first;
			it++;
		}
		return 0;
	}
};






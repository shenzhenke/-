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

//class Gift 
//{
//public:
//	int getValue(vector<int> gifts, int n)
//	{
//		// write code here
//		map<int, int> countGifts;
//		int giftsNumber = gifts.size();
//		for (int i = 0; i<giftsNumber; i++)
//		{
//			countGifts[gifts[i]]++;
//		}
//		int m = n / 2;
//		map<int, int>::iterator it = countGifts.begin();
//		while (it != countGifts.end())
//		{
//			if ((it->second)>m)
//				return it->first;
//			it++;
//		}
//		return 0;
//	}
//};



//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数

//class Solution
//{
//
//public:
//	bool Find(int target, vector<vector<int> > array)
//	{
//		size_t row = array.size();      //行
//		size_t col = array[0].size();  // 列 
//		for (int i = row - 1; i >= 0; i--)
//		{
//			if (array[i][col - 1] == target)
//				return true;
//		    if (array[i][col - 1]>target)
//			{
//				//二分查找
//				int end = col - 1;
//				int start = 0;
//				while (start < end)
//				{
//					int mid = start + (end - start) / 2;
//					if (array[i][mid] > target)
//						end = mid ;
//					else if (array[i][mid] < target)
//						start = mid + 1;
//					else
//						return true;
//				}
//			}
//		}
//		return false;
//	}
//};


//二维数组的查找问题
//class Solution
//{
//
//public:
//	bool Find(int target, vector<vector<int> > array)
//	{
//		size_t row = array.size();      //行
//		size_t col = array[0].size();  // 列 
//		for (int i = row - 1; i >= 0; i--)
//		{
//			if (array[i][col - 1] == target)
//				return true;
//			if (array[i][col - 1] > target)
//			{
//				//二分查找
//				int end = col - 1;
//				int start = 0;
//				while (start < end)
//				{
//					int mid = start + (end - start) / 2;
//					if (array[i][mid] > target)
//						end = mid;
//					else if (array[i][mid] < target)
//						start = mid + 1;
//					else
//						return true;
//				}
//			}
//		}
//		return false;
//	}
//};


//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) 
//	{
//		int Size = numbers.size();
//		map<int, int> countNumber;
//		for (int i = 0; i < Size; i++)
//		{
//			countNumber[numbers[i]]++;
//			if (countNumber[numbers[i]] >= (Size + 1) / 2)
//				return numbers[i];
//		}
//		return 0;
//	}
//};


//子数组最大和问题

//class Solution
//{
//public:
	//int SubArrayMaxSum(int *a, size_t n)
	//{
	//	if ((a == NULL) || (n == 0))
	//		return 0;
	//	int max = a[0];
	//	int cur = a[0];
	//	for (size_t i = 1; i < n; i++)
	//	{
	//		cur += a[i];
	//		max = (max>cur ? max : cur);  //当max > cur时，需要更新max
	//		if (cur < 0)
	//			cur = 0;                 //当cur < 0 时，需要将cur置0。
	//	}
	//	return max;
	//}
//};


//两个子数组最大的累加和问题
//class Solution
//{
//public:
//	int SubArrayMaxSum(int *a,  size_t n)
//	{
//		if ((a == NULL) || (n < 1))
//			return 0;
//		int maxR = a[n - 1];
//		int curR = a[n - 1];
//		vector<int> maxSubSumR;
//		maxSubSumR.push_back(maxR);
//		int maxSubSum = a[0];
//		int cur = a[0];
//		for (int i = n - 2; i >= 0; i--)
//		{
//			curR += a[i];
//			maxR = (maxR > curR ? maxR : curR);  //当max > cur时，需要更新max
//			maxSubSumR.push_back(maxR);
//			if (curR < 0)
//				curR = 0;                 //当cur < 0 时，需要将cur置0。
//		}
//		int max = a[0] + maxSubSumR[n - 2];
//		int j = 1;
//		for (int i = n - 3; i >= 0; i--)
//		{
//			cur += a[j];
//			maxSubSum = (maxSubSum>cur ? maxSubSum : cur);
//			max = (max > (maxSubSum + maxSubSumR[i]) ? max : (maxSubSum + maxSubSumR[i]));
//			j++;
//			if (cur < 0)
//				cur = 0;
//		}
//		return max;
//	}
//};

//未排序的正数数组中累加和为给定值的最长子数组长度
//class   Solution 
//{
//public:
//	int SubArrayMaxLegth(int* a, int n, int key)
//	{
//		if (a == NULL || n < 0 || key < 0)
//			return -1;
//		int left = -1;
//		int length = 0;
//		int maxLength = 0;
//		int  right = -1;
//		int sum = 0;
//		//循环结束的条件left==right&& left==n-1||right > n-1
//		while ((left != right) || (left != n - 1))
//		{
//			if (sum > key)
//			{
//				left++;
//				sum -= a[left];
//				length--;
//			}
//			else
//			{
//				if (sum == key)
//				{
//					maxLength = maxLength > length ? maxLength : length;
//				}
//					right++;
//					length++;
//					if (right > n - 1)
//						break;
//					sum += a[right];
//			}
//		}
//		return maxLength;
//	}
//};

//给定一个无序矩阵(Matrix)，其中有正，有负，有 0，求子矩阵的最大和
#define  M 100
#define  N 100
class Solution
{
public:
	int SubMatrixMax(int a[4][4], int m, int n)
	{
		if (a == NULL)
			return 0;
		int SubMatrixValue[M][N] = { 0 };
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0)
					SubMatrixValue[i][j] = a[i][j];
				else
					SubMatrixValue[i][j] = SubMatrixValue[i - 1][j] + a[i][j];
			}
		}
		//求出了1——>m行每一列的子数组中每一列的和
		int max = SubMatrixValue[0][0];
		int cur = SubMatrixValue[0][0];
		for (int k = -1; k < m; k++)
		{
		
			for (int i = k + 1; i < m; i++)
			{
				if (k != -1)
				{
					for (int j = 0; j < n; j++)
					{
						SubMatrixValue[i][j] -= SubMatrixValue[k][j];
					}
				}
				cur = SubMatrixValue[i][0];
				for (int j = 0; j < n; j++)
				{
					if (i != 0)
						cur += SubMatrixValue[i][j];
					else
						cur = SubMatrixValue[i][0];
					if (cur > max)
						max = cur;
					if (cur < 0)
						cur = 0;
				}
			}
		}
		return max;
	}
};






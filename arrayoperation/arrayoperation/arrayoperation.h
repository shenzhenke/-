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
//#define  M 100
//#define  N 100
//class Solution
//{
//public:
//	int SubMatrixMax(int a[4][4], int m, int n)
//	{
//		if (a == NULL)
//			return 0;
//		int SubMatrixValue[M][N] = { 0 };
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (i == 0)
//					SubMatrixValue[i][j] = a[i][j];
//				else
//					SubMatrixValue[i][j] = SubMatrixValue[i - 1][j] + a[i][j];
//			}
//		}
//		//求出了1——>m行每一列的子数组中每一列的和
//		int max = SubMatrixValue[0][0];
//		int cur = SubMatrixValue[0][0];
//		for (int k = -1; k < m; k++)
//		{
//		
//			for (int i = k + 1; i < m; i++)
//			{
//				if (k != -1)
//				{
//					for (int j = 0; j < n; j++)
//					{
//						SubMatrixValue[i][j] -= SubMatrixValue[k][j];
//					}
//				}
//				cur = SubMatrixValue[i][0];
//				for (int j = 0; j < n; j++)
//				{
//					if (i != 0)
//						cur += SubMatrixValue[i][j];
//					else
//						cur = SubMatrixValue[i][0];
//					if (cur > max)
//						max = cur;
//					if (cur < 0)
//						cur = 0;
//				}
//			}
//		}
//		return max;
//	}
//};



//给定一个无序数组 arr，其中元素可正、可负、可 0，给定一个整数 k。
//求arr所有的子数组中累加和为 k 的最长子数组长度。
//class Solution
//{
//public:
//	int SubSumK(int*  a, int n)
//	{
//		if (a == NULL || n <= 0)
//			return 0;
//		int cur = a[0];  //cur代表到当前位置,子数组的累加和
//		int max = a[0]; //max代表到当前位置,子数组的最大累加和
//		vector<int> v;
//		for (int i = 0; i < n; i++)
//		{
//			if (i == 0)
//				cur = a[0];
//			else
//				cur += a[i];
//			cur = cur>0 ? cur : 0;
//			max = max > cur ? max : cur;
//			v.push_back(max);
//		}
//		for (int i = 0; i < n; i++)
//		{
//
//		}
//	}
//};


//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		int Size = numbers.size();
//		map<int, int> countNumber;
//		for (int i = 0; i < Size; i++)
//		{
//			countNumber[numbers[i]]++;
//			if (Size % 2 == 0)
//			{
//				if (countNumber[numbers[i]] > Size / 2)
//					return numbers[i];
//			}
//			else
//			{
//				if (countNumber[numbers[i]] >= (Size + 1) / 2)
//					return numbers[i];
//			}
//		}
//		return 0;
//	}
//};


//旋转数组的最小值
//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		int Size = rotateArray.size();
//		if (Size == 0)
//			return 0;
//		int temp = rotateArray[0];
//		int i = 1;
//		while (i<Size)
//		{
//			if (temp>rotateArray[i])
//				return rotateArray[i];
//			temp = rotateArray[i];
//			i++;
//		}
//		return rotateArray[0];
//	}
//};



//找出数组中两个不相同的数据
//class Solution {
//public:
//	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) 
//	{
//		map<int, pair<int,int*>>  countNumber;
//		int Size = data.size();
//		if (Size == 0)
//			return;
//		int count = 0;
//		cout << &data[0] << endl;
//		cout << &data[Size-1] << endl;
//		for (int i = 0; i < Size; i++)
//		{
//			countNumber[data[i]].first++;
//			countNumber[data[i]].second = &data[i];
//		}
//		map<int, pair<int, int*>>::iterator it = countNumber.begin();
//		while (it != countNumber.end())
//		{
//			if (it->second.first == 1)
//			{
//				if (count == 0)
//				{
//					num1 = it->second.second;
//					count++;
//				}
//				else
//				{
//					num2 = it->second.second;
//					break;
//				}
//			}
//			it++;
//		}
//		if (num1 > num2&&num2 != NULL)
//			swap(num1, num2);
//		cout << num1 << endl;
//		cout << num2 << endl;
//		return;
//	}
//};


//输入一个递增排序的数组和一个数字S，
//在数组中查找两个数，是的他们的和正好是S，
//如果有多对数字的和等于S，输出两个数的乘积最小的。
//class Solution {
//public:
//	vector<int> FindNumbersWithSum(vector<int> array, int sum) 
//	{
//		vector<int> v;
//		size_t left = 0;
//		size_t right = array.size() - 1;
//		for (; left < array.size(); left++)
//		{
//			right = array.size() - 1;
//			while (left < right)
//			{
//				if (array[left] + array[right] < sum)
//					break;
//				else if (array[left] + array[right] == sum)
//				{
//					v.push_back(array[left]);
//					v.push_back(array[right]);
//					return v;
//				}
//				else
//				{
//					right--;
//				}
//			}
//		}
//		return v;
//	}
//};

//每年六一儿童节, 牛客都会准备一些小礼物去看望孤儿院的小朋友, 今年亦是如此。HF作为牛客的资深元老, 自然也准备了一些小游戏。其中, 有个游戏是这样的:首先, 让小朋友们围成一个大圈。然后, 他随机指定一个数m, 让编号为0的小朋友开始报数。每次喊到m - 1的那个小朋友要出列唱首歌, 然后可以在礼品箱中任意的挑选礼物, 并且不再回到圈中, 从他的下一个小朋友开始, 继续0...m - 1报数....这样下去....
//直到剩下最后一个小朋友, 可以不用表演, 并且拿到牛客名贵的“名侦探柯南”典藏版
//(名额有限哦!!^_^)。请你试着想下, 哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n - 1)

//class Sloution
//{
//public:
//	int LastRemaining_Solution(int n, int m)
//	{
//		int *arr = new int[n];
//		for (int i = 0; i < n; i++)
//			arr[i] = 1;
//		m = m%n;
//		int num = m;
//		int count = n;
//		int index = 0;
//		while (count != 1)
//		{
//			m--;
//			if (m == 0)
//			{
//				arr[index] = 0;
//				count--;
//				while (arr[index] == 0)
//				{
//					index++;
//					if (index == n)
//						index = 0;
//				}
//				m = num;
//			}
//			else
//			{
//				if (arr[index] != 0)
//				{
//					index++;
//					if (index == n)
//						index = 0;
//				}
//				while (arr[index] == 0)
//				{
//					index++;
//					if (index == n)
//						index = 0;
//				}
//			}
//			
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (arr[i] == 1)
//				return i;
//		}
//		return -1;
//	}
//};


class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
	
 	}
};



//顺时针从外到里打印矩形

//
//class Solution
//{
//public:
//	vector<int> printMatrix(vector<vector<int> > matrix){
//		vector<int> v;
//	 	int k = 0;
//		int  p = 0;
//		int m = matrix.size();
//		int n = matrix[0].size();
//		while (k < (matrix[0].size()+1)/ 2 && p <(matrix.size()+1) / 2)
//		{
//			//打印第一行
//			for (int j = p; j < n; j++)
//			{
//				v.push_back(matrix[p][j]);
//				if (v.size() == matrix.size()*matrix[0].size())
//					return v;
//			}
//			p++;
//
//			//打印最后一列
//			for (int i = p; i < m; i++)
//			{
//				v.push_back(matrix[i][n - 1]);
//				if (v.size() == matrix.size()*matrix[0].size())
//					return v;
//			}
//			m--;
//			//打印最后一行
//			for (int j = n - 1; j >= p; j--)
//			{
//				v.push_back(matrix[m][j - 1]);
//				if (v.size() == matrix.size()*matrix[0].size())
//					return v;
//			}
//			n--;
//			//打印第一列
//			for (int i = m - 1; i > k; i--)
//			{
//				v.push_back(matrix[i][k]);
//				if (v.size() == matrix.size()*matrix[0].size())
//					return v;
//			}
//			k++;
//		}
//		return v;
//	}
//};


//小明很喜欢数学, 有一天他在做数学作业时, 要求计算出9~16的和, 
//他马上就写出了正确答案是100。但是他并不满足于此, 
//他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
//没多久, 他就得到另一组连续正数和为100的序列:18, 19, 20, 21, 22。
//现在把问题交给你, 你能不能也很快的找出所有和为S的连续正数序列 ? Good Luck!
//class Solution 
//{
//public:
//	vector<vector<int> > FindContinuousSequence(int sum) 
//	{
//		vector<vector<int> > v;
//		if (sum <= 2)
//			return v;
//		const int Size = sum / 2 + 2;
//		int* arr = new int[Size];
//		for (int i = 0; i < Size; i++)
//		{
//			arr[i] = i + 1;
//		}
//		int count = 0;
//		int left = 0;
//		int right = 0;
//		int cur = 0;
//		while ((right < Size) && (left <= right))
//		{
//			if (cur > sum)
//			{
//				cur -= arr[left];
//				left++;
//			}
//			else if (cur < sum)
//			{
//				cur += arr[right];
//				right++;
//			}
//			else  
//			{
//				vector<int> SumS;
//				int i = left;
//				int j = right;
//				while (i < j)
//				{
//					SumS.push_back(arr[i]);
//					i++;
//				}
//				v.push_back(SumS);
//				count++;
//				if (right < Size)
//					cur += arr[right];
//				right++;
//			}		
//		}
//		delete[] arr;
//		return v;
//	}
//};






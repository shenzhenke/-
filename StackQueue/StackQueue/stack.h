//实现一个特殊功能的栈,在实现基本功能的基础上,再实现返回栈中最小元素的操作,push和pop以及getMin操作


class SepicalStack
{
public:
	void push(int value)
	{
		data.push(value);   //s
		if (true == minData.empty() || value <= minData.top())//min
			minData.push(value);
	}
	void pop()
	{
		assert(data.empty() != true); //s
		if (data.top() == minData.top())//
			minData.pop();
		data.pop();
	}
	int getMin()
	{
		assert(!minData.empty());
		return minData.top();
	}
private:
	stack<int> data;
	stack<int> minData;
};


void TestSepicalStack()
{
	SepicalStack s;
	s.push(4);
	//cout << s.getMin() << endl;
	s.push(1);
	//cout << s.getMin() << endl;
	s.push(5);
	//cout << s.getMin() << endl;
	s.push(7);
	//cout << s.getMin() << endl;
	//s.push(6);
	//cout << s.getMin() << endl;
	//s.push(2);
	//cout << s.getMin() << endl;
	//s.push(1);
	//cout << s.getMin() << endl;
	s.pop();
	//cout << s.getMin() << endl;
	s.pop();
	//cout << s.getMin() << endl;
	s.pop();
	//cout << s.getMin() << endl;
	s.pop();
	//cout << s.getMin() << endl;
	//s.pop();
	//cout << s.getMin() << endl;
	//cout << minData.top() << endl;
}




//一个栈中的元素类型为整型，先将该栈从顶到底按从大到小排序，只许申请一个栈
//只能申请新的变量,但不能申请额外的数据结构


//class  StackSortByStack
//{
//public:
//	stack<int> SortStack(stack<int> data)
//	{
//		stack<int> sortData;
//		while (!data.empty())
//		{
//			int cur = data.top();
//			data.pop();
//			if (true == sortData.empty() || cur <= sortData.top())
//				sortData.push(cur);
//			else
//			{
//				while (!sortData.empty() && cur > sortData.top())
//				{
//					int min = sortData.top();
//					sortData.pop();
//					data.push(min);
//				}
//				sortData.push(cur);
//			}
//		}
//		return sortData;
//	}
//};
//
//
//void TestSortStack()
//{
//	stack<int> s;
//	s.push(4);
//	s.push(5);
//	s.push(3);
//	s.push(6);
//	s.push(3);
//	s.push(1);
//	StackSortByStack sort;
//	s = sort.SortStack(s);
//	while (!s.empty())
//	{
//		cout << s.top() << endl;
//		s.pop();
//	}
//}
//









//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。
//例如序列1, 2, 3, 4, 5是某栈的压入顺序，序列4，5, 3, 2, 1
//是该压栈序列对应的一个弹出序列，但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。
//（注意：这两个序列的长度是相等的）
//
class IsCorrectPopStack 
{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) 
	{
		stack<int> s;
		if (pushV.size() != popV.size()||pushV.size()==0||popV.size()==0)
			return false;
		int count = 0;
		for (size_t i = 0; i < pushV.size(); i++)
		{
			s.push(pushV[i]);
			while (!s.empty()&&s.top() == popV[count])
			{
				s.pop();
				count++;
			}
		}
		if (!s.empty())
			return false;
		return true;
	}
};


void TestIsCorrectPopStack()
{
	IsCorrectPopStack s;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);

	cout << s.IsPopOrder(v1, v2) << endl;
}




//给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组
//{ 2, 3, 4, 2, 6, 2, 5, 1 }及滑动窗口的大小3，那么一共存在6个滑动窗口，
//他们的最大值分别为{ 4, 4, 6, 6, 6, 5 }；
//针对数组{ 2, 3, 4, 2, 6, 2, 5, 1 }的滑动窗口有以下6个：
//{ [2, 3, 4], 2, 6, 2, 5, 1 }，{ 2, [3, 4, 2], 6, 2, 5, 1 }，{ 2, 3, [4, 2, 6], 2, 5, 1 }，
//{ 2, 3, 4, [2, 6, 2], 5, 1 }，{ 2, 3, 4, 2, [6, 2, 5], 1 }，{ 2, 3, 4, 2, 6, [2, 5, 1] }。
class findMaxInWindows
{
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> v;
		if (num.empty() == true || size == 0)
			return v;
		for (size_t i = 0; i < num.size() - size + 1; i++)
		{
			int max = num[i];
			for (size_t j = i + 1; j < size + i; j++)
			{
				max = max>num[j] ? max : num[j];
			}
			v.push_back(max);
		}
		return v;
	}
		
};

void TestfindMaxInWindows()
{
	findMaxInWindows s;
	vector<int> v;
	int arr[] = { 2, 3, 4, 2, 6, 2, 5, 1,8 };
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		v.push_back(arr[i]);
	}
	v=s.maxInWindows(v, 1);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout<<endl;
}



//ʵ��һ�����⹦�ܵ�ջ,��ʵ�ֻ������ܵĻ�����,��ʵ�ַ���ջ����СԪ�صĲ���,push��pop�Լ�getMin����


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




//һ��ջ�е�Ԫ������Ϊ���ͣ��Ƚ���ջ�Ӷ����װ��Ӵ�С����ֻ������һ��ջ
//ֻ�������µı���,�����������������ݽṹ


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









//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ�
//��������1, 2, 3, 4, 5��ĳջ��ѹ��˳������4��5, 3, 2, 1
//�Ǹ�ѹջ���ж�Ӧ��һ���������У���4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С�
//��ע�⣺���������еĳ�������ȵģ�
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




//����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ�����磬�����������
//{ 2, 3, 4, 2, 6, 2, 5, 1 }���������ڵĴ�С3����ôһ������6���������ڣ�
//���ǵ����ֵ�ֱ�Ϊ{ 4, 4, 6, 6, 6, 5 }��
//�������{ 2, 3, 4, 2, 6, 2, 5, 1 }�Ļ�������������6����
//{ [2, 3, 4], 2, 6, 2, 5, 1 }��{ 2, [3, 4, 2], 6, 2, 5, 1 }��{ 2, 3, [4, 2, 6], 2, 5, 1 }��
//{ 2, 3, 4, [2, 6, 2], 5, 1 }��{ 2, 3, 4, 2, [6, 2, 5], 1 }��{ 2, 3, 4, 2, 6, [2, 5, 1] }��
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



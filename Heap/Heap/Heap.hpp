#pragma once

//大堆
template <typename T>
class Heap
{
public:
	Heap()
	{}
	Heap(T* a, size_t n)
	{
		//避免vector反复开辟容量，开销过大
		v.reserve(n);
		for (size_t i = 0; i < n; i++)
		{
			v.push_back(a[i]);
		}
		//建堆
		//(1)从最后一个非叶子结点开始，向上调整
		//(2)每个结点采用向下调整算法
		for (int i = (v.size() - 2) / 2; i >= 0; --i)
		{
			AdjustDown(i);
		}
	}
	
	//从当前结点开始,向下调整算法
	void AdjustUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (v[child] > v[parent])
			{
				swap(v[child], v[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

	bool Empty()
	{
		return v.empty();
	}
	size_t Size()
	{
		return v.size();
	}

	//从当前节点开始,向上调整算法
	void AdjustDown(int parent)
	{
		int child = parent * 2 + 1;
		while (child < v.size())
		{
			if ((child + 1) < v.size() && v[child + 1] > v[child])
			{
				child = child + 1;
			}
			if (v[child] > v[parent])
			{
				swap(v[child], v[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
	void Push(const T&x)
	{
		v.push_back(x);
		AdjustUp(v.size() - 1);
	}
	void Pop()
	{
		swap(v[0], v[v.size() - 1]);
		v.pop_back();
		AdjustDown(0);
	}
protected:
	vector<T> v;
};

void TestHeap()
{
	int a[] = { 10, 11, 13, 12, 18, 18, 15, 17, 14, 19 };
	Heap<int> t(a, sizeof(a) / sizeof(a[0]));
	t.Pop();
	t.Push(19);
}



template<class T>
class HeapSort
{
public:
	HeapSort(T* a,size_t n)
	{
		for (size_t i = 0; i < n; i++)
		{
			v.push_back(a[i]);
		}
		int size = v.size();
		for (int i = (v.size() - 2) / 2; i >= 0; i--)
		{
			AdjustDown(i, size);
		}
	}
	void AdjustDown(int parent,int size)
	{
		int child = parent * 2 + 1;
		while (child < size)
		{
			if (child + 1 < size && v[child + 1] > v[child])
				child = child + 1;
			if (v[parent] < v[child])
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
	//从小到大(升序)排序--->建大堆

	void Sort()
	{
		for (size_t i = 1; i < v.size(); i++)
		{
			int size = v.size() - i;
			swap(v[0], v[size]);
			AdjustDown(0, size);
		}
	}

	void Print()
	{
		int size = v.size();
		for (size_t i = 0; i < size; i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
protected:
	vector<T> v;
};

void TestHeapSort()
{
	int a[] = { 0, 1, 4, 3, 9, 5, 8, 7, 2 };
	HeapSort<int> t(a, sizeof(a) / sizeof(a[0]));
	t.Sort();
	t.Print();
}


//��һ������������С��K������
//���----��С��
//��С----�����

template <class T>
class HeapSearchTopK
{
public:
	//����һ������k�����ݵ�С��
	HeapSearchTopK(T* a,size_t k)
	{
		for (size_t i = 0; i < k; i++)
		{
			v.push_back(a[i]);
		}
		//��һ����k�����ݵ�С��
		for (int i = (v.size() - 2) / 2; i >= 0; i--)
		{
			AdjustDown(i);
		}
	}
	T& Top()
	{
		return v[0];
	}
	void Instead(T &x)
	{
		swap(v[0], x);
		AdjustDown(0);
	}
	void AdjustDown(int parent)
	{
		int child = parent * 2 + 1;
		while (child < v.size())
		{
			if ((child + 1) < v.size() && v[child + 1] < v[child])
			{
				child = child + 1;
			}
			if (v[child] < v[parent])
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
	void Print()
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
protected:
	vector<T> v;
};

void TestHeapSearchTopK()
{
	int a[10000];
	int b[10];
	for (int i = 0; i < 10000; i++)
	{
		a[i] = rand() % 10001 + 1000;
	}
	for (int i = 0; i < 10; i++)
	{
		b[i] = a[i];
	}
	size_t k = sizeof(b) / sizeof(b[1]);
	HeapSearchTopK<int> t(b, k);
	for (size_t i = k; i < 10000; i++)
	{
		if (a[i]>t.Top())
		{
			t.Instead(a[i]);
		}
	}
	t.Print();
}
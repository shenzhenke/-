
void Printf(int *a,size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void InsertSort(int *a, size_t n)
{
	assert(a != NULL);
	size_t end = 0;
	while (end < n - 1)
	{
		size_t index = end;
		int temp = a[index + 1];
		if (temp > a[index])  //不需要挪动数据
			a[index + 1] = temp;
		else				 //需要挪动数据
		{
			while (index >= 0) //时刻注意边界条件
			{
				a[index + 1] = a[index];
				index--;
				if (temp > a[index])
					break;
			}
			a[index + 1] = temp;
		}
		end++;
	}
}

void TestInsertSort()
{
	int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
}



void ShellSort(int* a, size_t n)
{
	assert(a != NULL);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;  //保证最后一次为直接插入
		for (size_t i=0; i<n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			for (; end >= 0; end -= gap)
			{
				if (temp > a[end])
					break;
				a[end + gap] = a[end];
			}
			a[end + gap] = temp;
		}
	}

}


void TestShellSort()
{
	int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
	ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
}


void SelectSort(int* a, size_t n)
{
	int end = n - 1;
	while (end >= 0)
	{
		int start = 0;
		int max = end;
		while (start < end)
		{
			if (a[start] > a[max])
			{
				max = start;
			}
			start++;
		}
		swap(a[max], a[end]);
		end--;
	}
}

void DoubleSelectSort(int* a, size_t n)
{
	int end = n - 1;
	int start = 0;
	while (end > start)
	{
		int cur = start;
		int max = end;
		int min = start;
		while (cur < end)
		{
			if (a[cur] > a[max])
			{
				max = cur;
			}
			if (a[cur] < a[min])
			{
				min = cur;
			}
			cur++;
		}
		swap(a[max], a[end]);
		swap(a[min], a[start]);
		start++;
		end--;
	}
}


void TestSelectSort()
{
	int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
	DoubleSelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
}

void AdjustDown(int* a, int n, int i)
{
		int parent = i;
		int child = i * 2 + 1;
		while (child < n - 1)
		{
			if (((child + 1) < (n - 1)) && a[child] < a[child + 1])
				child++;
			if (a[parent] < a[child])
				swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
}

void HeapSort(int* a, size_t n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int index = n;
	while (index > 0)
	{
		swap(a[0], a[index - 1]);
		AdjustDown(a, index, 0);
		index--;
	}
}

void TestHeapSort()
{
	int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
}

void BubbleSort(int* a, size_t n)
{
	assert(a != NULL);
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		bool correctSort = true;
		while (start < end)
		{
			if (a[start]>a[start + 1])
			{
				swap(a[start], a[start + 1]);
				correctSort = false;
			}
			start++;
		}
		if (correctSort == true)
			break;
		start = 0;
		end--;
	}
}


void TestBubbleSort()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
	BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
}


//左右指针法
//int PartSort(int* a,int left,int right)
//{
//	if (left >= right)
//		return 0;
//	int key = right;
//	while (left < right)
//	{
//		while (a[left] <= a[key] && left < right)
//		{
//			left++;
//		}
//		while (a[right] >= a[key] && left < right)
//		{
//			right--;
//		}
//		swap(a[left], a[right]);
//	}
//	swap(a[left], a[key]);
//	return left;
//}


//int PartSort(int* a, int left, int right)
//{
//	int tmp = a[right];
//	while (left < right)
//	{
//
//		while (a[left] <= tmp&&left < right)
//		{
//			left++;
//		}
//		a[right] = a[left];
//		while (a[right] >= tmp&&left < right)
//		{
//			right--;
//		}
//		a[left] = a[right];
//	}
//	a[left] = tmp;
//	return left;
//}

int PartSort(int* a, int begin, int end)
{
	int cur = begin;
	int prev = begin - 1;	
	while (cur < end)
	{
		while (cur < end  && a[cur] > a[end])
		{
			cur++;
		}
		if (cur < end)
		{
			prev++;
			swap(a[cur], a[prev]);
			cur++;
		}
	}
	prev++;
	swap(a[prev], a[end]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	assert(a != NULL);
	if (left >= right)
		return;
	int div = PartSort(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}

void TestQuickSort()
{
//	int arr[] = { 2, 1, 4, 9, 3, 6, 8, 7, 0, 5 };
//	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 5 };
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
}

void _Merge(int* a, int *tmp, int begin1, int end1, int begin2, int end2)
{
	int i = begin1;
	int index = begin1;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i] = a[begin1];
			begin1++;			
			i++;
		}
		else
		{
			tmp[i] = a[begin2];
			begin2++;
			i++;
		}
	}
	if (begin1 > end1)
	{
		while (begin2 <= end2)
		{
			tmp[i] = a[begin2];
			begin2++;
			i++;
		}
	}
	else
	{
		while (begin1 <= end1)
		{
			tmp[i] = a[begin1];
			begin1++;
			i++;
		}
	}
	while (index < i)
	{
		a[index] = tmp[index];
		++index;
	}
	return;
}

void _MergeSort(int *a, int *tmp, int begin, int end)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);
	_Merge(a, tmp, begin, mid, mid + 1, end);
}
void  MergerSort(int* a, int n)
{
	int* tmp = new int[n];
	_MergeSort(a, tmp, 0, n - 1);
	delete[] tmp;
}


void TestMergeSort()
{
	//int arr[] = { 2, 1, 4, 9, 3, 6, 8, 7, 0, 5 };
	//int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 5 };
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
	MergerSort(arr, sizeof(arr) / sizeof(arr[0]));
	Printf(arr, sizeof(arr) / sizeof(arr[0]));
}

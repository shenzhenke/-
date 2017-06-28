
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





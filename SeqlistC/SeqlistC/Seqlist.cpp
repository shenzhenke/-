#define _CRT_SECURE_NO_WARNINGS 
#include "SeqList.h"
void InitSeqList(pSeqlist p);//初始化顺序表




void PushBack(pSeqlist p, DataType d)   //在顺序表尾增加元素
{
	assert(p != NULL);
	if (MAX == p->count)
	{
		printf("顺序表满了！！！\n");
	}
	else
	{
		p->arr[p->count];
		p->count++;
	}
}
















void PopBack(pSeqlist p) //顺序表尾删除一个元素
{
	assert(p != NULL);
	p->count--;

}




void PushFront(pSeqlist p, DataType d) //在顺序表前增加一个元素
{
	int i = 0;
	assert(p != NULL);
	if (p->count != MAX)
	{
		for (i = p->count; i > 0; i++)
		{
			p->arr[i] = p->arr[i - 1];
		}
		p->arr[0] = d;
		p->count++;
	}
	else
	{
		printf("顺序表已满！！！\n");
	}

	return;
}


void PopFront(pSeqlist p)    //在顺序表前删除一个元素
{
	int i = 0;
	assert(p != NULL);
	for (i = 0; i < p->count - 2; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}
	p->count--;
}
int Find(pSeqlist p, DataType d)  //在顺序表中查找一个元素
{
	int i = 0;
	assert(p != NULL);
	for (i = 0; i < p->count; i++)
	{
		if (d == p->arr[i])
		{
			return i;
		}
	}
	return  -1;
}
void Remove(pSeqlist p, DataType d)   //删除顺序表中第一次出现的某个元素
{
	assert(p != NULL);
	if (p->count == 0)
	{
		printf("数据为空,无法删除");
		return;
	}
	int ret = Find(p, d);
	for (; ret < p->count - 1; ret++)
	{
		p->arr[ret] = p->arr[ret + 1];
	}
	p->count--;
}
void RemoveAll(pSeqlist p, DataType d);
void Show(pSeqlist p)
{
	int i = 0;
	assert(p != NULL);
	for (i = 0; i < p->count; i++)
	{
		printf("%d ", p->arr[i]);
	}
	printf("\n");
}


void Sort(pSeqlist p)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	assert(p != NULL);
	for (i = 0; i < p->count; i++)
	{
		if (p->arr[i]>p->arr[i + 1])
		{
			p->arr[i + 1] = temp;
			p->arr[i + 1] = p->arr[i];
			p->arr[i] = temp;
		}
	}
}
int BinarySearch(pSeqlist p, DataType d);
#define _CRT_SECURE_NO_WARNINGS 
#include "SeqList.h"
void InitSeqList(pSeqlist p);//��ʼ��˳���




void PushBack(pSeqlist p, DataType d)   //��˳���β����Ԫ��
{
	assert(p != NULL);
	if (MAX == p->count)
	{
		printf("˳������ˣ�����\n");
	}
	else
	{
		p->arr[p->count];
		p->count++;
	}
}
















void PopBack(pSeqlist p) //˳���βɾ��һ��Ԫ��
{
	assert(p != NULL);
	p->count--;

}




void PushFront(pSeqlist p, DataType d) //��˳���ǰ����һ��Ԫ��
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
		printf("˳�������������\n");
	}

	return;
}


void PopFront(pSeqlist p)    //��˳���ǰɾ��һ��Ԫ��
{
	int i = 0;
	assert(p != NULL);
	for (i = 0; i < p->count - 2; i++)
	{
		p->arr[i] = p->arr[i + 1];
	}
	p->count--;
}
int Find(pSeqlist p, DataType d)  //��˳����в���һ��Ԫ��
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
void Remove(pSeqlist p, DataType d)   //ɾ��˳����е�һ�γ��ֵ�ĳ��Ԫ��
{
	assert(p != NULL);
	if (p->count == 0)
	{
		printf("����Ϊ��,�޷�ɾ��");
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
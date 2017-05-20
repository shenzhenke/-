#include "Seqlist.h"
void InitSeqlist(pSeqList plist)
//初始化顺序表并给它开辟空间
{
	assert(plist);
	plist->capacity = 5;
	plist->arry = (DataType*)malloc(sizeof(DataType)*plist->capacity);
	assert(plist); //防止开辟空间不成功
	plist->size = 0;
}

void PrintSeqlist(pSeqList plist)
{
	
	if (plist->size == 0)
	{
		printf("该顺序表为空\n");
	}
	else
	{
		for (size_t i = 0; i < plist->size; i++)
		{
			printf("%d->",plist->arry[i]);
		}
		printf("NULL\n");
	}
}
void CheckCapacity(pSeqList plist)
{
	assert(plist);
	if (plist->capacity == 0)//如果刚开始没有容量
	{
		plist->arry = (DataType *)malloc(sizeof(DataType)* 5);
	}
	else if (plist->capacity == plist->size)//容量已经满了
	{
		plist->capacity = plist->capacity * 2;
		plist->arry = (DataType *)realloc(plist->arry,sizeof(DataType)* plist->capacity);
	}
}
void PushBack(pSeqList plist, DataType x)//尾插
{
	    CheckCapacity(plist);
		plist->arry[plist->size] = x;
		plist->size++;
}

void PopBack(pSeqList plist) //尾删
{
	assert(plist);
	if (plist->size == 0)
	{
		printf("该顺序表为空\n");
	}
	else
	{
		plist->size--;
	}
}


void PushFront(pSeqList plist, DataType x) //前插
{
	CheckCapacity(plist);
	for (size_t i = plist->size; i > 0; i--)
	{
		plist->arry[i] = plist->arry[i - 1];
	}
	plist->arry[0] = x;
	plist->size++;
}

void PopFront(pSeqList plist)  //头删
{
	assert(plist);
	if (plist->size == 0)
	{
		printf("顺序表为空\n");
	}
	else
	{
		for (size_t i = 0; (int)i < (int)plist->size - 1; i++)
		{
			plist->arry[i] = plist->arry[i + 1];
		}
		plist->size--;
	}
}
void Insert(pSeqList plist, int pos, DataType x)
//指定位置插入某个数据
{
	assert(pos < (int)plist->size);
	CheckCapacity(plist);
	for (int i = plist->size; i > pos ; i--)
	{
		plist->arry[i] = plist->arry[i - 1];
	}
		plist->arry[pos] = x;
		plist->size++;
}
void Remove(pSeqList plist, DataType x)
//找到第一次出现的数x并且删除它

{
	int i = Find(plist, x);
	if (i == -1)
	{
		;
	}
	else
	{
		for (int k = i; k < (int)(plist->size-1); k++)
		{
			plist->arry[k] = plist->arry[k + 1];
		}
		plist->size--;
	}

}
void RemoveAll(pSeqList plist, DataType x)
//找到所有出现数x并且删除它
{
	size_t i = plist->size;
	while (i)
	{
		Remove(plist,x);
		i--;
	}
}
int Find(pSeqList plist, DataType x)
//找出第一此出现某个数据的位置
{
	assert(plist);
	for (size_t i = 0; i < plist->size; i++)
	{
		if (plist->arry[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void ReverseList(pSeqList plist)
//翻转顺序表
{
	assert(plist);
	if (plist->size == 0)
	{
		printf("该顺序表为空\n");
	}
	else
	{
		for (size_t i = 0; i < plist->size / 2; i++)
		{
			DataType tmp = plist->arry[i];
			plist->arry[i] = plist->arry[plist->size - i - 1];
			plist->arry[plist->size - i - 1] = tmp;
		}
	}
}
void SortList(pSeqList plist)
{
	assert(plist);
	if (plist->size == 0)
	{
		printf("该顺序表为空\n");
	}
	else
	{
		for (size_t k = 0; k < plist->size; k++)
		{
			for (size_t i = 0; i < plist->size - k - 1; i++)
			{
				if (plist->arry[i]>plist->arry[i + 1])
				{
					DataType tmp = plist->arry[i];
					plist->arry[i] = plist->arry[i + 1];
					plist->arry[i + 1] = tmp;
				}
			}

		}
	}
}

void BinarySearch(pSeqList plist, DataType x)
{
	assert(plist);
	if (plist->size == 0)
	{
		printf("顺序表为空\n");
	}
	else
	{
		int start = 0;
		int end = plist->size - 1;
		while (start <= end)
		{
			if (plist->arry[(end + start)/2] == x)
			{
				printf("找到了\n");
				return;
			}
			else if (plist->arry[(end + start)/2]>x)
			{
				end = (end + start) / 2 + 1;
			}
			else
			{
				start = (end + start) / 2 + 1;
			}
		}
		printf("没找到\n");
	}
}

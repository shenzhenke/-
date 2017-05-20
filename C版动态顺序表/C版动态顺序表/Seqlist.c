#include "Seqlist.h"
void InitSeqlist(pSeqList plist)
//��ʼ��˳����������ٿռ�
{
	assert(plist);
	plist->capacity = 5;
	plist->arry = (DataType*)malloc(sizeof(DataType)*plist->capacity);
	assert(plist); //��ֹ���ٿռ䲻�ɹ�
	plist->size = 0;
}

void PrintSeqlist(pSeqList plist)
{
	
	if (plist->size == 0)
	{
		printf("��˳���Ϊ��\n");
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
	if (plist->capacity == 0)//����տ�ʼû������
	{
		plist->arry = (DataType *)malloc(sizeof(DataType)* 5);
	}
	else if (plist->capacity == plist->size)//�����Ѿ�����
	{
		plist->capacity = plist->capacity * 2;
		plist->arry = (DataType *)realloc(plist->arry,sizeof(DataType)* plist->capacity);
	}
}
void PushBack(pSeqList plist, DataType x)//β��
{
	    CheckCapacity(plist);
		plist->arry[plist->size] = x;
		plist->size++;
}

void PopBack(pSeqList plist) //βɾ
{
	assert(plist);
	if (plist->size == 0)
	{
		printf("��˳���Ϊ��\n");
	}
	else
	{
		plist->size--;
	}
}


void PushFront(pSeqList plist, DataType x) //ǰ��
{
	CheckCapacity(plist);
	for (size_t i = plist->size; i > 0; i--)
	{
		plist->arry[i] = plist->arry[i - 1];
	}
	plist->arry[0] = x;
	plist->size++;
}

void PopFront(pSeqList plist)  //ͷɾ
{
	assert(plist);
	if (plist->size == 0)
	{
		printf("˳���Ϊ��\n");
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
//ָ��λ�ò���ĳ������
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
//�ҵ���һ�γ��ֵ���x����ɾ����

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
//�ҵ����г�����x����ɾ����
{
	size_t i = plist->size;
	while (i)
	{
		Remove(plist,x);
		i--;
	}
}
int Find(pSeqList plist, DataType x)
//�ҳ���һ�˳���ĳ�����ݵ�λ��
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
//��ת˳���
{
	assert(plist);
	if (plist->size == 0)
	{
		printf("��˳���Ϊ��\n");
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
		printf("��˳���Ϊ��\n");
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
		printf("˳���Ϊ��\n");
	}
	else
	{
		int start = 0;
		int end = plist->size - 1;
		while (start <= end)
		{
			if (plist->arry[(end + start)/2] == x)
			{
				printf("�ҵ���\n");
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
		printf("û�ҵ�\n");
	}
}

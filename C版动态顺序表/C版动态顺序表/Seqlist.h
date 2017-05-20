#define _CRT_SECURE_NO_WARNINGS 
#ifndef __Seqlsit__
#define __Seqlist__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int DataType;
typedef struct pList
{
	DataType *arry;
	size_t size;
	size_t capacity;
}*pSeqList,pList;

void InitSeqlist(pSeqList plist);
void CheckCapacity(pSeqList  plist);
void PrintSeqlist(pSeqList plist);
void PushBack(pSeqList plist, DataType x);
void PopBack(pSeqList plist);
void PushFront(pSeqList plist, DataType x);
void PopFront(pSeqList plist);
void Insert(pSeqList plist, int pos, DataType x);
void Remove(pSeqList plist, DataType x);
void RemoveAll(pSeqList plist, DataType x);
int Find(pSeqList plist, DataType x);
void ReverseList(pSeqList plist);
void SortList(pSeqList plist);
void BinarySearch(pSeqList plist, DataType x);

#endif  //__Seqlsit__
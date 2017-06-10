#define _CRT_SECURE_NO_WARNINGS 
#ifndef __SeqList_H__
#define __SeqList_H__
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<windows.h>
#include<stdio.h>
#define MAX 100
typedef int DataType;
typedef struct  SeqList
{
	DataType arr[MAX];
	int count;
}SeqList, *pSeqlist;
void InitSeqList(pSeqlist p);
void PushBack(pSeqlist p, DataType d);
void PopBack(pSeqlist p);
void PushFront(pSeqlist p, DataType d);
void PopFront(pSeqlist p);
int Find(pSeqlist p, DataType d);
void Remove(pSeqlist p, DataType d);
void RemoveAll(pSeqlist p, DataType d);
void Show(pSeqlist p);
void Sort(pSeqlist p);
int BinarySearch(pSeqlist p, DataType d);
#endif

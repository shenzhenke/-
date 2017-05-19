#define _CRT_SECURE_NO_WARNINGS 
#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>


typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node* next;
}Node ,*pNode,*pList;

typedef struct ComplexNode
{
	DataType data;
	struct ComplexNode *next;
	struct ComplexNode *random;

}ComplexNode,*pComplexNode,*pComplexList;


void InitList(pList* pplist);
int GetListLength(pList plist);
void PushBack(pList *pplist, DataType d);
void PopBack(pList *pplist);
void PushFront(pList *pplist, DataType d);
void PopFront(pList *pplist);
pNode Find(pList plist, DataType d);
void Remove(pList *pplist, DataType d);
void RemoveAll(pList *pplsit, DataType d);
void PrintList(pList plist);
void Insert(pList *pplist,pNode pos,DataType d);
void Erase(pList *pplist, pNode pos);
void DestroyList(pList *pplist);

//删除无头单链表的非尾结点
void EraseNotTail(pNode pos);

//反转整个单链表

void ReverseList(pList* pplist);

//冒泡排序整个单链表
void BubbleSort(pList *pplist);

//在当前结点前插入一个数据d
void InsertFrontNode(pNode pos, DataType d);

//合并两个有序链表——非递归实现
pList Merge(pList l1,pList l2 );
//链表合并的递归实现
pList Merge2(pList l1, pList l2);

pNode FindMidNode(pList plist);
//查找链表的中间结点

void DelKNode(pList *pplist, int k);
//删除单链表的倒数第k个结点（k>1&&k<链表的总长度）
//时间复杂度尾O（N）

pNode  JosephCycle(pList *pplist, int num);
//约瑟夫环问题

pNode CheckCycle(pList plist);
//检测链表是否带环，返回两个指针的相遇点


int GetCircleLength(pNode meet);
//带环则求出环的长度

pNode   GetCycleEntryNode(pList list, pNode meetNode);
//带环求出环的入口点

int CheckCross(pList list1, pList list2);
//检测两条不带环链表是否相交相交返回1，不相交返回0

void PrintReversely(pList plist);
//逆序打印整个链表	

pComplexNode CreateComplexNode(DataType d);
//创建一个复杂链表结点
void PrintComplexList(pComplexList plist);
//打印一个复杂链表
pComplexList CloneComplexList(pComplexList plist);
//复制一个复杂链表
#endif //__LIST_H__



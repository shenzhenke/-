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

//ɾ����ͷ������ķ�β���
void EraseNotTail(pNode pos);

//��ת����������

void ReverseList(pList* pplist);

//ð����������������
void BubbleSort(pList *pplist);

//�ڵ�ǰ���ǰ����һ������d
void InsertFrontNode(pNode pos, DataType d);

//�ϲ����������������ǵݹ�ʵ��
pList Merge(pList l1,pList l2 );
//����ϲ��ĵݹ�ʵ��
pList Merge2(pList l1, pList l2);

pNode FindMidNode(pList plist);
//����������м���

void DelKNode(pList *pplist, int k);
//ɾ��������ĵ�����k����㣨k>1&&k<������ܳ��ȣ�
//ʱ�临�Ӷ�βO��N��

pNode  JosephCycle(pList *pplist, int num);
//Լɪ������

pNode CheckCycle(pList plist);
//��������Ƿ��������������ָ���������


int GetCircleLength(pNode meet);
//������������ĳ���

pNode   GetCycleEntryNode(pList list, pNode meetNode);
//�������������ڵ�

int CheckCross(pList list1, pList list2);
//������������������Ƿ��ཻ�ཻ����1�����ཻ����0

void PrintReversely(pList plist);
//�����ӡ��������	

pComplexNode CreateComplexNode(DataType d);
//����һ������������
void PrintComplexList(pComplexList plist);
//��ӡһ����������
pComplexList CloneComplexList(pComplexList plist);
//����һ����������
#endif //__LIST_H__



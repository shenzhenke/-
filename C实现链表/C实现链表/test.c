#define _CRT_SECURE_NO_WARNINGS 
#include "list.h"
int main()
{
	pComplexNode plist = NULL;
	pNode plist1 = NULL;
	pNode plist2 = NULL;
	pComplexNode ret = NULL;
	//InitList(&plist);
	//PushBack(&plist, 4);  //后插
	//PushBack(&plist, 3);
	//PushBack(&plist, 2);
	//PushBack(&plist, 1);
	////PrintList(plist);
	//PopFront(&plist);   //前删
	////PrintList(plist);
	////printf("%d\n",Find(plist, 4));  //查找
	////printf("%d\n",GetListLength(plist));  //得到链表的长度
	//PushFront(&plist, 1);   //前插   4321
	//PushFront(&plist, 4);
	//PushFront(&plist, 4);
	////PrintList(plist);
	//PopBack(&plist);   //尾删  432
	//PrintList(plist);
	//Remove(&plist, 4);  //删除第一次出现某个结点 32
	////PrintList(plist);
	///*Remove(&plist, 4);
	//PrintList(plist);*/
	////Remove(&plist, 2);
	////Remove(&plist, 4);
	////Remove(&plist, 3);
	////PrintList(plist);
	////RemoveAll(&plist, 4);
	////PrintList(plist);
	////Insert(&plist, plist->next->next, 4);
	////PrintList(plist);
	////ret = Find(plist, 3);
	//////Erase(&plist, ret);
	////PrintList(plist);
 ////    EraseNotTail(ret);
	///*PrintList(plist);
	//ReverseList(&plist);*/
	//PrintList(plist);
 //   BubbleSort(&plist);
	//PrintList(plist);
	//ret = Find(plist, 1);
 //   InsertFrontNode(ret, 0);
	//PushBack(&plist1, 4);  //后插
	//PushBack(&plist1, 3);
	//PushBack(&plist1, 2);
	//PushBack(&plist1, 1);
	//PushBack(&plist2, 5);
	//
	//PushBack(&plist, 5); 
	//PushBack(&plist, 4);  //后插
	//PushBack(&plist, 3);
	//PushBack(&plist, 2);
	//PushBack(&plist, 1);
	////PrintList(plist);
	//ret = Find(plist1, 2);
	//plist2->next = ret;
	//PushBack(&plist1, 4);  //后插
	//PushBack(&plist1, 6);
	//PushBack(&plist1, 8);
	//PushBack(&plist1, 10);
	// //后插
	//PushBack(&plist2, 5);
	//PushBack(&plist2, 7);
	//PushBack(&plist2, 9);
	//ret=Merge(plist1,plist2);
	//PrintList(ret);

	// 复杂链表

	ret = CreateComplexNode(4);
	plist = ret;
	plist->next = CreateComplexNode(3);
	plist->next->next = CreateComplexNode(2);
	plist->next->next->next = CreateComplexNode(1);
	plist->random = plist->next->next->next;
	plist->next->random = plist;
	plist->next->next->random = plist->next;
	plist->next->next->next->random = NULL;
	  PrintComplexList(CloneComplexList(plist));
    //printf("%d \n",FindMidNode(plist)->data);
  /*  DelKNode(&plist, 4);
	PrintList(plist);*/
	//printf("%d \n",JosephCycle(&plist, 3)->data);
	//ret =  CheckCycle(plist);
	//printf("%d \n", ret->data);
	//printf("%d \n", GetCircleLength(ret));
	//printf("%d \n", GetCycleEntryNode(plist, ret)->data);
	//printf("%d \n", CheckCross(plist1, plist2));
	//PrintReversely(plist);
//	DestroyList(&plist); 
	system("pause");
	return 0;
} 
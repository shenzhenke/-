#include "Seqlist.h"
int main()
{
	pList list ;
	InitSeqlist(&list);
	////PrintSeqlist(&list);
	////PushBack(&list, 6);
	////PushBack(&list, 5);
	////PushBack(&list, 4);
	////PushBack(&list, 3);
	////PushBack(&list, 2);
	////PushBack(&list, 1);
	////PrintSeqlist(&list);
	////PushFront(&list, 0);
	////PrintSeqlist(&list);
	////PopBack(&list);
	//PopFront(&list);
	//PrintSeqlist(&list);
	//PushBack(&list, 1);
	////Insert(&list, 0, 5);
	//PrintSeqlist(&list);
	//PopBack(&list);
	//PrintSeqlist(&list);
	//PushBack(&list, 0);
	///*PushBack(&list, 1);
	//PushBack(&list, 5);
	//PushBack(&list, 3);*/
	//PrintSeqlist(&list);
	////RemoveAll(&list, 4);
	////RemoveAll(&list, 5);
	////Remove(&list,0);
	//PrintSeqlist(&list);
	//ReverseList(&list);
	//PrintSeqlist(&list);
	//SortList(&list);
	//PrintSeqlist(&list);
	PushBack(&list, 1);
	BinarySearch(&list, 1);
	PushBack(&list, 2);
	BinarySearch(&list, 5);
	PushBack(&list, 3);
	BinarySearch(&list, 2);
	PushBack(&list, 4);
	BinarySearch(&list, 5);
	PushBack(&list, 5);
	BinarySearch(&list, 5);
	return 0;
}
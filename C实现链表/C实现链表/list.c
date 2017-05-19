#define _CRT_SECURE_NO_WARNINGS 
#include "list.h"
void InitList(pList* pplist)
{
	assert(pplist!=NULL);
	*pplist = NULL;
	printf("链表初始化成功！！！\n");

}
pNode BuyNode(DataType d)  //创建一个新结点
{
	pNode pnode = (pNode)malloc(sizeof(Node));//创建结点
	pnode->data = d;
	pnode->next = NULL;
	return pnode;
}
int GetListLength(pList plist)    //求链表的长度
{
	int count = 0;
	if (plist == NULL)
	{
		printf("该链表为空！！！\n");
	}
	else
	{
		while (plist != NULL)
		{
			count++;
			plist = plist->next;
		}
	}
	return count;
}
void PushBack(pList *pplist, DataType d) //尾插一个结点
{
	pNode NewNode = BuyNode(d);
	assert(pplist != NULL);
	pNode cur = *pplist;
	if (cur == NULL)
	{
		*pplist = NewNode;
		NewNode->next = NULL;;
	}
	else
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		 cur->next= NewNode;
		NewNode->next = NULL;
	}
	return;
}
void PopBack(pList *pplist)  //尾删一个元素
{
	   assert(pplist != NULL);
		pNode cur = *pplist;
		pNode del = *pplist;
		if (cur == NULL)
		{
			printf("该链表为空！！！！");
			return;
		}
		else
		{
			while (del->next != NULL)
			{
				cur = del;
				del = del->next;
			}
			cur->next = NULL;
			del = del->next;
			free(del);
			return;
		}

}
void PushFront(pList *pplist, DataType d) //前插一个元素
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	pNode NewNode = BuyNode(d);
	if (cur == NULL)
	{
		*pplist = NewNode;
		NewNode->next = NULL;
		return;
	}
	else
	{
		*pplist = NewNode;
		NewNode->next = cur;
		return;
	}
}
void PopFront(pList *pplist)   //前删一个元素
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	if (cur == NULL)  //没有结点
	{
		return;
	}
	else if (cur->next == NULL)  //有一个结点
	{
		cur = cur->next;
		free(cur);
		*pplist = NULL;
	}
	else    //有多个结点
	{
		 *pplist=cur->next;
		free(cur);
	}


}
pNode Find(pList plist, DataType d)   //查找结点
{
	if (plist == NULL)
	{
	    printf("该链表为空\n");
		return NULL;
	}
	else
	{
		while (plist!=NULL)
		{
			if (plist->data == d)
			{
				return plist;
			}
			else
			{
				plist = plist->next;
			}
		}
	}
	printf("没有找到该元素！！！\n");
	return NULL;
}
void Remove(pList *pplist, DataType d)  //删除第一次出现该元素的结点
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	pNode prev = *pplist;
	pNode del= Find(*pplist, d);
	if (del == NULL)  //只有一个结点且是要删除的结点
	{
		free(del);
		*pplist = NULL;
		return;
	}
	if (del == cur)  
	{
		*pplist = cur->next;
		free(del);
	}
	else
	{
		while (cur != del)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = del->next;
		free(del);
	}
	return;
}
void  RemoveAll(pList *pplsit, DataType d)  //删除出现这个结点的所有结点
{
	pNode cur = *pplsit;
	pNode prev = *pplsit;
	pNode  del = NULL;
	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
		if (prev->data == d)
		{
			Remove(pplsit, d);
		}
	}
	return;
}
void PrintList(pList plist)
{  
	pNode cur = plist;
	while (cur != NULL)
	{
		printf("%d->",cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
void Insert(pList *pplist, pNode pos, DataType d)//指定位置插入数据
{ 
	assert(pplist!=NULL);
	pNode cur = *pplist;
	pNode prev = *pplist;
	pNode NewNode = BuyNode(d);
	if (cur == pos)  //在所有结点之前
	{
		PushFront(pplist, d);
		return;
	}
	else 
	{
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = NewNode;
		NewNode->next = cur;
		return;
	}


}
void Erase(pList *pplist, pNode pos)//指定结点删除元素
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	pNode prev = *pplist;
	if (cur == pos)  //在所有结点之前
	{
		PopFront(pplist);
		return;
	}
	else
	{
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		return;
	}

}
void DestroyList(pList *pplist)
{
	pNode cur = *pplist;
	pNode del = *pplist;
	if (cur != NULL)
	{
		while (cur != NULL)
		{
			cur = cur->next;
			free(del);
			printf("del ");
			del = cur;
		}
	}
	else
	{
		printf("此链表为空\n");
		return;
	}
	printf("链表已经清除\n");
	return;

}
void EraseNotTail(pNode pos)        //删除无头单链表的非尾结点
{
	assert(pos);
	pNode del = pos;
	if (pos->next == NULL)
	{
		printf("该结点为尾结点\n");
		return;
	}
	else
	{
		del = pos->next;
		pos->data = pos->next->data;   //数据交换   
		pos->next = del->next;
		free(del);
	}
}

void ReverseList(pList* pplist)
{
	pNode newlist = NULL;
	pNode cur = NULL;
	assert(pplist);
	if ((*pplist == NULL) || (*pplist)->next == NULL)
	{
		return;
	}
	else
	{
		while ((*pplist)->next != NULL)
		{
			cur = *pplist;
			*pplist = (*pplist)->next;   //顺序很重要
			cur->next = newlist;
			newlist = cur;
		}
		cur = *pplist;
		cur->next = newlist;
		*pplist = cur;
		return;
	}

}
void BubbleSort(pList *pplist)
{
	assert(*pplist);
	pNode cur = *pplist;
	pNode prev = *pplist;
	pNode end = NULL;   //冒泡排序的终点
	int count = 0;
	if ((*pplist == NULL) && ((*pplist)->next == NULL))
	{
		return;
	}
	else
	{
		while (end != *pplist)
		{
			if (count == 0)
			{
				while (cur->next != end)
				{
					if (cur->data >= cur->next->data)
					{
						DataType i = cur->data;
						cur->data = cur->next->data;
						cur->next->data = i;
					}
					prev = cur;
					cur = cur->next;
				}
				end = prev;
				cur = *pplist;
				count++;
			}
			else
			{
				while (cur->next != end->next)
				{
					if (cur->data >= cur->next->data)
					{
						DataType i = cur->data;
						cur->data = cur->next->data;
						cur->next->data = i;
					}
					prev = cur;
					cur = cur->next;
				}
				end = prev;
				cur = *pplist;
			}

		}
	}
}
void InsertFrontNode(pNode pos, DataType d)//在当前结点的前面插入一个结点
{
	pNode newnode = BuyNode(d);
	if (pos == NULL)
	{
		return;
	}
	else
	{
		newnode->next = pos->next;
		pos->next = newnode;
		newnode->data = pos->data;
		pos->data = d;
		return;
	}

}

pNode FindMidNode(pList plist)
//查找链表的中间结点
{
	pNode slow = plist;
	pNode fast = plist;
	int count = 0;
	if (plist == NULL)
	{
		printf("当前链表为空\n");
		return NULL;
	}
	else if (plist->next == NULL)
	{
		return plist;
	}
	else
	{
		while (fast->next != NULL)
		{
			fast = fast->next;
			count++;
			if (count == 2)
			{
				slow = slow->next;
				count = 0;
			}
		}
		return slow;
	}
}


void DelKNode(pList *pplist, int k)
//删除单链表的倒数第k个结点（k>1&&k<链表的总长度）
//时间复杂度尾O（N）

{
	pNode slow = *pplist;
	pNode fast = *pplist;
	assert(*pplist != NULL);
	if ((*pplist)->next == NULL)
	{
		return;
	}
	else
	{
		while (fast->next != NULL)
		{
			--k;
			if (k <= 0)
			{
				slow = slow->next;
			}
			fast = fast->next;
		}
		 Erase(pplist, slow);
		 return;
	}

}

pNode  JosephCycle(pList *pplist, int num)
//约瑟夫环问题
{
	int k = num;
	pNode cur = *pplist;
	pNode del = *pplist;
	assert(*pplist);
	while (1)
	{
		if (cur->next == NULL)
		{
			printf("此链表未构成环!!!\n");
			return NULL;
		}
		--k;
		if (k <= 0)
		{
			del = cur->next;
			cur->data = del->data;
			cur->next = del->next;
			free(del);
			k = num;
		}
		if (cur->next == cur)
		{
			return cur;
			break;
		}
		if (k != num)
		{
			cur = cur->next;
		}
	}
}
pNode CheckCycle(pList plist)
{
	pNode slow = plist;
	pNode fast = plist;
	if ((plist->next == NULL) || (plist == NULL))
	{
		printf("该链表并未构成环\n");
		return NULL;
	}
	else
	{
		while (1)
		{
			slow = slow->next;
			fast = fast->next->next; 
			//当快慢指针以两倍速度进行时，返回的相遇点是固定的
			if (slow == fast)
			{
				break;
			}
		}
		return slow;
	}

}
int GetCircleLength(pNode meet)
{
	pNode cur = meet->next;
	int count = 0;
	while (cur != meet)
	{
		count++;
		cur = cur->next;
	}
	return ++count;
}
pNode   GetCycleEntryNode(pList list, pNode meetNode)
{
	pNode cur1 = meetNode;
	pNode cur2 = list;
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

int CheckCross(pList list1, pList list2)
    {
		pNode cur1 = list1;
		pNode cur2 = list2;
			if ((list1 == NULL) || (list2 == NULL))
			{
				return 0;
			}
				while (cur1->next != NULL) 
				{
					cur1 = cur1->next;
				}
				while ((cur2->next != NULL))
					{
						cur2 = cur2->next;
					}
				if (cur1 == cur2)
				{
					return 1;
				}
		return 0;
}
void PrintReversely(pList plist)
{
	pNode cur = plist;
	if (cur->next != NULL)
	{
		PrintReversely(cur->next);
	}
	printf("%d->",cur->data);
}
pList Merge(pList l1, pList l2)   //合并两条复杂链表
{
	
	pNode cur1 = NULL;
	pNode cur2 = NULL;
	pList newlist = NULL;
	pNode list = NULL;
	int count = 0;
	if (l1 == NULL)
	{
		return l2;
	}
	if(l2 == NULL)
	{
		return l1;
	}
	while ((l1) && (l2))
	{
		if (l2->data >= l1->data)
		{
			cur1 = l1->next;
			l1->next = l2;
			newlist = l1;
			l1 = cur1;
		}
		else if(l1->data > l2->data)
		{
			cur2 = l2->next;
			l2->next = l1;
			newlist = l2;
			l2 = cur2;
		}
		if (count == 0)
		{
			list = newlist;
			count++;
		}
		newlist = newlist->next;
	}
	if (l1 == NULL)
	{
		newlist = l2;
		return list;
	}
	if (l2 == NULL)
	{
		newlist = l1;
		return list;
	}
	return NULL;
}

pComplexNode CreateComplexNode(DataType d)
//创建一个复杂链表结点
{
	pComplexNode newnode = (pComplexNode)malloc(sizeof(ComplexNode));
	if (newnode == NULL)
	{
		perror("malloc");
		return NULL;
	}
	newnode->data = d;
	newnode->next = NULL;
	newnode->random = NULL;
	return newnode;
}

void PrintComplexList(pComplexList plist)
//打印一个复杂链表
{
	pComplexNode  cur = plist;
	if (plist == NULL)
	{
		printf("此链表为空！！！\n");
		return ;
	}
	while (cur != NULL)
	{
		if (cur->random!=NULL)
		{
			printf("%d->[%d]->", cur->data, cur->random->data);
		}
		else
		{
			printf("%d->[NULL]->", cur->data);
		}
		cur = cur->next;
	}

	printf("NULL\n");
}

pComplexList CloneComplexList(pComplexList plist)
//复制一个复杂链表
{
	pComplexNode ret = NULL;
	pComplexNode cur = plist;
	pComplexNode CloneNode = NULL;
	pComplexNode CloneNodeHead =NULL;
	//拷贝一份
	while (cur)
	{

		ret = CreateComplexNode(cur->data);
		ret->next = cur->next;
		cur->next = ret;
		cur = cur->next->next;
	}
	cur = plist;

	//调整random指针
	while (cur)
	{
		if (cur->random != NULL)
		{
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;
	}
	//分离两个链表
	if (plist!= NULL)
	{
		CloneNodeHead = CloneNode = plist->next;
		plist->next = CloneNode->next;
		plist = plist->next;
	}
	while (plist)
	{
		CloneNode->next = plist->next;   //把偶数位置的结点链接起来就是复制出来的新链表  
		CloneNode = CloneNode->next;
		plist->next = CloneNode->next;   
		plist = plist->next;
	}
	return CloneNodeHead;
}
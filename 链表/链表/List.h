#define _CRT_SECURE_NO_WARNINGS 
//输入一个链表，输出该链表中倒数第k个结点
class Solution {
public:
	typedef ListNode Node;
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
		if (pListHead == NULL)
			return NULL;
		vector<Node*>  t;
		Node* cur = pListHead;
		while (cur != NULL)
		{
			t.push_back(cur);
			cur = cur->next;
		}
		unsigned int countNode = t.size();
		if (k>countNode)
			return NULL;
		return t[countNode - k];
	}
};



//从尾到头打印单链表
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<ListNode*> v;
		ListNode* cur = head;
		while (cur != NULL){
			v.push_back(cur);
			cur = cur->next;
		}
		int countNode = v.size();
		vector<int>  rList;
		for (int i = countNode - 1; i >= 0; i--){
			rList.push_back(v[i]->val);
		}
		return rList;
	}
};






//反转链表

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode* newpHead = pHead;
		pHead = pHead->next;
		newpHead->next = NULL;
		ListNode* cur = NULL;
		while (pHead != NULL)
		{
			cur = pHead;
			pHead = pHead->next;
			cur->next = newpHead;
			newpHead = cur;
		}
		pHead = newpHead;
		return pHead;
	}
};


//返回链表第一个公共结点

class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;
		if (pHead1 == pHead2)
			return pHead1;
		set<ListNode*> t;
		ListNode* cur = pHead1;
		while (cur != NULL)
		{
			t.insert(cur);
			cur = cur->next;
		}
		cur = pHead2;
		while (cur != NULL)
		{
			if (t.insert(cur).second == false)
				return cur;
			cur = cur->next;
		}
		return NULL;
	}
};






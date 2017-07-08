
//struct ListNode 
//{
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//		val(x), next(NULL)
//	{
//	}
//};
//
//class Solution 
//{
//	typedef ListNode Node;
//public:
//	ListNode* deleteDuplication(ListNode* pHead)
//	{
//		if (pHead == NULL || pHead->next == NULL)
//			return pHead;
//		Node* cur = pHead->next;
//		while (cur->next != NULL&&cur != NULL)
//		{
//			Node* next = cur->next;
//			while (cur->val == next->val)
//			{
//				Node* del = next;
//				next = next->next;
//				cur->next = next;
//				del->next = NULL;
//				delete del;
//				del = NULL;
//				if (next == NULL)
//					return pHead;
//			}
//			cur = cur->next;
//		}
//		return  pHead;
//	}
//};








struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x)
		:val(x)
		,next(NULL) 
	{
	}
};

class Solution 
{
	typedef ListNode Node;
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		map<int, Node*> countNode;
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		Node* cur = pHead->next;
		int sort = 0;
		cur = pHead;
		Node* del = NULL;
		while (cur != NULL)
		{
			if (countNode.find(cur->val) != countNode.end())
			{
				del = cur;
				cur = cur->next;
				del->next = NULL;
				delete del;
				del = NULL;
			}
			if (cur != NULL)
			{
				if (cur->val < pHead->val)
					sort = -1;
				countNode.insert(make_pair(cur->val, cur));
				cur = cur->next;
			}
		}
		if (sort == -1)
		{
			map<int, Node*>::reverse_iterator it = countNode.rbegin();
			map<int, Node*>::reverse_iterator next = countNode.rbegin();
			while (it != countNode.rend())
			{
				if ((++next) != countNode.rend())
					(*it).second->next = (*(next)).second;
				else
					(*it).second->next = NULL;
				++it;
			}
			pHead = countNode.rbegin()->second;
		}
		else
		{
			map<int, Node*>::iterator it = countNode.begin();
			map<int, Node*>::iterator next = countNode.begin();
			while (it != countNode.end())
			{
				if ((++next) != countNode.end())
					(*it).second->next = (*(next)).second;
				else
					(*it).second->next = NULL;
				++it;
			}
			pHead = countNode.begin()->second;
		}
		return pHead;
	}
};
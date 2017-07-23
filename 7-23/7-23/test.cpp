#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
using namespace std;
#include <stack>
#define Swap(a,b) \
do { int tmp = a; \
	a = b;\
	b = tmp;\
} while (false)
class A
{
	char a;
	double b;
};
class B
{
	char  c;
	A a;
	char d;
};
struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
	Node(int x)
		:val(x)
		, left(NULL)
		, right(NULL)
	{}
};

int _TreeDepth(Node* root)
{
	if (root == NULL)
		return 0;
	int leftDepth = _TreeDepth(root->left);
	int rightDepth = _TreeDepth(root->right);
	return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);
}
int TreeDepth(Node* root)
{
	return	_TreeDepth(root);
}

//搜索二叉树第k大的结点
void InOrder(Node* pRoot, Node* &obj, int &k)
{
	if (pRoot == NULL)
		return;
	InOrder(pRoot->left, obj, k);
	if (--k == 0)
		obj = pRoot;
	InOrder(pRoot->right, obj, k);
}
Node* KthNode(Node* pRoot, int k)
{
	Node* obj = NULL;
	InOrder(pRoot, obj, k);
	return obj;
}


void _Destroy(Node* root)  //LRD
{
	if (root == NULL)
		return;
	_Destroy(root->left);
	_Destroy(root->right);
	if (root != NULL)
	{
		root->left = NULL;
		root->right = NULL;
		delete root;
		root = NULL;
	}
	return;
}
void Destroy(Node* root)
{
	_Destroy(root);
}


//从指定位置翻转链表


struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x)
		:val(x)
		, next(NULL) 
	{}
};
ListNode* RotateList(ListNode* list, size_t k)
{
	if (k <= 1 || list == NULL)
		return list;
	ListNode* cur = list;
	ListNode* next = NULL;
	ListNode* Head = list;
	ListNode* newHead = NULL;
	while (cur->next != NULL&&k != 1)
	{
		newHead = cur->next;
		next = newHead->next;
		newHead->next = Head;
		cur->next = next;
		Head = newHead;
		k--;
	}
	return newHead;
}

int LastRemaining_Solution(int n, int m)
{
	if (n <= 1 || m <= 1)
		return n - 1;
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	for (int i = 1; i < n; i++)
	{
		ListNode* newNode = new ListNode(i);
		cur->next = newNode;
		cur = cur->next;
	}
	cur->next = head;
	ListNode* prev = head;
	cur = head;
	int count = 0;
	while (cur->next != cur)
	{
		if (m - 1 == count)
		{
			ListNode* del = cur;
			prev->next = del->next;
			cur = cur->next;
			delete del;
			del = NULL;
			count = 0;
		}
		else
		{
			count++;
			prev = cur;
			cur = cur->next;
		}
	}
	return cur->val;
}

//ListNode* RotateList(ListNode* list, size_t k)
//{
//	if (k <= 1 || list == NULL)
//		return list;
//	stack<ListNode*> s;
//	ListNode* next = NULL;
//	ListNode* cur = list;
//	while (k != 0 && cur != NULL)
//	{
//		s.push(cur);
//		cur = cur->next;
//		next = cur;
//		k--;
//	}
//	ListNode* newHead = s.top();
//	cur = newHead;
//	s.pop();
//	while (!s.empty())
//	{
//		cur->next = s.top();
//		cur = cur->next;
//		s.pop();
//	}
//	cur->next = next;
//	list = newHead;
//	return list;
//}

void Print(ListNode* node)
{
	if (node == NULL)
	{
		return;
	}
	while (node->next!=NULL)
	{
		cout << node->val << "->";
		node = node->next;
	}
	cout << node->val << endl;
}
int main()
{
	/*int a = 10;
	int b = 20;
	Swap(a, b);
	cout << a << endl;
	cout << b << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;*/

	/*Node* root = new Node(0);
	Node* root1 = new Node(1);
	root->left = root1;
	Node* root2 = new Node(2);
	root->right = root2;
	Node* root3 = new Node(3);
	root1->left = root3;
	Node* root4 = new Node(4);
	root1->right = root4;
	Node* root5 = new Node(5);
	root2->right = root5;
	Node* root6 = new Node(6);
	root2->left = root6;
	Node* root7 = new Node(7);
	root5->left = root7;
	cout << TreeDepth(root) << endl;
	Destroy(root);*/

	ListNode* list = new ListNode(1);
	ListNode* list1 = new ListNode(2);
	ListNode* list2 = new ListNode(3);
	ListNode* list3 = new ListNode(4);
	ListNode* list4 = new ListNode(5);
	ListNode* list5 = new ListNode(6);
	ListNode* list6 = new ListNode(7);
	list->next = list1;
	list1->next = list2;
	list2->next = list3;
	list3->next = list4;
	list4->next = list5;
	list5->next = list6;
	Print(list);
	ListNode* newList=RotateList(list,8);
	Print(newList);

	cout << LastRemaining_Solution(3, 7) << endl;

	return 0;
}
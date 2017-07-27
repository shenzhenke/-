#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <stack>
#include <queue>
#include <unordered_map>
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x)
		:val(x)
		, left(NULL)
		, right(NULL)
	{}
};

//�ж�һ������Ƿ���һ�ö�������

void	 _IsInTree(TreeNode* root, TreeNode* node,bool& flag)
{
	if (root == NULL)
		return;
	_IsInTree(root->right, node, flag);
	if (root == node)
		flag = true;
	_IsInTree(root->left, node, flag);
}

bool IsInTree(TreeNode* root, TreeNode* node)
{
	if (root == NULL || node == NULL)
	{
		return false;
	}
	bool flag = false;
	_IsInTree(root, node, flag);
	return flag;
}



//�ж�һ�ö������Ƿ�����һ�ö�����������
void _InOrder(stack<TreeNode*>& s, TreeNode* root)
{
	if (root == NULL)
		return;
	_InOrder(s, root->left);
	s.push(root);
	_InOrder(s, root->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	if (pRoot1 == NULL || pRoot2 == NULL)
		return false;
	_InOrder(s1, pRoot1);
	_InOrder(s2, pRoot2);
	while (!s1.empty())
	{
		while (s1.top()->val == s2.top()->val)
		{
			s1.pop();
			s2.pop();
			if (s2.empty() == true)
				return true;
			if (s1.empty() == true)
				return false;
		}
		s1.pop();
	}
	return false;
}
	



//�ж�һ�����Ƿ�����ȫ������
bool IsCompleteTree(TreeNode* root)
{
	if (root == NULL)
		return false;
	queue<TreeNode*> q;
	TreeNode* cur = root;
	q.push(root);
	bool hasChildNode = true;
	while (!q.empty())
	{
		cur = q.front();
		if (cur->left != NULL)
		{
			if (hasChildNode == true)
				q.push(cur->left);  
			else
				return false;
		}
		else
			hasChildNode = false;  //֤����һ�������ڵ�Ϊ��ȫ�������ĵ�һ��û�к��ӵĽڵ�
		if (cur->right != NULL)
		{
			if (hasChildNode == true)
				q.push(cur->right);
			else
				return  false;
		}
		else
			hasChildNode = false;
		cout << cur->val << " ";
		q.pop();
	}
	return true;
}



void TestIsCompeleteTree()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* root1 = new TreeNode(2);
	root->left = root1;
	TreeNode* root2 = new TreeNode(3);
	root->right = root2;
	cout << IsCompleteTree(root) << endl;
	TreeNode* root3 = new TreeNode(4);
	root1->left = root3;
	cout << IsCompleteTree(root) << endl;
	TreeNode* root4 = new TreeNode(5);
	root2->left = root4;
	cout << IsCompleteTree(root) << endl;
}

//�����������ڵ����������ڵ�

//������������
//struct TreeLinkNode 
//{
//	int val;
//	struct TreeLinkNode *left;
//	struct TreeLinkNode *right;
//	struct TreeLinkNode *parent;
//	TreeLinkNode(int x) 
//		:val(x)
//		, left(NULL)
//		, right(NULL)
//		, parent(NULL)
//	{}
//};
//TreeLinkNode* TheNearestAncestor(TreeLinkNode* node1, TreeLinkNode* node2,TreeLinkNode* root)
//{
//	if (node1 == NULL || node2 == NULL||root==NULL)
//		return NULL;
//	if (node1 == node2)
//		return node1;
//	stack<TreeLinkNode*> s1;
//	stack<TreeLinkNode*> s2;
//	TreeLinkNode* cur = node1;
//	while (cur != root)
//	{
//		s1.push(cur);  
//		cur = cur->parent;
//	}
//	s1.push(root);
//	cur = node2;
//	while (cur != root)
//	{
//		s2.push(cur);
//		cur = cur->parent;
//	}
//	s1.push(root);
//	//������·���ӵ�ǰ�ڵ�һֱ�����ڵ���ջ
//	TreeLinkNode* prev = NULL;
//	while (!s1.empty() && !s2.empty())
//	{
//		if (s1.top() == s2.top())
//		{
//			prev = s1.top();
//			s1.pop();
//			s2.pop();
//		}
//		else
//			break;
//	}
//	return prev;
//}

//void TestTheNearestAncestor()
//{
//	TreeLinkNode* root = new TreeLinkNode(1);
//	root->parent = NULL;
//	TreeLinkNode* root1 = new TreeLinkNode(2);
//	root->left = root1;
//	root1->parent = root;
//	TreeLinkNode* root2 = new TreeLinkNode(3);
//	root2->parent = root;
//	root->right = root2;
//	TreeLinkNode* root3= new TreeLinkNode(4);
//	root1->left = root3;
//	root3->parent = root1;
//	TreeLinkNode* root4 = new TreeLinkNode(5);
//	root1->right = root4;
//	root4->parent = root1;
//	cout << TheNearestAncestor(root3, root4)->val << endl;
//	TreeLinkNode* root5 = new TreeLinkNode(6);
//	cout << TheNearestAncestor(root3, root5) << endl;
//
//	root2->left = root5;
//	root5->parent = root2;
//	cout << TheNearestAncestor(root3, root5)->val << endl;
//}



//����������������,��֤����ڶ�������
//void _TheNearestAncestor(TreeNode* node1, TreeNode* node2, TreeNode* root, TreeNode* &nearestAncestor)
//{
//	if (root == NULL&&nearestAncestor != NULL)
//		return;
//	if (root->val > node1->val&&root->val > node2->val)  //֤����������
//	{
//		_TheNearestAncestor(node1, node2, root->left, nearestAncestor);
//	}
//	else if (root->val < node1->val&&root->val < node2->val)  //֤����������
//	{
//		_TheNearestAncestor(node1, node2, root->right, nearestAncestor);
//	}
//	else
//	{
//		nearestAncestor = root;
//	}
//}
//
//TreeNode* TheNearestAncestor(TreeNode* node1, TreeNode* node2, TreeNode* root)
//{
//	if (root == NULL || node1 == NULL || node2 == NULL)
//		return NULL;
//	TreeNode* nearestAncestor = NULL;
//	_TheNearestAncestor(node1, node2, root, nearestAncestor);
//	return nearestAncestor;
//}


//��ͨ������
//bool  GetPaths(TreeNode* node, TreeNode* root, stack<TreeNode*> & paths)
//{
//	if (root == NULL)
//		return false;
//	paths.push(root);
//	if (root == node)
//		return true;
//	if (GetPaths(node, root->right, paths))
//		return true;
//	if (GetPaths(node, root->left, paths))
//		return true;
//	paths.pop();
//	return false;
//}


void  GetPaths(TreeNode* node, TreeNode* root, stack<TreeNode*> & paths,stack<TreeNode*> help)
{
	if (root == NULL)
		return;
	help.push(root);
	if (root == node)
		paths = help;
	GetPaths(node, root->left, paths, help);
	GetPaths(node, root->right, paths, help);
	return;
}
TreeNode* TheNearestAncestor(TreeNode* node1, TreeNode* node2, TreeNode* root)
{
	if (node1 == NULL || node2==NULL || root == NULL)
		return NULL;
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	stack<TreeNode*> help;
	GetPaths(node1, root, s1, help);
	GetPaths(node2, root, s2, help);
	if (s1.empty() == true || s2.empty() == true)
		return NULL;
	/*if (GetPaths(node1, root, s1) == false || GetPaths(node2, root, s2) == false)
		return NULL;*/
	while (s1.size() != s2.size())
	{
		if (s1.size() > s2.size())
			s1.pop();
		else
			s2.pop();
	}
	while (!s1.empty() && !s2.empty())
	{
		if (s1.top() != s2.top())
		{
			s1.pop();
			s2.pop();
		}
		else
			return s1.top();
	}
	return NULL;
}

void  TestTheNearestAncestor()
{
	TreeNode* root = new TreeNode(5);
	TreeNode* root1 = new TreeNode(3);
	root->left = root1;
	TreeNode* root2 = new TreeNode(7);
	root->right = root2;
	cout << TheNearestAncestor(root1, root2, root)->val << endl;
	TreeNode* root3 = new TreeNode(1);
	root1->left = root3;
	cout << TheNearestAncestor(root1, root3, root)->val << endl;
	TreeNode* root4 = new TreeNode(4);
	root1->right = root4;
	cout << TheNearestAncestor(root1, root3, root)->val << endl;
	TreeNode* root5 = new TreeNode(6);
	root2->left = root5;
	TreeNode* root6 = new TreeNode(8);
	root2->right = root6;

}



int main()
{
//	TestIsCompeleteTree();
	TestTheNearestAncestor();
	return 0;
}
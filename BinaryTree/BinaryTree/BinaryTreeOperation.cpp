#include <iostream>
#include <vector>
#include <map>
using namespace std;
////二叉树的高度,递归版
//class Solution {
//public:
//	int TreeDepth(TreeNode* pRoot)
//	{
//		return _TreeDepth(pRoot);
//	}
//protected:
//	int _TreeDepth(TreeNode* root)
//	{
//		if (root == NULL)
//			return 0;
//		return (_TreeDepth(root->left) + 1)>(_TreeDepth(root->right) + 1) ? (_TreeDepth(root->left) + 1) : (_TreeDepth(root->right) + 1);
//
//	}
//
//};
//
//
////输入一棵二叉树，判断该二叉树是否是平衡二叉树
//class Solution {
//public:
//	bool IsBalanced_Solution(TreeNode* pRoot)
//	{
//		return	_IsBalanced(pRoot);
//	}
//
//	bool _IsBalanced(TreeNode* root)
//	{
//		if (root == NULL)
//			return true;
//		int leftdepth = _Depth(root->left);
//		int rightdepth = _Depth(root->right);
//		return abs(leftdepth - rightdepth)<2 && _IsBalanced(root->left) && _IsBalanced(root->right);
//	}
//	int _Depth(TreeNode* root)
//	{
//		if (root == NULL)
//			return 0;
//		return _Depth(root->left)>_Depth(root->right) ? _Depth(root->left) + 1 : _Depth(root->right) + 1;
//	}
//};
//
//
//
////从上到下打印二叉树,同层结点从左到右
//class Solution
//{
//	typedef  TreeNode Node;
//public:
//	vector<int> PrintFromTopToBottom(TreeNode* root)
//	{
//		vector<int> v;
//		queue<Node*> q;
//		Node* cur = root;
//		if (cur == NULL)
//			return v;
//		q.push(cur);
//		while (!q.empty())
//		{
//			if (cur->left != NULL)
//				q.push(cur->left);
//			if (cur->right != NULL)
//				q.push(cur->right);
//			Node* top = q.front();
//			v.push_back(top->val);
//			q.pop();
//			cur = q.front();
//		}
//		return v;
//	}
//};








//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
//要求不能创建任何新的结点，只能调整树中结点指针的指向。
//class Solution {
//	typedef TreeNode Node;
//public:
//	TreeNode* Convert(TreeNode* pRootOfTree)
//	{
//		if (pRootOfTree == NULL)
//			return NULL;
//		stack<Node*> s;
//		vector<Node*> v;
//		v.push_back(NULL);
//		Node* cur = pRootOfTree;
//		while (cur != NULL || !s.empty())
//		{
//			while (cur != NULL)
//			{
//				s.push(cur);
//				cur = cur->left;
//			}
//			cur = s.top();
//			v.push_back(cur);
//			s.pop();
//			cur = cur->right;
//		}
//		v.push_back(NULL);
//		for (size_t i = 1; i < v.size() - 1; i++)
//		{
//			v[i]->right = v[i + 1];
//			v[i]->left = v[i - 1];
//		}
//		return v[1];
//	}
//};







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

class Solution
{
	typedef TreeNode Node;
public:
	vector<vector<int> > Print(TreeNode* pRoot)
	{
		map<Node*, int> s;
		int high = 0;
		high = _Depth(pRoot, s);
		vector<vector<int> > v(high);
		map<Node*, int>::iterator it = s.begin();
		while (it != s.end())
		{
			v[high - (it->second)].push_back((it->first)->val);
			it++;
		}
		return v;
	}
private:
	int  _Depth(Node* root, map<Node*, int> & s)
	{
		if (root == NULL)
			return 0;
		size_t L_Depth = 1;
		L_Depth += _Depth(root->left, s);
		size_t R_Depth = 1;
		R_Depth += _Depth(root->right, s);
		size_t Depth = L_Depth > R_Depth ? L_Depth : R_Depth;
		s[root] = Depth;
		return Depth;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* root1 = new TreeNode(2);
	root->left = root1;
	TreeNode* root2 = new TreeNode(3);
	root1->left = root2;
	TreeNode* root3 = new TreeNode(4);
	root1->right = root3;
	TreeNode* root4 = new TreeNode(5);
	root->right = root4;
	TreeNode* root5 = new TreeNode(6);
	root4->left = root5;
	TreeNode* root6 = new TreeNode(7);
	root4->right = root6;
	Solution a;
	vector<vector<int> >v(3);
	v = a.Print(root);
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
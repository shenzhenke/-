#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
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

//class Solution
//{
//	typedef TreeNode Node;
//public:
//	vector<vector<int> > Print(TreeNode* pRoot)
//	{
//		map<Node*, int> s;
//		int high = 0;
//		high = _Depth(pRoot, s);
//		vector<vector<int> > v(high);
//		map<Node*, int>::iterator it = s.begin();
//		while (it != s.end())
//		{
//			v[high - (it->second)].push_back((it->first)->val);
//			it++;
//		}
//		return v;
//	}
//private:
//	int  _Depth(Node* root, map<Node*, int> & s)
//	{
//		if (root == NULL)
//			return 0;
//		size_t L_Depth = 1;
//		L_Depth += _Depth(root->left, s);
//		size_t R_Depth = 1;
//		R_Depth += _Depth(root->right, s);
//		size_t Depth = L_Depth > R_Depth ? L_Depth : R_Depth;
//		s[root] = Depth;
//		return Depth;
//	}
//};


class Solution
{
	typedef TreeNode Node;
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		stack<Node*> s1;
		stack<Node*> s2;
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;
		_InOrder(s1, pRoot1);
		_InOrder(s2, pRoot2);
		while (!s1.empty())
		{
			while (s1.top() == s2.top())
			{
				s1.pop();
				s2.pop();
				if (s2.empty() == true)
					return true;
			}
			s1.pop();
		}
		return false;
	}

	vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
	{
		int sum = 0;
		int count = 0;
		int countPath = 0;
		_CountPath(root, expectNumber, sum, countPath);
		vector<vector<int> > v(countPath);
		vector<int> help;
		_FindPath(root, expectNumber, v, help, sum, count);
		for (size_t i = 0; i < v.size(); i++)
		{
			if (i % 2 == 0)
				reverse(v[i].begin(), v[i].end());
		}
		return v;
	}
	void  _FindPath(TreeNode* root, int expectNumber, vector<vector<int> >& v,
		vector<int> help, int sum, int& count)
	{
		if (root == NULL)
			return;
		sum += root->val;
		if (sum == expectNumber&&root->left == NULL&&root->right == NULL)
		{
			help.push_back(root->val);
			for (size_t i = 0; i < help.size(); i++)
			{
				v[count].push_back(help[i]);
			}
			count++;
			return;
		}
		help.push_back(root->val);
		_FindPath(root->left, expectNumber, v, help, sum, count);
		_FindPath(root->right, expectNumber, v, help, sum, count);
	}
	void  _CountPath(TreeNode* root, int expectNumber, int sum, int& countPath)
	{
		if (root == NULL)
			return;
		sum += root->val;
		if (sum == expectNumber&&root->left == NULL&&root->right == NULL)
		{
			countPath++;
			return;
		}
		_CountPath(root->left, expectNumber,sum, countPath);
		_CountPath(root->right, expectNumber, sum ,countPath);
	}
protected:
	void _InOrder(stack<Node*>& s, Node* root)
	{
		if (root == NULL)
		{
			s.push(NULL);
			return;
		}
		_InOrder(s, root->left);
		s.push(root);
		_InOrder(s, root->right);
	}
	


};






//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则输出Yes, 否则输出No。假设输入的数组的任意两个数字都互不相同。
class SquenceOfBST
{
public:
	bool VerifySquenceOfBST(vector<int> sequence) 
	{
		if (sequence.size() <= 1)
			return true;
		 return PartOfBst(0, sequence.size() - 1,sequence);
	}
	bool PartOfBst(int begin, int end,vector<int>& sequence)
	{
		if (begin == end)
			return true;
		int end1 = begin;
		int begin2 = begin;
		for (int i = begin; i < end;i++)
		{
			if (sequence[i]>sequence[end])
				begin2 = i;
		}
		end1 = begin2 - 1;
		int j = begin2;
		while (j < end)
		{
			if (sequence[j] < sequence[end])
				return false;
			j++;
		}
		return PartOfBst(begin, end1, sequence) && PartOfBst(begin2, end - 1, sequence);
	}
};



void LevelOrder(TreeNode* root)
{
	queue<TreeNode*> q;  //队列先进先出
	if (root == NULL)
		return ;
	q.push(root);
	TreeNode* cur = root;
	while (!q.empty())
	{
		cur = q.front();
		cout << cur->val << " ";
		if (cur->left != NULL)  
			q.push(cur->left);
		if (cur->right != NULL)
			q.push(cur->right);
		q.pop();
	}
	cout << endl;
	return;
}


int countZeroNumber(int number)
{
	//末尾产生0必须是要有5和0 2*5 5*6 5*8 0
	//所以只要统计出到n的时候共有多少个数字能够拆出多少含有5,比如25=5*5等
	int count = 0;
	for (int i = 1; i <= number; i++)
	{
		int j = i;
		while (j % 5 == 0)
		{
			count++;
			j /= 5;
		}
	}
	return count;
}


int main()
{
	
	countZeroNumber(55);
	/*vector<int> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(9);
	v.push_back(10);
	SquenceOfBST a;
	cout << a.VerifySquenceOfBST(v) << endl;*/
	/*TreeNode* root = new TreeNode(1);
	TreeNode* root1 = new TreeNode(2);
	root->left = root1;
	TreeNode* root2 = new TreeNode(3);
	root1->left = root2;
	TreeNode* root3 = new TreeNode(4);
	root1->right = root3;
	TreeNode* root4 = new TreeNode(7);
	root->right = root4;*/
	/*TreeNode* root5 = new TreeNode(-2);
	root4->left = root5;
	TreeNode* root6 = new TreeNode(7);
	root4->right = root6;
	LevelOrder(root);*/
	/*Solution a;
	vector<vector<int> >v(3);
	v = a.Print(root);
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}
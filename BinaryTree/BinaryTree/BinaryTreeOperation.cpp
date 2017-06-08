//�������ĸ߶�,�ݹ��
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		return _TreeDepth(pRoot);
	}
protected:
	int _TreeDepth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		return (_TreeDepth(root->left) + 1)>(_TreeDepth(root->right) + 1) ? (_TreeDepth(root->left) + 1) : (_TreeDepth(root->right) + 1);

	}

};


//����һ�ö��������жϸö������Ƿ���ƽ�������
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot)
	{
		return	_IsBalanced(pRoot);
	}

	bool _IsBalanced(TreeNode* root)
	{
		if (root == NULL)
			return true;
		int leftdepth = _Depth(root->left);
		int rightdepth = _Depth(root->right);
		return abs(leftdepth - rightdepth)<2 && _IsBalanced(root->left) && _IsBalanced(root->right);
	}
	int _Depth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		return _Depth(root->left)>_Depth(root->right) ? _Depth(root->left) + 1 : _Depth(root->right) + 1;
	}
};



//���ϵ��´�ӡ������,ͬ���������
class Solution
{
	typedef  TreeNode Node;
public:
	vector<int> PrintFromTopToBottom(TreeNode* root)
	{
		vector<int> v;
		queue<Node*> q;
		Node* cur = root;
		if (cur == NULL)
			return v;
		q.push(cur);
		while (!q.empty())
		{
			if (cur->left != NULL)
				q.push(cur->left);
			if (cur->right != NULL)
				q.push(cur->right);
			Node* top = q.front();
			v.push_back(top->val);
			q.pop();
			cur = q.front();
		}
		return v;
	}
};
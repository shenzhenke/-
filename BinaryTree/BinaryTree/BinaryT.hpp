struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) 
		: val(x)
		, left(NULL)
		, right(NULL) 
	{}
	
};
class Solution {
protected:
	typedef TreeNode Node;
	void  ConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		if (pre.size() == 0 || vin.size() == 0)
			return ;
		Node* root = new Node(pre[0]);
		for (int i = 0; i < vin.size(); i++)
		{
			if (pre[0]==vin[i])

		}
	}
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		if (pre.size() == 0 || vin.size() == 0)
			return NULL;
		ConstructBinaryTree(pre, vin);
	}
};
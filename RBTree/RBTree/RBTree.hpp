#pragma once

enum Colour
{
	RED,
	BLACK
};

template<typename K,typename V>
struct RBTreeNode
{
	//结点
	RBTreeNode* _left;
	RBTreeNode* _right;
	RBTreeNode* _parent;
	//颜色
	Colour _col;
	//KV
	K _key;
	V _value;
	RBTreeNode(const K& key, const V& value)
		:_key(key)
		, _value(value)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _col(RED)  //把新增结点置成红色为了保持每条路径的黑色结点个数不变
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(NULL)
	{}
	bool Insert(const K& key, const V& value)
	{
		//1.插入结点为根节点，必须为黑色
		if (_root == NULL)
		{
			_root = new Node(key, value);
			_root->_col = BLACK;
			return true;
		}
		Node* cur = _root;
		Node* parent = NULL;
		while (cur != NULL)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key, value);
		if (key > parent->_key)
			parent->_right = cur;
		else
			parent->_left = cur;
		cur->_parent = parent;
		while (parent != NULL)
		{
			Node* pparent = parent->_parent;
			Node* uncle = NULL;
			//2.如果插入节点或者调整结点的父结点为黑色结点,增加一个红色结点，对每条路径的黑色结点个数没影响
			if (parent->_col == BLACK)
			{
				break;
			}

			//判断叔叔结点是否存在,存在是在左还是右？
			if (pparent != NULL)
			{
				if (pparent->_right == parent)
					uncle = pparent->_left;
				else
					uncle = pparent->_right;
			}

			//3.插入结点或调整结点父结点为红色且叔叔结点为红色
			if (uncle != NULL&&uncle->_col == RED)
			{
				parent->_col = BLACK;
				uncle->_col = BLACK;
				if (pparent == _root)
					return true;
				pparent->_col = RED;
				//继续向上调整
				//假如调整到根结点，只需将根结点的颜色置为黑色即可
				if (parent == _root)
				{
					parent->_col = BLACK;
					return true;
				}
				cur = parent->_parent;
				parent = cur->_parent;
			}
			//4.插入结点或调整结点父结点为红色且叔叔结点不存在或
			//  插入结点或调整结点父结点为红色且叔叔结点存在为黑色二者逻辑一样。
			else
			//剩下的情况 (uncle == NULL || uncle->_col == BLACK)
			{
				//判断父结点在左还是在有
				if (pparent->_left == parent)
				{
					//左--左
					if (parent->_left == cur)
					{
						_RotateR(pparent);
						pparent->_col = RED;
						parent->_col = BLACK;
						if (pparent == _root)
						{
							_root = parent;
						}
					}
					//左--右
					else
					{
						_RotateL(parent);
						_RotateR(pparent);
						cur->_col = BLACK;
						parent->_col = RED;
						pparent->_col = RED;
						if (pparent == _root)
							_root = cur;
					}
				}
				//父结点在右
				else
				{
					//右--右
					if (parent->_right == cur)
					{
						_RotateL(pparent);
						pparent->_col = RED;
						parent->_col = BLACK;
						if (pparent == _root)
							_root = parent;
					}
					//右--左
					else
					{
						_RotateR(parent);
						_RotateL(pparent);
						parent->_col = RED;
						pparent->_col = RED;
						cur->_col = BLACK;
						if (pparent == _root)
							_root = parent;
					}
				}
				break;
			}
		}
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	bool Isbalance()
	{
		//1.空树认为是RBTree
		if (_root == NULL)
			return true;
		//2.根结点非黑不是RBTree
		if (_root->_col == RED)
			return false;
		int count = 0;
		//以左子树上的黑色结点作为一个基准，如果一样就证明是，不一样就证明不是RBTree
		Node* cur = _root;
		while (cur != NULL)
		{
			if (cur->_col == BLACK)
				count++;
			cur = cur->_left;
		}
		//num用来标记每条路径上的黑色结点的个数
	   //count用来标记左子树上的黑色结点的个数
		int num = 0;
		return _Isbalance(_root, count, num);
	}
protected:
	bool _Isbalance(Node* root, int count, int num)
	{
		if (root == NULL)
			return true;
		//3.连续红结点不是RBTree,root结点一定有父结点
		if (root->_col == RED&&root->_parent->_col == RED)
		{
			cout << root->_key << " 有连续的红结点" << endl;
			return false;
		}
		if (root->_col == BLACK)
			num++;
		if (root->_left == NULL&&root->_right == NULL)
		{
			if (num != count)
			{
				cout << root->_key << " 黑色结点个数不一样" << endl;
				return false;
			}
		}
		return _Isbalance(root->_left, count, num) && _Isbalance(root->_right, count, num);
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	void _RotateR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
	    //链上SubLR
		parent->_left = SubLR;
		if (SubLR != NULL)
			SubLR->_parent = parent;
		Node* pparent = parent->_parent;
		//链上SubL
		SubL->_parent = pparent;
		if (pparent != NULL)
		{
			if (pparent->_left == parent)
				pparent->_left = SubL;
			else
				pparent->_right = SubL;
		}
		//链上parent
		parent->_parent = SubL;
		SubL->_right = parent;
	}
	void _RotateL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL= SubR->_left;
		//链上SubLR
		parent->_right= SubRL;
		if (SubRL != NULL)
			SubRL->_parent = parent;
		Node* pparent = parent->_parent;
		//链上SubL
		SubR->_parent = pparent;
		if (pparent != NULL)
		{
			if (pparent->_left == parent)
				pparent->_left = SubR;
			else
				pparent->_right = SubR;
		}
		//链上parent
		parent->_parent = SubR;
		SubR->_left = parent;
	}
	Node* _root;
};
void TestRBTree()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	RBTree<int, int> t;
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		t.Insert(a[i], i);
	}
	t.InOrder();
	cout << "Isbalance---->" << t.Isbalance()<< endl;
}
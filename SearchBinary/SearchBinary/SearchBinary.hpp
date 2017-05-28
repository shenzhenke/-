template <class K>
struct SearchBinaryTreeNode
{
	SearchBinaryTreeNode<K>* _lchild;
	SearchBinaryTreeNode<K>* _rchild;
	K _key;
	SearchBinaryTreeNode(const K& key)
		:_key(key)
		, _lchild(NULL)
		, _rchild(NULL)
	{}
};

template <typename K>
class SearchBinaryTree
{
	typedef SearchBinaryTreeNode<K> Node;
public:
	SearchBinaryTree()
		:_root(NULL)
	{}

	bool Insert(const K& key)
	{
		if (_root == NULL)
		{
			_root = new Node(key);
		}
		Node* parent = NULL;
		Node* cur = _root;
		while (cur != NULL)
		{
			//依据小值在左树,大值在右树这一特性
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_rchild;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_lchild;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key > key)
		{
			parent->_lchild = cur;
		}
		else
		{
			parent->_rchild = cur;
		}
		return true;
	}

	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
		return;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur != NULL)
		{
			if (cur->_key > key)
			{
				cur = cur->_lchild;
			}
			else if (cur->_key < key)
			{
				cur = cur->_rchild;
			}
			else
			{
				return cur;
			}
		}
		return NULL;
	}

	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}
	bool  Remove(const K& key)
	{
		Node* cur = _root;
		Node* parent = _root;
		//1.首先找数据
		while (cur != NULL)
		{
			//1.1去左子树找
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_lchild;
			}
			//1.2去右子树找
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_rchild;
			}
			//1.3找到数据
			else
			{
				//2.删除数据
				//2.1删除叶子节点的数据(有可能是最后一个节点)
				if (cur->_lchild == NULL&&cur->_rchild == NULL)
				{
					if (cur == _root)
					{
						_root = NULL;
					}
					//2.1非根节点需要看是父节点的左孩子还是右孩子
					else
					{
						if (parent->_lchild == cur)
						{
							parent->_lchild = NULL;
						}
						else
						{
							parent->_rchild = NULL;
						}
					}
					delete cur;
					cur = NULL;
				}
				//2.2删除左孩子为空,右孩子不为空的数据
				else if (cur->_lchild == NULL)
				{
					//是否是删除根上的数据
					if (cur == _root)
					{
						_root = cur->_rchild;
					}
					else
					{
						parent->_rchild = cur->_rchild;
					}
					delete cur;
					cur = NULL;
				}
				//2.3删除右孩子为空,左孩子不为空的数据
				else if (cur->_rchild == NULL)
				{
					//是否是删除根上的数据
					if (cur == _root)
					{
						_root = cur->_lchild;
					}
					else
					{
						parent->_lchild = cur->_lchild;
					}
					delete cur;
					cur = NULL;
				}
				//2.4删除左右孩子都不为空的数据--替换法
				//找左子树的最右节点或右子树的最左节点
				else
				{
					Node* del = cur;
					//找左子树的最右节点
					parent = cur;
					cur = cur->_lchild;
					while (cur->_rchild != NULL)
					{
						parent = cur;
						cur = cur->_rchild;
					}
					//最右节点为叶子节点,分为是不是左子树上唯一节点两种情况
					if (cur->_lchild == NULL&&cur->_rchild == NULL)
					{
						swap(cur->_key, del->_key);
						if (parent->_lchild == cur)
							parent->_lchild = NULL;
						else
							parent->_rchild = NULL;
						del = cur;
					}
					//最右节点不为叶子节点
					else
					{
						swap(cur->_key, del->_key);
						parent->_lchild = cur->_lchild;
						del = cur;
					}
					delete del;
					del = NULL;
				}
				return true;
			}
		}
		return false;
	}


	bool RemoveR(const K& key)
	{
		return _RemoveR(_root, key);
	}
protected:
	void _Inorder(Node* root)
	{
		if (root == NULL)
			return;
		_Inorder(root->_lchild);
		cout << root->_key << " ";
		_Inorder(root->_rchild);
	}

	//root有两层含义：1.上一个结点左孩子或右孩子的别名; 
	               //2.上一个结点左孩子或右孩子的值
	bool _InsertR(Node* &root, const K& key)
	{
		if (root == NULL)
		{
			root = new Node(key);
			return true;
		}
		if (root->_key < key)
		{
			return  _InsertR(root->_rchild, key);
		}
		else if (root->_key > key)
		{
			return _InsertR(root->_lchild, key);
		}
		else
		{
			return false;
		}
	}

	Node* _FindR(Node* &root, const K& key)
	{
		if (root == NULL)
		{
			return NULL;
		}
		if (root->_key > key)
		{
			return _FindR(root->_lchild, key);
		}
		else if (root->_key < key)
		{
			return  _FindR(root->_rchild, key);
		}
		else
		{
			return root;
		}
	}

	bool _RemoveR(Node* &root, const K& key)
	{
		if (root == NULL)
		{
			return false;
		}
		if (root->_key > key)
		{
			return _RemoveR(root->_lchild, key);
		}
		else if (root->_key < key)
		{
			return _RemoveR(root->_rchild, key);
		}
		else
		{
			if (root->_lchild == NULL)
			{
				Node* del = root;
				if (_root == root)
					_root = root->_rchild;
				else
					root = root->_rchild;
				delete del;
			}
			else if (root->_rchild == NULL)
			{
				Node* del = root;
				if (_root == root)
					_root = root->_lchild;
				else
					root = root->_lchild;
				delete del;
			}
			else
			{
				Node* cur = root;
				cur = cur->_lchild;
				while (cur->_rchild != NULL)
				{
					cur = cur->_rchild;
				}
				swap(root->_key, cur->_key);
				_RemoveR(root->_lchild, key);
			}
			return true;
		}
	}

protected:
	Node* _root;
};



void TestSearchBinaryTree()
{
	SearchBinaryTree<int> t;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		t.InsertR(a[i]);
	}
	t.FindR(0);
	t.Inorder();
	t.RemoveR(5);
	t.Inorder();
	t.RemoveR(7);
	t.RemoveR(7);
	t.Inorder();
	t.RemoveR(6);
	t.Inorder();
	t.RemoveR(5);
	t.RemoveR(4);
	t.Inorder();
	t.RemoveR(3);
	t.Inorder();
	t.RemoveR(2);
	t.Inorder();
	t.RemoveR(1);
	t.Inorder();
	t.RemoveR(0);
	t.Inorder();
	t.RemoveR(8);
	t.Inorder();
	t.RemoveR(9);
	t.Inorder();
}


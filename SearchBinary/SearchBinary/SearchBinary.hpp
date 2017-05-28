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
			//����Сֵ������,��ֵ��������һ����
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
		//1.����������
		while (cur != NULL)
		{
			//1.1ȥ��������
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_lchild;
			}
			//1.2ȥ��������
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_rchild;
			}
			//1.3�ҵ�����
			else
			{
				//2.ɾ������
				//2.1ɾ��Ҷ�ӽڵ������(�п��������һ���ڵ�)
				if (cur->_lchild == NULL&&cur->_rchild == NULL)
				{
					if (cur == _root)
					{
						_root = NULL;
					}
					//2.1�Ǹ��ڵ���Ҫ���Ǹ��ڵ�����ӻ����Һ���
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
				//2.2ɾ������Ϊ��,�Һ��Ӳ�Ϊ�յ�����
				else if (cur->_lchild == NULL)
				{
					//�Ƿ���ɾ�����ϵ�����
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
				//2.3ɾ���Һ���Ϊ��,���Ӳ�Ϊ�յ�����
				else if (cur->_rchild == NULL)
				{
					//�Ƿ���ɾ�����ϵ�����
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
				//2.4ɾ�����Һ��Ӷ���Ϊ�յ�����--�滻��
				//�������������ҽڵ��������������ڵ�
				else
				{
					Node* del = cur;
					//�������������ҽڵ�
					parent = cur;
					cur = cur->_lchild;
					while (cur->_rchild != NULL)
					{
						parent = cur;
						cur = cur->_rchild;
					}
					//���ҽڵ�ΪҶ�ӽڵ�,��Ϊ�ǲ�����������Ψһ�ڵ��������
					if (cur->_lchild == NULL&&cur->_rchild == NULL)
					{
						swap(cur->_key, del->_key);
						if (parent->_lchild == cur)
							parent->_lchild = NULL;
						else
							parent->_rchild = NULL;
						del = cur;
					}
					//���ҽڵ㲻ΪҶ�ӽڵ�
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

	//root�����㺬�壺1.��һ��������ӻ��Һ��ӵı���; 
	               //2.��һ��������ӻ��Һ��ӵ�ֵ
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


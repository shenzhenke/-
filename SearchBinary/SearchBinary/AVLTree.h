template <typename K,typename V>
struct AVLTreeNode
{
	K _key;
	V _value;
	int _bf; //ƽ������,ֻ��ȡֵΪ-1,1,0
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	AVLTreeNode(const K& key, const V& value)
		:_key(key)
		, _value(value)
		, _bf(0)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
	{}
};

template <typename K, typename V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(NULL)
	{}
	bool Insert(const K& key, const V& value)
	{

		//1.����
		if (_root == NULL)
		{
			_root = new Node(key, value);
			return true;
		}
		//2.���Ҳ���λ��
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
		//3.������
		cur = new Node(key, value);
		if (key > parent->_key)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		//4.����ƽ������
		while (parent != NULL)
		{
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;
			//��Ϊƽ������Ϊ-1,���������������ĸ߶�Ҫ��1;
			//    ƽ������Ϊ 1,���������������ĸ߶�Ҫ��1��
			//4.1����ĳ�����Ƚ���ƽ��������Ϊ����ĳ������Ϊ0ʱ��
			//֤��������ĸ߶Ȳ�û�з����仯,����ֹͣ����ƽ������
			if (parent->_bf == 0)
			{
				break;
			}
			//4.2��Ϊ�ҵ���������˫��
			else if (parent->_bf == -2)
			{
				if (cur->_bf == -1)
					_RotateR(parent);
				else
					_RotateLR(parent);
				break;
			}
			//4.3��Ϊ����������˫��
			else if (parent->_bf == 2)
			{
				if (cur->_bf == 1)
					_RotateL(parent);
				else
					_RotateRL(parent);
				break;
			}
			//4.4���Ƚ��ƽ������Ϊ-1����1��Ҫ�������ϵ���
			//   ֱ�����ڵ����
			else
			{
				cur = parent;
				parent = parent->_parent;
			}
		}
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	int Depth()
	{
		int depth = 0;
		return _Depth(_root,depth);
	}

	//int Depth()
	//{
	//	return _Depth(_root);
	//}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
protected:

	bool _IsBalance(Node* root)
	{
		if (root == NULL)
			return true;
	/*	int rightDepth =_Depth (root->_right);
		int leftDepth = _Depth(root->_left);
		if (root->_bf != _Depth(root->_right) - _Depth(root->_left))
		{
			cout << root->_key << " bf is error" << endl;
		}
		return abs(rightDepth - leftDepth) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);*/
		int rightDepth = _Depth(root->_right)
	}

	//������������ĸ߶�ʱ�临�Ӷ�ԼΪO(N^2)
	//�������ĸ߶�ʱ�临�Ӷ�ԼΪO(N)
	//int _Depth(Node* root)
	//{
	//	if (root == NULL)
	//		return 0;
	//	return _Depth(root->_right) > _Depth(root->_left) ? _Depth(root->_right) + 1 : _Depth(root->_left) + 1;
	//}
	int _Depth(Node* root, int& depth)
	{
		if (root == NULL)
			return 0;
		int rightDepth = _Depth(root->_right, depth) + 1;
		int leftDepth = _Depth(root->_left, depth) + 1;
		depth = rightDepth > leftDepth ? leftDepth : rightDepth;
		return depth;
	}
	void _InOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	void _RotateL(Node* &parent)
	{
		//1.��Ҫ�޸ĵĽ��������
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		Node* pparent = parent->_parent;
		//2.��������SubR���
		SubR->_left = parent;
		SubR->_parent = pparent;
		SubR->_bf = 0;
		//4.��������parent���
		//��һ�������ڸı�pparentָ��֮ǰ,��ΪparentΪpparent->left������
		//���ں���ᵼ������parent������ʵ����������SubR
		parent->_right = SubRL;
		parent->_parent = SubR;
		parent->_bf = 0;
		//5.�ı�pparent��ָ����
		if (pparent == NULL)
			_root = SubR;
		else if (pparent->_left == parent)
			pparent->_left = SubR;
		else
			pparent->_right = SubR;
		//4.��������SubRL���
		if (SubRL != NULL)
			SubRL->_parent = parent;
		
	}

	void _RotateR(Node* &parent)
	{
		//1.��Ҫ�޸ĵĽ��������
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		Node* pparent = parent->_parent;
		//2.��������SubL���
		SubL->_right = parent;
		SubL->_parent = parent->_parent;
		SubL->_bf = 0;
		//3.��������parent���
		parent->_left = SubLR;
		parent->_parent = SubL;
		parent->_bf = 0;
		//4.�ı�pparent��ָ����
		if (pparent == NULL)
			_root = SubL;
		else if (pparent->_left == parent)
			pparent->_left = SubL;
		else
			pparent->_right = SubL;
		//5.��������SubRL���
		if (SubLR != NULL)
			SubLR->_parent = parent;
	}
	void _RotateLR(Node* &parent)
	{
		//˫����ʱ����ĳЩ����»ᵼ��bf�����쳣
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		int bf = SubLR->_bf;
		_RotateL(parent->_left);
		_RotateR(parent);
		if (bf == -1)
		{
			parent->_bf = 1;
			SubL->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			SubL->_bf = -1;
		}
		else
		{
			SubL->_bf = parent->_bf = 0;
		}
		SubLR->_bf = 0;
	}
	void _RotateRL(Node* &parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		int bf = SubRL->_bf;
		_RotateR(parent->_right);
		_RotateL(parent);
		if (bf == 1)
		{
			parent->_bf = -1;
			SubR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			SubR->_bf = 1;
		}
		else
		{
			SubR->_bf = parent->_bf = 0;
		}
		SubRL->_bf = 0;
	}

	Node* _root;
};

void TestAVLTree()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		t.Insert(a[i], i);
	}
	t.InOrder();
	cout << t.Depth() << endl;
	//cout << "IsBalance:" << t.IsBalance() << endl;
}
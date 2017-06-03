#pragma once

enum Colour
{
	RED,
	BLACK
};

template<typename K,typename V>
struct RBTreeNode
{
	//���
	RBTreeNode* _left;
	RBTreeNode* _right;
	RBTreeNode* _parent;
	//��ɫ
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
		, _col(RED)  //����������óɺ�ɫΪ�˱���ÿ��·���ĺ�ɫ����������
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
		//1.������Ϊ���ڵ㣬����Ϊ��ɫ
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
			//2.�������ڵ���ߵ������ĸ����Ϊ��ɫ���,����һ����ɫ��㣬��ÿ��·���ĺ�ɫ������ûӰ��
			if (parent->_col == BLACK)
			{
				break;
			}

			//�ж��������Ƿ����,�������������ң�
			if (pparent != NULL)
			{
				if (pparent->_right == parent)
					uncle = pparent->_left;
				else
					uncle = pparent->_right;
			}

			//3.������������㸸���Ϊ��ɫ��������Ϊ��ɫ
			if (uncle != NULL&&uncle->_col == RED)
			{
				parent->_col = BLACK;
				uncle->_col = BLACK;
				if (pparent == _root)
					return true;
				pparent->_col = RED;
				//�������ϵ���
				//�������������㣬ֻ�轫��������ɫ��Ϊ��ɫ����
				if (parent == _root)
				{
					parent->_col = BLACK;
					return true;
				}
				cur = parent->_parent;
				parent = cur->_parent;
			}
			//4.������������㸸���Ϊ��ɫ�������㲻���ڻ�
			//  ������������㸸���Ϊ��ɫ�����������Ϊ��ɫ�����߼�һ����
			else
			//ʣ�µ���� (uncle == NULL || uncle->_col == BLACK)
			{
				//�жϸ��������������
				if (pparent->_left == parent)
				{
					//��--��
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
					//��--��
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
				//���������
				else
				{
					//��--��
					if (parent->_right == cur)
					{
						_RotateL(pparent);
						pparent->_col = RED;
						parent->_col = BLACK;
						if (pparent == _root)
							_root = parent;
					}
					//��--��
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
		//1.������Ϊ��RBTree
		if (_root == NULL)
			return true;
		//2.�����Ǻڲ���RBTree
		if (_root->_col == RED)
			return false;
		int count = 0;
		//���������ϵĺ�ɫ�����Ϊһ����׼�����һ����֤���ǣ���һ����֤������RBTree
		Node* cur = _root;
		while (cur != NULL)
		{
			if (cur->_col == BLACK)
				count++;
			cur = cur->_left;
		}
		//num�������ÿ��·���ϵĺ�ɫ���ĸ���
	   //count��������������ϵĺ�ɫ���ĸ���
		int num = 0;
		return _Isbalance(_root, count, num);
	}
protected:
	bool _Isbalance(Node* root, int count, int num)
	{
		if (root == NULL)
			return true;
		//3.�������㲻��RBTree,root���һ���и����
		if (root->_col == RED&&root->_parent->_col == RED)
		{
			cout << root->_key << " �������ĺ���" << endl;
			return false;
		}
		if (root->_col == BLACK)
			num++;
		if (root->_left == NULL&&root->_right == NULL)
		{
			if (num != count)
			{
				cout << root->_key << " ��ɫ��������һ��" << endl;
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
	    //����SubLR
		parent->_left = SubLR;
		if (SubLR != NULL)
			SubLR->_parent = parent;
		Node* pparent = parent->_parent;
		//����SubL
		SubL->_parent = pparent;
		if (pparent != NULL)
		{
			if (pparent->_left == parent)
				pparent->_left = SubL;
			else
				pparent->_right = SubL;
		}
		//����parent
		parent->_parent = SubL;
		SubL->_right = parent;
	}
	void _RotateL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL= SubR->_left;
		//����SubLR
		parent->_right= SubRL;
		if (SubRL != NULL)
			SubRL->_parent = parent;
		Node* pparent = parent->_parent;
		//����SubL
		SubR->_parent = pparent;
		if (pparent != NULL)
		{
			if (pparent->_left == parent)
				pparent->_left = SubR;
			else
				pparent->_right = SubR;
		}
		//����parent
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
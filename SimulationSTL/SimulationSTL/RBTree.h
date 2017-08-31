
enum Color
{
	RED,
	BLACK
};

template<typename K,template V>
struct RBTreeNode
{
	RBTreeNode* _left;
	RBTreeNode* _right;
	RBTreeNode* _parent;
	Color _col;
	K _key;
	V _value;

	RBTreeNode(const K& key,const V& value)
		:_key(key)
		,_value(value)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _col(RED)
	{}
};

template <typename K,typename V>
class RBTree
{
	typedef RBTreeNode Node;
public:
	RBTree()
		:_root(NULL)
	{}
	bool insert(const K& key, const V& value)
	{
		//(1)�����жϲ�����ʱ������Ƿ�Ϊ��
		if (_root == NULL)
		{
			_root = new Node(key, value);
			_root->_col = BLACK;
			return true;
		}

		//ȥѰ��keyֵ�ò���ĵط�
		Node* cur = _root;
		Node* parent = NULL;
		while (cur != NULL)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else  if (cur->_key < key)
			{
				parent = NULL;
				cur = cur->_right;
			}
			else
			{
				return  false;
			}
		}
		cur = new Node(key, value);
		
		if (key > parent->_key)
			parent->_right = cur;
		else
			parent->_left = cur;


		//(2)���������Ϊ�ĸ����Ϊ��ɫʱ
		if (parent->_col == BLACK)
		{
			break;
		}


		//�ж��������Ƿ���ڣ����������ӻ����Һ���
		Node* pparent = parent->_parent;
		Node* uncle = NULL;
		if (pparent != NULL)
		{
			if (pparent->_left == parent)
				uncle = pparent->_right;
			else
				uncle = pparent->_left;
		}

		//(3)��������㸸���Ϊ��ɫ,�������������Ϊ��ɫʱ

		if (uncle != NULL&&uncle->_col == RED)
		{
			pparent->_col = RED;
			parent->_col = BLACK;
			uncle->_col = BLACK;
		}

		//uncle ==NULL ���� uncle��������Ϊ��ɫ 
		else
		{
			if (pparent->_left == parent)  //��
			{
				if (parent->_right == cur)  //����
				{
					_RotateL(parent);
					_RotateR(pparent);
					if (pparent == _root)
						_root = cur;
					cur->_col = BLACK;
					parent->_col = RED;
					pparent->_col = RED;

				}
				else   //����   ��parentΪ�����ҵ���
				{
					_RotateR(pparent);
					if (pparent == _root)
						_root = parent;
					parent->_col = BLACK;
					pparent->_col = RED;
				}
			}
			else
			{
				if (parent->_left == cur)  //����
				{
					_RotateR(parent);
					_RotateL(pparent);
					if (pparent == _root)
						_root = cur;
					cur->_col = BLACK;
					parent->_col = RED;
					pparent->_col = RED;
				}
				else  //����
				{
					_RotateL(pparent);
					if (pparent == _root)
						_root = parent;
					parent->_col = BLACK;
					pparent->_col = RED;
				}
			}
		}

	}
private:
	void _RotateR(Node* parent)
	{
		//�Ľ��ָ��
		Node* subL = parent->_left;
		Node*  subLR = subL->_right;

		//����subLR
		if (subLR != NULL)
			subLR->_parent = parent;

		//����subL
		Node* pparent= parent->_parent;
		if (pparent != NULL)
		{
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
		}
		subL->_right = parent;
		//����parent
		parent->_parent = subL;
		parent->_left = subLR;
	}

	void  _RotateL(Node *parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		//����subRL
		if (subRL != NULL)
			subRL->_parent = parent;

		//����subR
		Node* pparent = parent->_parent;
		if (pparent != NULL)
		{
			if (pparent->_right == parent)
				pparent->_right = subR;
			else
				pparent->_left = subR;
		}
		subR->_left = parent;

		//����parent

		parent->_right = subRL;
		parent->_parent = subR;
	}

	Node *_root;
};

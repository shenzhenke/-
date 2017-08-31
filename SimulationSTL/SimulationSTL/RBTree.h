
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
		//(1)首先判断插入结点时这棵树是否为空
		if (_root == NULL)
		{
			_root = new Node(key, value);
			_root->_col = BLACK;
			return true;
		}

		//去寻找key值该插入的地方
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


		//(2)当调整结点为的父结点为黑色时
		if (parent->_col == BLACK)
		{
			break;
		}


		//判断叔叔结点是否存在？存在是左孩子还是右孩子
		Node* pparent = parent->_parent;
		Node* uncle = NULL;
		if (pparent != NULL)
		{
			if (pparent->_left == parent)
				uncle = pparent->_right;
			else
				uncle = pparent->_left;
		}

		//(3)当调整结点父结点为红色,且叔叔结点存在且为红色时

		if (uncle != NULL&&uncle->_col == RED)
		{
			pparent->_col = RED;
			parent->_col = BLACK;
			uncle->_col = BLACK;
		}

		//uncle ==NULL 或者 uncle结点存在且为黑色 
		else
		{
			if (pparent->_left == parent)  //左
			{
				if (parent->_right == cur)  //左右
				{
					_RotateL(parent);
					_RotateR(pparent);
					if (pparent == _root)
						_root = cur;
					cur->_col = BLACK;
					parent->_col = RED;
					pparent->_col = RED;

				}
				else   //左左   以parent为中心右单旋
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
				if (parent->_left == cur)  //右左
				{
					_RotateR(parent);
					_RotateL(pparent);
					if (pparent == _root)
						_root = cur;
					cur->_col = BLACK;
					parent->_col = RED;
					pparent->_col = RED;
				}
				else  //右右
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
		//改结点指向
		Node* subL = parent->_left;
		Node*  subLR = subL->_right;

		//链上subLR
		if (subLR != NULL)
			subLR->_parent = parent;

		//链上subL
		Node* pparent= parent->_parent;
		if (pparent != NULL)
		{
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
		}
		subL->_right = parent;
		//链上parent
		parent->_parent = subL;
		parent->_left = subLR;
	}

	void  _RotateL(Node *parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		//链上subRL
		if (subRL != NULL)
			subRL->_parent = parent;

		//链上subR
		Node* pparent = parent->_parent;
		if (pparent != NULL)
		{
			if (pparent->_right == parent)
				pparent->_right = subR;
			else
				pparent->_left = subR;
		}
		subR->_left = parent;

		//链上parent

		parent->_right = subRL;
		parent->_parent = subR;
	}

	Node *_root;
};

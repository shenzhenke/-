#define _CRT_SECURE_NO_WARNINGS
#pragma once

//结点类型
enum PointerType  
{
	LINK,
	THREAD,
};

template<class T>
struct BinaryTreeThNode
{
	T _data;
	BinaryTreeThNode* _lchild;
	BinaryTreeThNode* _rchild;
	//用来标记左右节点是否被线索化
	PointerType _leftType;
	PointerType _rightType;
	BinaryTreeThNode(const T& data)
		:_data(data)
		, _lchild(NULL)
		, _rchild(NULL)
		, _leftType(LINK)
		, _rightType(LINK)
	{}
};

template <typename T,typename Ref,typename Ptr>
class Iterator
{

public:
	typedef BinaryTreeThNode<T> Node;
	typedef Iterator<T, Ref, Ptr> Self;

	Iterator(Node* node)
		:_node(node)
	{}
	Ref operator*() const
	{
		return _node->_data;
	}

	Ref operator*() 
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return this->_node;
	}

	Ptr operator->() const
	{
		return this->_node;
	}

	//中序
	Self& operator++()
	{
		if (_node->_rightType == THREAD)
			_node = _node->_rchild;
		else
		{
			//找最左结点
			Node* cur = _node->_rchild;
			while (cur->_leftType == LINK)
			{
				cur = cur->_lchild;
			}
			_node = cur;
		}
			return *this;
	}

	Self& operator--()
	{
		if (_node->_leftType == THREAD)
			_node = _node->_lchild;
		else
		{
			Node* cur = _node->_lchild;
			//找最右结点
			while (cur->_rightType == LINK)
			{
				cur = cur->_rchild;
			}
			_node = cur;
		}
		return *this;
	}

	bool operator!=(const Iterator& t)
	{
		return this->_node != t._node;
	}
protected:
	Node* _node;
};

template <typename T>
class BinaryTreeTh
{
public:
	typedef BinaryTreeThNode<T> Node;
	typedef Iterator<T, const T&, const T*>  ConstIterator;
	typedef Iterator <T, T&, T*> Iterator;
//	typedef Iterator<T,const T &,const T*>  ConstIterator;
	BinaryTreeTh(T* a, size_t n,const T& invalid)	
	{
		if (a != NULL)
		{
			size_t index = 0;
			_root = CreatBinaryTreeTh(a, n, invalid, index);
		}
	}

	Iterator Begin()
	{
		Node* cur = _root;
		while (cur->_leftType == LINK)
		{
			cur = cur->_lchild;
		}
		return Iterator(cur);
	}

	ConstIterator Begin() const 
	{
		Node* cur = _root;
		while (cur->_leftType == LINK)
		{
			cur = cur->_lchild;
		}
		return ConstIterator(cur);
	}

	Iterator End()
	{
		return Iterator(NULL);
	}

	ConstIterator End() const
	{
		return ConstIterator(NULL);
	}
	void InOrder()
	{
		if (_root != NULL)
		{
			_InOrder(_root);
			cout << endl;
		}
		return;
	}

	//前序线索化
	void PrevOrderThreading()
	{
		//DLR,第一个被线索化的一定是最后的子树的左结点
		Node* prev = NULL;
		_PrevOrderThreading(_root,prev);
	}

	//中序线索化
	void InOrderThreading()
	{
		Node* prev = NULL;
		_InOrderThreading(_root, prev);
		if (prev != NULL)
			prev->_rightType = THREAD;
	}

	//后序线索化
	void  PostOrderThreading()
	{
		Node* prev = NULL;
		_PostOrderThreading(_root, prev);
	}


	//DLR
	void PrevOrderTh()
	{
		Node* cur = _root;

		while (cur != NULL)
		{
			//能够继续往左子树遍历的前提是该左子树未被线索化
			while (cur->_leftType == LINK)
			{
				//左子树的根结点遍历完
				cout << cur->_data << " ";
				cur = cur->_lchild;
			}
			if (cur->_rightType == LINK)
			{
				cout << cur->_data << " ";
				cur = cur->_rchild;
			}
			else
			{
				//&&后面的条件需考虑
				while (cur->_rightType == THREAD&&cur->_leftType == THREAD)
				{
					cout << cur->_data << " ";
					cur = cur->_rchild;
				}
			}
		}
	
	}


	//LDR
	void InOrderTh()
	{
		Node* cur = _root;
		while (cur != NULL)
		{
			while (cur->_leftType == LINK)
			{
				cur = cur->_lchild;
			}
			cout << cur->_data << " ";
			if (cur->_rightType == LINK)
			{
				cur = cur->_rchild;
			}
			else
			{
				
				while (cur->_rightType == THREAD)  //考虑连续的THREAD
				{
					cur = cur->_rchild;
					if (cur == NULL)
					{
						cout << endl;
						return;
					}
					cout << cur->_data << " ";
				}
				cur = cur->_rchild;
			}
		}
		cout << endl;
	}

	//LRD
	/*void PostOrderTh()
	{
		Node* cur = _root;
		Node* prev = NULL;
		while (cur != NULL)
		{
			prev = cur;
			while (cur->_leftType == LINK)
			{
				cur = cur->_lchild;
			}
			if (cur->_rightType == LINK)
			{
				cur = cur->_rchild;
			}
			else
			{
				while (cur->_rightType == THREAD)
				{
					cout << cur->_data << " ";
					cur = cur->_rchild;
				}
				while (prev != NULL&&prev->_lchild != cur)
				{
					prev = prev->_lchild;
				}
				if (prev != NULL)
					cur = prev;
			}
		}
	}*/

protected:
	Node* CreatBinaryTreeTh(T* a, size_t n,const T& invalid, size_t& index)
	{
		Node* root = NULL;
		if (a[index] != invalid&&index < n)
		{
			root = new Node(a[index]);
			root->_lchild = CreatBinaryTreeTh(a, n, invalid, ++index);
			root->_rchild = CreatBinaryTreeTh(a, n, invalid, ++index);
		}
		return root;
	}
	void _InOrder(Node* root)
	{
		if (root != NULL)
		{
			_InOrder(root->_lchild);
			cout << root->_data << " ";
			_InOrder(root->_rchild);
		}
	}



	//前序  DLR
	void _PrevOrderThreading(Node* cur,Node* & prev)
	{
//		static Node* prev = NULL;  //引发线程安全问题
		if (cur == NULL)
			return;
		//左边指向前驱,右边指向后继
		if (cur->_lchild == NULL)
		{
			cur->_lchild = prev;
			cur->_leftType = THREAD;
		}
		if (prev != NULL&&prev->_rchild == NULL)
		{
			prev->_rchild = cur;
			prev->_rightType = THREAD;
		}
		if (cur != NULL)
		{
			prev = cur;
			if (cur->_leftType == LINK)
				_PrevOrderThreading(cur->_lchild, prev);
			if (cur->_rightType == LINK)
				_PrevOrderThreading(cur->_rchild, prev);
		}
	}


     //中序	LDR  会导致最后一个结点并没有线索化
	void _InOrderThreading(Node* cur, Node* &prev)
	{
		if (cur != NULL&&cur->_lchild == NULL)
		{
			cur->_lchild = prev;
			cur->_leftType = THREAD;
		}
		if (cur != NULL)
		{
			if (cur->_leftType != THREAD)
				_InOrderThreading(cur->_lchild, prev);
			if (prev != NULL&&prev->_rchild == NULL)
			{
				prev->_rchild = cur;
				prev->_rightType = THREAD;
			}
			prev = cur;
			if (cur->_rightType != THREAD)
				_InOrderThreading(cur->_rchild, prev);
		}
	}


	void _PostOrderThreading(Node* cur, Node* &prev)
	{
		if (cur != NULL&&cur->_lchild == NULL)
		{
			cur->_lchild = prev;
			cur->_leftType = THREAD;
		}
		if (cur != NULL)
		{
			if (cur->_leftType == LINK)
				_PostOrderThreading(cur->_lchild, prev);
			if (cur->_rightType == LINK)
				_PostOrderThreading(cur->_rchild, prev);
			if (prev != NULL&&prev->_rchild == NULL)
			{
				prev->_rchild = cur;
				prev->_rightType = THREAD;
			}
			prev = cur;
		}
	}

protected:
	Node* _root;
};

	void TestBinaryTreeTh()
	{
		int array[] = { 1, 2, 3, '*', '*', 4, '*', '*', 5, 6, '*', '*', 7 };
		//int array[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
		BinaryTreeTh<int> t(array, sizeof(array) / sizeof(array[0]), '*');

		t.InOrder();
//		t.PrevOrderThreading();
//		t.PrevOrderTh();
		t.InOrderThreading();
		t.InOrderTh();
		//BinaryTreeTh<int>::Iterator it = t.Begin();

		//while (it != t.End())
		//{
		//	//*it = 5;
		//	cout << *it << " ";
		//	++it;
		//}
	//	t.PostOrderThreading();
		//t.PostOrderTh();

	}
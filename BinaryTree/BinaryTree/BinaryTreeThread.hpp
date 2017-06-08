#define _CRT_SECURE_NO_WARNINGS
#pragma once

//�������
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
	//����������ҽڵ��Ƿ�������
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

	//����
	Self& operator++()
	{
		if (_node->_rightType == THREAD)
			_node = _node->_rchild;
		else
		{
			//��������
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
			//�����ҽ��
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

	//ǰ��������
	void PrevOrderThreading()
	{
		//DLR,��һ������������һ������������������
		Node* prev = NULL;
		_PrevOrderThreading(_root,prev);
	}

	//����������
	void InOrderThreading()
	{
		Node* prev = NULL;
		_InOrderThreading(_root, prev);
		if (prev != NULL)
			prev->_rightType = THREAD;
	}

	//����������
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
			//�ܹ�������������������ǰ���Ǹ�������δ��������
			while (cur->_leftType == LINK)
			{
				//�������ĸ���������
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
				//&&����������迼��
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
				
				while (cur->_rightType == THREAD)  //����������THREAD
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



	//ǰ��  DLR
	void _PrevOrderThreading(Node* cur,Node* & prev)
	{
//		static Node* prev = NULL;  //�����̰߳�ȫ����
		if (cur == NULL)
			return;
		//���ָ��ǰ��,�ұ�ָ����
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


     //����	LDR  �ᵼ�����һ����㲢û��������
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
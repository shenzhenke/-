#define _CRT_SECURE_NO_WARNINGS 
#pragma once
template <class T>
//��������һ��������������: ������  ������ �Һ�����
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode* _lchild;
	BinaryTreeNode* _rchild;
	BinaryTreeNode(const T& data)
		:_data(data)
		, _lchild(NULL)
		, _rchild(NULL)
	{}
};
 

//�����鹹��������,���õ�������ʽ
template<class T>
class BinaryTree
{
public:
	typedef BinaryTreeNode<T> Node;
	//����
	BinaryTree()
		:_root(NULL)
	{}

	BinaryTree(T* a, const T& invalid, size_t n)
	{
		size_t index = 0;
		if (a != NULL)
		{
			_root = CreatBinaryTree(a, invalid, n, index);
		}
	}

	Node* CreatBinaryTree(T* a, const T& invalid, size_t n, size_t& index)
	{
		Node* _root = NULL;
		if (a[index] != invalid && index < n)
		{
			_root = new Node(a[index]);
			_root->_lchild = CreatBinaryTree(a, invalid, n, ++index);
			_root->_rchild = CreatBinaryTree(a, invalid, n, ++index);
		}
		return _root;
	}
	//���������operator=ֻ����ĳ�ֱ�����ʽȡ������,������һ����������Ӽ���
	//��������
	BinaryTree(const BinaryTree<T> & tree)
	{
		_root = CreatBinaryTree(tree._root);
	}
	//����operator=
	Node* CreatBinaryTree(Node* root)
	{
		Node* _root = NULL;
		if (root != NULL)
		{
			_root = new Node(root->_data);
			_root->_lchild = CreatBinaryTree(root->_lchild);
			_root->_rchild = CreatBinaryTree(root->_rchild);
		}
		return _root;
	}

	BinaryTree<T> operator=(const BinaryTree<T> & tree)
	{
		if (tree->_root != this->_root)
		{
			this->~BinaryTree();
			_root = CreatBinaryTree(tree._root);
		}
		return *this;
	}

	//��������ǵݹ�,����Ҫ��������������  DLR
	//����ջ���Ƚ����˼�뱣������
	void PrevOrder()
	{
		cout <<"   PrevOrder:" << "  ";
		stack<Node*> s;
		Node* cur = _root;
		while (cur != NULL || !s.empty())
		{
			while (cur)
			{
				cout << cur->_data << " ";
				s.push(cur);
				cur = cur->_lchild;
			}

			//����������,����������������
			cur = s.top();
			cur = cur->_rchild;
			s.pop();
		}
		cout << endl;
		stack<Node*> s1;
		Node* cur1 = _root;
		if (_root == NULL)
			return;
		s.push(cur1);
		while (!s.empty())
		{
			cur1 = s.top();
			s.pop();
			cout << cur1->_data << " ";
			if (cur1->_rchild != NULL)
				s.push(cur1->_rchild);
			if (cur1->_lchild != NULL)
				s.push(cur1->_lchild);
		}
		cout << endl;


	}

	//������� LDR
	void InOrder()
	{
		cout << "   InOrder:" << "    ";
		stack<Node*> s;
		Node* cur = _root;
		while (cur != NULL || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_lchild;
			}
			cur = s.top();
			cout << cur->_data << " ";
			s.pop();
			cur = cur->_rchild;
		}
		cout << endl;
	}

	//������� LRD
	//void PostOrder()
	//{
	//	cout << "  PostOrder:   ";
	//	stack<Node*> s;
	//	Node* cur = _root;
	//	while (cur != NULL || !s.empty())
	//	{
	//		while (cur)
	//		{
	//			s.push(cur);
	//			cur = cur->_lchild;
	//		}
	//		cur = s.top();
	//		if (cur == NULL)
	//		{
	//			s.pop();
	//			cur = s.top();
	//			cout << cur->_data << " ";
	//			s.pop();
	//			if (s.top())
	//			{
	//				cur = s.top();
	//			}
	//			else
	//			{
	//				while (!s.top())
	//				{
	//					s.pop();
	//					cur = s.top();
	//					cout << cur->_data << " ";
	//					s.pop();
	//					if (s.empty())
	//						return;
	//					cur = s.top();
	//				}
	//			}
	//		}
	//		s.push(NULL);
	//		cur = cur->_rchild;
	//	}

	//}

	void PostOrder()
	{
		stack<Node*> s;
		Node* cur = _root;
		Node* prev = NULL;
		while (cur != NULL || !s.empty())
		{
			while (cur != NULL)
			{
				s.push(cur);
				cur = cur->_lchild;
			}
			Node* front = s.top();
			if ((front->_rchild == NULL) || (front->_rchild == prev))
			{
				cout << front->_data << " ";
				prev = front;
				s.pop();
			}
			else
			{
				cur = front->_rchild;
			}
		}
	}

	//�������   ���ö��е�˼��,�Ƚ��ȳ�
	void LevelOrder()
	{
		cout << "   LevelOrder: ";
		Node*  cur = _root;
		queue<Node*> q;
		if (cur)
			q.push(cur);
		while (!q.empty())
		{
			cur = q.front();
			if (cur->_lchild != NULL)
			{
				q.push(cur->_lchild);
			}
			if (cur->_rchild != NULL)
			{
				q.push(cur->_rchild);
			}
			cout << cur->_data << " ";
			q.pop();
		}
	}

	//��Ҷ�ӽڵ�(û������,û���Һ��ӵĽڵ�)����
	size_t LeafSize()
	{
		int count = 0;
		queue<Node*> q;
		if (_root)
		{
			q.push(_root);
		}
		while (q.size())
		{
			Node* cur = q.front();
			if (cur->_lchild != NULL)
				q.push(cur->_lchild);
			if (cur->_rchild != NULL)
				q.push(cur->_rchild);
			if ((cur->_rchild == NULL) && (cur->_lchild == NULL))
				count++;
			q.pop();
		}
		return count;
	}


	//������
	Node* Find(const T& x)
	{
		queue<Node*> q;
		if (_root)
		{
			q.push(_root);
		}
		while (q.size())
		{
			Node* cur = q.front();
			if (cur->_lchild != NULL)
				q.push(cur->_lchild);
			if (cur->_rchild != NULL)
				q.push(cur->_rchild);
			if (cur->_data == x)
				return cur;
			q.pop();
		}
		return NULL;
	}

	//��ڵ����
	size_t Size()
	{
		int count = 0;
		queue<Node*> q;
		if (_root)
		{
			q.push(_root);
		}
		while (!q.empty())
		{
			Node* cur = q.front();
			if (cur->_lchild != NULL)
				q.push(cur->_lchild);
			if (cur->_rchild != NULL)
				q.push(cur->_rchild);
			q.pop();
			count++;
		}
		return count;
	}

	//������������
	size_t Depth()
	{
		int count = 0;
		stack<Node*> s;
		stack<int> s1;
		Node* cur = _root;
		while (cur != NULL || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_lchild;
			}
			cur = s.top();
			while (cur == NULL)
			{
				s.pop();
				cur = s.top();
			}
			s1.push(s.size());
			cur = cur->_rchild;
			//��ÿ���ҽڵ�����ջ�е�ָ���ÿ�ָ�����
			if (cur == NULL)
			{
				while (cur == NULL)
				{
					s.pop();
					if (s.empty())
						break;
					cur = s.top();
					if (cur != NULL)
					{
						cur = cur->_rchild;
						s.pop();
						s.push(NULL);
					}
				}
			}
			else
			{
				s.pop();
				s.push(NULL);
			}
		}
		while (!s1.empty())
		{
			if (s1.top() > count)
			{
				count = s1.top();
			}
			s1.pop();
		}
		return count;
	}


	//��������
	~BinaryTree()
	{
		if (_root)
		{
			Destroy(_root);
		}
	}

protected:
	void Destroy(Node* root)
	{
		if (root)
		{
			Destroy(root->_lchild);
			Destroy(root->_rchild);
		}
		delete root;
		root = NULL;
		return;
	}
	Node* _root;
};


void TestBinaryTreeNR()
{
	int array[] = { 1, 2, 3, '*', '*', 4, 8, '*', '*', 9, '*', 10,'*','*',  5, 6, '*', '*', 7 };
	BinaryTree<int> t(array, '*', sizeof(array) / sizeof(array[0]));
	t.PrevOrder();
	cout << endl;
	t.InOrder();
	t.PostOrder();
	cout << endl;
	t.LevelOrder();
	cout << endl;
	cout << t.Size() << endl;
	cout << t.Depth() << endl;
}
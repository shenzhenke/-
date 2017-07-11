#define _CRT_SECURE_NO_WARNINGS
#pragma once
template <class T>
struct BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;    //����
	BinaryTreeNode<T>* _right;  // �Һ���
	BinaryTreeNode(const T& x)
		:_left(NULL)
		, _right(NULL)
		, _data(x)
	{}
};

template <class T>
class BinaryTree
{
public:
	typedef BinaryTreeNode<T> Node;
	//����
	BinaryTree()
		:_root(NULL)
	{
	}
	//��һ�����鴴��һ��������
	BinaryTree(T* a,size_t n, const T& invalid)
	{
			size_t index = 0;
			_root = CreatBinaryTree(a, n, invalid, index);
	}

	//����������Ϊ�������
	//index����ȡ���õ�ԭ��:�������е�Ԫ��Ϊ�Ƿ�ֵʱ,index��ֵ��û�иı�
	Node* CreatBinaryTree(T* a, size_t n, const T& invalid, size_t& index)
	{
		Node* _root = NULL;
		if ((a[index] != invalid)&& index < n )
		{
			_root = new Node(a[index]);
			_root->_left = CreatBinaryTree(a, n, invalid, ++index);
			_root->_right = CreatBinaryTree(a, n, invalid, ++index);
		}
		return _root;
	}


	Node* CreatBinaryTree(Node* root) 
	{
		Node* _root = NULL;
		if (root !=NULL )
		{
			_root = new Node(root->_data);
			_root->_left = CreatBinaryTree(root->_left);
			_root->_right = CreatBinaryTree(root->_right);
		}
		return _root;
	}
	//��������
	BinaryTree(const BinaryTree<T>& root)
	{
		_root = CreatBinaryTree(root._root);
	}

	BinaryTree<T>& operator=(const BinaryTree<T>& root)
	{
		if (_root != root._root)
		{
			this->~BinaryTree();
			_root = CreatBinaryTree(root._root);
		}
		return *this;
	}

	
	//��������  һ��һ���������
	~BinaryTree()
	{
		if (_root)
		{
			Destroy(_root);
		}
	}
	//���������ȱ���������,�ٱ���������,���к�ֻ�Ǹ���˳��ͬ����
	//�������  dlr

	void PrevOrder()
	{
		_PrevOrder(_root);
		cout << endl;
	}

	//������� ldr
	
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	//������� lrd
	
	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}

	//�������  ���ö���---�Ƚ��ȳ�

	void LevelOrder()
	{
		queue<Node*> q;
		if (_root)
		{
			q.push(_root);
		}
		while (q.size())
		{
			Node* cur = q.front();
			if (cur->_left != NULL)
			    q.push(cur->_left);
			if (cur->_right != NULL)
				q.push(cur->_right);
			cout << cur->_data << " ";
			q.pop();
		}
		cout << endl;
	}


	//������
	Node* Find(const T& x)
	{
		return	_Find(_root, x);
	}

	//��Ҷ�ӽڵ�(û������,û���Һ��ӵĽڵ�)����
	size_t LeafSize()
	{
		if (_root != NULL)
			return _LeafSize(_root);
		return 0;
	}


	//���ܽ��ĸ���
	size_t Size()
	{
		if (_root)
			return _Size(_root);
		return 0;
	}


	//���k��Ľ��ĸ���
	size_t GetKLevel(size_t k)
	{
		if (_root)
			return _GetKLevel(_root, k);
		return 0;
	}


	//������������
	size_t Depth()
	{
		map<Node*, int> s;
		int high = 0;
		if (_root)
			high = _Depth(_root, s);
		vector<vector<int> > v(3);
		map<Node*, int>::iterator it = s.begin();
		while (it != s.end())
		{
			v[high-(it->second) ].push_back((it->first)->_data);
			it++;
		}
		return 0;
	}
protected:

	void Destroy(Node* root)
	{
		if ( root !=NULL )
		{
			Destroy(root->_left);
			Destroy(root->_right);
		}
		delete root;
		root = NULL;
		return;
	}

	void _PrevOrder(Node* root)
	{
		if ( root !=NULL )
		{
			cout << root->_data << " ";
			_PrevOrder(root->_left);
			_PrevOrder(root->_right);
		}
		return;
	}

	void _InOrder(Node*  root)
	{
		if ( root !=NULL )
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}

	void _PostOrder(Node* root)
	{
		if ( root !=NULL )
		{
			_PostOrder(root->_left);
			_PostOrder(root->_right);
			cout << root->_data << " ";
		}
	}

	Node* _Find(Node* root,const T& x)
	{
		static Node* node = NULL;
		if (root == NULL)
		{
			return NULL;
		}
		if (root->_data == x)
		{	
			node = root;
			return node;
		}
		else
		{
			if (_Find(root->_left, x) == NULL)
			{
				return _Find(root->_right, x);
			}
			else
			{
				return node;
			}
		}
	}

	size_t _Size(Node* root)
	{
		static int count = 0;
		if ( root !=NULL )
		{
			count++;
			_Size(root->_left);
			_Size(root->_right);
		}
		return count;
	}


	/*size_t _Depth(Node* root)
	{
		if (root == NULL)
			return 0;
		size_t L_Depth = 1;
		L_Depth += _Depth(root->_left);
		size_t R_Depth = 1;
		R_Depth += _Depth(root->_right);
		return L_Depth > R_Depth ? L_Depth : R_Depth;
	}*/

size_t  _Depth(Node* root, map<Node*, int> & s)
{
	if (root == NULL)
		return 0;
	size_t L_Depth = 1;
	L_Depth += _Depth(root->_left, s);
	size_t R_Depth = 1;
	R_Depth += _Depth(root->_right, s);
	size_t Depth = L_Depth > R_Depth ? L_Depth : R_Depth;
	s[root] = Depth;
	return Depth;
}


	//��k��������+��k���������Ľ��ĸ���
	size_t _GetKLevel(Node* root, size_t k)
	{
		if (k == 0 || root == NULL)
			return 0;
		if (k == 1)
			return 1;
		int numleft = _GetKLevel(root->_left, k - 1);
		int numright = _GetKLevel(root->_right, k - 1);
		return(numleft + numright);
	}

	size_t _LeafSize(Node* root)
	{
		static int count = 0;
		if ((root->_left == NULL) && (root->_right == NULL))
			return ++count;
		if (root != NULL)
		{
			_LeafSize(root->_left);
			_LeafSize(root->_right);
		}
		return count;
	}


	Node* _root;
};




void TestBinaryTree()
{
	int array[] = { 1, 2, 3, '*', '*', 4, '*', '*', 5, 6,'*','*',7 };
	BinaryTree<int> t(array,sizeof(array)/sizeof(array[0]),'*');
	t.InOrder();
	t.PostOrder();
	t.PrevOrder();
	//BinaryTree<int> t1(t); 
	//t.PrevOrder();                            // �������
	//t.InOrder();                             //  �������
	//t.PostOrder();                          //   �������
	//t.LevelOrder();                        //    �������
	//cout << t.Size() << endl;              //    ������������
	//cout << t.LeafSize() << endl;         //     ������Ҷ�ӽ��ĸ���
	//cout << t.GetKLevel(3) << endl;      //      ��������k��Ľ��ĸ���
	t.Depth();          //       �����������
	//BinaryTreeNode<int>* node = t.Find(2);
	//BinaryTree<int> t2;
	//t2 = t;                          
}
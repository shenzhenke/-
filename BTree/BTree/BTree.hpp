
template<class K,class V,size_t M>
//�����͵�ģ�����������ʱ��ɳ���
//M�����ĺ��Ӹ���Ϊ	[M/2,M]		������
//M�����Ĺؼ��ָ���Ϊ	[M/2-1,M-1]	���ؼ���,��Ϊ��������
struct BTreeNode
{
	//������Ĵ�СԤ����һλ��Ϊ�˱��ڷ���
	pair<K, V> _kvs[M];					//kvs����,���kv
	BTreeNode<K, V, M>* _parent;		   //ָ�򸸽���ָ�룬���ڷ���
	BTreeNode<K, V, M>* _subs[M + 1];	  //ָ���ӽ���ָ������
	size_t _size;				         //kvs����,��Ч���ݸ���
	
	BTreeNode()
		:_parent(NULL)
		, _size(0)
	{
		for (size_t i = 0; i < M + 1; i++)
		{
			_subs[i] = NULL;
		}
	}
};

template<class K, class V, size_t M>
class BTree
{
	typedef BTreeNode<K, V, M> Node;
public:
	BTree()
		:_root(NULL)
	{}
	//Ϊ�˱��ڲ���,������ֵ����Ϊpair<Node*,int>
	//����Ҫ����λ�õĸ�����Լ������±�
	pair<Node* ,int>  Find(const K& key)
	{
		Node* cur = _root;
		Node* parent = NULL;
		size_t index = 0;
		while (cur != NULL)
		{
			index = 0;
			while (index < cur->_size)
			{
				if (cur->_kvs[index].first == key)
				{
					return make_pair(cur, -1);
				}
				else if (cur->_kvs[index].first > key)
				{
					break;
				}
				else
				{
					++index;
				}
			}
			//ע�������߼�˳��
			parent = cur;
			cur = cur->_subs[index];
		}
		//BTree������Ҫ�ڿ�λ�ò��룬һ���������ж���ؼ���
		//��������ĺ���Ϊ�գ�û�ҵ��ؼ���ʱ���Ϳ��Բ�����
		return make_pair(parent, index);
	}

	bool Insert(const pair<K, V> & kv)
	{
		if (_root == NULL)
		{
			_root = new Node();
			_root->_kvs[0] = kv;
			_root->_subs[0] = NULL;
			_root->_subs[1] = NULL;
			_root->_size++;
		}
		pair<Node*, int> ret = this->Find(kv.first);
		if (ret.second == -1)
			return false;
		//Ҫ����λ�õĽ��
		Node* cur = ret.first;
		Node* parent = cur->_parent;
		Node* sub = NULL;
		pair<K, V> newKV = kv;
		while (1)
		{
			this->InsertKV(cur, newKV, sub);
			if (cur->_size < M)
			{
				return true;
			}
			//�ߵ������ʾ����ŵ�kv�Ѿ�����,��Ҫ����
			Node* brother = new Node();
			int mid = M / 2;
			int i = mid + 1;
			int j = 0;

			//���м���֮������ݸ��Ƹ��ֵܽ��
			for (; i < M; i++)
			{
				brother->_kvs[j] = cur->_kvs[i];
				brother->_size++;
				cur->_size--;
				if (cur->_subs[i] != NULL)
				{
					cur->_subs[i]->_parent = brother;
					brother->_subs[j] = cur->_subs[i];
					cur->_subs[i] = NULL;
				}
				j++;
			}
			if (cur->_subs[i] != NULL)
				cur->_subs[i]->_parent = brother;
			brother->_subs[j] = cur->_subs[i];
			cur->_subs[i] = NULL;
			
			//����Ѿ��������
			if (parent == NULL)
			{
				Node* root = new Node();
				root->_kvs[0] = cur->_kvs[mid];
				root->_subs[0] = cur;
				cur->_parent = root;
				cur->_size--;
				root->_subs[1] = brother;
				brother->_parent = root;
				_root = root;
				_root->_size++;
				return true;
			}

			//���м�������
			newKV = cur->_kvs[mid];
			cur->_size--;
			cur = parent;
			parent = cur->_parent;
			sub = brother;
		}
	}

	void InOrder()
	{
		_InOrder(_root);
	}
private:
	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		size_t i = 0;
		for (; i < root->_size; i++)
		{
			_InOrder(root->_subs[i]);
			cout << "    "<<root->_kvs[i].first << " ��" << root->_kvs[i].second << endl;
		}
		_InOrder(root->_subs[i]);
	}
	void InsertKV(Node* cur,const pair<K, V>& kv,Node* sub)
	{
		size_t index = 0;
		for (; index < cur->_size; index++)
		{
			if (kv.first < cur->_kvs[index].first)
				break;
		}
		for (size_t i = cur->_size ; i > index; i--)
		{
			cur->_kvs[i] = cur->_kvs[i - 1];
			cur->_subs[i + 1] = cur->_subs[i];
		}
		cur->_kvs[index] = kv;
		cur->_subs[index + 1] = sub;
		if (sub != NULL)
		{
			sub->_parent = cur;
		}
		cur->_size++;
		return;
	}
	Node* _root;
};


void  TestBTree()
{
	BTree<int, int, 3> t;
	int arr[] = { 50, 75, 139, 49, 145, 36, 101 };
	//int arr[] = { 1, 5, 16, 17, 18, 20, 30, 35, 36, 40, 45, 46, 50, 55, 56 };
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		t.Insert(make_pair(arr[i], i));
	}
	t.InOrder();
}
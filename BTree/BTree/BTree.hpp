
template<class K,class V,size_t M>
//非类型的模板参数在推演时变成常量
//M阶树的孩子个数为	[M/2,M]		个孩子
//M阶树的关键字个数为	[M/2-1,M-1]	个关键字,且为升序排列
struct BTreeNode
{
	//将数组的大小预留出一位是为了便于分裂
	pair<K, V> _kvs[M];					//kvs数组,存放kv
	BTreeNode<K, V, M>* _parent;		   //指向父结点的指针，便于分裂
	BTreeNode<K, V, M>* _subs[M + 1];	  //指向孩子结点的指针数组
	size_t _size;				         //kvs数量,有效数据个数
	
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
	//为了便于插入,将返回值设置为pair<Node*,int>
	//返回要插入位置的父结点以及它的下标
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
			//注意代码的逻辑顺序
			parent = cur;
			cur = cur->_subs[index];
		}
		//BTree并不需要在空位置插入，一个结点可以有多个关键字
		//当这个结点的孩子为空，没找到关键字时，就可以插入了
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
		//要插入位置的结点
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
			//走到这里表示结点存放的kv已经满了,需要分裂
			Node* brother = new Node();
			int mid = M / 2;
			int i = mid + 1;
			int j = 0;

			//将中间结点之后的数据复制给兄弟结点
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
			
			//如果已经到根结点
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

			//将中间结点上移
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
			cout << "    "<<root->_kvs[i].first << " ：" << root->_kvs[i].second << endl;
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
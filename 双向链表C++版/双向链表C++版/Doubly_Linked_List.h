#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <assert.h>
using namespace std;
typedef int DataType;
//struc�������η���Ϊ���е�
struct ListNode
{
	ListNode *_next;
	ListNode *_prev;
	DataType _data;
	ListNode(const DataType d)
		:_next(NULL)
		,_prev(NULL)
		, _data(d)
	{
	}
};
class List
{
public:
	typedef ListNode Node;

	List();

	List(const List &s);

	List& operator=(List s);//����Ϊ��ʵ������

	~List();


	void PushBack(DataType x);

	void PopBack();

	void PushFront(DataType x);

	void PopFront();

	void Insert(Node * pos, DataType x);

	void Erase(Node* pos);

	ListNode * Find_Pos(DataType x);
	
	void Reverse();

	void display();
private:
	Node *_head;
	Node *_tail;
};

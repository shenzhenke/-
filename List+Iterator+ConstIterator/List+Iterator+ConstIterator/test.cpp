#include "List.h"
#include <list>
void Printlist(list<int>& l)
{
	list<int>::const_iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";

		//*it = 10;

		++it;
	}
	cout << endl;
}

int main()
{
	list<int> l1;
	l1.push_back(0);
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	/*l1.push_back(4);
	l1.push_back(6);
	l1.push_back(8);*/




	list<int>::iterator it1 = l1.begin();
	//it1++;
	//l1.erase(it1);
	while (it1 != l1.end())
	{
		if (*it1 % 2 == 0)
		{
			it1 = l1.erase(it1);
		}
		++it1;  
//list不能使用++的原因是eraser的返回值为删除结点的下一个结点,假如最后一个结点的前一个数据为奇数,
//最后一个结点的数据为偶数,要删除,返回值就为链表的_head,因为迭代器为[)区间,再执行++操作会导致迭代器没有指向

	}
	Printlist(l1);


	List<int> l2;
	l2.PushBack(1);
	l2.PushBack(2);
	l2.PushBack(2);
	l2.PushBack(4);
	l2.PushFront(0);
	l2.PushBack(5);
	//PrintList(l2);
	List<int>::Iterator it2 = l2.Begin();
	//l2.Erase(it2);
	//while (it2 != l2.End())
	//{
	//	//取奇数数据,删除数据中为偶数的结点
	//	if (*it2 % 2 == 0)
	//	{
	//		it2 = l2.Erase(it2);
	//	}
	//	++it2;
	//}
//	l2.Clear();
	PrintList(l2);
}
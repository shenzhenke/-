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
//list����ʹ��++��ԭ����eraser�ķ���ֵΪɾ��������һ�����,�������һ������ǰһ������Ϊ����,
//���һ����������Ϊż��,Ҫɾ��,����ֵ��Ϊ�����_head,��Ϊ������Ϊ[)����,��ִ��++�����ᵼ�µ�����û��ָ��

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
	//	//ȡ��������,ɾ��������Ϊż���Ľ��
	//	if (*it2 % 2 == 0)
	//	{
	//		it2 = l2.Erase(it2);
	//	}
	//	++it2;
	//}
//	l2.Clear();
	PrintList(l2);
}
#include "Vector.h"
#include  <vector>
void Printvector(vector<int> &l)
{
	vector<int>::iterator it = l.begin();
	while (it != l.end())
	{
		//当进行删除操作（erase，pop_back）后，指向删除点的迭代器全部失效；指向删除点后面的元素的迭代器也将全部失效
			if (*it % 2 == 0)
			{
			 //l.erase(it);
			 //删除这个结点,it的指向并未改变,将it后面的元素前移,但是这个时候已经不能引用了,因为指向的元素已经变了
				l.insert(it, 0);
			}
			cout << *it << " ";
			++it;
		/*if (*it % 2 == 0)
		{
			it = l.erase(it);
		}
		else
		{
			cout << *it << " ";
			++it;
		}*/
	}
	cout << endl;
}
void Testvector()
{

	vector<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	//l.push_back(6);
	Printvector(l);
}
int main()
{
	
	Testvector();
//	TestVector();
	return 0;
}
#include "Vector.h"
#include  <vector>
void Printvector(vector<int> &l)
{
	vector<int>::iterator it = l.begin();
	while (it != l.end())
	{
		//������ɾ��������erase��pop_back����ָ��ɾ����ĵ�����ȫ��ʧЧ��ָ��ɾ��������Ԫ�صĵ�����Ҳ��ȫ��ʧЧ
			if (*it % 2 == 0)
			{
			 //l.erase(it);
			 //ɾ��������,it��ָ��δ�ı�,��it�����Ԫ��ǰ��,�������ʱ���Ѿ�����������,��Ϊָ���Ԫ���Ѿ�����
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
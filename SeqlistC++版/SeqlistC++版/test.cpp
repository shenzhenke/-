#include "Seqlist.h" 

int main()
{
	//��������
	Seqlist s1(1);
	s1.Display();
	
	//������
	Seqlist s2;
	s2.Display();
	s2.Push_Back(1);
	s2.Push_Back(2);
	s2.Push_Back(3);
	s2.Push_Back(4);
	s2.Display();

	////��ֵ����
	//Seqlist s3;
	//s3 = s2;
	//s3.Display();
	//
	////ǰ�����
	//s3.Push_Front(0);
	//s3.Display();

	////ǰɾ����
	//s3.Pop_Front();
	//s3.Display();

	////��ɾ����
	//s3.Pop_Back();
	//s3.Display();

	////ɾ����һ�γ���ָ�����ݲ���
	//s3.Remove(4);
	//s3.Display();
 // 
	////��ֵ����
	//s3 = s3;
	//s3.Display();

	////����˳������
	//s3.Inverse();
	//s3.Display();

	////ɾ��ָ��������ݲ���
	//s3.Erase(2);
	//s3.Display();

	////ָ��λ�ò������ݲ���
	//Seqlist s4(1);
	//s4.Insert(0,0);
	//s4.Display();

	////��ָ�����ݲ���
	//int a = s3.Find(0);
	//cout << a << endl;
	//
	////�������
	//Seqlist s5(1);
	//s5.Push_Back(3);
	//s5.Push_Back(2);
	//s5.Push_Back(6);
	//s5.Push_Back(5);
	//s5.Push_Back(4);
	//s5.Display();
	//s5.Sort();
	//s5.Display();
	return 0;
}
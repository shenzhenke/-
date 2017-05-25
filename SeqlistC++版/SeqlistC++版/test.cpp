#include "Seqlist.h" 

int main()
{
	//遍历测试
	Seqlist s1(1);
	s1.Display();
	
	//后插测试
	Seqlist s2;
	s2.Display();
	s2.Push_Back(1);
	s2.Push_Back(2);
	s2.Push_Back(3);
	s2.Push_Back(4);
	s2.Display();

	////赋值测试
	//Seqlist s3;
	//s3 = s2;
	//s3.Display();
	//
	////前插测试
	//s3.Push_Front(0);
	//s3.Display();

	////前删测试
	//s3.Pop_Front();
	//s3.Display();

	////后删测试
	//s3.Pop_Back();
	//s3.Display();

	////删除第一次出现指定数据测试
	//s3.Remove(4);
	//s3.Display();
 // 
	////赋值测试
	//s3 = s3;
	//s3.Display();

	////逆置顺序表测试
	//s3.Inverse();
	//s3.Display();

	////删除指定结点数据测试
	//s3.Erase(2);
	//s3.Display();

	////指定位置插入数据测试
	//Seqlist s4(1);
	//s4.Insert(0,0);
	//s4.Display();

	////找指定数据测试
	//int a = s3.Find(0);
	//cout << a << endl;
	//
	////排序测试
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
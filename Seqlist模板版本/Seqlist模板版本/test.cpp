#include "Seqlist.h"
//#include "List.h"
int sum = 0;
int k = 0;
class Sum
{
public:
	Sum() 
	{ 
		sum += ++k;
	}

};

//template <class T,int value>
//class Add
//{
//public:
//	 Add()
//	{
//		 
//	}
//
//private:
//
//};
//
//template <class T, int value>
//T Add(const T& x) 
//{
//	return x + value; 
//}

int main()
{

	//cout << Add<int, 1>(0) << endl;

//	Add<int ,1> *ptr=new Add<int , 1>[100];
	
	/*int n = 0;
	cin >> n;
	Sum *ptr=new Sum[n];
	cout << sum << endl;
	delete[]ptr;
	cout << sum << endl;*/
	//拷贝构造,赋值运算符的重载
//	List <string> l;
////	l.Pushback("1233");
////	l.Pushback("1888884");
//	l.Display();
//	List <string> l1(l);
//	l1.Display();
//
		
	//尾插和尾删
	/*List <string> l;
	l.Pushback("1233");
	l.Pushback("1888884");
	l.Display();
	List <string> l1(l);
	l1.Display()*/
	//l.Popback();
	//l.Popback();
	//l.Popback();
	//l.Display();

	//头插和头删
	/*List<string> l;
	l.Pushfront("123");
	l.Pushfront("12");
	l.Pushfront("1");
	l.Display();
	l.Popfront();
	l.Display();
	l.Popfront();
	l.Popfront();
	l.Popfront();
	l.Display();
	*/
	
	
	
	
	
	////尾删和尾插
	//Seqlist<int> l;
	//l.Pushback(1);
	//l.Pushback(2);
	//l.Pushback(3);
	//l.Pushback(4);
	//l.Display();
	//l.Popback();
	//l.Display();
	//l.Popback();
	//l.Popback();
	//l.Popback();
	//l.Popback();
	//l.Display();

	/*Seqlist<string> l;
	l.Pushback("1111");
	l.Pushback("33322");
	l.Pushback("333");
	l.Pushback("3344333");*/
	//l.Pushback("3333333");
	//l.Pushback("3333333");
	//l.Pushback("3333333");
	//l.Pushback("330333");
	//l.Pushback("33333333");
	/*l.Display();
	l.Popback();
	l.Popback(); 
	l.Popback();
	l.Popback();*/
	//l.Popback();
	//l.Popback();
	//l.Popback();
	//l.Popback();
	//l.Popback();
	//l.Popback();
	//l.Popback();
	//l.Popback();
	//l.Popback();
	//l.Display();
	//Seqlist<string> l1(l);
	//l1.Display();


	//头插和头删
	/*Seqlist<string> l;
	l.Pushfront("123");
	l.Pushfront("1234");
	l.Pushfront("123");
	l.Pushfront("123");
	l.Pushfront("12131241131242413355332523");
	l.Pushfront("123");
	l.Pushfront("123456");
	l.Display();
	Seqlist <string>s2;
	s2.Pushback("123");
	s2.Display();
	s2 = l;
	l.Display();
	s2.Display();*/
	//l.Popfront();
	//l.Popfront();
	//l.Popfront();
	//l.Popfront();
	//l.Popfront();
	//l.Popfront();
	//l.Popfront();
	//l.Popfront();
	//l.Popfront();
	//l.Popfront();
	//l.Popfront();
	//l.Display();


	//指定位置删除和指定位置插入,以及查找一个元素
	//Seqlist<string> l;
	//l.Insert(0, "123");
	//l.Insert(0, "3");
	//l.Insert(1, "12");
	//l.Insert(2, "13");
	//l.Insert(0, "1");
	//l.Display();
	//cout << l.Find("1234") << endl;
	//l.Display();
	//l.Erase(0);
	//l.Erase(0);
	//l.Erase(0);
	//l.Erase(0);
	//l.Erase(0);
	//l.Erase(0);
	//l.Display();

//队列，先进先出
//Queue <string,List<string>> s;
//s.Push("123");
//cout << s.Empty() << endl;
//cout << s.Size() << endl;
//cout << s.Front()<< endl;
//cout << s.Back() << endl;
//s.Pop();
//cout << s.Empty() << endl;
//cout << s.Size() << endl;

//栈，后进先出
//Stack <string,Seqlist<string>> s;
//s.Push("12");
//s.Push("34");
//s.Push("42");
//s.Push("1");
//cout << s.Empty() << endl;
//cout << s.Size() << endl;
//cout << s.Top() << endl;
//s.Pop();
//s.Pop();
//s.Pop();
//s.Pop();
//s.Pop();
//cout << s.Empty() << endl;
//cout << s.Size() << endl;

	return 0;
}
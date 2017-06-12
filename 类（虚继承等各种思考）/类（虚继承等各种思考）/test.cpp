#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//using namespace std;
//class A 
//{
//public:
//	int  _a;
//};
//
//class B : virtual  public A 
//{
//public:
//	int _b;
//};
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D :public B,public C
//{
//public:
//	int _d;
//};
//int main()
//{
//
//
//
//	D d;
//	d._a = 4;
//	d._b = 1;
//	d._c = 2;
//	d._d = 3;
//
//
//
//
//	return 0;
//}

//
//#include <iostream>
//#include <string>
//using  namespace std;
//class Person  
//{
//public:   
//	Person(char *s="xiaowang")
//		: _name(s)
//	{}
//	Person(const string& name) 
//		  : _name(name)   
//            {}   
//		  void Display()   
//		  { 
//			  cout << _name << endl; 
//		  } 
//         public:   string _name; // 姓名 
//};  
//class Student : public Person  
//{
//public :   int _num ; // 学号 
//};
//int main()
//{
//	Student A;
//	A._name="xiaoli";
//	A._num = 123;
//	//A = B;  //父类是不可以给子类赋值的
//	Person B;
//	B = A;  //子类是可以给父类赋值，会发生切片行为
//
//	Person * b = &B;
//	b = &A;  //父类的指针或者引用能够指向子类
//	Student *a = &A;
//	
//	//a = &B; //子类的指针或者引用不能够指向子类
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{/*
//	int const a = 10;
//	*a = 10;*/
//	int a = 248, b = 4;
//	int const c = 21;
//	const int *d = &a;
//	d = &a;
//	int *const e = &b;
//	int const * const f = &a;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//struct A
//{
//	unsigned int a;
//	char b[2];
//	double c;
//	short d;
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//struct A
//{
//	int b;
//	char a[0];
//
//};
//int main()
//{
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	Person(char *name = "xiaowang", int id = 0)
//		:_name(name)
//		, _id(id)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person &s)
//		:_name(s._name)
//		, _id(s._id)
//	{
//		cout << "Person(const Person &s)" << endl;
//	}
//
//	Person & operator=(const Person &s)
//	{
//		if (this != &s)
//		{
//			this->_name = s._name;
//			this->_id = s._id;
//		}
//		cout << "operator=" << endl;
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//protected:
//	string _name;
//	int _id;
//};
//
//class Student :public Person
//{
//public:
//
//	Student( char *name = "", int num = 10, int id = 0)
//		:Person(name,id) //基类和派生类各自初始化自身的成员
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student &s)
//		:_num(s._num)
//		, Person(s)
//	{
//		cout << "Student(const Student &s)" << endl;
//	}
//	~Student()
//	{
//		//Person::~Person();
//		//不用再去调用父类的析构函数了，系统会自动帮你调用，否则会造成一块空间被多次析构
//		cout << "~Student()" << endl;
//	}
//	Student & operator=(const Student & s)
//	{
//		cout << "Student & operator=" << endl;
//		if (this != &s)
//		{
//			//this->operator=(s);  
//			//由于访问原则，为就近原则，这造成程序一直调用Student的赋值运算符重载
//			Person::operator=(s);
//			_num = s._num;
//		}
//	
//		return *this;
//	}
//protected:
//	int _num;
//
//};
//
//
//                  
//int main()
//{
//	Person s3("szk", 0);
//	Person s4("szk", 1);
//	s4 = s3;
//     Student s1("szk",9,8);
//     Student s2("szk",10,9);
//	 s2 = s1;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class  A
//{
//public:
//	virtual void f1()
//	{
//		cout << "A::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "A::f2()" << endl;
//	}
//private:
//	int _a;
////	static int a; //静态成员变量并不计入对象的大小，因为它是属于
//};
//
//
//class B :public A 
//{
//public :
//	 void f1()  //重写这个函数的时候基类函数必须加virtual关键字，而派生类的函数可加可不加
//	{
//		cout << "B::f1()" << endl;
//	}
//	void f2()
//	{
//		cout << "B::f2()" << endl;
//	}
//private:
//	int _b;
//};
//
//int main()
//{
//     //cout << sizeof(A) << endl;
//	//cout << sizeof(B) << endl;
//	A a;
//	B b;
//	a = b;
//	b.f1();
//	cout << endl;
//	a.f1();
//	cout << endl;
//
//	A * pa = &a;
//	B * pb = &b;
//	pa = pb;
//	pa->f1();
//	cout << endl;
//	pb->f1();
//
//
//	return 0;
//}
//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	void f1()
//	{
//		cout << "A::f1()" << endl;
//	}
//private:
//	int _a;
//};
//class  B
//{
//public:
//	virtual void f1()
//	{
//		cout << "B::f1()" << endl;
//	}
//private:
//	int _b;
//};
//
//class C :public B
//{
//public:
//	virtual void f1()  //重写这个函数的时候基类函数必须加virtual关键字，而派生类的函数可加可不加
//	{
//		cout << "C::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "C::f2()" << endl;
//	}
//private:
//	int _c;
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	cout << sizeof(C) << endl;
//	A a;
//	B b;
//	C c;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public: 
//	virtual void f1()
//	{
//		cout << "A::f1()" << endl;
//		cout << endl;
//	}
//	virtual void f2()
//	{
//		cout << "A::f2()" << endl;
//		cout << endl;
//	}
//	virtual void f3()
//	{
//		cout << "A::f3()" << endl;
//		cout << endl;
//	}
//private:
//	int _a;
//};
//
//class B :public A
//{
//public:
//	virtual void f4()
//	{
//		cout << "B::f4()" << endl;
//		cout << endl;
//	}
//    virtual void f5()
//	{
//		cout << "B::f5()" << endl;
//	}
//private:
//	int _b;
//};
//
//class C :public A
//{
//	virtual void f1()
//	{
//		cout << "C::f1()" << endl;
//		cout << endl;
//	}
//	virtual void f5()
//	{
//		cout << "C::f5()" << endl;
//		cout << endl;
//	}
//
//};
//typedef void(*V_FUNC)();
//void PrintfVTable(int * Vtable)
//{
//	cout << endl;
//	printf("Vtable:0x%p\n",Vtable);
//	for (size_t i = 0; Vtable[i]; i++)
//	{
//		void(*f)() = (void (*)()) Vtable[i];
//		//V_FUNC f = (V_FUNC)Vtable[i];
//		   f();
//	}
//}
//int main()
//{
//	A a;
//	A b;
//	C c;
//	int *A_Vtable_ptr =((int *) *((int *)&a));
//	int *B_Vtable_ptr = ((int *)*((int *)&c));
//	int *C_Vtable_ptr = ((int *)*((int *)&c));
//	PrintfVTable(A_Vtable_ptr);
//	cout << endl;
//	cout << endl;
//	PrintfVTable(B_Vtable_ptr);
//	cout << endl;
//	return 0;
//
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	void f1()
//	{
//		cout << "A::f1()" << endl;
//	}
//private:
//	int _a;
//};
//
//
////（2）定义一个含有虚函数的类
//class  B
//{
//public:
//	virtual void f1()
//	{
//		cout << "B::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "B::f2()" << endl;
//	}
//	int _b;
//};
//
////(3)定义一个继承B类的子类，并且本身还有独立虚函数的类
//class C :public B
//{
//public:
//	virtual void f1()
//	{
//		cout << "C::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "C::f2()" << endl;
//	}
//	int _c;
//};
//
////
//class D :public B
//{
//public:
//	virtual void f1()
//	{
//		cout << "D::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "D::f2()" << endl;
//	}
//	int _d;
//};
//class E :public C,public D
//{
//public:
//	virtual void f1()
//	{
//		cout << "E::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "E::f2()" << endl;
//	}
//	virtual void f3()
//	{
//		cout << "E::f3()" << endl;
//	}
//	int _e;
//};
//
//class C1 : virtual public B
//{
//public:
//	virtual void f1()
//	{
//		cout << "C1::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "C1::f2()" << endl;
//	}
//	int _c1;
//};
//
////
//class D1 : virtual public B
//{
//public:
//	virtual void f1()
//	{
//		cout << "D1::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "D1::f2()" << endl;
//	}
//	int _d1;
//};
//
//class E1 :public C1, public D1
//{
//public:
//	virtual void f1()
//	{
//		cout << "E1::f1()" << endl;
//	}
//	virtual void f2()
//	{
//		cout << "E1::f2()" << endl;
//	}
//	virtual void f3()
//	{
//		cout << "E1::f3()" << endl;
//	}
//	int _e1;
//};
//int main()
//{
//	E e;
//	e.D::_b = 1;
//	e.C::_b = 2;
//	e._c = 3;
//	e._d = 4;
//	e._e = 5;
//	E1 e1;
//	e1.D1::_b = 1;
//	e1.C1::_b = 2;
//	e1._c1 = 3;
//	e1._d1 = 4;
//	e1._e1 = 5;
//	cout << sizeof(E) << endl;
//	cout << sizeof(E1) << endl;
//	return 0;
//}

//
//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void f2()
//	{
//	}
//	/*virtual void f2()
//	{
//	}
//	virtual void f3()
//	{
//	}*/
//	int _a;
//};
//class B : virtual public A
//{
//public:
//	/*virtual void f2()
//	{
//	}*/
//	virtual void f1()
//	{
//	}
//	int _b;
//
//};
//class C :virtual public A
//{
//public:
//	//virtual void f1()
//	//{
//	//}
//	/*virtual void f2()
//	{
//	}*/
//	int _c;
//
//};
//class D :public B,public C
//{
//public:
//	virtual void f2()
//	{
//	}
//	/*virtual void f2()
//	{
//	}*/
//	//virtual void f3()
//	//{
//	//}
//	//virtual void f4()
//	//{
//	//}
//	int _d;
//
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	cout << sizeof(D) << endl;
//	B b;
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}

#include  <iostream>
using namespace std;
class A
{
public:
	virtual void f1()
	{
		cout << "A::f1()" << endl;
		cout << endl;
	}
	virtual void f2()
	{
		cout << "A::f2()" << endl;
		cout << endl;
	}
	int _a;
};

class B : virtual public A
{
public:
	virtual void f1()
	{
		cout << "B::f1()" << endl;
		cout << endl;
	}
	virtual void f3()
	{
		cout << "B::f3()" << endl;
		cout << endl;
	}

	int _b;
};
class C : virtual public A
{
public:
	virtual void f1()
	{
		cout << "C::f1()" << endl;
		cout << endl;
	}
	virtual void f4()
	{
		cout << "C::f4()" << endl;
		cout << endl;
	}
	int _c;
};

class D :public B,public C
{
public:
	virtual void f1()
	{
		cout << "D::f1()" << endl;
		cout << endl;
	}

	virtual void f5()
	{
		cout << "D::f5()" << endl;
		cout << endl;
	}

	int _d;
};


typedef void(*V_FUNC)();
void PrintfVTable(int * Vtable)
{
	cout << endl;
	printf("Vtable:0x%p\n",Vtable);
	for (size_t i = 0; Vtable[i]; i++)
	{
		void(*f)() = (void (*)()) Vtable[i];
		//V_FUNC f = (V_FUNC)Vtable[i];
		   f();
	}
}
int main()
{


	D d;

	d.B::_a = 1;

	d.C::_a = 2;

	d._b = 3;

	d._c = 4;

	d._d = 5;



	int *d_First_Vatable = ((int *)*((int *)&d));
	int *d_Sencond_Vatable = ((int *)*((int *)&d + 3));
	int *d_Third_Vatable = ((int *)*((int *)&d + 7));
	
	PrintfVTable(d_First_Vatable);
	PrintfVTable(d_Sencond_Vatable);
	PrintfVTable(d_Third_Vatable);
	return 0;
}


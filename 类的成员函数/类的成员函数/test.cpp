#define _CRT_SECURE_NO_WARNINGS 
//#include  <iostream>
//using namespace std;
//namespace name1
//{
//	int a;
//}
//namespace name2   //namespace+名字构成名字空间域
//{
//	int a;
//
//}
//int main()
//{
//	name1::a = 10;   //::作用域解析符，用它声明函数是属于哪个类的
//	name2::a = 10;
//	return 0;
//}

//#include <iostream>
//#include <windows.h>
//using namespace std;
//void ADD(int a, int b)
//{
//	return;
//}
//void ADD(double a, double b)
//{
//	return;
//}
//int add(int a = 1, int b = 1)   // 全缺省参数、
//                               //缺省参数就是在声明某种方法的时候为之指定一个默认值，
//							  //在调用该方法的时候如果采用该默认值，你就无须指定该参数。
//							 //缺省参数使用主要规则：调用时你只能从最后一个参数开始进行省略，
//							//换句话说，如果你要省略一个参数，你必须省略它后面所有的参数，
//						   //即：带缺省值的参数必须放在参数表的最后面。 缺省值必须是常量。
//						  //显然，这限制了缺省参数的数据类型，例如动态数组和界面类型的缺省参数值只能是 nil；
//						 //至于记录类型，则根本不能用作缺省参数。 缺省参数必须通过值参或常参传递。
//{
//	return a + b;
//
//}
////int add1(int a = 5, int b)缺省参数使用主要规则：调用时你只能从最后一个参数开始进行省略
////{                                               如果你要省略一个参数，你必须省略它后面所有的参数
////	return a + b;
//
////}
//int main()
//{
//	ADD(1, 2);
//	ADD(2.0, 1.0);  //传入不同的参数进入不同的函数
//	//  函数重载：函数名可以相同，参数的类型不同或者参数的个数不同（参数列表不同），
//	//            返回值可同可不同.
//	cout <<"a+b="<< add(4) << endl;
////	cout << "a+b=" << add1(4) << endl;
//	system("pause");
//	return 0;
//}


//引用：并非定义一个新变量，而是给一个已经定义的变量取一个别名
// 类型&引用变量名=已经定义过的变量名
//引用的特点：一个变量可以取多个别名；引用必须初始化；引用只能在初始化的时候引用一次，不能变为再引用其他变量
//#include <iostream>
//#include <windows.h>
//using  namespace std;
//int main()
//{
//	//int a = 10;
//	//const int &b = a;
//
//	//int &d = a;
//	//int c = 10;  // 引用只能在初始化的时候引用一次，不能变为再引用其他变量
//	//int &b = c;
//	//cout << "a=" << a << " " << "b=" << b << endl;
//	//cout << "&a=" << &a << " " << "&b=" << &b <<" "<<"&d="<<&d<< endl;//两个变量的地址输出为一样的，所以为同一个变量
//	
//	
//	const int a = 10;  
//	//int &b = a;       //常量具有常属性，只有常引用能引用常量
//	const int &b = 10;
//	double d = 9.987;
//	//int &c = d;     //double类型到int类型时赋值要产生一个临时变量，而c引用的这个临时变量具有常属性
//    const	int &c = d;
//	cout << "d=" << d << endl;
//	cout << "int d=" << (int)d<< endl;
//	system("pause");
//	return 0;
//}

//
//#include <iostream>
//#include <windows.h>
//using namespace std;

//类内定义成员函数
//class people
//{
//public:
//	void display()
//	{
//		cout << "name:" << _name << "->" << "sex:" << _sex << "->" << "age:" << _age << endl;
//	
//	}
//public:
//	char* _name;
//	char* _sex;
//	 int _age;
//
//};


//类外定义成员函数
//class people
//{
//public:
//	void display();  //申明一下成员函数
//public:
//	char* _name;
//	char* _sex;
//	int _age;
//
//};
//void people::display()
//{
//		cout << "name:" << _name << "->" << "sex:" << _sex << "->" << "age:" << _age << endl;
//
//}
//int main()
//{
//	people p;
//	p._name = "szk";
//	p._age = 22;
//	p._sex = "man";
//	p.display();
//	system("pause");
//	return 0;
//
//}
//#include <iostream>
//#include <windows.h>
//using namespace std;
//class Date
//{
//public:
//	void dispaly()  //dispaly(Data this*) 
//		//每个成员函数都有一个this指针，为隐式的（构造函数比较特殊，没有this指针）
////编译器会对成员函数进行处理，在对象调用成员函数时，对象地址做实参传递给成员函数的第一个形参this指针
//// this指针是成员函数隐含指针形参，是编译器⾃⼰处理的，我们不能在成员函
////数的形参中添加this指针的参数定义，也不能在调⽤时显⽰传递对象的地址给
////this指针
//	{
//		//cout << _year << "-" << _month << "-" << _day;
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//	
//public:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d;
//	d._year = 2017;
//	d._month = 2;
//	d._day = 28;
//	d.dispaly();
//	system("pause");
//	return 0;
//}



//#include <iostream>
//#include <windows.h>
//using namespace std;
//class Date     //以class开头，类名为Date
//{
//public:
//	void display(int year,int month,int day);
//	//{
//		//cout << _year << "-" << _month << "-" << _day << endl;
//	
//	//}
//public:  //public private为成员访问限定符     ::作用域限定符
//	int _year;
//	int _month;
//	int _day;
//
//};
//void Date::display(int year, int month, int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main()
//{
//	cout << sizeof(Date) << endl;  //实例化出的对象占⽤实际的物理空间存储类成员变量，定义一个类并没有分配实际的内存空间来存储它
//	Date date;   //  定义了一个对象名date 类是对象的抽象，而对象是类的实例化  系统默认类的成员是私有的
//	                                 // 先要将类实例化成对象才能进行成员函数的访问 
//	date.display(2017, 2, 27);      //对象名.成员函数名
//	Date t, *p;
//	p = &t;       
//	p->display(2018,2,27);         //指针->函数名
//	Date &d = t;
//	d.display(2019, 2, 27);                                //引用传递访问成员函数
//
//	system("pause");
//	return 0;
//}


//#include <iostream>
//#include <windows.h>
//using namespace std;
//class  Complex
//{
//public:
//	Complex(double real = 0, double image = 0)
//		:_real(real)
//		, _image(image);
//	{
//	
//	}
//private:
//	double _image;
//	double _real;
//};
//int main()
//{
//	Complex a;
//	
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <windows.h>
//using namespace std;
//class Complex
//{
//public:
//	Complex(double real=0.0,double image=0.0)  //构造函数
//	{
//		cout << "Complex" << endl;
//		this->_real = real;
//		this->_image = image;
//	}
//	Complex  ( const Complex  &com)   //拷贝构造函数
//	{
//		cout << "Complex(Complex &a)" << endl;
//		if (this != &com)
//		{
//			_real = com._real;
//			_image = com._image;
//		}
//	}
//	Complex  operator+(Complex &a)   //重载运算符"+"
//	{
//		cout << "Complex  operator+(Complex &a) " << endl;
//		Complex tmp;
//		tmp._real = this->_real + a._real;
//		tmp._image = _image + a._image;
//		return tmp;
//	}
//	Complex  operator-(Complex &a)  //重载运算符"-"
//	{
//		Complex tmp;
//		tmp._real = this->_real - a._real;
//		tmp._image = _image - a._image;
//		return tmp;
//	}
//	Complex  operator*(Complex &a)
//	{
//		Complex tmp;
//		tmp._real = this->_real * a._real;
//		tmp._image = _image * a._image;
//		return tmp;
//	}
//	Complex & operator=(Complex &a)   //使用  Complex &作为函数返回值是为了实现连等
//	{
//		cout << "Complex & operator=" << endl;
//		_real =  a._real;
//		_image = a._image;
//		return *this;
//	}
//	~Complex()
//	{
//		cout << "~Complex()" << endl;
//
//	}
//	void display()
//	{
//		cout << _real << "+" <<"("<< _image << ")"<<"i" << endl;
//	}
//private:
//	double _real;
//	double _image;
//};
//int main()
//{
//	Complex c(1.0, 2.0);  //先构造的后析构，后构造的先析构
//	Complex e(0.5, 2.5);
//	Complex a;
//	a=c + e;
//
//	//c.display();
//	//e.display();
//	a.display();
//	//c.display();
//	//Complex d = c;
//	//d.display();
//	//Complex add;
//	//add= d + c; //加
//	//add.display();
//	//Complex sub;
//	//sub= d - e;  //减
//	//sub.display();
//	//Complex  mul;
//	//mul= c*e; //乘法
//	//mul.display();
//	return 0;
//}

//#include <iostream>
//#include <time.h>
//using namespace std;
//class Time
//{
//public:
//	Time()   //构造函数
//	{
//		int i = 0;
//		cout << "Time()" << endl;
//			_hour = 0;
//			_minute = 0;
//			_second = 0;
//	}
//	Time(const Time&t)//传参使用引用是为了防止出现无穷递归
//	{
//		int i = 0;
//		cout << "Time(const Time&t)" << endl;
//			_hour = t._hour;
//			_minute = t._minute;
//			_second = t._second;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//	//const int a = 10;
//	//int arr[a];   错误，a的值是未知的
//public:
//	/*Date(int year, int month, int day,const Time&t)
//	{
//		cout << "Date()-非初始化列表" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//		_t = t;
//	}*/
//	Date(int year, int month, int day,const Time &t)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _t(t)
//	{
//		cout << "Date()-初始化列表" << endl;
//	}
//


//private:
//	int _year;
//	int _month;
//	int _day;
//    Time _t;
//	//const int a = 10;  const数据成员只在某个对象生存期内是常量，
//	//而对于整个类而言却是可变的，因为类可以创建多个不同的对象，不同的对像其const数据成员的值可以不同
//};
//int main()
//{
//	Time t1;
//	Date d1(2017, 3, 2,t1);
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//		Date(int year=2017, int month=3, int day=4) //缺省参数对这个参数指定默认值
//			:_year(year),
//			_month(month),
//			_day(day)
//		{
//			cout << "Date()" << endl;
//		}
//		Date(const Date &d) //拷贝构造函数，加const防止值被修改
//		{
//			cout << "Date(const Date &d)" << endl;
//		}
//		~Date()//析构函数，无参数，无返回值
//		{
//			cout << "~Date()" << endl;
//		}
//
//		void test()
//		{
//			test1(); //非const成员函数内调用非const成员函数时，权限没有变，所以能
//			cout << "ok" << endl;
//		}
//
//		void test1()
//		{
//			display();//非const成员函数内调用const成员函数时，权限被缩小， Date *this变成cons Date *this，所以能
//			cout << "ok" << endl;
//		}
//	
//	
//	
//		//void display()  //隐含的传参void display(Date *this)
//			void display() const //隐含的传参void display(const Date *this)使得函数传过来的参数值不会发生变化
//			 //const修饰this指针所指向的对象时，也就是保证调用这个const成员函数的对象在函数内不会发生改变
//	{
//			//_year = 2018;
//    		//test();  当const成员函数内去调用非const成员函数时，权限被放大，const Date *this变成 Date *this，所以不能
//			cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//		const	Date * operator &()const
//			{
//				return this;
//			}
//
//	private:
//		   int 	_year;
//		   int  _month;
//		   int  _day;
//};
//int main()
//{
//   const	Date d(2017, 3, 5);//const对象可以调⽤const成员函数
//	d.display();
////	d.test();  const对象不可以调⽤⾮const成员函数，因为不能将const Date 转化为Date &
//	Date a(2017, 3, 5);//非const对象可以调⽤const成员函数
//	a.display();
//	const Date *p = &a;
//	cout << &d << endl;
//	a.test(); // 非const对象可以调⽤⾮const成员函数
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Box
//{
//private:
//	int _height;
//	int _width;
//	int _length;
//public:
//	Box(int height,int width,int length)
//	{
//		_height = height;
//		_width = width;
//		this->_length = length;
//	}
//	void V()
//	{
//		cout << _length*_width*_height << endl;;
//	}
//};
//int main()
//{
//	Box box1(2, 3, 4);
//	Box box2(3, 3, 4);
//	box1.V();
//	box2.V();
//	return 0;
//}


//内联函数：以inline修饰的函数以及定义在类内的成员函数。以空间换时间的做法，省去调用函数的额外开销
//#include <iostream>
//using namespace std;
//class DATE
//{
//public:
//	//DATE(int year, int month, int day)//构造函数，参数可有可无
//
//	//DATE(int year=2017, int month=3, int day=5)
////构造函数，给参数赋默认值，叫做缺省参数，赋默认值时不允许只给前面的参数赋值，而不给后面的参数赋值
//
//
////this->_year  错误构造函数没有隐含的this指针形参，因为它是用来创建对象，对像没有建立所以不能用this指针
//
//    DATE(int year = 2017, int month = 3, int day = 5)
//    :_year(year),               //初始化列表初始化：常量成员变量；引用成员变量；没有缺省构造函数的类的成员变量
//	 _month(month),
//	 _day(day)
//	{
//		/*this->_year = year;
//		_month = month;
//		_day = day;*/
//	}
//	DATE(DATE &d)  //拷贝构造函数必须有参数，用已有的对象创建新的对象
//	{
//		this->_year = d._year;
//		this->_month = d._month;
//		this->_day = d._day;
//	}
//	//inline  void  display();
//	friend void display(const DATE &d);
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//  
// void display(const DATE &d)     
////inline是一个用于实现的关键字所以必须与定义放在一起才有作用，不能与申明放在一起
//{
//	cout << d._year << "-" << d._month << "-" << d._day << endl;
//}
//int main()
//{
//	DATE d;
//	display(d);
//	return 0;
//}

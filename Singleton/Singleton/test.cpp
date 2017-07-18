#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
class Lock
{
public:
	explicit Lock(mutex& mtx)  //加锁,加explicit防止被隐式类型转换
		:_mtx(mtx)
	{
		_mtx.lock();
	}
	~Lock()  //解锁
	{
		_mtx.unlock();
	}
private:
	mutex& _mtx;
	Lock(Lock&);
	Lock& operator=(Lock&);
};
class LazySingleton
{
public:
	static LazySingleton* GetInstance();	
protected:
	LazySingleton()   //保证全局只有唯一一个实例,将构造函数声明为私有 
		:_a(0)
	{}
	LazySingleton(LazySingleton&);  //为了更加保险，将拷贝构造和赋值运算符的重载也设置为防拷贝
	LazySingleton& operator=(LazySingleton&);
private:
	int _a;
    static LazySingleton* _inst;  //静态成员变量需在类内声明,类外初始化,作为唯一实例的指针
};


LazySingleton* LazySingleton::_inst = NULL;

LazySingleton* LazySingleton::GetInstance()
{
	//为了实现线程安全，需要在这个地方加锁,采用RAII的方式封装锁
	mutex mtx;
	Lock a(mtx);
	if (_inst == NULL)
		_inst = new LazySingleton;
	return _inst;
}

 class EagerSingleton 
 {

 public:
	 static EagerSingleton* getInstence()
	 {
		 return _inst;
	 }

 private:
	 EagerSingleton()
		 :_a(0)
	 {}
	 static EagerSingleton* _inst;
	 int _a;
 };
 EagerSingleton*  EagerSingleton::_inst = new EagerSingleton();


 void Swap(int *a, int *b)
 {
	 int c;
	 c = *a;
	 *a = *b;
	 *b = c;
 }

 int main(void)
 {
	 int a;
	 int b;
	 int ret;
	 a = 16;
	 b = 64;
	 ret = 0;
	 Swap(&a, &b);
	 ret = a - b;
	 return ret;
 }
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
class Lock
{
public:
	explicit Lock(mutex& mtx)  //����,��explicit��ֹ����ʽ����ת��
		:_mtx(mtx)
	{
		_mtx.lock();
	}
	~Lock()  //����
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
	LazySingleton()   //��֤ȫ��ֻ��Ψһһ��ʵ��,�����캯������Ϊ˽�� 
		:_a(0)
	{}
	LazySingleton(LazySingleton&);  //Ϊ�˸��ӱ��գ�����������͸�ֵ�����������Ҳ����Ϊ������
	LazySingleton& operator=(LazySingleton&);
private:
	int _a;
    static LazySingleton* _inst;  //��̬��Ա����������������,�����ʼ��,��ΪΨһʵ����ָ��
};


LazySingleton* LazySingleton::_inst = NULL;

LazySingleton* LazySingleton::GetInstance()
{
	//Ϊ��ʵ���̰߳�ȫ����Ҫ������ط�����,����RAII�ķ�ʽ��װ��
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
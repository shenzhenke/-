//#define _CRT_SECURE_NO_WARNINGS 
////����ʱ�临�ӶȺͿռ临�Ӷ�
#include <iostream>
using namespace std;
//����쳲��������е��������ֵ
//0 1 1 2 3 5
int Fib(int n)
{
	//if (n < 1)
	//{
	//	return 0;
	//}
	//else if (n < 2)
	//{
	//	return 1;
	//}
	//else
	//{
	//	return Fib(n - 1) + Fib(n - 2);
	//}

	return n < 2 ? n : Fib(n - 1) + Fib(n - 2);
}
//쳲��������еĵݹ�ʵ��ʱ�临�Ӷ�ΪO(2^N)�ռ临�Ӷ�ΪO(N)

int main()
{
	//��쳲��������е�ÿһ���ֵʱ�临�Ӷ�ΪO(2^N)
	const int N = 10;
	int arr[N + 1];
	for (size_t i = 0; i < N + 1; i++)
	{
		arr[i] = Fib(i);
		cout << arr[i] << " " ;
	}
	cout << endl;
	return 0;
}
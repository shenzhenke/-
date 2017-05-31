//#define _CRT_SECURE_NO_WARNINGS 
////计算时间复杂度和空间复杂度
#include <iostream>
using namespace std;
//计算斐波那契数列的所有项的值
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
//斐波那契数列的递归实现时间复杂度为O(2^N)空间复杂度为O(N)

int main()
{
	//求斐波那契数列的每一项的值时间复杂度为O(2^N)
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
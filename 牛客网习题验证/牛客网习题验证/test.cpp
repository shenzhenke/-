#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//#include <windows.h>
//int main()
//{
//	//int K, 
// //    *p=&K;  //��������͵�����k�����͵�*p��pֻ��һ��ָ�룬����һ��k�ĵ�ַ���ݣ�����ָ��k��
//	//scanf("%d", p);
//	//char s[] = "123", *p;
//	//p = s;
//	//printf("%c\n",*p++);   //1
//	/*int a = 1;
//	int b = 0;
//	int c = 0;
//	if (a > b > c)
//	{
//		printf("qwr");
//	}*/
//	//int(*p)(void);
//	system("pause");
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string a = "hello world";  //0x00f3fe54
//	string b = a;    //0x00f3fe30
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//	string c = b;
//	c = "";
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//	a = "";
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//	return 0;
//}





//
////���������ж��ٸ�����ͬ�Ķ�����λ
//#include<iostream>
//using namespace std;
//int countBitDiff(int m, int n)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((m & (1 << i)) != (n & (1 << i)))
//			count++;
//	}
//	return count;
//}
//
//int main()
//{
//	cout << countBitDiff(1999, 2299) << endl;
//	return 0;
//}


//��ά�����ӡ����
//#include <iostream>
//#include <vector>
//using  namespace std;
//vector<int> arrayPrint(vector<vector<int> > arr, int n)
//{
//	vector<int> array;
//	int i = 0;
//	int j = n - 1;
//	for (int k = 0; k < n; k++)
//	{
//		i = 0;
//		j = n - k - 1;
//		array.push_back(arr[i][j]);
//		while ((++i) < n && (++j) < n)
//		{
//			array.push_back(arr[i][j]);
//		}
//	}
//	for (int k = 0; k < n - 1; k++)
//	{
//		i = k + 1;
//		j = 0;
//		array.push_back(arr[i][j]);
//		while ((++i) < n && (++j) < n)
//		{
//			array.push_back(arr[i][j]);
//		}
//	}
//	return  array;
//}
//int main()
//{ 
//	vector<vector<int> > vecInt(4, vector<int>(4));
//	int a[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
//	for (int i = 0; i < 4; i++)    //��ʼ����ά���飬����ʵ������Բ��ó�ʼ���ģ�vector��Ĭ�ϳ�ʼ��Ϊ0  
//	for (int j = 0; j < 4; j++)
//		vecInt[i][j] = a[i][j];
//	vector<int> arr = arrayPrint(vecInt, 4);
//	for (int i = 0; i < 16; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}



//���ֱ��ͼ����
//��һ��ֱ��ͼ����һ�����������ʾ������ÿ�еĿ��Ϊ1��������ֱ��ͼ�����������������
//���磬����ֱ��ͼ[2, 7, 9, 4], ���������������ε����Ϊ14(��[7, 9]������7x2�ľ���)��
//����һ��ֱ��ͼA�������ܿ��n���뷵���������������ֱ֤��ͼ���С�ڵ���500����֤�����int��Χ��

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int countArea(vector<int> A, int n)
//{
//	sort(A.begin(), A.end());
//	int Size = n;
//	for (int i = 0; i < n; i++)
//	{
//		A[i] = A[i] * Size;
//		Size--;
//	}
//	sort(A.begin(), A.end());
//	return A[n - 1];
//}
//int main()
//{
//	vector<int> A;
//	A.push_back(9);
//	A.push_back(8);
//	A.push_back(9);
//	A.push_back(4);
//	cout << countArea(A, 4) << endl;
//	return 0;
//}



//��Ŀ����
//����һ���������飬����ͨ�����ö��ֲ��ҵķ�ʽ����λĳһԪ�أ����д���ֲ��ҵ��㷨��
//�������в���ָ��Ԫ�ء�����һ����������A�����Ĵ�Сn��ͬʱ����Ҫ���ҵ�Ԫ��val��
//�뷵�����������е�λ��(��0��ʼ)���������ڸ�Ԫ�أ����� - 1������Ԫ�س��ֶ�Σ�
//�뷵�ص�һ�γ��ֵ�λ�á�

//#include <iostream>
//#include <assert.h>
//#include <vector>
//using namespace std;
//int getPos(vector<int> A, int n, int val)
//{
//	assert(n > 0);
//	int left = 0;
//	int right = n;
//	int mark = -1;
//	while (left < right)
//	{
//		int mid = (left >> 1) + (right >> 1);
//		if (val > A[mid])
//		{
//			left = mid + 1;
//		}
//		else if (val < A[mid])
//		{
//			right = mid ;
//		}
//		else
//		{
//			mark = mid;
//			if (mid % 2 != 0)
//			{
//				right = mid;
//				left = 0;
//			}
//			else
//			{
//				right = mid - 1;
//				left = 0;
//			}
//		}
//	}
//	return mark;
//}
//int main()
//{
//	vector<int> A;
//	A.push_back(1);
//	A.push_back(3);
//	//A.push_back(9);
//	A.push_back(5);
//	A.push_back(7);
//	A.push_back(9);
//	A.push_back(9);
//	A.push_back(11);
//	//A.push_back(13);
//
//	cout << getPos(A, 7, 1) << endl;
//	cout << getPos(A, 7, 3) << endl;
//	cout << getPos(A, 7, 5) << endl;
//	cout << getPos(A, 7, 7) << endl;
//	cout << getPos(A, 7, 9) << endl;
//	cout << getPos(A, 7, 11) << endl;
//	cout << getPos(A, 7, 13) << endl;
//
//	/*cout << getPos(A, 8, 1) << endl;
//	cout << getPos(A, 8, 3) << endl;
//	cout << getPos(A, 8, 5) << endl;
//	cout << getPos(A, 8, 7) << endl;
//	cout << getPos(A, 8, 9) << endl;
//	cout << getPos(A, 8, 11) << endl;
//	cout << getPos(A, 8, 13) << endl;*/
//	return 0;
//}




//��Ŀ����
//����һ���ַ����������һ����Ч�㷨���ҵ���һ���ظ����ֵ��ַ���
//����һ���ַ���(��һ��ȫΪ��ĸ)A�����ĳ���n���뷵�ص�һ���ظ����ֵ��ַ���
//��֤�ַ��������ظ��ַ����ַ����ĳ���С�ڵ���500
//#include <iostream>
//#include <assert.h>
//#include <vector>
//#include <map>
//using namespace std;
//char findfirstrepeat(string a, int n)
//{
//	assert(n > 1 && n <= 500);
//	map<char, int> t;
//	for (int i = 0; i < n; i++)
//	{
//		if (t.insert(pair<char, int>(a[i], 1)).second == 0)
//			return a[i];
//	}
//	/*int num = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = num + 1; j < n ; j++)
//		{
//			if (a[i] == a[j])
//				return a[i];
//		}
//		num++;
//	}*/
//	return -1;
//}
//int main()
//{
//	string s = "012340dbcdd";
//	int n = s.size();
//	cout << findfirstrepeat(s, n) << endl;
//	return 0;
//


#include <stdio.h>
int main()
{
	int i = 0;
	int arr[100] = { 0 };    //����һ�����������ÿ��������������
	for (i = 2; i <= 1000; i++)
	{
		int m = 0;
		int k = 0;
		int j = 0;
		int sum = 0;
		for (m = 1; m < i; m++)//�˴�������<=;���������Ӳ��ܰ���������
		{
			if (i%m == 0)    //�ҳ�i����������֮�����������
			{
				arr[k] = m;  //���ҵ������Ӵ����������
				k++;       //��k��ֵ���ж�i���ж��ٸ�����
			}

		}
		for (j = 0; j < k; j++)
			//�˴�������<=;��Ϊ������±��0��ʼ,���Ҵ�����ӵ�ʱ��Ҳ��a[0]��ʼ���
		{
			sum = arr[j] + sum;   //��sum����ʾ����������ӵĺ�
		}
		if (sum == i) //�������֮�͵���i,��i��ӡ����.
		{
			for (int m = 0; m < k; m ++)
			{
				if (m == 0)
					printf("%d", arr[m]);
				else
					printf("+%d", arr[m]);
			}
			printf("=%d\n", i);
		}
	}
	return 0;
}
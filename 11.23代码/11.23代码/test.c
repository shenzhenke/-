#define _CRT_SECURE_NO_WARNINGS
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��

//#include <stdio.h>
//int main()
//{
//	int a = 1999;
//	int b = 2299;
//	int i = 0;
//	int k = 0;
//	int count = 0;  // ����ͳ�ƶ�����λ����ͬ�ĸ���
//	for (i = 0; i < 32; i++)
//	{
//		k = ((a >> i)&1) ^ ((b >> i)&1); //^��λ���,��ͬ����,�����һ,&��λ��ͬһ��һ,�������
//		if (1 == k)
//		{
//			count++;
//		}
//	}
//	printf("%d\n",count);
//	return 0;
//}

//unsigned int  reverse_bit(unsigned int value);
//��������ķ��� ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832

//#include <stdio.h>
//#include <math.h>
//double  reverse_bit(unsigned int value)
//{
//	int i = 0;
//	double sum = 0;
//	int k = 0;
//	for (i = 0; i < 32; i++)
//	{
//		k=(value >> i) & 1;
//		sum = sum + k*pow(2,31-i);
//	}
//	return sum;
//}
//int main()
//{
//	unsigned int value = 25;
//	double ret = reverse_bit(value);
//    printf("%lf\n",ret);
//	return 0;
//}

//
//4.
//һ��������ֻ��һ�����ֳ�����һ�Ρ�
//�����������ֶ��ǳɶԳ��ֵġ����ҳ�������֡���ʹ��λ���㣩
//�磺
//���ݣ�1 3 5 7 1 3 5 8���������У�ֻ��7������һ�Ρ�
//�ṹ���ҵ��������ǣ�7.

//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1, 3, 5, 7, 1, 3, 5 };
//	int i = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	int j = 0;
//	int m = 0;
//	for (k = 0; k < i; k++)
//	{
//		for (j = 0; j < i ; j++)
//		{
//			if ((0 == (arr[k] ^ arr[j])) && (k != j))
//			{
//				m = 1;
//				break;
//			}
//			m = 0;
//		}
//		if (0 == m)
//		{
//			printf("%d\n", arr[k]);
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//
//	int arr[] = { 1, 3, 5, 7, 1, 3, 5 };
//	int i = 0;
//	int k = sizeof(arr) / sizeof(arr[0]);
//	for (i = 1; i < k; i++)
//	{
//		arr[0] = arr[0] ^ arr[i];
//		//����������������ȡ��λ����������Ϊ1����ͬΪ0����λ����ʣ��Ϊ1�ľ��ǵ���
//	}
//	printf("��������ǣ�%d\n", arr[0]);
//	return 0;
//}
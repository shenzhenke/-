#define _CRT_SECURE_NO_WARNINGS 

//��1000�굽2000��֮������ĸ���
//#include <stdio.h>
//int main()
//{
//	int year;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (year % 4 == 0)
//		{
//			if (year % 100 != 0)
//			{
//				printf("%d ", year);
//				count++;
//			}
//			if (year % 400 == 0)
//			{
//				printf("%d ", year);
//				count++;
//			}
//		}
//	}
//	printf("\n���������Ϊ��");
//	printf("\n%d", count);
////	return 0;
////}
//
//
////# include <stdio.h>
//
////int main()
////{ 
////	printf("����������������");
////	int a, b, c;
////	scanf("d% d%", &a, &b);
////	return 0; 
////}


//�ж�1000-2000��֮����һ��������
//#include <stdio.h>
//#include<string.h>
//int main()
//{
//	int a, b;
//	printf("������������:\n");
//	scanf_s("%d %d", &a , &b);
//	//if (year >= 1000 && year <= 2000)//����ݵ��ж�������1000-2000֮��.
//	//{
//	//	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))//����Ϊ�ܱ�400���������ܱ�4�����Ҳ��ܱ�100���������.
//	//		printf("��\n");
//	//	else
//	//		printf("����\n");
//	//}
//	//else
//	//	printf("���������Ϊ1000��2000������\n");
//	return 0;
//}





//��������,��������ʱ����
//#include <stdio.h>
//int main()
//{
//	int a = 3, b = 4;
//	printf("a=%d b=%d\n", a, b);
//	a = a^b;
//	b = a^b;
//	a = a^b;
//	printf("a=%d b=%d", a, b);
//	return 0;
//}




//ͳ��ĳһ�����ݶ����Ʊ�ʾ�б���λΪ1��λ��
//#include <stdio.h>
//int main()
//  {
//	int count;
//	count = count_one_bits(count);
//	printf("%d", count);
//        return 0;
//        
//   }
//int  count_one_bits(unsigned int value)
//{
//	int count = 0;
//	printf("������һ��������\n");
//	scanf_s("%d", &value);
//	while (value != 0)
//	{
//		if (value % 2 == 1)
//		{
//			count++;
//		}
//		value = value / 2;
//	}
//	return  count;
//}


//#include <stdio.h> 
//int count_one_bits(unsigned int value) 
//{   
//	   int count =0; 
//     while(value!=0) 
//  {    
//		 if(value%2==1) 
//    { 
//		 count++;
//	 } 
//      value=value/2; 
//   } 
//     return count; 
//}
//int main()
//{
//	unsigned int num = 0;
//	int ret = 0;
//	scanf_s("%d", &num);
//	ret = count_one_bits(num);
//	printf("count=%d\n", ret);
//	return 0;
//}
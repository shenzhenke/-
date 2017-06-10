
#define _CRT_SECURE_NO_WARNINGS 
#include "SeqList.h"
void menu()
{
	printf("**********************************************************\n");
	printf("****1.PushBack          2.PopBack    *********************\n");
	printf("****3.PushFront         4.PopFront   *********************\n");
	printf("****5.Find              6.Remove     *********************\n");
	printf("****7.RemoveAll         8.Show       *********************\n");
	printf("****9.Sort             10.BinarySearch     ***************\n");
	printf("*****           0.Exit                       *************\n");
	printf("**********************************************************\n");
}
int main()
{
	SeqList *myseqlist = NULL;
	int input = 0;
	menu();
	printf("«Î ‰»Îƒ„µƒ—°‘Ò£∫\n");
	scanf("%d", &input);
	do
	{
		switch (input)
		{
		case 1:
			PushBack(myseqlist, 4);
			break;
		case 2:
			PopBack(myseqlist);
			break;
		case 3:
			PushFront(myseqlist, 2);
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
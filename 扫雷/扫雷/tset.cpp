#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
enum
{
	EXIT, /*ö��Ԫ�ر�����ϵͳ������һ����ʾ��ŵ���ֵ����0��ʼ˳����Ϊ0��1��2����EXIT��ֵΪ0,PLAY��ֵΪ1*/
	PLAY
};
void menu()
{
	printf("�������������������\n");
	printf("������    1.PLAY      ������\n");
	printf("������    0.EXIT      ������\n");
	printf("�������������������\n");
}
void game()
{
	int ret = 0;
	int k = 0;   //�����ж�����Ƿ������׵�����
	int board1[ROWS][COLS] = { 0 };   //��һ��������Ϊ����׵�����
	int board2[ROWS][COLS] = { 0 };   //�ڶ���������Ϊͳ���׵�����
	Init_Interface(board1, board2, ROWS, COLS);  //��ʼ��ɨ������
	while (1)
	{
		int ret1 = play_move(board1, board2, ROWS, COLS);   //�����������
		{
			if (ret1 == -1)
			{
				printf("\n���׳ɹ�,��������.\n");
				sweep_board(board1, ROWS, COLS); //��ӡ��������
				break;
			}
			display_board(board2, ROWS, COLS);
			//���׹���
			k = 0;
			printf("��������������\n");
			printf("���� ����0: ����  ����\n");
			printf("���� ����1: �����ס���\n");
			printf("��������������\n");
			printf("��ѡ��\n");
			while (k == 0)
			{
				scanf("%d", &k);
				switch (k)      //�ж��Ƿ���Ҫ����
				{
				case 0:
					pai_lei(board1, board2, ROWS, COLS);
					break;
				case 1:
					break;
				default:
					k = 0;
					printf("�������\n");
					break;
				}
				if (k == 0)
				{
					printf("��ѡ���Ƿ�������ף�");
				}
			}
			//����
			int ret2 = win(board2, ROWS, COLS);
			{
				if (ret2 == sweep)  //���ص�ֵΪ�׵ĸ�����ɹ�
				{
					printf("��ϲɨ�׳ɹ�.\n");
					sweep_board(board1, ROWS, COLS); //��ӡ��������
					break;
				}
				else
				{
					printf("���Ѿ��ɹ���ɨ��%d����\n", ret2);
				}
			}
			int ret3 = error_sweep(board2, ROWS, COLS);    //�ж�ɨ���׵ĸ���
			{
				printf("���Ѿ������ɨ��%d����\n", ret3);
			}
			int ret4 = check_sweep(board2, ROWS, COLS);   //��������Ƿ�����
			if (ret4 == 1)
			{
				printf("û�ܳɹ��ҳ����е���,���ź�");
				break;
			}
		}
		display_board(board2, ROWS, COLS);
	}

}
int main()
{
	int  input = 0;
	do
	{
		menu();
		printf("���������ѡ��");
		scanf("%d", &input);  //
		switch (input)
		{
		case PLAY:
			game();
			break;
		case  EXIT:
			break;
		default:
			printf("������������,����������.\n");
			break;
		}
	} while (input);
	return 0;
}
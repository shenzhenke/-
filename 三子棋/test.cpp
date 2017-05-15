#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
void menu()   //��ӡ�˵�
{
	printf("��������������\n");
	printf("����    1.PLAY    ����\n");
	printf("����    0.EXIT    ����\n");
	printf("��������������\n");
}
enum Option
{
	EXIT,
	PLAY
};
void game()
{
	int k = 0;
	int execut = 0;
	int board[ROWS][COLS];
	printf("��������������\n");
	printf("����    0.��    ����\n");
	printf("����    1.�е�    ����\n");
	printf("����    2.����    ����\n");
	printf("��������������\n");
	printf("��ѡ����Ϸģʽ��\n");
	while (1)
	{
		scanf("%d", &k);
		if ((k != 0) && (k != 1) && (k != 2))
		{
			printf("�������,����������.");
		}
		else
		{
			break;
		}
	}
	int ret = 0;
	Init_chessboard(board, ROWS, COLS);   //��ʼ������
	while (1)
	{
		Play_move_chess(board, ROWS, COLS); //������� 
		Display_chessboard(board, ROWS, COLS);  //��������
		ret = Check_win(board, ROWS, COLS);   //�ж���Ӯ
		if (0 == ret)
		{
			printf("��ϲ��Ӯ��.\n");
			break;
		}
		ret = Check_win(board, ROWS, COLS);  //�ж������Ƿ�����
		if (3 == ret)
		{
			printf("������.\n");
			break;
		}
		switch (k)
		{
		case 0:
			Computer_move_chess(board, ROWS, COLS); //�����Զ�����
			break;
		case 1:
			Computer_more_think_move_chess(board, ROWS, COLS);
			break;
		case 2:
			execut = Computer_think_move_chess(board, ROWS, COLS);
			if (0 == execut)
				Computer_more_think_move_chess(board, ROWS, COLS);
			break;
		}
		printf("������֮������̣�\n");
		Display_chessboard(board, ROWS, COLS);  //��������
		Check_win(board, ROWS, COLS);   //�ж���Ӯ
		ret = Check_win(board, ROWS, COLS);
		if (1 == ret)
		{
			printf("���ź�,������.\n");
			break;
		}
	}
}
int main()
{
	int input;
	do   //do...whlieѭ����֤���ٴ�ӡ�˵�һ��
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case PLAY:
			game();
			break;
		case EXIT:
			break;
		default:
			printf("������������,����������.\n");
			break;
		}
	} while (input);
	return 0;
}
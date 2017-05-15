#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void  Init_chessboard(int board[ROWS][COLS], int rows, int cols)//��ʼ������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = ' ';
		}
	}
	/*memset(board, ' ', sizeof(char)*rows*cols);*/
	for (i = 0; i < rows; i++)
	{
		if (0 == i)
		{
			printf("_____________\n");
		}
		printf("|");
		for (j = 0; j < cols; j++)
		{

			printf(" %c |", board[i][j]);

		}
		printf("\n");
		printf("|___|___|___|\n");
	}
}

void  Play_move_chess(int board[ROWS][COLS], int rows, int cols) //�������
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("���������꣺");
		scanf("%d%d", &x, &y);
		x--;   //��Ϊ������±���㿪ʼ,��������������±��ȥ1
		y--;
		if ((x >= 0) && (x <= rows - 1) && (y >= 0) && (y <= cols - 1) && (board[x][y] == ' '))  //��֤��������겻Խ����û��ռ��
		{
			board[x][y] = 0;
			break;
		}
		else
		{
			printf("������������,����������.\n");
		}
	}
}




void  Computer_move_chess(int board[ROWS][COLS], int rows, int cols) //��������
{
	int x = 0;
	int y = 0;
	srand((unsigned int)time(NULL));
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = 1;
			break;
		}
	}
}


void  Display_chessboard(int board[ROWS][COLS], int rows, int cols)  //��������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		if (0 == i)
		{
			printf("_____________\n");
		}
		printf("|");
		for (j = 0; j < cols; j++)
		{
			if (board[i][j] == ' ')
			{
				printf(" %c |", board[i][j]);
			}
			else
			{
				printf(" %d |", board[i][j]);
			}

		}
		printf("\n");
		printf("|___|___|___|\n");
	}
}

int   Check_win(int board[ROWS][COLS], int rows, int cols)  //�ж���Ӯ
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))  //ÿһ�����
		{
			if (0 == board[i][0])
			{
				return 0;
			}
			if (1 == board[i][0])
			{
				return 1;
			}
		}
	}
	for (j = 0; j < cols; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]))  //ÿһ�����
		{
			if (0 == board[0][j])
			{
				return 0;
			}
			if (1 == board[0][j])
			{
				return 1;
			}
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))  //���Խ���һ��
	{
		if (0 == board[1][1])
		{
			return 0;
		}
		if (1 == board[1][1])
		{
			return 1;
		}
	}
	if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
	{
		if (0 == board[1][1])
		{
			return 0;
		}
		if (1 == board[1][1])
		{
			return 1;
		}
	}
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (board[i][j] == ' ')
			{
				return -1;
			}
		}
	}
	return 3;
}


int Computer_think_move_chess(int board[ROWS][COLS], int rows, int cols) ////����������������ʱ��������Ӯ
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		if ((board[i][0] + board[i][1] + board[i][2]) == (2 + ' '))  //ÿһ��������Ԫ�����
		{
			for (j = 0; j < cols; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = 1;
					return 1;
				}
			}
		}
	}
	for (j = 0; j < cols; j++)
	{
		if (board[0][j] + board[1][j] + board[2][j] == (2 + ' '))  //ÿһ�����
		{
			for (i = 0; i < cols; i++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = 1;
					return 1;
				}
			}
		}
	}
	if (board[0][0] + board[1][1] + board[2][2] == (2 + ' '))  //���Խ���һ��
	{
		for (i = 0; i < rows; i++)
		{
			if (board[i][i] == ' ')
			{
				{
					board[i][i] = 1;
					return 1;
				}
			}
		}
	}
	if (board[0][2] + board[1][1] + board[2][0] == (2 + ' '))
	{
		if (board[0][2] == ' ')
		{
			board[0][2] = 1;
			return 1;
		}
		if (board[1][1] == ' ')
		{
			board[1][1] = 1;
			return 1;
		}
		if (board[2][0] == ' ')
		{
			board[2][0] = 1;
			return 1;
		}
	}
	return 0;
}


void  Computer_more_think_move_chess(int board[ROWS][COLS], int rows, int cols)  //�����ܹ����������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		if ((board[i][0] + board[i][1] + board[i][2]) == (0 + ' '))  //ÿһ��������Ԫ�����
		{
			for (j = 0; j < cols; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = 1;
					return;
				}
			}
		}
	}
	for (j = 0; j < cols; j++)
	{
		if (board[0][j] + board[1][j] + board[2][j] == (0 + ' '))  //ÿһ�����
		{
			for (i = 0; i < cols; i++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = 1;
					return;
				}
			}
		}
	}
	if (board[0][0] + board[1][1] + board[2][2] == (0 + ' '))  //���Խ���һ��
	{
		for (i = 0; i < rows; i++)
		{
			if (board[i][i] == ' ')
			{
				{
					board[i][i] = 1;
					return;
				}
			}
		}
	}
	else if (board[0][2] + board[1][1] + board[2][0] == (0 + ' '))
	{
		if (board[0][2] == ' ')
		{
			{
				board[0][2] = 1;
				return;
			}
		}
		if (board[1][1] == ' ')
		{
			{
				board[1][1] = 1;
				return;
			}
		}
		if (board[2][0] == ' ')
		{
			{
				board[2][0] = 1;
				return;
			}
		}
	}
	else
	{
		srand((unsigned int)time(NULL));
		while (1)
		{
			i = rand() % 3;
			j = rand() % 3;
			if (board[i][j] == ' ')
			{
				board[i][j] = 1;
				return;
			}
		}
	}
}
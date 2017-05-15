#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void  Init_chessboard(int board[ROWS][COLS], int rows, int cols)//初始化棋盘
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

void  Play_move_chess(int board[ROWS][COLS], int rows, int cols) //玩家走棋
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		x--;   //因为数组的下标从零开始,所以让它输入的下标减去1
		y--;
		if ((x >= 0) && (x <= rows - 1) && (y >= 0) && (y <= cols - 1) && (board[x][y] == ' '))  //保证输入的坐标不越界且没被占用
		{
			board[x][y] = 0;
			break;
		}
		else
		{
			printf("您的输入有误,请重新输入.\n");
		}
	}
}




void  Computer_move_chess(int board[ROWS][COLS], int rows, int cols) //电脑走棋
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


void  Display_chessboard(int board[ROWS][COLS], int rows, int cols)  //更新棋盘
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

int   Check_win(int board[ROWS][COLS], int rows, int cols)  //判断输赢
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))  //每一行相等
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
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]))  //每一列相等
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
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))  //主对角线一样
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


int Computer_think_move_chess(int board[ROWS][COLS], int rows, int cols) ////电脑在有两个连线时候走棋能赢
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		if ((board[i][0] + board[i][1] + board[i][2]) == (2 + ' '))  //每一行有两个元素相等
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
		if (board[0][j] + board[1][j] + board[2][j] == (2 + ' '))  //每一列相等
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
	if (board[0][0] + board[1][1] + board[2][2] == (2 + ' '))  //主对角线一样
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


void  Computer_more_think_move_chess(int board[ROWS][COLS], int rows, int cols)  //电脑能够堵玩家棋子
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		if ((board[i][0] + board[i][1] + board[i][2]) == (0 + ' '))  //每一行有两个元素相等
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
		if (board[0][j] + board[1][j] + board[2][j] == (0 + ' '))  //每一列相等
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
	if (board[0][0] + board[1][1] + board[2][2] == (0 + ' '))  //主对角线一样
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
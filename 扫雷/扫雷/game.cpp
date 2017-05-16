#include <stdio.h>
#include "game.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

void Init_Interface(int board1[ROWS][COLS], int board2[ROWS][COLS], int rows, int cols)  //��ʼ��ɨ������,�Լ���������0��������,1��������
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int count = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board1[i][j] = 0;
		}
	}
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board2[i][j] = '*';
		}
	}
	srand((unsigned int)time(NULL));
	while (count != sweep)   //����20����
	{
		int x = rand() % 10 + 2;
		int y = rand() % 10 + 2;
		if (board1[x][y] == 0)
		{
			count++;
			board1[x][y] = 1;
		}
	}
	//��ʼ������
	printf("     1   2   3   4   5   6   7   8   9  10  \n");
	printf("   _________________________________________\n");
	for (i = 2; i < rows - 2; i++)
	{
		if (i > 10)
		{
			printf("%d |   |", i - 1);
		}
		else if (i <= 10)
		{
			printf("%d  |   |", i - 1);
		}
		for (j = 3; j < cols - 2; j++)
		{
			printf("   |");
		}
		printf("\n");
		printf("   | %c |", board2[i][2]);
		for (j = 3; j < cols - 2; j++)
		{
			printf(" %c |", board2[i][j]);
		}
		printf("\n");
		printf("   |___|");
		for (j = 3; j < cols - 2; j++)
		{
			printf("___|");
		}
		printf("\n");
	}


}

void  display_board(int board2[ROWS][COLS], int rows, int cols) //��ӡɨ������
{
	int i = 0;
	int j = 0;
	printf("     1   2   3   4   5   6   7   8   9  10  \n");
	printf("   _________________________________________\n");
	for (i = 2; i < rows - 2; i++)
	{
		if (i > 10)
		{
			printf("%d |   |", i - 1);
		}
		else if (i <= 10)
		{
			printf("%d  |   |", i - 1);
		}
		for (j = 3; j < cols - 2; j++)
		{
			printf("   |");
		}
		printf("\n");
		if ((board2[i][2] == '*') || (board2[i][2] == 'Y') || (board2[i][2] == 'N'))
		{
			printf("   | %c |", board2[i][2]);
		}
		if ((board2[i][2] != '*') && (board2[i][2] != 'Y') && (board2[i][2] != 'N'))
		{
			printf("   | %d |", board2[i][2]);
		}
		for (j = 3; j < cols - 2; j++)
		{
			if ((board2[i][j] == '*') || (board2[i][j] == 'Y') || (board2[i][j] == 'N'))
				printf(" %c |", board2[i][j]);
			if (((board2[i][j] != '*') && (board2[i][j] != 'Y')) && (board2[i][j] != 'N'))
				printf(" %d |", board2[i][j]);
		}
		printf("\n");
		printf("   |___|");
		for (j = 3; j < cols - 2; j++)
		{
			printf("___|");
		}
		printf("\n");
	}
}




int   play_move(int board1[ROWS][COLS], int board2[ROWS][COLS], int rows, int cols)    //�����������
{
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	int static  first_move = 0;    //����һ����̬����,�ж�first_move�ǲ��ǵ�һ������
	int count = 0;
	printf("���������꣺");
	while (1)
	{
		scanf("%d%d", &x, &y);
		x++;
		y++;
		if ((x >= 2) && (x <= rows - 3) && (y >= 2) && (y <= cols - 3))
		{
			first_move++;
			if (1 == first_move)
			{
				if (board1[x][y] == 1)   //��һ������,��ת��
				{
					for (i = 2; i < rows - 2; i++)
					{
						for (j = 2; j < cols - 2; j++)
						{
							if (board1[i][j] == 0)
							{
								board1[i][j] = 1;
								board1[x][y] = 0;
								break;
							}
						}
						break;
					}
				}
				//ͳ�Ƶ�һ����Χ�׵����
				count = board1[x - 1][y] + board1[x - 1][y + 1] + board1[x - 1][y - 1]
					+ board1[x + 1][y] + board1[x + 1][y + 1] + board1[x + 1][y - 1]
					+ board1[x][y + 1] + board1[x][y - 1];
				board2[x][y] = count;
				if (board1[x][y - 1] != 1)
				{
					count = 0;
					count = board1[x - 1][y - 1] + board1[x - 1][y] + board1[x - 1][y - 2]
						+ board1[x + 1][y - 1] + board1[x + 1][y] + board1[x + 1][y - 2]
						+ board1[x][y] + board1[x][y - 2];
					board2[x][y - 1] = count;
				}
				if (board1[x][y + 1] != 1)
				{
					count = 0;
					count = board1[x - 1][y + 1] + board1[x - 1][y + 2] + board1[x - 1][y]
						+ board1[x + 1][y + 1] + board1[x + 1][y + 2] + board1[x + 1][y]
						+ board1[x][y + 2] + board1[x][y];
					board2[x][y + 1] = count;
				}
				if (board1[x + 1][y] != 1)
				{
					count = 0;
					count = board1[x][y] + board1[x][y + 1] + board1[x][y - 1]
						+ board1[x + 2][y] + board1[x + 2][y + 1] + board1[x + 2][y - 1]
						+ board1[x + 1][y + 1] + board1[x + 1][y - 1];
					board2[x + 1][y] = count;
				}
				if (board1[x - 1][y] != 1)
				{
					count = 0;
					count = board1[x - 2][y] + board1[x - 2][y + 1] + board1[x - 2][y - 1]
						+ board1[x][y] + board1[x][y + 1] + board1[x][y - 1]
						+ board1[x - 1][y + 1] + board1[x - 1][y - 1];
					board2[x - 1][y] = count;
				}
				if (board1[x + 1][y - 1] != 1)
				{
					count = 0;
					count = board1[x][y - 1] + board1[x][y] + board1[x][y - 2]
						+ board1[x + 2][y - 1] + board1[x + 2][y] + board1[x + 2][y - 2]
						+ board1[x + 1][y] + board1[x + 1][y - 2];
					board2[x + 1][y - 1] = count;
				}
				if (board1[x - 1][y - 1] != 1)
				{
					count = 0;
					count = board1[x - 2][y - 1] + board1[x - 2][y] + board1[x - 2][y - 2]
						+ board1[x][y - 1] + board1[x][y] + board1[x][y - 2]
						+ board1[x - 1][y] + board1[x - 1][y - 2];
					board2[x - 1][y - 1] = count;
				}
				if (board1[x - 1][y + 1] != 1)
				{
					count = 0;
					count = board1[x - 2][y + 1] + board1[x - 2][y + 2] + board1[x - 2][y]
						+ board1[x][y + 1] + board1[x][y + 2] + board1[x - 2][y]
						+ board1[x - 1][y + 2] + board1[x - 1][y];
					board2[x - 1][y + 1] = count;
				}
				if (board1[x + 1][y + 1] != 1)
				{
					count = 0;
					count = board1[x][y + 1] + board1[x][y + 2] + board1[x][y]
						+ board1[x + 2][y + 1] + board1[x + 2][y + 2] + board1[x + 2][y]
						+ board1[x + 1][y + 2] + board1[x + 1][y];
					board2[x + 1][y + 1] = count;
				}
				return -2;
			}
			if (board2[x][y] == '*')
			{
				board2[x][y] = 1;
				if (board1[x][y] == board2[x][y])
				{
					return -1;     //֤���ȵ�����
				}
				else
				{
					int count = 0;
					count = board1[x - 1][y] + board1[x - 1][y + 1] + board1[x - 1][y - 1]
						+ board1[x + 1][y] + board1[x + 1][y + 1] + board1[x + 1][y - 1]
						+ board1[x][y + 1] + board1[x][y - 1];
					board2[x][y] = count;
					return count;
				}
			}
		}
		printf("\n�������,�������������꣺");
	}
}

void  sweep_board(int board1[ROWS][COLS], int rows, int cols)   //��ӡ�����׵�ͼ
{
	int i = 0;
	int j = 0;
	printf("     1   2   3   4   5   6   7   8   9  10  \n");
	printf("   _________________________________________\n");
	for (i = 2; i < rows - 2; i++)
	{
		if (i > 10)
		{
			printf("%d |   |", i - 1);
		}
		else if (i <= 10)
		{
			printf("%d  |   |", i - 1);
		}
		for (j = 3; j < cols - 2; j++)
		{
			printf("   |");
		}
		printf("\n");
		printf("   | %d |", board1[i][2]);
		for (j = 3; j < cols - 2; j++)
		{
			printf(" %d |", board1[i][j]);
		}
		printf("\n");
		printf("   |___|");
		for (j = 3; j < cols - 2; j++)
		{
			printf("___|");
		}
		printf("\n");
	}
}


int  win(int board2[ROWS][COLS], int rows, int cols)  //�ж�����Ƿ�ɨ�׳ɹ�
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 2; i <= rows - 3; i++)
	{
		for (j = 2; j <= cols - 3; j++)
		{
			if (board2[i][j] == 'Y')
				count++;
		}
	}
	return count;
}



void  pai_lei(int board1[ROWS][COLS], int  board2[ROWS][COLS], int rows, int cols)    //����Ƿ�����
{
	int x = 0;
	int y = 0;
	printf("������Ҫ���׵����꣺");
	while (1)
	{
		scanf("%d%d", &x, &y);
		x++;
		y++;
		if ((x >= 2) && (x <= rows - 3) && (y >= 2) && (y <= cols - 3))
		{
			if ((board1[x][y] == 1) && (board2[x][y] == '*'))
			{
				board2[x][y] = 'Y';
				break;
			}
			else if ((board1[x][y] == 0) && (board2[x][y] == '*'))
			{
				board2[x][y] = 'N';
				break;
			}
		}
		printf("\n�������,�������������꣺");
	}
}

int  error_sweep(int board2[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 2; i <= rows - 3; i++)
	{
		for (j = 2; j <= cols - 3; j++)
		{
			if (board2[i][j] == 'N')
				count++;
		}
	}
	return count;
}


int  check_sweep(int board2[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for (i = 2; i <= rows - 3; i++)
	{
		for (j = 2; j <= cols - 3; j++)
		{
			if (board2[i][j] == '*')
				return 0;
		}
	}
	return 1;
}
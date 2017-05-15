#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
void menu()   //打印菜单
{
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("☆☆☆    1.PLAY    ☆☆☆\n");
	printf("☆☆☆    0.EXIT    ☆☆☆\n");
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
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
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("☆☆☆    0.简单    ☆☆☆\n");
	printf("☆☆☆    1.中等    ☆☆☆\n");
	printf("☆☆☆    2.困难    ☆☆☆\n");
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("请选择游戏模式：\n");
	while (1)
	{
		scanf("%d", &k);
		if ((k != 0) && (k != 1) && (k != 2))
		{
			printf("输入错误,请重新输入.");
		}
		else
		{
			break;
		}
	}
	int ret = 0;
	Init_chessboard(board, ROWS, COLS);   //初始化棋盘
	while (1)
	{
		Play_move_chess(board, ROWS, COLS); //玩家走棋 
		Display_chessboard(board, ROWS, COLS);  //更新棋盘
		ret = Check_win(board, ROWS, COLS);   //判断输赢
		if (0 == ret)
		{
			printf("恭喜您赢了.\n");
			break;
		}
		ret = Check_win(board, ROWS, COLS);  //判断棋盘是否走满
		if (3 == ret)
		{
			printf("棋逢对手.\n");
			break;
		}
		switch (k)
		{
		case 0:
			Computer_move_chess(board, ROWS, COLS); //电脑自动走棋
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
		printf("电脑走之后的棋盘：\n");
		Display_chessboard(board, ROWS, COLS);  //更新棋盘
		Check_win(board, ROWS, COLS);   //判断输赢
		ret = Check_win(board, ROWS, COLS);
		if (1 == ret)
		{
			printf("很遗憾,您输了.\n");
			break;
		}
	}
}
int main()
{
	int input;
	do   //do...whlie循环保证至少打印菜单一次
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case PLAY:
			game();
			break;
		case EXIT:
			break;
		default:
			printf("您的输入有误,请重新输入.\n");
			break;
		}
	} while (input);
	return 0;
}
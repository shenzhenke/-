#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
enum
{
	EXIT, /*枚举元素本身由系统定义了一个表示序号的数值，从0开始顺序定义为0，1，2…。EXIT的值为0,PLAY的值为1*/
	PLAY
};
void menu()
{
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("☆☆☆☆☆    1.PLAY      ☆☆☆☆☆\n");
	printf("☆☆☆☆☆    0.EXIT      ☆☆☆☆☆\n");
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
}
void game()
{
	int ret = 0;
	int k = 0;   //用来判断玩家是否输入雷的坐标
	int board1[ROWS][COLS] = { 0 };   //第一张棋盘作为埋好雷的棋盘
	int board2[ROWS][COLS] = { 0 };   //第二张棋盘作为统计雷的棋盘
	Init_Interface(board1, board2, ROWS, COLS);  //初始化扫雷棋盘
	while (1)
	{
		int ret1 = play_move(board1, board2, ROWS, COLS);   //玩家输入坐标
		{
			if (ret1 == -1)
			{
				printf("\n踩雷成功,光荣牺牲.\n");
				sweep_board(board1, ROWS, COLS); //打印布雷棋盘
				break;
			}
			display_board(board2, ROWS, COLS);
			//排雷过程
			k = 0;
			printf("☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
			printf("☆☆☆ 输入0: 排雷  ☆☆☆\n");
			printf("☆☆☆ 输入1: 不排雷☆☆☆\n");
			printf("☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
			printf("请选择：\n");
			while (k == 0)
			{
				scanf("%d", &k);
				switch (k)      //判断是否需要排雷
				{
				case 0:
					pai_lei(board1, board2, ROWS, COLS);
					break;
				case 1:
					break;
				default:
					k = 0;
					printf("输入错误\n");
					break;
				}
				if (k == 0)
				{
					printf("请选择是否继续排雷：");
				}
			}
			//结束
			int ret2 = win(board2, ROWS, COLS);
			{
				if (ret2 == sweep)  //返回的值为雷的个数则成功
				{
					printf("恭喜扫雷成功.\n");
					sweep_board(board1, ROWS, COLS); //打印布雷棋盘
					break;
				}
				else
				{
					printf("您已经成功的扫出%d颗雷\n", ret2);
				}
			}
			int ret3 = error_sweep(board2, ROWS, COLS);    //判断扫错雷的个数
			{
				printf("您已经错误的扫出%d颗雷\n", ret3);
			}
			int ret4 = check_sweep(board2, ROWS, COLS);   //检查雷阵是否填满
			if (ret4 == 1)
			{
				printf("没能成功找出所有的雷,很遗憾");
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
		printf("请输入你的选择：");
		scanf("%d", &input);  //
		switch (input)
		{
		case PLAY:
			game();
			break;
		case  EXIT:
			break;
		default:
			printf("您的输入有误,请重新输入.\n");
			break;
		}
	} while (input);
	return 0;
}
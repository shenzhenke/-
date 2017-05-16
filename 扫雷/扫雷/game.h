#define _CRT_SECURE_NO_WARNINGS 
#ifndef __GAME_H__
#define __GAME_H__
#define ROWS 14    //宏定义行
#define COLS 14    //列
#define sweep 20
void Init_Interface(int board1[ROWS][COLS], int board2[ROWS][COLS], int rows, int cols);  //初始化扫雷棋盘
void  display_board(int board2[ROWS][COLS], int rows, int cols); //打印扫雷棋盘
int   play_move(int board1[ROWS][COLS], int board2[ROWS][COLS], int rows, int cols); //玩家输入坐标并判断是否是雷
void  pai_lei(int board1[ROWS][COLS], int  board2[ROWS][COLS], int rows, int cols);  //玩家是否排雷
int   win(int board2[ROWS][COLS], int rows, int cols);    //判断玩家输赢
int  error_sweep(int board2[ROWS][COLS], int rows, int cols);    //判断玩家扫雷错误数
int  check_sweep(int board2[ROWS][COLS], int rows, int cols);   //判断雷阵是否填满
void  sweep_board(int board1[ROWS][COLS], int rows, int cols); //打印布雷棋盘
#endif //__GAME_H__
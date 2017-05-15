
#ifndef __GAME_H__
#define __GAME_H__
#define ROWS 3
#define COLS  3
void  Init_chessboard(int board[ROWS][COLS], int rows, int cols);   //初始化棋盘
void  Play_move_chess(int board[ROWS][COLS], int rows, int cols); //玩家走棋
void  Computer_move_chess(int board[ROWS][COLS], int rows, int cols); //电脑自动走棋
int   Computer_think_move_chess(int board[ROWS][COLS], int rows, int cols); //电脑在有两个连线时候走棋能赢
void  Computer_more_think_move_chess(int board[ROWS][COLS], int rows, int cols);//电脑能够堵玩家棋子
void  Display_chessboard(int board[ROWS][COLS], int rows, int cols);  //更新棋盘
int   Check_win(int board[ROWS][COLS], int rows, int cols);     //判断输赢
#endif //__GAME_H__
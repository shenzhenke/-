
#ifndef __GAME_H__
#define __GAME_H__
#define ROWS 3
#define COLS  3
void  Init_chessboard(int board[ROWS][COLS], int rows, int cols);   //��ʼ������
void  Play_move_chess(int board[ROWS][COLS], int rows, int cols); //�������
void  Computer_move_chess(int board[ROWS][COLS], int rows, int cols); //�����Զ�����
int   Computer_think_move_chess(int board[ROWS][COLS], int rows, int cols); //����������������ʱ��������Ӯ
void  Computer_more_think_move_chess(int board[ROWS][COLS], int rows, int cols);//�����ܹ����������
void  Display_chessboard(int board[ROWS][COLS], int rows, int cols);  //��������
int   Check_win(int board[ROWS][COLS], int rows, int cols);     //�ж���Ӯ
#endif //__GAME_H__
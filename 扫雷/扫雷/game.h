#define _CRT_SECURE_NO_WARNINGS 
#ifndef __GAME_H__
#define __GAME_H__
#define ROWS 14    //�궨����
#define COLS 14    //��
#define sweep 20
void Init_Interface(int board1[ROWS][COLS], int board2[ROWS][COLS], int rows, int cols);  //��ʼ��ɨ������
void  display_board(int board2[ROWS][COLS], int rows, int cols); //��ӡɨ������
int   play_move(int board1[ROWS][COLS], int board2[ROWS][COLS], int rows, int cols); //����������겢�ж��Ƿ�����
void  pai_lei(int board1[ROWS][COLS], int  board2[ROWS][COLS], int rows, int cols);  //����Ƿ�����
int   win(int board2[ROWS][COLS], int rows, int cols);    //�ж������Ӯ
int  error_sweep(int board2[ROWS][COLS], int rows, int cols);    //�ж����ɨ�״�����
int  check_sweep(int board2[ROWS][COLS], int rows, int cols);   //�ж������Ƿ�����
void  sweep_board(int board1[ROWS][COLS], int rows, int cols); //��ӡ��������
#endif //__GAME_H__
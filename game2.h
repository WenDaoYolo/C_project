#include<stdio.h>
#include<windows.h>
#include<time.h>
#define ROW 3
#define COL 3
#define ROLL 3
void PrintMenu();
void GameIn();
void ReBoard(char arr[ROW][COL]);
void PrintBoard(char arr[ROW][COL]);
char GetStatus(char arr[ROW][COL], int GetX,int GetY);//C��Ϸ���� W��Ϸʤ��(���/����) Pƽ��
int JudgmentXY(int x, int y,char arr[ROW][COL]);
void PlayerMove(int x, int y, char arr[ROW][COL]);
void ComputerMove(char arr[ROW][COL]);
void Judgment(char status);
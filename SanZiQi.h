#include<stdio.h>
#include<windows.h>
#include<time.h>

#define ROW 3										//�������̲���
#define COL 3
enum GAMESTATUS{CONTINUE,DRAW,PWIN,CWIN};			//������Ϸ״̬

void PrintMenu();									//��ӡ��Ϸ�˵�
void PrintRule();									//��ӡ��Ϸ����
void Reboard(char board[ROW][COL]);					//��ʼ������
void PrintBoard(char board[ROW][COL]);			    //��ӡ����
void PlayerMove(char board[ROW][COL]);				//��һغ�
void ComputerMove(char board[ROW][COL]);			//���Իغ�
GAMESTATUS GetGameStatus(char board[ROW][COL]);     //��ȡ��Ϸ״̬
int JudgmentGameStatus(GAMESTATUS GameStatus);      //�ж���Ϸ״̬
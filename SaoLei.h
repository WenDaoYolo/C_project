#include<stdio.h>
#include<windows.h>
#include<time.h>

#define row 9							    //չʾ��С
#define col 9
#define ROW row+2						    //ʵ�ʴ�С
#define COL col+2
#define MINES 30						    //���׸���
enum GAMESTATUS{CONTINUE,GAMEOVER,WIN};		//������Ϸ״̬

/*

���̷���
real :A-���� a-����  N-������
show :*-δ֪ x-����  ����-������

��Ϸ״̬
CONTINUE:����
GAMEOVER:��Ϸʧ��
WIN:��Ϸʤ��

*/

void PrintMenu();																				 //��ӡ��Ϸ�˵�
void Reboard(char board[ROW][COL], char flag);													 //��ʼ������
void PrintBoard(char board[ROW][COL]);															 //��ӡ����
char GetMessageForMines(char real[ROW][COL],int PlayerX,int PlayerY);							 //��ȡ������Ϣ
void LayMines(char board[ROW][COL]);															 //�������
GAMESTATUS GetGameStatus(char real[ROW][COL],char show[ROW][COL],int x,int y);                   //��ȡ��Ϸ״̬
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#define row 9									//������̲���
#define col 9									
#define ROW row+2								//ʵ�����̲���
#define COL col+2
#define Mine (row*col)/4						//������

/*
	����Լ��:
	rel		��Ϣ�洢����	A����	a����	N���ŵ�
	show	��Ϣչʾ����	*δ֪	x����	
	
*/

void PrintMenu();															//��ӡ�˵�
void Reboard(char arr[ROW][COL],char flag);									//��ʼ������
void Printboard(char arr[ROW][COL]);										//��ӡ����
void Plantmine(char arr[ROW][COL]);											//�����㷨
char FindMine(char arr[ROW][COL],int x,int y);								//�����㷨
char UpdateStatus(int x,int y,char rel[ROW][COL],char show[ROW][COL]);		//C	��Ϸ����, G	��ը����, W	��Ϸʤ��
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define ROW 3										//����X�����
#define COL 3										//����Y�����

void PrintMenu();									//��ӡ���˵�
void Reboard(char arr[ROW][COL]);					//��ʼ������
void Printboard(char arr[ROW][COL]);				//��ӡ����
void PlayerMove(char arr[ROW][COL]);				//����ƶ�
void ComputerMove(char arr[ROW][COL]);				//�����ƶ�
char Getstatus(char arr[ROW][COL]);					//��ȡ��Ϸ״̬		C:��Ϸ����	D:ƽ��	x:���ʤ��	o:����ʤ��
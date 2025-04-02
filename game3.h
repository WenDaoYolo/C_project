#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#define row 9									//玩家棋盘参数
#define col 9									
#define ROW row+2								//实际棋盘参数
#define COL col+2
#define Mine (row*col)/4						//地雷数

/*
	规则约定:
	rel		信息存储棋盘	A无雷	a有雷	N已排点
	show	信息展示棋盘	*未知	x踩雷	
	
*/

void PrintMenu();															//打印菜单
void Reboard(char arr[ROW][COL],char flag);									//初始化棋盘
void Printboard(char arr[ROW][COL]);										//打印棋盘
void Plantmine(char arr[ROW][COL]);											//布雷算法
char FindMine(char arr[ROW][COL],int x,int y);								//排雷算法
char UpdateStatus(int x,int y,char rel[ROW][COL],char show[ROW][COL]);		//C	游戏继续, G	被炸死了, W	游戏胜利
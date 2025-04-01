#include<stdio.h>
#include<windows.h>
#include<time.h>
#define ROW 3										//棋盘X轴参数
#define COL 3										//棋盘Y轴参数

void PrintMenu();									//打印主菜单
void Reboard(char arr[ROW][COL]);					//初始化棋盘
void Printboard(char arr[ROW][COL]);				//打印棋盘
void PlayerMove(char arr[ROW][COL]);				//玩家移动
void ComputerMove(char arr[ROW][COL]);				//电脑移动
char Getstatus(char arr[ROW][COL]);					//获取游戏状态		C:游戏继续	D:平局	x:玩家胜利	o:电脑胜利
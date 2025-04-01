#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"

void GameIn() {
		//配置游戏参数
		char board[ROW][COL];
		char status = 0;
		//初始化棋盘
		Reboard(board);
	while (1) {
		//打印棋盘
		system("cls");
		Printboard(board);
		//玩家移动
		PlayerMove(board);
		//获取游戏状态&判断游戏状态
		status=Getstatus(board);
		if (status != 'C')
			break;
		//打印棋盘
		system("cls");
		Printboard(board);
		//电脑移动
		printf("电脑回合中...\n");
		Sleep(2000);
		ComputerMove(board);
		//获取游戏状态&判断游戏状态
		status=Getstatus(board);
		if (status != 'C')
			break;
	}
		//输出游戏结果&打印棋盘
		system("cls");
	if (status == 'x')
		printf("\a玩家胜利!\n");
	else if(status == 'o')
		printf("电脑胜利!\n");
	else if(status=='D')
		printf("平局!\n");
		
		Printboard(board);
		Sleep(3500);
		system("cls");
}

int main() {
	//设置菜单控制帧
	int MenuChoose = 1;
	//配置随机种子器
	srand((unsigned int)time(NULL));
	//程序主框架
	while (MenuChoose!=2) {
		PrintMenu();
		printf("请输入>");
		scanf("%d", &MenuChoose);
		switch (MenuChoose) {
		case 1:
			system("cls");
			//游戏子框架
			GameIn();
			break;
		case 2:
			printf("Program exited!\n");
			break;
		default:
			system("cls");
			printf("\aError!\n");
			break;
		}
	}
	return 0;
}
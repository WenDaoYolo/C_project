#define _CRT_SECURE_NO_WARNINGS 1
#include "game3.h"

void GameIn() {
	char rel[ROW][COL], show[ROW][COL];
	int PlayerX = 0, PlayerY = 0;
	char status = 0;
		//初始化棋盘
		Reboard(rel, 'A');
		Reboard(show, '*');
		//布雷
		Plantmine(rel);
		//打印棋盘
		while (1) {
			system("cls");
			Printboard(show);
			//玩家移动
			while (1) {
				printf("请输入坐标>");
				scanf("%d%d", &PlayerX, &PlayerY);
				if (PlayerX >= 1 && PlayerX <= row && PlayerY >= 1 && PlayerY <= col && (rel[PlayerX][PlayerY] == 'A' || rel[PlayerX][PlayerY] == 'a'))
					break;
				else
					printf("坐标非法!");
			}
			//获取并更新游戏状态					
			status = UpdateStatus(PlayerX, PlayerY, rel, show);
			//判断游戏状态
			if (status == 'W') {
				system("cls");
				Printboard(show);
				printf("\a游戏胜利!\n");
				break;
			}	
			else if (status == 'G') {
				system("cls");
				Printboard(show);
				printf("\a老登,你被炸死了O.O!\n");
				break;
			}
		}
		Sleep(3000);
		system("cls");
}

int main() {
	//配置全局参数
	int MenuChoose = 1;
	srand((unsigned int)time(NULL));
	//程序主框架
	while (MenuChoose!=2) {
		//打印菜单
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
			printf("Error!\n");
			break;
		}
	}
	return 0;
}
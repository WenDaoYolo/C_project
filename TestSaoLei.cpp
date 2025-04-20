#define _CRT_SECURE_NO_WARNINGS 1
#include "SaoLei.h"

void GameIn() {
	int PlayerX, PlayerY;
	char real[ROW][COL], show[ROW][COL];
	Reboard(real,'A');
	Reboard(show,'*');
	LayMines(real);
	while (1) {
		system("cls");
		PrintBoard(show);
		while (1) {
			printf("请输入坐标>");
			scanf("%d%d", &PlayerX, &PlayerY);
			if (PlayerX >= 1 && PlayerX <= 9 && PlayerY >= 1 && PlayerY <= 9 && (real[PlayerX][PlayerY] == 'A' || real[PlayerX][PlayerY] == 'a'))
			{	
				show[PlayerX][PlayerY] = GetMessageForMines(real, PlayerX, PlayerY);
				break;
			}
			else
				printf("坐标非法!\a\n");
		}
		if (GetGameStatus(real,show, PlayerX, PlayerY) == GAMEOVER)
		{	
			system("cls");
			printf("老登，你被炸死了O.O\a\n");
			printf("====================\n");
			break;
		}
		else if (GetGameStatus(real,show, PlayerX, PlayerY) == WIN)
		{
			system("cls");
			printf("游戏胜利\a\n");
			printf("====================\n");
			break;
		}
	}
	PrintBoard(show);
	Sleep(4000);
	system("cls");
}

int main() {
	int IndexChoose = 1;
	srand((unsigned int)time(NULL));
	while (IndexChoose!=3) {
		PrintMenu();
		printf(">");
		scanf("%d", &IndexChoose);
		switch (IndexChoose) {
		case 1:
			system("cls");
			GameIn();
			break;
		case 2:
			system("cls");
			printf("输入格式：行坐标 列坐标,回车确定\n");
			break;
		case 3:
			system("cls");
			printf("----程序已退出----\n");
			break;
		default:
			system("cls");
			printf("输入错误!\a\n");
			break;
		}
	}
	return 0;
}
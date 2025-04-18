#define _CRT_SECURE_NO_WARNINGS 1
#include "SanZiQi.h"

void GameIn() {
	char board[ROW][COL];
	GAMESTATUS GameStatus;
	Reboard(board);
	while (1) {

		system("cls");
		PrintBoard(board);

		PlayerMove(board);
		GameStatus=GetGameStatus(board);
		if (JudgmentGameStatus(GameStatus))
			break;

		system("cls");
		PrintBoard(board);

		printf("电脑回合中...");
		Sleep(2000);

		ComputerMove(board);
		GameStatus=GetGameStatus(board);
		if (JudgmentGameStatus(GameStatus))
			break;

	}
	PrintBoard(board);
	Sleep(4000);
	system("cls");
}

int main() {
	int IndexChoose = 1;
	//配置随机种子器
	srand((unsigned int)time(NULL));
	//程序主框架
	while (IndexChoose != 3) {
		PrintMenu();
		printf(">");
		scanf("%d", &IndexChoose);
		switch (IndexChoose) {
		case 1:
			system("cls");
			GameIn();//游戏子框架
			break;
		case 2:
			system("cls");
			PrintRule();
			break;
		case 3:
			system("cls");
			printf("---------程序已退出-----------\n");
			break;
		default:
			system("cls");
			printf("输入错误!\a\n");
			break;
		}
	}
	return 0;
}
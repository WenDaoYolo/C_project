#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"


void PrintMenu() {
	printf("*=========================================*\n");
	printf(" Menu:                                     \n");
	printf("                 1.play                    \n");
	printf("                 2.exit                    \n");
	printf("                                           \n");
	printf("*=========================================*\n");
}

void GameIn() {
	char board[ROW][COL];
	int PlayerX = 0, PlayerY = 0;
	char status='C';
	ReBoard(board);
	while (1) {
		PrintBoard(board);
		printf("你的回合,请输入坐标>\n");
		Reinput:
		scanf("%d%d", &PlayerX, &PlayerY);
		if (JudgmentXY(PlayerX, PlayerY,board))
			goto Reinput;

		status = GetStatus(board, PlayerX, PlayerY);

		PlayerMove(PlayerX, PlayerY, board);
		Judgment(status);
		if (status == 'W') {
			break;
		}
		else if (status == 'P')
		{
			break;
		}
		ComputerMove(board);
		Judgment(status);
		if (status == 'W') {
			break;
		}
		else if (status == 'P')
		{
			break;
		}
	}
	PrintBoard(board);
}

void ReBoard(char arr[ROW][COL]) {
	int i = 0, j = 0;
	for (i = 0; i < ROW;i++) {
		for (j = 0; j < COL; j++) {
			arr[i][j] =' ';
		}
	}
}

void PrintBoard(char arr[ROW][COL]){
	int i = 0,j = 0;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			printf(" %c ", arr[i][j]);
			if(j<COL-1)
			printf("|");
		}
		putchar('\n');
		if (i<ROW-1) {
			for (j = 0; j < COL; j++) {
				printf("---");
				if (j < COL - 1)
					printf("|");
			}
			putchar('\n');
		}
	}
}

char GetStatus(char arr[ROW][COL], int GetX, int GetY) {


	return 'W';
}

int JudgmentXY(int x, int y,char arr[ROW][COL]) {
	if (x < 1 || x>3 || y < 1 || y>3||arr[x][y]!=' ') {
		printf("坐标非法,请重新输入>");
		return 1;
	}
	return 0;
}

void PlayerMove(int x, int y, char arr[ROW][COL]) {
	arr[x-1][y-1] = 'x';
}
void ComputerMove(char arr[ROW][COL]) {
	int x, y;
	input:
	x = rand() % 3;
	y = rand() % 3;
	if (arr[x][y] != ' ')
		goto input;
	arr[x][y] = 'o';
}
void Judgment(char status){
	if (status == 'W') {
		printf("玩家胜利!\n");
	}
	else if (status == 'P')
	{
		printf("平局!\n");
	}
}
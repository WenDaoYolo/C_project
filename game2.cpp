#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
void PrintMenu() {
	printf("***********************************\n");
	printf(" Menu:                             \n");
	printf("             1.play                \n");
	printf("             2.exit                \n");
	printf("                                   \n");
	printf("***********************************\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void Reboard(char arr[ROW][COL]) {
	int i = 0, j = 0;
	for (i = 0; i < ROW;i++) {
		for (j = 0; j < COL;j++) {
			arr[i][j] = ' ';
		};
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void Printboard(char arr[ROW][COL]) {
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			printf(" %c ",arr[i][j]);
			if(j<COL-1)
			printf("|");
		}
		putchar('\n');
		if (i < ROW - 1) {
			for (j = 0; j < COL; j++) {
				printf("---");
				if (j < COL - 1)
					printf("|");
			}
			putchar('\n');
		}

	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void PlayerMove(char arr[ROW][COL]) {
	int PlayerX=0, PlayerY=0;
	printf("你的回合,请输入(格式:x y)>");
	while (1) {
		scanf("%d%d", &PlayerX, &PlayerY);
		if (PlayerX >= 1 && PlayerX <= 3 && PlayerY >= 1 && PlayerY <= 3 && arr[PlayerX - 1][PlayerY - 1] == ' ') {
			arr[PlayerX - 1][PlayerY - 1] = 'x';
			break;
		}
		else
			printf("坐标非法,请重新输入>");
		}
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void ComputerMove(char arr[ROW][COL]) {
	int ComputerX=0, ComputerY=0;
	while (1) {
		ComputerX = rand() % 3;
		ComputerY = rand() % 3;
		if (arr[ComputerX][ComputerY] == ' ') {
			arr[ComputerX][ComputerY] = 'o';
			break;
		}	
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////
char Getstatus(char arr[ROW][COL]) {
	int i = 0, j = 0;

	//横轴
	for (i = 0, j = 0; i < ROW; i++)
		if (arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i][j + 2] && arr[i][j] != ' ') {
			if (arr[i][j] == 'x')
				return 'x';
			else
				return 'o';
		}	
	//纵轴
	for (i = 0, j = 0; j < COL; j++)
		if (arr[i][j] == arr[i + 1][j] && arr[i + 1][j] == arr[i + 2][j] && arr[i][j] != ' ') {
			if (arr[i][j] == 'x')
				return 'x';
			else
				return 'o';
		}	
	//对角线
		i = 0, j = 0;
		if (arr[i][j] == arr[i + 1][j+1] && arr[i + 1][j+1] == arr[i + 2][j+2] && arr[i+1][j+1] != ' ') {
			if (arr[i+1][j+1] == 'x')
				return 'x';
			else
				return 'o';
		}
		i = 0, j = 0;
		if (arr[i][COL-1] == arr[i+1][j + 1] && arr[i + 1][j + 1] == arr[ROW-1][j] && arr[i+1][j+1] != ' ') {
			if (arr[i+1][j+1] == 'x')
				return 'x';
			else
				return 'o';
		}
	//继续
	for (i = 0; i <= ROW;i++) {
		for (j = 0; j < COL;j++) {
			if (arr[i][j] == ' ')
				return 'C';
		}
	}
	//平局
	return 'D';
}
///////////////////////////////////////////////////////////////////////////////////////////////////
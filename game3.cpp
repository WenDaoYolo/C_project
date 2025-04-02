#define _CRT_SECURE_NO_WARNINGS 1
#include "game3.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
void PrintMenu() {
	printf("*******************************\n");
	printf("  Menu:                        \n");
	printf("            1.play             \n");
	printf("            2.exit             \n");
	printf("                               \n");
	printf("*******************************\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void Reboard(char arr[ROW][COL],char flag) {
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			arr[i][j] = flag;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void Printboard(char arr[ROW][COL]) {
	int i = 0, j = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);//坐标栏显示绿色
	for (int k = 0; k <= 9; k++)
		printf("%d ",k);
	putchar('\n');
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原白色字体颜色
	for (i = 1; i <=row; i++) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);//坐标栏显示绿色
			printf("%d ", i);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//还原白色字体颜色
		for (j = 1; j <=col; j++) {
			printf("%c ", arr[i][j]);
		}
		putchar('\n');
	}
	printf("Mines:%d\n",Mine);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void Plantmine(char arr[ROW][COL]) {
	int MineX = 0, MineY = 0;
	for (int i = 1; i <= Mine; i++) {
		while (1) {
			MineX = rand() % row + 1;
			MineY = rand() % col + 1;
			if (arr[MineX][MineY] == 'A') {
				arr[MineX][MineY] = 'a';
				break;
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
char FindMine(char arr[ROW][COL], int x, int y){
	//左右扩散,上下扩散
	int i = 0,j = 0;
	int count = 0;
	for (j = y - 1; j <= y + 1;j++) {
		for(i=x-1;i<=x+1;i++)
			if (arr[i][j]=='a') {
				count++;
			}
	}
	return count+'0';
}
////////////////////////////////////////////////////////////////////////////////////////////////////
char UpdateStatus(int x, int y, char rel[ROW][COL], char show[ROW][COL]) {
		int i = 0,j = 0;
		if (rel[x][y] == 'a') {
			show[x][y] = 'x';
			return 'G';
		}
			int FM=FindMine(rel,x,y);
			show[x][y] = FM;
			rel[x][y] = 'N';
			for (i = 1; i <= row; i++) {
				for (j = 1; j <= col; j++) {
					if (rel[i][j] == 'A')
					{
						return 'C';
					}
				}
			}
			return 'W';
}
////////////////////////////////////////////////////////////////////////////////////////////////////		
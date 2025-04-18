#define _CRT_SECURE_NO_WARNINGS 1
#include "SanZiQi.h"

void PrintMenu() {
	printf("=================================================\n");
	printf("  Menu��                                         \n");
	printf("                   1:��ʼ��Ϸ                    \n");
	printf("                   2:��Ϸ����                    \n");
	printf("                   3:�˳���Ϸ                    \n");
	printf("                                                 \n");
	printf("=================================================\n");
}

void PrintRule() {
	printf("����һ��Ϊʤ�����������ʽ:������ �����꣬�س�ȷ��\n");
}

void Reboard(char board[ROW][COL]) {
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			board[i][j] = ' ';
}

void PrintBoard(char board[ROW][COL]) {
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			printf(" %c ", board[i][j]);
			if(j!=COL-1)
			printf("|");
		}
		putchar('\n');
		if(i!=ROW-1)
		for (j = 0; j < COL; j++) {
			printf("---", board[i][j]);
			if(j!=COL-1)
			printf("|");
		}
		putchar('\n');
	}
}

void PlayerMove(char board[ROW][COL]) {
	int PlayerX, PlayerY;
	printf("����������>");
	while(1) {
		scanf("%d%d", &PlayerX, &PlayerY);
		if (PlayerX >= 1 && PlayerX <= 3 && PlayerY >= 1 && PlayerY <= 3 && board[PlayerX-1][PlayerY-1] == ' ')
		{
			board[PlayerX-1][PlayerY-1] = 'x';
			break;
		}
		else
			printf("����Ƿ�������������>");
	}
}

void ComputerMove(char board[ROW][COL]) {
	int ComputerX, ComputerY;
	while (1) {                                            //��Ľ�,����������Ҳ����ѭ��
		ComputerX = rand() % ROW;
		ComputerY = rand() % COL;
		if (board[ComputerX][ComputerY]==' ') {
			board[ComputerX][ComputerY] = 'o';
			break;
		}
	}
}

GAMESTATUS GetGameStatus(char board[ROW][COL]) { 
	int i = 0, j = 0; 
	for (i = 0; i < ROW; i++) {
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == 'x')
				return PWIN;
			else
				return CWIN;
		}
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			if (board[i][0] == 'x')
				return PWIN;
			else
				return CWIN;
		}
	}

	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'x')
			return PWIN;
		else
			return CWIN;
	}

	if (board[0][COL-1] != ' ' && board[0][COL-1] == board[1][COL-2] && board[1][COL-2] == board[2][COL-3])
	{
		if (board[0][COL-1] == 'x')
			return PWIN;
		else
			return CWIN;
	}

	for(i=0;i<=ROW;i++)
		for (j = 0; j <= COL; j++) {
			if (board[i][j]==' ')
				return CONTINUE;
		}

	return DRAW;
   //���ж��Ƿ�ʤ�������ж��Ƿ�����������ж��Ƿ�ƽ��
}

int JudgmentGameStatus(GAMESTATUS GameStatus){
	if (GameStatus == CONTINUE)
		return 0;
	else if (GameStatus == DRAW)
	{	
		system("cls");
		printf("ƽ��!\n");
		return 1;
	}
	else if (GameStatus == PWIN||GameStatus==CWIN)
	{	
		system("cls");
		if (GameStatus == PWIN)
			printf("���ʤ��!\a\n");
		else if(GameStatus==CWIN)
			printf("����ʤ��!\a\n");
		return 1;
	}
}
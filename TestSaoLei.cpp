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
			printf("����������>");
			scanf("%d%d", &PlayerX, &PlayerY);
			if (PlayerX >= 1 && PlayerX <= 9 && PlayerY >= 1 && PlayerY <= 9 && (real[PlayerX][PlayerY] == 'A' || real[PlayerX][PlayerY] == 'a'))
			{	
				show[PlayerX][PlayerY] = GetMessageForMines(real, PlayerX, PlayerY);
				break;
			}
			else
				printf("����Ƿ�!\a\n");
		}
		if (GetGameStatus(real,show, PlayerX, PlayerY) == GAMEOVER)
		{	
			system("cls");
			printf("�ϵǣ��㱻ը����O.O\a\n");
			printf("====================\n");
			break;
		}
		else if (GetGameStatus(real,show, PlayerX, PlayerY) == WIN)
		{
			system("cls");
			printf("��Ϸʤ��\a\n");
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
			printf("�����ʽ�������� ������,�س�ȷ��\n");
			break;
		case 3:
			system("cls");
			printf("----�������˳�----\n");
			break;
		default:
			system("cls");
			printf("�������!\a\n");
			break;
		}
	}
	return 0;
}
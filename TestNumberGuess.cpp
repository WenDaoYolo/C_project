#define _CRT_SECURE_NO_WARNINGS 1
#include "NumberGuess.h"
#include<windows.h>
#include<time.h>

void GameIn() {
	static int mincount = 99999;
	int PlayerGuess,count = 0, randNumber = rand() % 100;
	while (1) {
		printf(">");
		scanf("%d", &PlayerGuess);
		if (PlayerGuess > randNumber)
		{
			printf("�´���!\n");
			count++;
		}
		else if (PlayerGuess < randNumber)
		{
			printf("��С��!\n");
			count++;
		}
		else
		{
			printf("�¶���!\a\n");
			count++;
			break;
		}
	}
	if (count < mincount)
		mincount = count;
	Sleep(2000);
	system("cls");
	PrintResult(count,mincount);
	Sleep(3000);
	system("cls");
}

int main() {
	int IndexChoose = 1;
	srand((unsigned int)time(NULL));
	//���������
	while (IndexChoose!=3) {
		PrintMenu();
		printf(">");
		scanf("%d", &IndexChoose);
		switch (IndexChoose) {
		case 1:
			system("cls");
			printf("-----------��ʼ��Ϸ-----------\n");
			GameIn();//��Ϸ�ӿ��
			break;
		case 2:
			system("cls");
			PrintRule();
			break;
		case 3:
			system("cls");
			printf("---------�������˳�-----------\n");
			break;
		default:
			system("cls");
			printf("�������!\a\n");
			break;
		}
	}
	return 0;
}
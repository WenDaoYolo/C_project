#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void PrintMenu() {
	printf("*=================================*\n");
	printf("  Menu:	                           \n");
	printf("             1. play               \n");
	printf("             2. exit               \n");
	printf("                                   \n");
	printf("*=================================*\n");
}

void PrintMenu2(int num,int history) {
	printf("*=================================*\n");
	printf("  Result:                          \n");
	printf("             ���ִ���:%d           \n",num);
	printf("             ��ʷ����:%d           \n",history);
	printf("                                   \n");
	printf("*=================================*\n");
}

void GameIn() {
	int random = rand() % 100;
	int guess = 0;
	int count = 0;
	static int mincount = 99999;
	while (1) {
		printf("������>");
		scanf("%d", &guess);
		if (guess > random)
		{
			printf("�´���!\n");
			count++;
		}
		else if (guess < random)
		{
			printf("��С��!\n");
			count++;
		}
		else
		{
			printf("�¶���!\n");
			count++;
			break;
		}
	}
	if (count < mincount)
		mincount = count;
	Sleep(2000);
	PrintMenu2(count, mincount);
	Sleep(2000);
}
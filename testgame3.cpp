#define _CRT_SECURE_NO_WARNINGS 1
#include "game3.h"

void GameIn() {
	char rel[ROW][COL], show[ROW][COL];
	int PlayerX = 0, PlayerY = 0;
	char status = 0;
		//��ʼ������
		Reboard(rel, 'A');
		Reboard(show, '*');
		//����
		Plantmine(rel);
		//��ӡ����
		while (1) {
			system("cls");
			Printboard(show);
			//����ƶ�
			while (1) {
				printf("����������>");
				scanf("%d%d", &PlayerX, &PlayerY);
				if (PlayerX >= 1 && PlayerX <= row && PlayerY >= 1 && PlayerY <= col && (rel[PlayerX][PlayerY] == 'A' || rel[PlayerX][PlayerY] == 'a'))
					break;
				else
					printf("����Ƿ�!");
			}
			//��ȡ��������Ϸ״̬					
			status = UpdateStatus(PlayerX, PlayerY, rel, show);
			//�ж���Ϸ״̬
			if (status == 'W') {
				system("cls");
				Printboard(show);
				printf("\a��Ϸʤ��!\n");
				break;
			}	
			else if (status == 'G') {
				system("cls");
				Printboard(show);
				printf("\a�ϵ�,�㱻ը����O.O!\n");
				break;
			}
		}
		Sleep(3000);
		system("cls");
}

int main() {
	//����ȫ�ֲ���
	int MenuChoose = 1;
	srand((unsigned int)time(NULL));
	//���������
	while (MenuChoose!=2) {
		//��ӡ�˵�
		PrintMenu();
		printf("������>");
		scanf("%d", &MenuChoose);
		switch (MenuChoose) {
		case 1:
			system("cls");
			//��Ϸ�ӿ��
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
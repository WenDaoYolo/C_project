#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"

void GameIn() {
		//������Ϸ����
		char board[ROW][COL];
		char status = 0;
		//��ʼ������
		Reboard(board);
	while (1) {
		//��ӡ����
		system("cls");
		Printboard(board);
		//����ƶ�
		PlayerMove(board);
		//��ȡ��Ϸ״̬&�ж���Ϸ״̬
		status=Getstatus(board);
		if (status != 'C')
			break;
		//��ӡ����
		system("cls");
		Printboard(board);
		//�����ƶ�
		printf("���Իغ���...\n");
		Sleep(2000);
		ComputerMove(board);
		//��ȡ��Ϸ״̬&�ж���Ϸ״̬
		status=Getstatus(board);
		if (status != 'C')
			break;
	}
		//�����Ϸ���&��ӡ����
		system("cls");
	if (status == 'x')
		printf("\a���ʤ��!\n");
	else if(status == 'o')
		printf("����ʤ��!\n");
	else if(status=='D')
		printf("ƽ��!\n");
		
		Printboard(board);
		Sleep(3500);
		system("cls");
}

int main() {
	//���ò˵�����֡
	int MenuChoose = 1;
	//�������������
	srand((unsigned int)time(NULL));
	//���������
	while (MenuChoose!=2) {
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
			system("cls");
			printf("\aError!\n");
			break;
		}
	}
	return 0;
}
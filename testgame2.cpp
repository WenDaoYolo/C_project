#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"


int main() {
	int MenuChoose = 0;
	srand((unsigned int)time(NULL));

	while (MenuChoose!=2) {
		PrintMenu();
		printf("ÇëÊäÈë>");
		scanf("%d", &MenuChoose);
		switch (MenuChoose) {
		case 1:
			system("cls");
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
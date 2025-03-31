#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
int main() {
	int MenuChoose = 1;
	srand((unsigned int)time(NULL));
	while (MenuChoose!=2) {
		PrintMenu();
		printf("ÇëÑ¡Ôñ>");
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
		}
	}
	return 0;
}


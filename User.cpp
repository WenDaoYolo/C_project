#define _CRT_SECURE_NO_WARNINGS 1
#include "User.h"

void PrintLoginMenu() {
	printf("=************************=\n");
	printf("      Contact System      \n");
	printf("          1.��¼          \n");
	printf("          2.ע��          \n");
	printf("          0.�˳�          \n");
	printf("=************************=\n");
}

void UserRegister(User* user1) {
	char tmp[20] = { 0 };
	printf("�������˺�(11λ)>");
	scanf("%s", user1->admin);
	printf("����������(11λ)>");
	scanf("%s", user1->password);

	if (strlen(user1->password)!= USERDATA_LENGTH && strlen(user1->admin) != USERDATA_LENGTH)
	{
		system("cls");
		printf("�˺Ż����벻���Ϲ涨!\n");
		return;
	}

	printf("���ٴ�ȷ������>");
	scanf("%s", tmp);

	if (strcmp(tmp, user1->password) == 0)
	{
		strcpy(tmp, user1->admin);
		FILE* ptr1=fopen(strcat(tmp, ".txt"), "wb");
		if (ptr1 == NULL) {
			perror("UserRegister");
			return;
		}
		FILE* ptr2 = fopen("UserData.txt", "ab");
		if (ptr2 == NULL) {
			fclose(ptr1);
			ptr1 = NULL;
			return;
		}

		fwrite(user1, sizeof(User),1, ptr2);
		fclose(ptr1);
		ptr1 = NULL;
		fclose(ptr2);
		ptr2 = NULL;
		printf("ע��ɹ�!\a\n");
	}
	else
	{
		printf("�������!\n");
		return;
	}
}


int UserLogin(User* user1,char* fn){
	FILE* ptr=fopen("UserData.txt", "r");
	if (ptr == NULL)
	{
		perror("UserLogin");
		return 0;
	}
	User user2 = { 0 };
	User user3 = { 0 };
	printf("�˺�>");
	scanf("%s", user3.admin);
	printf("����>");
	scanf("%s", user3.password);
	int i = 0;
	while (i = fread(&user2, sizeof(User), 1, ptr) == 1)
	{
		if (strcmp(user3.admin, user2.admin) == 0 && strcmp(user3.password, user2.password)==0)
		{
			printf("��¼�ɹ�!\a\n");
			//����ͨѶ¼ģ��
			strcpy(fn, user3.admin);
			return 1;
		}
	}
	printf("�˺Ż��������!\n");
	fclose(ptr);
	ptr = NULL;
	return 0;
}
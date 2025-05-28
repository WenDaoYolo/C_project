#define _CRT_SECURE_NO_WARNINGS 1
#include "User.h"

void PrintLoginMenu() {
	printf("=************************=\n");
	printf("      Contact System      \n");
	printf("          1.登录          \n");
	printf("          2.注册          \n");
	printf("          0.退出          \n");
	printf("=************************=\n");
}

void UserRegister(User* user1) {
	char tmp[20] = { 0 };
	printf("请输入账号(11位)>");
	scanf("%s", user1->admin);
	printf("请输入密码(11位)>");
	scanf("%s", user1->password);

	if (strlen(user1->password)!= USERDATA_LENGTH && strlen(user1->admin) != USERDATA_LENGTH)
	{
		system("cls");
		printf("账号或密码不符合规定!\n");
		return;
	}

	printf("请再次确认密码>");
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
		printf("注册成功!\a\n");
	}
	else
	{
		printf("密码错误!\n");
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
	printf("账号>");
	scanf("%s", user3.admin);
	printf("密码>");
	scanf("%s", user3.password);
	int i = 0;
	while (i = fread(&user2, sizeof(User), 1, ptr) == 1)
	{
		if (strcmp(user3.admin, user2.admin) == 0 && strcmp(user3.password, user2.password)==0)
		{
			printf("登录成功!\a\n");
			//连接通讯录模块
			strcpy(fn, user3.admin);
			return 1;
		}
	}
	printf("账号或密码错误!\n");
	fclose(ptr);
	ptr = NULL;
	return 0;
}
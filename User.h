#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define USERDATA_LENGTH 11

typedef struct User{
	char admin[USERDATA_LENGTH+1];
	char password[USERDATA_LENGTH+1];
}User;

void PrintLoginMenu();                            //��ӡ��¼�˵�
void UserRegister(User* user1);					  //�û�ע��ģ��
int UserLogin(User* user1,char* fn);              //�û���¼ģ��
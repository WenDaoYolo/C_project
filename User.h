#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define USERDATA_LENGTH 11

typedef struct User{
	char admin[USERDATA_LENGTH+1];
	char password[USERDATA_LENGTH+1];
}User;

void PrintLoginMenu();                            //打印登录菜单
void UserRegister(User* user1);					  //用户注册模块
int UserLogin(User* user1,char* fn);              //用户登录模块
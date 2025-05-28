#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DEFAULT 3                           //通讯录初始容量
#define INC_DEF 2                           //通讯录容量增长单位
#define LENGTH 77                           //通讯录边框长度

typedef struct PeoInfo {                    //构造联系人信息类
	char name[20];
	char sex[5];
	int age;
	char tele[12];
	char addr[22];
}PeoInfo;

typedef struct Contact {                     //构造通讯录类
	int count;
	int capacity;
	PeoInfo* PeopleInfomation;
}Contact;

void InitContact(Contact* con,char* fn);      //初始化通讯录
void Destroy(Contact* con,char* fn);          //销毁通讯录

void DisplayIndexMenu();                      //打印主菜单
void CheckCapacity(Contact* con);             //通讯录增容检查

void AddContact(Contact* con);                //添加联系人
void DeleteContact(Contact* con);             //删除联系人
void SearchContact(Contact* con);             //查找联系人
void ModifyContact(Contact* con);             //修改联系人
void SortContact(Contact* con);               //排序通讯录

void DisplayContact(Contact* con);            //查看通讯录




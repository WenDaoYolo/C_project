#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 25
#define MAX_PEO 1000

typedef struct PeoInfo {            //���������Ϣ��
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contact {            //����ͨѶ¼��  
	PeoInfo PeoInfo_1[MAX_PEO];
	int count;                      //��¼��ǰͨѶ¼����ЧԪ�ظ���
}Contact;

void PrintIndexMenu();              //��ӡ���˵�
void initContact(Contact* pcon);    //��ʼ��ͨѶ¼
void AddContact(Contact* pcon);     //�����ϵ��
void DisplayContact(Contact* pcon); //��ʾͨѶ¼��Ϣ
void DeleteContact(Contact* pcon);  //ɾ����ϵ��
void ModifyContact(Contact* pcon);  //�޸���ϵ��
void SearchContact(Contact* pcon);  //������ϵ��
void SortContact(Contact* pcon);    //������ϵ��


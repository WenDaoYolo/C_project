#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DEFAULT 3                           //ͨѶ¼��ʼ����
#define INC_DEF 2                           //ͨѶ¼����������λ
#define LENGTH 77                           //ͨѶ¼�߿򳤶�

typedef struct PeoInfo {                    //������ϵ����Ϣ��
	char name[20];
	char sex[5];
	int age;
	char tele[12];
	char addr[22];
}PeoInfo;

typedef struct Contact {                     //����ͨѶ¼��
	int count;
	int capacity;
	PeoInfo* PeopleInfomation;
}Contact;

void InitContact(Contact* con,char* fn);      //��ʼ��ͨѶ¼
void Destroy(Contact* con,char* fn);          //����ͨѶ¼

void DisplayIndexMenu();                      //��ӡ���˵�
void CheckCapacity(Contact* con);             //ͨѶ¼���ݼ��

void AddContact(Contact* con);                //�����ϵ��
void DeleteContact(Contact* con);             //ɾ����ϵ��
void SearchContact(Contact* con);             //������ϵ��
void ModifyContact(Contact* con);             //�޸���ϵ��
void SortContact(Contact* con);               //����ͨѶ¼

void DisplayContact(Contact* con);            //�鿴ͨѶ¼




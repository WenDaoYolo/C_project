#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"

//����ר��ģ��**********************************************************************

	//�����ֲ�����ϵ��(���ڷ����±꣬�����ڷ���-1)
	static int Find(Contact* con, char* str) {
		int i = 0;
		for (i = 0; i < con->count; i++) {
			if (strcmp((con->PeopleInfomation + i)->name, str) == 0)
			{
				return i;
			}
		}
		return -1;
	}

	//�����������Ԫ�رȽϷ���
	static int CmpByName(const void* e1,const void* e2 ) {
		return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
	}

	//�����������Ԫ�رȽϷ���
	static int CmpByAge(const void* e1,const void* e2) {
		return ((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age;
	}

	//�ж�ͨѶ¼�Ƿ�Ϊ��
	static int ChekContactIsNUll(Contact* con) {
		if (con->count == 0) {
			printf("ͨѶ¼Ϊ��!\n");
			return 1;
		}
		return 0;
	}
	//�ļ�����
	static void InitloadContact(Contact* con,char* fn) {
	FILE* ptr = fopen(strcat(fn, ".txt"), "rb");
	if (ptr == NULL) {
		perror("InitloadContact/fopen");
		return;
	}
		size_t tmp = 0;
		while ((tmp = fread((con->PeopleInfomation) + (con->count), sizeof(PeoInfo), 1, ptr)) == 1) {
				con->count++;
			CheckCapacity(con);
		}
		fclose(ptr);
		ptr = NULL;
	}
	
	//�ļ�����
	static void SaveContact(Contact* con,char* fn) {
	FILE* ptr=fopen(fn, "wb");
	if (ptr == NULL) {
		perror("SaveContact/fopen");
		return;
	}
	int i = 0;
	for (i = 0; i < con->count; i++) {
		fwrite(con->PeopleInfomation+i,sizeof(PeoInfo),1,ptr);
	}
	fclose(ptr);
	ptr = NULL;
}

	//��ӡͨѶ¼���±߿�
	static void PrintUpAndDownBorder() {
		putchar('*');
		for (int k = 0; k < LENGTH; k++)
			putchar('-');
		putchar('*');
		putchar('\n');
	}

//********************************************************************************

void InitContact(Contact* con,char* fn) {
	con->count = 0;
	con->capacity = DEFAULT;
	con->PeopleInfomation=(PeoInfo*)calloc(DEFAULT , sizeof(PeoInfo));
	if (con->PeopleInfomation == NULL) {
		perror("InitContact");
		return;
	}
	InitloadContact(con,fn);
}

void DisplayIndexMenu() {
	printf("=************************=\n");
	printf("      Contact System      \n");
	printf("       1.�����ϵ��       \n");
	printf("       2.ɾ����ϵ��       \n");
	printf("       3.������ϵ��       \n");
	printf("       4.�޸���ϵ��       \n");
	printf("       5.����ͨѶ¼       \n");
	printf("       6.�鿴ͨѶ¼       \n");
	printf("       0.�˳�ͨѶ¼       \n");
	printf("=************************=\n");
}

void Destroy(Contact* con,char* fn) {
	SaveContact(con,fn);
	free(con->PeopleInfomation);
	con->PeopleInfomation = NULL;
}

void CheckCapacity(Contact* con) {
	if (con->count == con->capacity)
	{
		PeoInfo* tmp=NULL;
		tmp=(PeoInfo*)realloc(con->PeopleInfomation,((con->capacity) + INC_DEF) * sizeof(PeoInfo));
		if (tmp != NULL)
		{
			con->PeopleInfomation = tmp;
			tmp = NULL;
			con->capacity += INC_DEF;
			printf("���ݳɹ�!\n");
		}
		else
			printf("����ʧ��!\n");
	}
}

void AddContact(Contact* con) {
	CheckCapacity(con);
	int j = con->count;
	printf("����>");
	scanf("%s", con->PeopleInfomation[j].name);
	printf("�Ա�>");
	scanf("%s", con->PeopleInfomation[j].sex);
	printf("����>");
	scanf("%d", &(con->PeopleInfomation[j].age));
	printf("�绰>");
	scanf("%s", con->PeopleInfomation[j].tele);
	printf("��ַ>");
	scanf("%s", con->PeopleInfomation[j].addr);
	printf("\n��ӳɹ�!\n");
	con->count++;
}

void DeleteContact(Contact* con) {
	if (ChekContactIsNUll(con))
		return;
	char str[25] = { 0 };
	int i = 0;
	printf("��������ϵ������>");
	scanf("%s", str);
	if ((i = Find(con, str)) == -1)
	{
		printf("��ϵ�˲�����!\n");
		return;
	}
	else {
		while (i < con->count) {
			memcpy(con->PeopleInfomation+i, con->PeopleInfomation+i+1, sizeof(PeoInfo));
			i++;
		}
		printf("ɾ���ɹ�!\n");
		con->count--;
	}
}

void DisplayContact(Contact* con) {
	if (ChekContactIsNUll(con))
		return;
	int i = 0;
	PrintUpAndDownBorder();
	printf("|%-20s\t%-5s\t%-2s\t%-12s\t%-22s|\n", "����", "�Ա�", "����", "�ֻ���", "��ַ");
	for (i = 0; i < con->count; i++)
		printf("|%-20s\t%-5s\t%-2d\t%-12s\t%-22s|\n",
			con->PeopleInfomation[i].name,
			con->PeopleInfomation[i].sex,
			con->PeopleInfomation[i].age,
			con->PeopleInfomation[i].tele,
			con->PeopleInfomation[i].addr
			);
	PrintUpAndDownBorder();
}
void SortContact(Contact* con){
	if (ChekContactIsNUll(con))
		return;
	int SortChoose = 0;
	printf("1.���� 2.����\n");
	printf("��ѡ�������������>");
	scanf("%d", &SortChoose);
	if (SortChoose == 1)
		qsort(con->PeopleInfomation,con->count,sizeof(PeoInfo),CmpByName);
	else if(SortChoose==2)
		qsort(con->PeopleInfomation, con->count, sizeof(PeoInfo), CmpByAge);
	else
	{
		printf("ѡ�����!\n");
		return;
	}
	printf("����ɹ�!\n");
}

void SearchContact(Contact* con) {
	if (ChekContactIsNUll(con))
		return;
	char name[20] = {0};
	int i=0;
	printf("��������ϵ������>");
	scanf("%s", name);
	if ((i = Find(con, name)) == -1) {
		printf("��ϵ�˲�����!\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-2d\t%-12s\t%-22s\n",
			con->PeopleInfomation[i].name,
			con->PeopleInfomation[i].sex,
			con->PeopleInfomation[i].age,
			con->PeopleInfomation[i].tele,
			con->PeopleInfomation[i].addr
		);
	}
}

void ModifyContact(Contact* con) {
	if (ChekContactIsNUll(con))
		return;
	char name[20] = { 0 };
	int i = 0;
	printf("������Ҫ�޸ĵ���ϵ�˵�����>");
	scanf("%s", name);
	if ((i = Find(con, name)) == -1) {
		printf("��ϵ�˲�����!\n");
		return;
	}
	else
	{
		printf("����>");
		scanf("%s", con->PeopleInfomation[i].name);
		printf("�Ա�>");
		scanf("%s", con->PeopleInfomation[i].sex);
		printf("����>");
		scanf("%d", &(con->PeopleInfomation[i].age));
		printf("�绰>");
		scanf("%s", con->PeopleInfomation[i].tele);
		printf("��ַ>");
		scanf("%s", con->PeopleInfomation[i].addr);
		printf("�޸ĳɹ�!\n");
	}
}

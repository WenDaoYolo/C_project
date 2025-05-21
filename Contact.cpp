#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"

void PrintIndexMenu() {
	printf("************************\n");
	printf("        Contact         \n");
	printf("        1.add           \n");
	printf("        2.delete        \n");
	printf("        3.modify        \n");
	printf("        4.search        \n");
	printf("        5.sort          \n");
	printf("        6.display       \n");
	printf("        0.exit          \n");
	printf("************************\n");
}

void initContact(Contact* pcon) {
	pcon->count = 0;
	memset(pcon->PeoInfo_1, 0, sizeof(pcon->PeoInfo_1));
}

void AddContact(Contact* pcon) {
	if (pcon->count == MAX_PEO)
	{
		printf("ͨѶ¼����!\n");
		return;
	}
	printf("����>");
	scanf("%s", pcon->PeoInfo_1[pcon->count].name);
	printf("�Ա�>");
	scanf("%s", pcon->PeoInfo_1[pcon->count].sex);
	printf("����>");
	scanf("%d", &(pcon->PeoInfo_1[pcon->count].age));
	printf("�绰>");
	scanf("%s", pcon->PeoInfo_1[pcon->count].tele);
	printf("��ַ>");
	scanf("%s", pcon->PeoInfo_1[pcon->count].addr);
	printf("��ӳɹ�!\n");
	pcon->count++;
}

void DisplayContact(Contact* pcon) {
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-25s\n", "����", "�Ա�", "����", "�绰����", "��ַ");
	for (i = 0; i < pcon->count; i++) {
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-25s\n",
			pcon->PeoInfo_1[i].name,
			pcon->PeoInfo_1[i].sex,
			pcon->PeoInfo_1[i].age,
			pcon->PeoInfo_1[i].tele,
			pcon->PeoInfo_1[i].addr);
	}
}

/*
ɾ��ģ���˼�룺αɾ����ͨ�����Ǻͼ��������Ƶķ�ʽ�ﵽɾ��Ч��
�Ȳ���Ҫɾ����Ԫ���±꣬�Ӹ�λ�ô��������е�Ԫ�ؾ���ǰŲ��һλ
���ԣ��������ڴ��ϲ�û��ʵ��ɾ����ͨ��������������Ч��Ԫ�ظ���
ͬ�������Ԫ��ʵ���Ͼ����޸Ĳ�����Ԫ�أ�Ȼ�����Ӽ�����

���Է��֣����ҡ�ɾ�����޸Ĺ���ģ�鶼��Ҫȥ����Ԫ�ص�λ�ã����Կ��Զ���һ��ģ���ר�ú���
*/


//ģ���ר�ú�����������static����ʹ��ֻ�ڱ�Դ�ļ���ʹ�ã��Ӷ���߰�ȫ��
//ͨ�����ֲ��ң��������򷵻�Ԫ�������±꣬�������ڷ���-1
static int FindByName(Contact* pcon, char* name) {
	int i = 0;
	for (i = 0; i < pcon->count; i++) {
		if (strcmp(pcon->PeoInfo_1[i].name, name) == 0)
			return i;
	}
	return -1;
}

void DeleteContact(Contact* pcon) {
	char name[MAX_NAME];
	int pos = 0;
	if (pcon->count == 0)
	{
		printf("ͨѶ¼Ϊ��!\n");
		return;
	}
	printf("������Ҫɾ����ϵ�˵�����>");
	scanf("%s", name);
	pos = FindByName(pcon, name);
	if (pos == -1)
	{
		printf("��ϵ�˲�����!\n");
		return;
	}
	int i = 0;
	for (i = pos; i < pcon->count - 1; i++) {
		pcon->PeoInfo_1[i] = pcon->PeoInfo_1[i + 1];
	}
	printf("ɾ���ɹ�!\n");
	pcon->count--;
}

void ModifyContact(Contact* pcon) {
	char name[MAX_NAME];
	if (pcon->count == 0)
	{
		printf("ͨѶ¼Ϊ��!\n");
		return;
	}
	printf("���������޸ĵ���ϵ������>");
	scanf("%s", &name);
	int pos = FindByName(pcon, name);
	if (pos == -1)
	{
		printf("��ϵ�˲�����!\n");
		return;
	}
	printf("����>");
	scanf("%s", pcon->PeoInfo_1[pos].name);
	printf("�Ա�>");
	scanf("%s", pcon->PeoInfo_1[pos].sex);
	printf("����>");
	scanf("%d", &(pcon->PeoInfo_1[pos].age));
	printf("�绰>");
	scanf("%s", pcon->PeoInfo_1[pos].tele);
	printf("��ַ>");
	scanf("%s", pcon->PeoInfo_1[pos].addr);
	printf("�޸ĳɹ�!\n");
}

void SearchContact(Contact* pcon) {
	char name[MAX_NAME];
	if (pcon->count == 0)
	{
		printf("ͨѶ¼Ϊ��!\n");
		return;
	}
	printf("������Ҫ��ѯ����ϵ������>");
	scanf("%s", name);
	int pos = FindByName(pcon, name);
	if (pos == -1)
	{
		printf("��ϵ�˲�����!\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-25s\n",
			pcon->PeoInfo_1[pos].name,
			pcon->PeoInfo_1[pos].sex,
			pcon->PeoInfo_1[pos].age,
			pcon->PeoInfo_1[pos].tele,
			pcon->PeoInfo_1[pos].addr);
	}
}

int CmpByAge(const void* e1, const void* e2) {
	return ((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age;
}

int CmpByName(const void* e1, const void* e2) {
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}


void SortContact(Contact* pcon) {
	int choose;
	if (pcon->count == 0)
	{
		printf("ͨѶ¼Ϊ��!\n");
		return;
	}
	printf("��ѡ����������\n");
	printf("1.����\n");
	printf("2.����\n");
	printf(">");
	scanf("%d", &choose);
	if (choose == 1)
		qsort(pcon->PeoInfo_1, pcon->count, sizeof(PeoInfo), CmpByName);
	else if (choose == 2)
		qsort(pcon->PeoInfo_1, pcon->count, sizeof(PeoInfo), CmpByAge);
	else
	{
		printf("�������!\n");
		return;
	}
	printf("����ɹ�!\n");
}
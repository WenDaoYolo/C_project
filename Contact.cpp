#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"

//函数专用模块**********************************************************************

	//按名字查找联系人(存在返回下标，不存在返回-1)
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

	//按名字排序的元素比较方法
	static int CmpByName(const void* e1,const void* e2 ) {
		return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
	}

	//按年龄排序的元素比较方法
	static int CmpByAge(const void* e1,const void* e2) {
		return ((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age;
	}

	//判断通讯录是否为空
	static int ChekContactIsNUll(Contact* con) {
		if (con->count == 0) {
			printf("通讯录为空!\n");
			return 1;
		}
		return 0;
	}
	//文件加载
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
	
	//文件保存
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

	//打印通讯录上下边框
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
	printf("       1.添加联系人       \n");
	printf("       2.删除联系人       \n");
	printf("       3.查找联系人       \n");
	printf("       4.修改联系人       \n");
	printf("       5.排序通讯录       \n");
	printf("       6.查看通讯录       \n");
	printf("       0.退出通讯录       \n");
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
			printf("增容成功!\n");
		}
		else
			printf("增容失败!\n");
	}
}

void AddContact(Contact* con) {
	CheckCapacity(con);
	int j = con->count;
	printf("姓名>");
	scanf("%s", con->PeopleInfomation[j].name);
	printf("性别>");
	scanf("%s", con->PeopleInfomation[j].sex);
	printf("年龄>");
	scanf("%d", &(con->PeopleInfomation[j].age));
	printf("电话>");
	scanf("%s", con->PeopleInfomation[j].tele);
	printf("地址>");
	scanf("%s", con->PeopleInfomation[j].addr);
	printf("\n添加成功!\n");
	con->count++;
}

void DeleteContact(Contact* con) {
	if (ChekContactIsNUll(con))
		return;
	char str[25] = { 0 };
	int i = 0;
	printf("请输入联系人姓名>");
	scanf("%s", str);
	if ((i = Find(con, str)) == -1)
	{
		printf("联系人不存在!\n");
		return;
	}
	else {
		while (i < con->count) {
			memcpy(con->PeopleInfomation+i, con->PeopleInfomation+i+1, sizeof(PeoInfo));
			i++;
		}
		printf("删除成功!\n");
		con->count--;
	}
}

void DisplayContact(Contact* con) {
	if (ChekContactIsNUll(con))
		return;
	int i = 0;
	PrintUpAndDownBorder();
	printf("|%-20s\t%-5s\t%-2s\t%-12s\t%-22s|\n", "姓名", "性别", "年龄", "手机号", "地址");
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
	printf("1.姓名 2.年龄\n");
	printf("请选择你的排序依据>");
	scanf("%d", &SortChoose);
	if (SortChoose == 1)
		qsort(con->PeopleInfomation,con->count,sizeof(PeoInfo),CmpByName);
	else if(SortChoose==2)
		qsort(con->PeopleInfomation, con->count, sizeof(PeoInfo), CmpByAge);
	else
	{
		printf("选择错误!\n");
		return;
	}
	printf("排序成功!\n");
}

void SearchContact(Contact* con) {
	if (ChekContactIsNUll(con))
		return;
	char name[20] = {0};
	int i=0;
	printf("请输入联系人姓名>");
	scanf("%s", name);
	if ((i = Find(con, name)) == -1) {
		printf("联系人不存在!\n");
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
	printf("请输入要修改的联系人的姓名>");
	scanf("%s", name);
	if ((i = Find(con, name)) == -1) {
		printf("联系人不存在!\n");
		return;
	}
	else
	{
		printf("姓名>");
		scanf("%s", con->PeopleInfomation[i].name);
		printf("性别>");
		scanf("%s", con->PeopleInfomation[i].sex);
		printf("年龄>");
		scanf("%d", &(con->PeopleInfomation[i].age));
		printf("电话>");
		scanf("%s", con->PeopleInfomation[i].tele);
		printf("地址>");
		scanf("%s", con->PeopleInfomation[i].addr);
		printf("修改成功!\n");
	}
}

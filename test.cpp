#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
/*
项目要求：编写通讯录模块

1.能存储1000个联系人的信息
存储的信息包括：姓名、性别、年龄、地址、手机号

2.能对通讯录中的信息进行修改
包括：添加联系人、删除联系人、修改联系人信息、通讯录信息查询、通讯录信息排序、查看通讯录所有信息

扩展：解决同名问题

*/
enum option {               //定义操作标识符
	EXIT,
	ADD,
	DELETE,
	MODIFY,
	SEARCH,
	SORT,
	DISPLAY
};

int main() {
	int IndexMenuChoose;
	Contact con;            //创建通讯录
	initContact(&con);      //初始化通讯录

	do {
		PrintIndexMenu();
		printf("请输入>");
		scanf("%d", &IndexMenuChoose);
		switch (IndexMenuChoose) {
		case ADD:
			AddContact(&con);
			break;
		case DELETE:
			DeleteContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case DISPLAY:
			DisplayContact(&con);
			break;
		case EXIT:
			break;
		default:
			printf("输入错误!\n");
			break;
		}
	} while (IndexMenuChoose);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
/*
��ĿҪ�󣺱�дͨѶ¼ģ��

1.�ܴ洢1000����ϵ�˵���Ϣ
�洢����Ϣ�������������Ա����䡢��ַ���ֻ���

2.�ܶ�ͨѶ¼�е���Ϣ�����޸�
�����������ϵ�ˡ�ɾ����ϵ�ˡ��޸���ϵ����Ϣ��ͨѶ¼��Ϣ��ѯ��ͨѶ¼��Ϣ���򡢲鿴ͨѶ¼������Ϣ

��չ�����ͬ������

*/
enum option {               //���������ʶ��
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
	Contact con;            //����ͨѶ¼
	initContact(&con);      //��ʼ��ͨѶ¼

	do {
		PrintIndexMenu();
		printf("������>");
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
			printf("�������!\n");
			break;
		}
	} while (IndexMenuChoose);
	return 0;
}
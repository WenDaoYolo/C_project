#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
#include "User.h"

/*
	��Ŀ˵����
	1.ͨѶ¼ϵͳ���ö�̬����ģʽ
	2.ͨѶ¼ϵͳ��������ɾ���顢�ġ��š���ʾ�Ļ�������
	3.ͨѶ¼���м���ģ����Դ洢���ݣ���׷�Ӹ����˻�����
*/

enum ContactOption {
	EXIT,
	ADD,
	DELETE,
	SEARCH,
	MODIFY,
	SORT,
	DISPLAY,
};

enum LoginOption {
	LOGIN=1,
	REGISTER=2
};

int main() {

	int KEY = 0;                                 //��Կ
	int matching = 0;                            //ƥ����
	char filename[USERDATA_LENGTH+1+4] = { 0 };  //�û��ļ�·��,+4Ԥ��".txt"�ռ�

	//��¼ģ��-----------------------
	{
		int LoginChoose = 1;
		User user1 = {0};
		while (LoginChoose&&KEY==0) {
			
			PrintLoginMenu();
			printf("��ѡ��>");
			scanf("%d", &LoginChoose);
			switch (LoginChoose) {
			case LOGIN:
				matching =UserLogin(&user1,filename);
				KEY = matching;
				break;
			case REGISTER:
				UserRegister(&user1);
				break;
			case EXIT:
				break;
			default:
				printf("�������!\a\n");
			}
		}
	}
	//--------------------------------
	
	//ͨѶ¼ģ��----------------------
	if (KEY)
	{
		Contact con;
		int IndexChoose = 1;
		InitContact(&con,filename);
		while (IndexChoose) {
			DisplayIndexMenu();
			printf("��ѡ��>");
			scanf("%d", &IndexChoose);
			switch (IndexChoose) {
			case ADD:
				AddContact(&con);
				break;
			case DELETE:
				DeleteContact(&con);
				break;
			case SEARCH:
				SearchContact(&con);
				break;
			case MODIFY:
				ModifyContact(&con);
				break;
			case SORT:
				SortContact(&con);
				break;
			case DISPLAY:
				DisplayContact(&con);
				break;
			case EXIT:
				Destroy(&con,filename);
				break;
			default:
				printf("�������!\a\n");
				break;
			}
		}
	}
	//--------------------------------

	return 0;
}
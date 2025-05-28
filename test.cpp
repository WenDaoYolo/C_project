#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
#include "User.h"

/*
	项目说明书
	1.通讯录系统采用动态增容模式
	2.通讯录系统具有增、删、查、改、排、显示的基础功能
	3.通讯录具有记忆模块可以存储数据，并追加个人账户功能
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

	int KEY = 0;                                 //密钥
	int matching = 0;                            //匹配项
	char filename[USERDATA_LENGTH+1+4] = { 0 };  //用户文件路径,+4预留".txt"空间

	//登录模块-----------------------
	{
		int LoginChoose = 1;
		User user1 = {0};
		while (LoginChoose&&KEY==0) {
			
			PrintLoginMenu();
			printf("请选择>");
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
				printf("输入错误!\a\n");
			}
		}
	}
	//--------------------------------
	
	//通讯录模块----------------------
	if (KEY)
	{
		Contact con;
		int IndexChoose = 1;
		InitContact(&con,filename);
		while (IndexChoose) {
			DisplayIndexMenu();
			printf("请选择>");
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
				printf("输入错误!\a\n");
				break;
			}
		}
	}
	//--------------------------------

	return 0;
}
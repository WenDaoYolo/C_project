#define _CRT_SECURE_NO_WARNINGS 1
#include "NumberGuess.h"

void PrintMenu() {
	printf("=================================================\n");
	printf("  Menu��                                         \n");
	printf("                   1:��ʼ��Ϸ                    \n");
	printf("                   2:��Ϸ����                    \n");
	printf("                   3:�˳���Ϸ                    \n");
	printf("                                                 \n");
	printf("=================================================\n");
}

void PrintRule() {
	printf("��Ϸ����:��һ��1-100֮������֣��������룬�س�ȷ��\n");
}

void PrintResult(int count,int mincount) {
	printf("=================================================\n");
	printf("  Result��                                       \n");
	printf("                  ��ǰ�غϴ���:%d                \n",count);
	printf("                  ��ʷ��Ѽ�¼:%d                \n",mincount);
	printf("                                                 \n");
	printf("=================================================\n");

}

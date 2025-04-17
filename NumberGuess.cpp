#define _CRT_SECURE_NO_WARNINGS 1
#include "NumberGuess.h"

void PrintMenu() {
	printf("=================================================\n");
	printf("  Menu：                                         \n");
	printf("                   1:开始游戏                    \n");
	printf("                   2:游戏规则                    \n");
	printf("                   3:退出游戏                    \n");
	printf("                                                 \n");
	printf("=================================================\n");
}

void PrintRule() {
	printf("游戏规则:猜一个1-100之间的数字，键盘输入，回车确定\n");
}

void PrintResult(int count,int mincount) {
	printf("=================================================\n");
	printf("  Result：                                       \n");
	printf("                  当前回合次数:%d                \n",count);
	printf("                  历史最佳记录:%d                \n",mincount);
	printf("                                                 \n");
	printf("=================================================\n");

}

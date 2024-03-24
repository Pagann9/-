#include "stack_Head.h"
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

LinkStack Head;

int main()
{
	//接收菜单界面返回值、链栈长度、数据
	ElemType MENU_num = 1, length, data; 
	//接收基本功能函数返回值
	Status P_initLStack, P_isEmptyLStack, P_stackLength, P_pushLStack, P_popLStack, P_getTopLStack, P_clearLStack, P_print, P_destroyLStack;
	while (MENU_num != 0)
	{
		MENU_num = MENU();  //菜单
		switch (MENU_num)
		{
		case 1:  //初始化
			P_initLStack = initLStack(&Head);
			printf("初始化：%d", P_initLStack);break;
		case 2:  //判空
			P_isEmptyLStack = isEmptyLStack(&Head);
			printf("%d", P_isEmptyLStack); break;
		case 3:  //长度
			P_stackLength = LStackLength(&Head, &length);
			printf("%d/%d", P_stackLength, length); break;
		case 4:  //入栈
			printf("请输入数据：");
			scanf_s("%d", &data);
			P_pushLStack = pushLStack(&Head, data);
			printf("%d", P_pushLStack); break;
		case 5:  //出栈
			P_popLStack = popLStack(&Head, &data);
			printf("%d/%d", P_popLStack, data); break;
		case 6:  //获取栈头元素
			P_getTopLStack = getTopLStack(&Head, &data);
			printf("%d/%d", P_getTopLStack, data); break;
		case 7:  //清空
			P_clearLStack = clearLStack(&Head);
			printf("%d", P_clearLStack); break;
		case 8:  //打印
			P_print = print(&Head);
			printf("%d", P_print); break;
		case 9:  //销毁
			P_destroyLStack = destroyLStack(&Head);
			printf("%d", P_destroyLStack); break;
		case 0:return 0;
		}
		system("pause");
		system("cls");
	}
}

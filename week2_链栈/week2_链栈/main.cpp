#include "pch.h"
#include "pch.h"
#include "LinkStack2.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

ElemType MENU();

LinkStack* Head = NULL;

int main()
{
	ElemType MENU_num = 1, length, data;
	Status P_initLStack, P_isEmptyLStack, P_stackLength, P_pushLStack, P_popLStack, P_getTopLStack, P_clearLStack, P_print, P_destroyLStack;
	while (MENU_num != 0)
	{
		MENU_num = MENU();
		switch (MENU_num)
		{
		case 1:
			P_initLStack = initLStack(Head);
			printf("初始化：%d", P_initLStack);
		case 2:
			P_isEmptyLStack = isEmptyLStack(Head);
			printf("%d", P_isEmptyLStack); break;
		case 3:
			P_stackLength = LStackLength(Head, &length);
			printf("%d/%d", P_stackLength, length); break;
		case 4:
			printf("请输入数据：");
			scanf_s("%d", &data);
			P_pushLStack = pushLStack(Head, data);
			printf("%d", P_pushLStack); break;
		case 5:
			P_popLStack = popLStack(Head, &data);
			printf("%d/%d", P_popLStack, data); break;
		case 6:
			P_getTopLStack = getTopLStack(Head, &data);
			printf("%d/%d", P_getTopLStack, data); break;
		case 7:
			P_clearLStack = clearLStack(Head);
			printf("%d", P_clearLStack); break;
		case 8:
			P_print = print(Head);
			printf("%d", P_print); break;
		case 9:
			P_destroyLStack = destroyLStack(Head);
			printf("%d", P_destroyLStack); break;
		case 0:return 0;
		}
		system("pause");
		system("cls");
	}
}


#include "pch.h"
#include "Head.h"
#include <stdio.h>

ElemType MENU()
{
    ElemType MENU_num;
    printf("1.判空\n2.长度\n3.入栈\n4.出栈\n5.求栈顶\n6.销毁栈\n0.退出\n请输 入；");
    scanf_s("%d", &MENU_num);
    return MENU_num;
}

void initStack(LINK* L)
{
	(*L)->top = NULL;
}

ElemType stackEmpty(LINK* L)
{
	if ((*L)->top == NULL) return 1;
	else return 0;
}
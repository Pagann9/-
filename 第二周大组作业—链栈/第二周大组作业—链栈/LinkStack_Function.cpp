#include "pch.h"
#include "Head.h"
#include <stdio.h>

ElemType MENU()
{
    ElemType MENU_num;
    printf("1.�п�\n2.����\n3.��ջ\n4.��ջ\n5.��ջ��\n6.����ջ\n0.�˳�\n���� �룻");
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
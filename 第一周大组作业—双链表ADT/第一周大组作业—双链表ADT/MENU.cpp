#include "duLinkedList.h"
#include "pch.h"
#include <stdio.h>

ElemType menu();

ElemType menu()
{
	ElemType menu_num;
	printf("1.�½�����\n");
	scanf_s("%d", &menu_num);
	return menu_num;
}
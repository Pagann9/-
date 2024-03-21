#include "duLinkedList.h"
#include "pch.h"
#include <stdio.h>

ElemType menu();

ElemType menu()
{
	ElemType menu_num;
	printf("1.ÐÂ½¨Á´±í\n");
	scanf_s("%d", &menu_num);
	return menu_num;
}
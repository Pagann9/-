#include "pch.h"
#include <stdio.h>
#include "duLinkedList.h"

ElemType menu();

ElemType menu()
{
	ElemType menu_num;
	printf("1.�½�����\n2.��������\n3.ǰ����ڵ�\n4.�����ڵ�\n5.ɾ���ڵ�\n6.��������\n0.�˳�\n�����룺");
	scanf_s("%d", &menu_num);
	return menu_num;
}
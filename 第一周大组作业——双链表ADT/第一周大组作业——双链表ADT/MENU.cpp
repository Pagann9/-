#include "pch.h"
#include <stdio.h>
#include "duLinkedList.h"

ElemType menu();

ElemType menu()
{
	ElemType menu_num;
	printf("1.新建链表\n2.销毁链表\n3.前插入节点\n4.后插入节点\n5.删除节点\n6.遍历链表\n0.退出\n请输入：");
	scanf_s("%d", &menu_num);
	return menu_num;
}
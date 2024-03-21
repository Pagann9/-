#include <stdio.h>
#include "pch.h"
#include "linkedList.h"
#include "head.h"

ElemType FunctionMenu()
{
    ElemType menu_num;
    printf("1.创建链表\n2.销毁链表\n3.插入节点\n4.删除节点\n5.遍历链表\n6.查询节点\n7.反转链表\n8.奇偶调换\n9.中间节点\n0.退出\n请输入:");
    scanf_s("%d", &menu_num);
    return menu_num;
}
#include <stdio.h>
#include "pch.h"
#include "linkedList.h"
#include "head.h"

ElemType FunctionMenu()
{
    ElemType menu_num;
    printf("1.��������\n2.��������\n3.����ڵ�\n4.ɾ���ڵ�\n5.��������\n6.��ѯ�ڵ�\n7.��ת����\n8.��ż����\n9.�м�ڵ�\n0.�˳�\n������:");
    scanf_s("%d", &menu_num);
    return menu_num;
}
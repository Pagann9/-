#pragma once
#include "pch.h"
#include <malloc.h>
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#define OVERFLOW -1

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	char data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr 	 top;	  //ջ��ָ��
	int		 count;  //ջ��Ԫ�ظ���
}LinkStack;

typedef LinkStack* LINK;

ElemType MENU();
//��ջ
Status initLStack(LinkStack* s);//��ʼ��ջ
int isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��
char getTopLStack(LinkStack* s);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack* s);//���ջ
Status destroyLStack(LinkStack* s);//����ջ
Status LStackLength(LinkStack* s, int* length);//���ջ����
Status pushLStack(LinkStack* s, char data);//��ջ
char popLStack(LinkStack* s);//��ջ
Status print(LinkStack* s);//��ӡջ
ElemType getpriority(char p);

ElemType Possess_1(char* infix, char* postfix);
void Possess_2(char* postfix);
#endif

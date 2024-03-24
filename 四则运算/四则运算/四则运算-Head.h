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
	LinkStackPtr 	 top;	  //栈顶指针
	int		 count;  //栈中元素个数
}LinkStack;

typedef LinkStack* LINK;

ElemType MENU();
//链栈
Status initLStack(LinkStack* s);//初始化栈
int isEmptyLStack(LinkStack* s);//判断栈是否为空
char getTopLStack(LinkStack* s);//得到栈顶元素
Status clearLStack(LinkStack* s);//清空栈
Status destroyLStack(LinkStack* s);//销毁栈
Status LStackLength(LinkStack* s, int* length);//检测栈长度
Status pushLStack(LinkStack* s, char data);//入栈
char popLStack(LinkStack* s);//出栈
Status print(LinkStack* s);//打印栈
ElemType getpriority(char p);

ElemType Possess_1(char* infix, char* postfix);
void Possess_2(char* postfix);
#endif

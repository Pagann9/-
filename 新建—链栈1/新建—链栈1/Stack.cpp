#include "HEAD.h"
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
//链栈

//初始化栈
Status initLStack(LinkStack* s) {
	s = (LinkStack*)malloc(sizeof(LinkStack));
	s->top = NULL;
	s->count = 0;
	return (Status)SUCCESS;
}

//菜单界面
ElemType MENU()
{
	ElemType MENU_num;
	printf("1.初始化\n2.判空\n3.长度\n4.入栈\n5.出栈\n6.求栈顶\n7.清空栈\n8.打印栈\n9.销毁栈\n0.退出\n请输入；");
	scanf_s("%d", &MENU_num);
	return MENU_num;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s) {
	if (s == NULL)
	{
		printf("链栈不存在，请初始化！\n");
		return (Status)ERROR;
	}
	if (s->top == NULL) return (Status)SUCCESS;
	else return (Status)ERROR;
}

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s == NULL)
	{
		printf("链栈不存在，请初始化！\n");
		return (Status)ERROR;
	}
	if (s->top == NULL)
	{
		*e = 0;
		return (Status)ERROR;
	}
	*e = s->top->data;
	return (Status)SUCCESS;
}

//清空栈
Status clearLStack(LinkStack* s) {
	StackNode* s_clearLStack;
	if (s == NULL)
	{
		printf("链栈不存在，请初始化！\n");
		return (Status)ERROR;
	}
	if (s->top == NULL)
	{
		printf("栈为空！");
		return;
	}

	do
	{
		s_clearLStack = s->top;
		s->top = s->top->next;
		free(s_clearLStack);
		s->count--;
	} while (s->top != NULL);
	if (s->top == NULL) return (Status)SUCCESS;
	else return(Status)ERROR;
}

//销毁栈
Status destroyLStack(LinkStack* s) {
	if (s == NULL) return (Status)SUCCESS;
	clearLStack(s);
	free(s);
	if (s == NULL) return (Status)ERROR;
}

//检测栈长度
Status LStackLength(LinkStack* s, int* length) {
	if (s == NULL)
	{
		printf("链栈不存在，请初始化！\n");
		return (Status)ERROR;
	}
	*length = s->count;
	return (Status)SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, ElemType data) {
	StackNode* p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (s == NULL)
	{
		printf("链栈不存在，请初始化！\n");
		return (Status)ERROR;
	}
	p->data = data;
	if (s->count == 0)
	{
		s->top = p;
		s->top->next = NULL;
		s->count++;
	}
	else
	{
		p->next = s->top;
		s->top = p;
		s->count++;
	}
	if (s->top != NULL) return (Status)SUCCESS;
	else return (Status)ERROR;
}

//出栈
Status popLStack(LinkStack* s, ElemType* data) {
	StackNode* POP;
	if (s == NULL)
	{
		printf("链栈不存在，请初始化！\n");
		return (Status)ERROR;
	}
	if (s->top == NULL)
	{
		*data = 0;
		return (Status)ERROR;
	}
	else
	{
		POP = s->top;
		s->top = POP->next;
		*data = POP->data;
		delete(POP);
		s->count--;
		return (Status)SUCCESS;
	}
}

//打印栈
Status print(LinkStack* s) {
	StackNode* s_Print;
	if (s == NULL)
	{
		printf("链栈不存在，请初始化！\n");
		return (Status)ERROR;
	}
	if (s->top == NULL) return (Status)ERROR;
	else
	{
		s_Print = s->top;
		while (s_Print)
		{
			printf("%d ", s_Print->data);
			s_Print = s_Print->next;
		}
		return (Status)SUCCESS;
	}
}
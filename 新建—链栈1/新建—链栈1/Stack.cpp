#include "HEAD.h"
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack* s) {
	s = (LinkStack*)malloc(sizeof(LinkStack));
	s->top = NULL;
	s->count = 0;
	return (Status)SUCCESS;
}

//�˵�����
ElemType MENU()
{
	ElemType MENU_num;
	printf("1.��ʼ��\n2.�п�\n3.����\n4.��ջ\n5.��ջ\n6.��ջ��\n7.���ջ\n8.��ӡջ\n9.����ջ\n0.�˳�\n�����룻");
	scanf_s("%d", &MENU_num);
	return MENU_num;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	if (s == NULL)
	{
		printf("��ջ�����ڣ����ʼ����\n");
		return (Status)ERROR;
	}
	if (s->top == NULL) return (Status)SUCCESS;
	else return (Status)ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s == NULL)
	{
		printf("��ջ�����ڣ����ʼ����\n");
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

//���ջ
Status clearLStack(LinkStack* s) {
	StackNode* s_clearLStack;
	if (s == NULL)
	{
		printf("��ջ�����ڣ����ʼ����\n");
		return (Status)ERROR;
	}
	if (s->top == NULL)
	{
		printf("ջΪ�գ�");
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

//����ջ
Status destroyLStack(LinkStack* s) {
	if (s == NULL) return (Status)SUCCESS;
	clearLStack(s);
	free(s);
	if (s == NULL) return (Status)ERROR;
}

//���ջ����
Status LStackLength(LinkStack* s, int* length) {
	if (s == NULL)
	{
		printf("��ջ�����ڣ����ʼ����\n");
		return (Status)ERROR;
	}
	*length = s->count;
	return (Status)SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType data) {
	StackNode* p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (s == NULL)
	{
		printf("��ջ�����ڣ����ʼ����\n");
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

//��ջ
Status popLStack(LinkStack* s, ElemType* data) {
	StackNode* POP;
	if (s == NULL)
	{
		printf("��ջ�����ڣ����ʼ����\n");
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

//��ӡջ
Status print(LinkStack* s) {
	StackNode* s_Print;
	if (s == NULL)
	{
		printf("��ջ�����ڣ����ʼ����\n");
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
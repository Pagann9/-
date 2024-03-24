#include "pch.h"
#include "stack_Head.h"

//³õÊ¼»¯Õ»
Status initLStack(LinkStack* s) {
	s = (LinkStack*)malloc(sizeof(LinkStack));
	s->top = NULL;
	s->count = 0;
	return (Status)SUCCESS;
}

//²Ëµ¥½çÃæ
ElemType MENU()
{
	ElemType MENU_num;
	printf("1.³õÊ¼»¯\n2.ÅÐ¿Õ\n3.³¤¶È\n4.ÈëÕ»\n5.³öÕ»\n6.ÇóÕ»¶¥\n7.Çå¿ÕÕ»\n8.´òÓ¡Õ»\n9.Ïú»ÙÕ»\n0.ÍË³ö\nÇëÊäÈë£»");
	scanf_s("%d", &MENU_num);
	return MENU_num;
}

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
Status isEmptyLStack(LinkStack* s) {
	if (s->top == NULL) return (Status)SUCCESS;
	else return (Status)ERROR;
}

//µÃµ½Õ»¶¥ÔªËØ
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s->top == NULL)
	{
		*e = 0;
		return (Status)ERROR;  //ÅÐ¿Õ
	}
	*e = s->top->data;
	return (Status)SUCCESS;
}

//Çå¿ÕÕ»
Status clearLStack(LinkStack* s) {
	StackNode* s_clearLStack;
	if (s->top == NULL)
	{
		printf("Õ»Îª¿Õ£¡");
		return (Status)ERROR;  //ÅÐ¿Õ
	}

	do
	{
		s_clearLStack = s->top;
		s->top = s->top->next;
		free(s_clearLStack);
		s->count--;
	} while (s->top != NULL);
	if (s->top == NULL) return (Status)SUCCESS;  //¼ì²é
	else return(Status)ERROR;
}

//Ïú»ÙÕ»
Status destroyLStack(LinkStack* s) {
	if (s->top == NULL) return (Status)ERROR;  //ÅÐ¿Õ
	else
	{
		clearLStack(s);
		free(s->top);
		return (Status)SUCCESS;
	}
}

//¼ì²âÕ»³¤¶È
Status LStackLength(LinkStack* s, int* length) {
	*length = s->count;
	return (Status)SUCCESS;
}

//ÈëÕ»
Status pushLStack(LinkStack* s, ElemType data) {
	StackNode* p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	if (s->count == 0)  //¿ÕÕ»
	{
		s->top = p;
		s->top->next = NULL;
		s->count++;
	}
	else  //Õ»·Ç¿Õ
	{
		p->next = s->top;
		s->top = p;
		s->count++;
	}
	if (s->top != NULL) return (Status)SUCCESS;  //¼ì²é
	else return (Status)ERROR;
}

//³öÕ»
Status popLStack(LinkStack* s, ElemType* data) {
	StackNode* POP;
	if (s->top == NULL)  //ÅÐ¿Õ
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

//´òÓ¡Õ»
Status print(LinkStack* s) {
	StackNode* s_Print;
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


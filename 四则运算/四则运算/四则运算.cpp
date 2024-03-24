#include "pch.h"
#include "��������-Head.h"

extern LinkStack Head;

//��ʼ��ջ
Status initLStack(LinkStack* s) {
	s = (LinkStack*)malloc(sizeof(LinkStack));
	s->top = NULL;
	s->count = 0;
	return (Status)SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
int isEmptyLStack(LinkStack* s) {
	if (s->top == NULL) return 1;
	else return 0;
}

//�õ�ջ��Ԫ��
char getTopLStack(LinkStack* s) {
	if (s->top == NULL) return '\0';  //�п�
	else return s->top->data;
}

//���ջ
Status clearLStack(LinkStack* s) {
	StackNode* s_clearLStack;
	if (s->top == NULL)
	{
		printf("ջΪ�գ�");
		return (Status)ERROR;  //�п�
	}

	do
	{
		s_clearLStack = s->top;
		s->top = s->top->next;
		free(s_clearLStack);
		s->count--;
	} while (s->top != NULL);
	if (s->top == NULL) return (Status)SUCCESS;  //���
	else return(Status)ERROR;
}

//����ջ
Status destroyLStack(LinkStack* s) {
	if (s->top == NULL) return (Status)ERROR;  //�п�
	else
	{
		clearLStack(s);
		free(s->top);
		return (Status)SUCCESS;
	}
}

//���ջ����
Status LStackLength(LinkStack* s, int* length) {
	*length = s->count;
	return (Status)SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s, char data) {
	StackNode* p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	if (s->count == 0)  //��ջ
	{
		s->top = p;
		s->top->next = NULL;
		s->count++;
	}
	else  //ջ�ǿ�
	{
		p->next = s->top;
		s->top = p;
		s->count++;
	}
	if (s->top != NULL) return (Status)SUCCESS;  //���
	else return (Status)ERROR;
}

//��ջ
char popLStack(LinkStack* s) {
	StackNode* POP;
	char c_popLStack;
	if (s->top == NULL)  //�п�
	{
		return '\0';
	}
	else
	{
		POP = s->top;
		s->top = POP->next;
		c_popLStack = POP->data;
		delete(POP);
		s->count--;
		return c_popLStack;
	}
}

//��ӡջ
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

ElemType getpriority(char p)  //������������ȼ�
{
	switch (p)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}
}

ElemType Possess_1(char* infix, char* postfix)  //����׺���ʽת��Ϊ��׺���ʽ
{
	char* p, * q;
	ElemType FLAG_right = 0, FLAG_left = 0, c_Empty;  //������������Ƿ�ƥ�䡢���ջ�Ƿ�Ϊ��
	p = infix;  //��׺
	q = postfix;  //��׺
	initLStack(&Head);  //��ʼ��ջ
	while ((*p) != '\0')
	{
		if ((*p) >= 48 && (*p) <= 57)  //����
		{
			*q = *p;
			q++;
			p++;
		}
		else if ((*p) == '(')  //������
		{
			FLAG_left++;  //��ʾ��������
			pushLStack(&Head, *p);  //��ջ
			p++;  //���������ַ���
			*q = ' ';  //ʹ��������������ַֿ�
			q++;  //�ո���ջ
		}
		else if ((*p) == ')')  //������
		{
			FLAG_right++;  //��ʾ��������
			if (FLAG_right > FLAG_left)
			{
				printf("�������");
				return 1;
			}
			while (getTopLStack(&Head) != '(' && isEmptyLStack(&Head) != 1)
			{
				*q = popLStack(&Head);  //���������
				q++;
			}
			if (getTopLStack(&Head) == '(')  //����������
			{
				popLStack(&Head);
				p++;
			}
		}
		else if (((*p) == '+' || (*p) == '-' || (*p) == '*' || (*p) == '/' || (*p) == '\0')
			&& ((*(p - 1) >= 48 && *(p - 1) <= 57 && *(p + 1) >= 48 && *(p + 1) <= 57) ||
				(*(p - 1) >= 48 && *(p - 1) <= 57 && *(p + 1) == '(') ||
				(*(p + 1) >= 48 && *(p + 1) <= 57 && *(p - 1) == ')')))
		{  //����ͬΪ���ֻ���������ұ������Ż��ұ�������������ż�Ϊ����
			if (getpriority(*p) > getpriority(getTopLStack(&Head)))  //��������ȼ��ϴ�
			{
				pushLStack(&Head, *p);
				p++;  //���������ַ���
				*q = ' ';  //ʹ��������������ַֿ�
				q++;
			}
			else
			{
				while (getpriority(*p) <= getpriority(getTopLStack(&Head))) //��������ȼ���С
				{
					*q = popLStack(&Head);  //����
					q++;
					if (isEmptyLStack(&Head) == 1) break;
				}
			}
		}
		else  //�����޹��ַ�
		{
			printf("�������");
			return 1;
		}
	}
	if (FLAG_left != FLAG_right)  //�������ż��ֵ��ţ���ƥ�䣬����ʽ������
	{
		printf("�������");
		return 1;
	}
	if (isEmptyLStack(&Head) == 0)  //��ʣ�������������
	{
		while (isEmptyLStack(&Head) != 1)
		{
			*q = popLStack(&Head);
			q++;
		}
	}
	*q = '\0';
	printf("%s\n", postfix);  //�����׺
	return 0;
}

void Possess_2(char* postfix)
{
	char* q;
	ElemType count_1 = 0, count_2 = 0, sum = 0, c_blank = 0;  //��һ����ջ����ֵ���ڶ�����ջ����ֵ��ѹջ�ļ�����
	q = postfix;  //��׺
	while ((*q) != '\0')
	{
		if (((*q) >= 48 && (*q) <= 57) || (*q) == ' ')  //����ѹջ
		{
			pushLStack(&Head, *q);
			q++;
		}
		else
		{
			while (getTopLStack(&Head) != ' ') count_1 = (popLStack(&Head) - 48) + count_1 * 10;  //��������1
			popLStack(&Head);  //�����ո�
			while (getTopLStack(&Head) != ' ' && isEmptyLStack(&Head) != 1) count_2 = (popLStack(&Head) - 48) + count_2 * 10;
			//��������2
			switch (*q)  //��������������������
			{
			case '+':sum = count_1 + count_2; q++; break;
			case '-':sum = count_1 - count_2; q++; break;
			case '*':sum = count_1 * count_2; q++; break;
			case '/':sum = count_1 / count_2; q++; break;
			}
			count_1 = count_2 = 0;  //����ֵ��0
			while (sum % 10 != 0)  //������ѹջ
			{
				pushLStack(&Head, sum % 10 + 48);
				sum = sum / 10;
			}
		}
	}
	//����������
	while (getTopLStack(&Head) != ' ' && getTopLStack(&Head) != NULL) sum = (popLStack(&Head) - 48) + sum * 10;
	printf("%d", sum);  //���������
}
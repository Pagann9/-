#include "pch.h"
#include "四则运算-Head.h"

extern LinkStack Head;

//初始化栈
Status initLStack(LinkStack* s) {
	s = (LinkStack*)malloc(sizeof(LinkStack));
	s->top = NULL;
	s->count = 0;
	return (Status)SUCCESS;
}

//判断栈是否为空
int isEmptyLStack(LinkStack* s) {
	if (s->top == NULL) return 1;
	else return 0;
}

//得到栈顶元素
char getTopLStack(LinkStack* s) {
	if (s->top == NULL) return '\0';  //判空
	else return s->top->data;
}

//清空栈
Status clearLStack(LinkStack* s) {
	StackNode* s_clearLStack;
	if (s->top == NULL)
	{
		printf("栈为空！");
		return (Status)ERROR;  //判空
	}

	do
	{
		s_clearLStack = s->top;
		s->top = s->top->next;
		free(s_clearLStack);
		s->count--;
	} while (s->top != NULL);
	if (s->top == NULL) return (Status)SUCCESS;  //检查
	else return(Status)ERROR;
}

//销毁栈
Status destroyLStack(LinkStack* s) {
	if (s->top == NULL) return (Status)ERROR;  //判空
	else
	{
		clearLStack(s);
		free(s->top);
		return (Status)SUCCESS;
	}
}

//检测栈长度
Status LStackLength(LinkStack* s, int* length) {
	*length = s->count;
	return (Status)SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, char data) {
	StackNode* p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	if (s->count == 0)  //空栈
	{
		s->top = p;
		s->top->next = NULL;
		s->count++;
	}
	else  //栈非空
	{
		p->next = s->top;
		s->top = p;
		s->count++;
	}
	if (s->top != NULL) return (Status)SUCCESS;  //检查
	else return (Status)ERROR;
}

//出栈
char popLStack(LinkStack* s) {
	StackNode* POP;
	char c_popLStack;
	if (s->top == NULL)  //判空
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

//打印栈
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

ElemType getpriority(char p)  //反馈运算符优先级
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

ElemType Possess_1(char* infix, char* postfix)  //将中缀表达式转换为后缀表达式
{
	char* p, * q;
	ElemType FLAG_right = 0, FLAG_left = 0, c_Empty;  //检测左右括号是否匹配、检测栈是否为空
	p = infix;  //中缀
	q = postfix;  //后缀
	initLStack(&Head);  //初始化栈
	while ((*p) != '\0')
	{
		if ((*p) >= 48 && (*p) <= 57)  //数字
		{
			*q = *p;
			q++;
			p++;
		}
		else if ((*p) == '(')  //左括号
		{
			FLAG_left++;  //表示有左括号
			pushLStack(&Head, *p);  //入栈
			p++;  //继续遍历字符串
			*q = ' ';  //使得运算符两边数字分开
			q++;  //空格入栈
		}
		else if ((*p) == ')')  //右括号
		{
			FLAG_right++;  //表示有右括号
			if (FLAG_right > FLAG_left)
			{
				printf("输入错误！");
				return 1;
			}
			while (getTopLStack(&Head) != '(' && isEmptyLStack(&Head) != 1)
			{
				*q = popLStack(&Head);  //弹出运算符
				q++;
			}
			if (getTopLStack(&Head) == '(')  //弹出左括号
			{
				popLStack(&Head);
				p++;
			}
		}
		else if (((*p) == '+' || (*p) == '-' || (*p) == '*' || (*p) == '/' || (*p) == '\0')
			&& ((*(p - 1) >= 48 && *(p - 1) <= 57 && *(p + 1) >= 48 && *(p + 1) <= 57) ||
				(*(p - 1) >= 48 && *(p - 1) <= 57 && *(p + 1) == '(') ||
				(*(p + 1) >= 48 && *(p + 1) <= 57 && *(p - 1) == ')')))
		{  //两边同为数字或左边数字右边左括号或右边数字左边右括号即为合理
			if (getpriority(*p) > getpriority(getTopLStack(&Head)))  //运算符优先级较大
			{
				pushLStack(&Head, *p);
				p++;  //继续遍历字符串
				*q = ' ';  //使得运算符两边数字分开
				q++;
			}
			else
			{
				while (getpriority(*p) <= getpriority(getTopLStack(&Head))) //运算符优先级较小
				{
					*q = popLStack(&Head);  //弹出
					q++;
					if (isEmptyLStack(&Head) == 1) break;
				}
			}
		}
		else  //其他无关字符
		{
			printf("输入错误！");
			return 1;
		}
	}
	if (FLAG_left != FLAG_right)  //左右括号检测值异号，不匹配，计算式不合理
	{
		printf("输入错误！");
		return 1;
	}
	if (isEmptyLStack(&Head) == 0)  //把剩余运算符弹出来
	{
		while (isEmptyLStack(&Head) != 1)
		{
			*q = popLStack(&Head);
			q++;
		}
	}
	*q = '\0';
	printf("%s\n", postfix);  //输出后缀
	return 0;
}

void Possess_2(char* postfix)
{
	char* q;
	ElemType count_1 = 0, count_2 = 0, sum = 0, c_blank = 0;  //第一个出栈计算值，第二个出栈计算值，压栈的计算结果
	q = postfix;  //后缀
	while ((*q) != '\0')
	{
		if (((*q) >= 48 && (*q) <= 57) || (*q) == ' ')  //数字压栈
		{
			pushLStack(&Head, *q);
			q++;
		}
		else
		{
			while (getTopLStack(&Head) != ' ') count_1 = (popLStack(&Head) - 48) + count_1 * 10;  //弹出数字1
			popLStack(&Head);  //弹出空格
			while (getTopLStack(&Head) != ' ' && isEmptyLStack(&Head) != 1) count_2 = (popLStack(&Head) - 48) + count_2 * 10;
			//弹出数字2
			switch (*q)  //根据运算符进行运算操作
			{
			case '+':sum = count_1 + count_2; q++; break;
			case '-':sum = count_1 - count_2; q++; break;
			case '*':sum = count_1 * count_2; q++; break;
			case '/':sum = count_1 / count_2; q++; break;
			}
			count_1 = count_2 = 0;  //计算值归0
			while (sum % 10 != 0)  //计算结果压栈
			{
				pushLStack(&Head, sum % 10 + 48);
				sum = sum / 10;
			}
		}
	}
	//弹出计算结果
	while (getTopLStack(&Head) != ' ' && getTopLStack(&Head) != NULL) sum = (popLStack(&Head) - 48) + sum * 10;
	printf("%d", sum);  //输出计算结果
}
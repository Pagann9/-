#include "pch.h"
#include "四则运算-Head.h"
#include <stdio.h>
#include <stdlib.h>

LinkStack Head;

int main()
{
	ElemType c_Possess_1 = 0;  //检测输入算式是否合理
	char infix[100] = { '\0' };  //中缀表达式
	char postfix[100] = { '\0' };  //后缀表达式

	printf("请输入中缀表达式：");
	scanf("%s", infix);
	c_Possess_1 = Possess_1(infix, postfix);
	if (c_Possess_1 == 0) Possess_2(postfix);  //若输入算式合理进行计算
	return 0;
}


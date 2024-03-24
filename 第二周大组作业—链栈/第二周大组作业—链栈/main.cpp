#include "pch.h"
#include "Head.h"
#include <stdio.h>
#include <stdlib.h>

LinkStack* Head;

int main()
{
	ElemType MENU_num = 1, C_stackEmpty;
	MENU_num = MENU();
	initStack(&Head);
	while (MENU_num)
	{
		switch (MENU_num)
		{
		case 1:C_stackEmpty = stackEmpty(&Head); printf("%d", C_stackEmpty); break;
		case 2:stackLength(&Head); break;
		}
		system("pause");
		system("cls");
	}
}

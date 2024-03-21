#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include "duLinkedList.h"

DuLinkedList* L;
extern ElemType menu();

int main()
{
	Status InitList_DuL_Check;
	ElemType MENU = 1;
	while (MENU)
	{
		MENU = menu();
		switch (MENU)
		{
		case 1: InitList_DuL_Check = InitList_DuL(L); printf("\n%d", InitList_DuL_Check); break;
		}
	}
}

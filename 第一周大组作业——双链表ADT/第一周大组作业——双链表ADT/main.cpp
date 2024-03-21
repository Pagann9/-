#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "duLinkedList.h"

DuLinkedList* L;
DuLNode* p, * q;
extern ElemType menu();
typedef DuLinkedList* LINK;

extern void visit(ElemType e);

int main()
{
	Status InitList_DuL_Check, InsertBeforeList_DuL_Check, InsertAfterList_DuL_Check, DeleteList_DuL_Check;
	ElemType MENU = 1,e;
	while (MENU)
	{
		MENU = menu();  //初始菜单
		switch (MENU)
		{
		case 0: return 0;
		case 1: 
			L = (LINK)malloc(sizeof(DuLinkedList));
			(*L) = (DuLinkedList)malloc(sizeof(DuLNode)); 
			InitList_DuL_Check = InitList_DuL(L); printf("\n%d", InitList_DuL_Check); break;
		case 2: DestroyList_DuL(L); break;
		case 3: InsertBeforeList_DuL_Check = InsertBeforeList_DuL(p, q); printf("\n%d", InsertBeforeList_DuL_Check); break;
		case 4: InsertAfterList_DuL_Check = InsertAfterList_DuL(p, q); printf("\n%d", InsertAfterList_DuL_Check); break;
		case 5: DeleteList_DuL_Check = DeleteList_DuL(p,&e); printf("\n%d", DeleteList_DuL_Check); break;
		case 6: TraverseList_DuL(*L,visit);
		}
		system("pause");
		system("cls");
	}
}

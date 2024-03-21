#include <stdio.h>
#include <stdlib.h>
#include "pch.h"
#include "linkedList.h"
#include "Head.h"

LinkedList Head;
LinkedList* L;
LNode* p, * q;
extern ElemType Linkedlist_num; //链表长度计数器
typedef LinkedList* LINK;
extern Status InsertList(LNode* p, LNode* q);
extern void visit(ElemType e);

int main()
{
	ElemType menu_FirstNum, menu_SecondNum = 1,SearchList_Check, ReverseList_Check,e = 0;
	Status InitList_Check, InsertList_Check,DeleteList_Check;
	LNode* ReverseEvenList_Check, *FindMidNode_Check;
	L = (LINK)malloc(sizeof(LinkedList));
    *L = (LinkedList)malloc(sizeof(LNode));
	while (menu_SecondNum)
	{
		system("cls");
		menu_SecondNum = FunctionMenu();
		switch (menu_SecondNum)
		{
		case 1: InitList_Check = InitList(L); printf("%d\n", InitList_Check); break;
		case 2: DestroyList(L); break;
		case 3: InsertList_Check = InsertList(p, q); printf("%d\n", InsertList_Check); break;
		case 4: DeleteList_Check = DeleteList(p, &e); printf("%d\n", DeleteList_Check); break;
		case 5: TraverseList(*L, visit); break;
		case 6: SearchList_Check = SearchList(*L, e); printf("%d\n", SearchList_Check); break;
		case 7: ReverseList_Check = ReverseList(L); printf("%d\n", ReverseList_Check); break;
		case 8: ReverseEvenList_Check = ReverseEvenList(L); printf("%d", ReverseEvenList_Check->next->data); break;
		case 9: FindMidNode_Check = FindMidNode(L); printf("%d", FindMidNode_Check->data); break;
		case 0: return 0;
		}
		system("pause");
	}
}

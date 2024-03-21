#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "pch.h"
#include "linkedList.h"
#include "Head.h"

ElemType Linkedlist_num; //链表长度计数器
extern LinkedList* L;
typedef LinkedList* LINK;

LinkedList* Insert_Search(ElemType e);
LinkedList* Delete_Search(ElemType e);
LNode* Insert_Create();
LNode* Reverse_List(LNode* head);

void visit(ElemType e);

Status InitList(LinkedList* L)
{
    LinkedList* Initlist_temp1,* Initlist_temp2;
    LinkedList Initlist_Check;
    if ((*L) == NULL) return (Status)ERROR;
    (*L)->next = NULL;
    printf("请输入链表长度:");
    scanf_s("%d", &Linkedlist_num);
    Initlist_temp1 = Initlist_temp2 = L;
    for (int i = 0; i < Linkedlist_num; i++) //创建链表
    {
        Initlist_temp1 = (LINK)malloc(sizeof(LinkedList));
        *Initlist_temp1 = (LinkedList)malloc(sizeof(LNode));
        (*Initlist_temp1)->data = i;
        (*Initlist_temp1)->next = NULL;
        (*Initlist_temp2)->next = *Initlist_temp1;
        Initlist_temp2 = Initlist_temp1;
    }
    Initlist_Check = *L;
    while (Initlist_Check->next != NULL) Initlist_Check = Initlist_Check->next;
    if (Initlist_Check->data == Linkedlist_num - 1) return Status(SUCCESS);
    else return Status(ERROR);
}

void DestroyList(LinkedList* L)
{
    LNode* p;
    if (L == NULL)
    {
        printf("链表为空！\n");
        return;
    }
    p = *L;
    while (p != NULL)
    {
        *L = p->next;
        free(p);
        p = *L;
    }
}

Status InsertList(LNode* p, LNode* q)
{
    LNode* TEMP;
    ElemType InsertList_num;
    q = Insert_Create();
    printf("请输入待插入的节点：");
    scanf_s("%d", &InsertList_num);
    if (InsertList_num<0 || InsertList_num>Linkedlist_num) return Status(ERROR);
    p = *Insert_Search(InsertList_num);
    if (p == NULL) return Status(ERROR);
    TEMP = p->next;
    p->next = q;
    q->next = TEMP;
    if (p->next == q) return Status(SUCCESS);
    else return Status(ERROR);
}

Status DeleteList(LNode* p, ElemType* e)
{
    ElemType DeleteList_num, DeleteList_Check_num;
    LNode* TEMP;
    printf("请输入待删除的结点：");
    scanf_s("%d", &DeleteList_num);
    p=*Delete_Search(DeleteList_num);
    *e = p->next->data;
    DeleteList_Check_num = p->next->next->data;
    TEMP = p->next;
    p->next = p->next->next;
    free(TEMP);
    if (p->next->data == DeleteList_Check_num) return Status(SUCCESS);
    else return Status(ERROR);
}

void TraverseList(LinkedList L, void(*visit)(ElemType e))
{
    L = L->next;
    while(L->next != NULL)
    {
        L = L->next;
        visit(L->data);
    }
    }

Status SearchList(LinkedList L, ElemType e)
{
    ElemType FLAG = 0;
    printf("请输入待查询数据：");
    scanf_s("%d", &e);
    while (L->next != NULL)
    {
        L = L->next;
        if (L->data == e)
        {
            FLAG = 1;
            break;

        }
    }
    if(FLAG == 1) return Status(SUCCESS);
    else
    {
        printf("该节点不存在！");
        return Status(ERROR);
    }
}

Status ReverseList(LinkedList* L)
{
    ElemType ReverseList_choose;
    LinkedList Head = *L;
    LinkedList pre, cur;
    system("cls");
    printf("1.迭代法\n2.递归法\n请输入：");
    scanf_s("%d", &ReverseList_choose);
    if (ReverseList_choose == 1)
    {
        pre = Head->next;
        Head->next = NULL;
        cur = pre->next;
        while (cur != NULL)
        {
            pre->next = cur->next;
            cur->next = pre;
            cur = pre->next;
        }
        Head->next = pre;
        *L = Head;
    }
    if (ReverseList_choose == 2)
    {
        *L = Reverse_List(Head);
    }
    if ((*L)->next != NULL) return Status(SUCCESS);
    else return Status(ERROR);
}

LNode* ReverseEvenList(LinkedList* L)
{
    LNode* TEMP_1,*TEMP_2;
    TEMP_1 = *L;
    while (TEMP_1->next != NULL && TEMP_1->next->next != NULL)
    {
        TEMP_2 = TEMP_1->next;
        TEMP_1->next = TEMP_2->next;
        TEMP_2->next = TEMP_1->next->next;
        TEMP_1->next->next = TEMP_2;
        TEMP_1 = TEMP_1->next->next;
    }
    return *L;
}

LNode* FindMidNode(LinkedList* L)
{
    LNode* Fast, * Slow;
    Fast = *L;
    Slow = Fast->next;
    while (Fast != NULL && Fast->next != NULL)
    {
        Fast = Fast->next->next;
        Slow = Slow->next;
    }
    return Slow;
}

void visit (ElemType e)
{
    printf("%d ", e);
}

LNode* Reverse_List(LNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    LNode* newhead = Reverse_List(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

LNode* Insert_Create()
{
    LNode* create_linkedList;
    create_linkedList = (LNode*)malloc(sizeof(LNode));
    create_linkedList->next = NULL;
    printf("请输入新数据：");
    scanf_s("%d", &create_linkedList->data);
    return create_linkedList;
}

LinkedList* Insert_Search(ElemType e)
{
    LinkedList* TEMP = NULL;
    if ((*L)->next == NULL) return NULL;
    TEMP = L;
    if ((*TEMP)->next == NULL) return NULL;
    for (int i = 0; i < e; i++) *TEMP = (*TEMP)->next;
    return TEMP;
}

LinkedList* Delete_Search(ElemType e)
{
    LinkedList* TEMP;
    TEMP = L;
    for (int i = 0; i < e-1; i++) *TEMP = (*TEMP)->next;
    return TEMP;
}

#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include "duLinkedList.h"

extern DuLinkedList* L; //头结点
ElemType LINK_SIZEnum;  //链表计数
typedef DuLinkedList* LINK;

DuLNode* Insert_Create();  //创建插入节点
DuLNode* Insert_Search(ElemType e);  //寻找插入节点
DuLNode* Delete_Search(ElemType e);  //寻找删除节点
void visit (ElemType e);

Status InitList_DuL(DuLinkedList* L)
{
	DuLinkedList* TEMP_1 = NULL, * TEMP_2 = NULL;
	DuLinkedList LINK_Check = NULL;
	(*L)->prior = NULL;
	(*L)->next = NULL;
	(*L)->data = 0;
	TEMP_1 = TEMP_2 = L;
	printf("请输入链表长度：");
	scanf_s("%d", &LINK_SIZEnum);
	for (int i = 1; i < LINK_SIZEnum+1; i++)
	{
		TEMP_1 = (LINK)malloc(sizeof(DuLinkedList));
		(*TEMP_1) = (DuLinkedList)malloc(sizeof(DuLNode));		
		(*TEMP_1)->data = i;
		(*TEMP_2)->next = *TEMP_1;
		(*TEMP_1)->next = NULL;
		TEMP_2 = TEMP_1;
	}
	LINK_Check = *L;
	while (LINK_Check->next != NULL) LINK_Check = LINK_Check->next;  //检查是否创建完成
	if (LINK_Check->data == LINK_SIZEnum) return Status(SUCCESS);
	else return Status(ERROR);
}

void DestroyList_DuL(DuLinkedList* L)
{
	DuLNode* p;
	if (L == NULL)
	{
		printf("链表为空！\n");  //检查链表是否为空
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

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)  //前插
{
	ElemType InsertList_num;
	q = Insert_Create();
	printf("请输入待插入的节点：");
	scanf_s("%d", &InsertList_num);
	if (InsertList_num<0 || InsertList_num>LINK_SIZEnum) return Status(ERROR);  //输入的报错
	p = Insert_Search(InsertList_num);  //寻找插入的结点
	if (p == NULL) return Status(ERROR);  
	q->prior = p->prior;
	q->next = p;
	if (q->next == p) return Status(SUCCESS);  //检查
	else return Status(ERROR);
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)  //后插
{
	ElemType InsertList_num;
	q = Insert_Create();
	printf("请输入待插入的节点：");
	scanf_s("%d", &InsertList_num);
	if (InsertList_num<0 || InsertList_num>LINK_SIZEnum) return Status(ERROR);  // 报错
	p = Insert_Search(InsertList_num);  //寻找插入节点
	if (p == NULL) return Status(ERROR);
	q->next = p->next;
	p->next = q;
	if (p->next == q) return Status(SUCCESS);  //检查
	else return Status(ERROR);
}

Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	ElemType DeleteList_num, DeleteList_Check_num;
	DuLNode* TEMP;
	printf("请输入待删除的结点：");
	scanf_s("%d", &DeleteList_num);
	p = Delete_Search(DeleteList_num);  //寻找删除节点的前一个节点
	if(p == NULL) return Status(ERROR);//空链表报错
	*e = p->next->data;
	DeleteList_Check_num = p->next->next->data;
	TEMP = p->next;
	p->next = p->next->next;
	free(TEMP);
	if (p->next->data == DeleteList_Check_num) return Status(SUCCESS);  //检查
	else return Status(ERROR);
}

void TraverseList_DuL(DuLinkedList L, void(*visit)(ElemType e))
{
	while (L->next != NULL)
	{
		L = L->next;  //遍历
		visit(L->data);
	}
}

DuLNode* Insert_Create()  //创建待插入节点
{
	DuLNode* create_linkedList;
	create_linkedList = (DuLNode*)malloc(sizeof(DuLNode));
	create_linkedList->next = NULL;
	create_linkedList->prior = NULL;
	printf("请输入新数据：");
	scanf_s("%d", &create_linkedList->data);
	return create_linkedList;
}

DuLNode* Insert_Search(ElemType e)
{
	DuLNode* TEMP = NULL;
	if (*L == NULL) return NULL;
	TEMP = *L;
	if (TEMP->next == NULL) return NULL;  //空链表报错
	for (int i = 0; i < e; i++) TEMP = TEMP->next;  //寻找待插入节点
	return TEMP;
}

DuLNode* Delete_Search(ElemType e)
{
	DuLNode* TEMP;
	TEMP = *L;
	for (int i = 0; i < e - 2; i++) TEMP = TEMP->next;  
	return TEMP;
}

void visit(ElemType e)
{
	printf("%d ", e);
}
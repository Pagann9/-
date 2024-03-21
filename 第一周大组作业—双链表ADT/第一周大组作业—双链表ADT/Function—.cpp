#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include "duLinkedList.h"

extern DuLinkedList* L; //ͷ���
ElemType LINK_SIZEnum;  //�������
typedef DuLinkedList* LINK;

DuLNode* Insert_Create();  //��������ڵ�
DuLNode* Insert_Search(ElemType e);  //Ѱ�Ҳ���ڵ�
DuLNode* Delete_Search(ElemType e);  //Ѱ��ɾ���ڵ�
void visit (ElemType e);

Status InitList_DuL(DuLinkedList* L)
{
	DuLinkedList* TEMP_1 = NULL, * TEMP_2 = NULL;
	DuLinkedList LINK_Check = NULL;
	(*L)->prior = NULL;
	(*L)->next = NULL;
	(*L)->data = 0;
	TEMP_1 = TEMP_2 = L;
	printf("�����������ȣ�");
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
	while (LINK_Check->next != NULL) LINK_Check = LINK_Check->next;  //����Ƿ񴴽����
	if (LINK_Check->data == LINK_SIZEnum) return Status(SUCCESS);
	else return Status(ERROR);
}

void DestroyList_DuL(DuLinkedList* L)
{
	DuLNode* p;
	if (L == NULL)
	{
		printf("����Ϊ�գ�\n");  //��������Ƿ�Ϊ��
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

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)  //ǰ��
{
	ElemType InsertList_num;
	q = Insert_Create();
	printf("�����������Ľڵ㣺");
	scanf_s("%d", &InsertList_num);
	if (InsertList_num<0 || InsertList_num>LINK_SIZEnum) return Status(ERROR);  //����ı���
	p = Insert_Search(InsertList_num);  //Ѱ�Ҳ���Ľ��
	if (p == NULL) return Status(ERROR);  
	q->prior = p->prior;
	q->next = p;
	if (q->next == p) return Status(SUCCESS);  //���
	else return Status(ERROR);
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)  //���
{
	ElemType InsertList_num;
	q = Insert_Create();
	printf("�����������Ľڵ㣺");
	scanf_s("%d", &InsertList_num);
	if (InsertList_num<0 || InsertList_num>LINK_SIZEnum) return Status(ERROR);  // ����
	p = Insert_Search(InsertList_num);  //Ѱ�Ҳ���ڵ�
	if (p == NULL) return Status(ERROR);
	q->next = p->next;
	p->next = q;
	if (p->next == q) return Status(SUCCESS);  //���
	else return Status(ERROR);
}

Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	ElemType DeleteList_num, DeleteList_Check_num;
	DuLNode* TEMP;
	printf("�������ɾ���Ľ�㣺");
	scanf_s("%d", &DeleteList_num);
	p = Delete_Search(DeleteList_num);  //Ѱ��ɾ���ڵ��ǰһ���ڵ�
	if(p == NULL) return Status(ERROR);//��������
	*e = p->next->data;
	DeleteList_Check_num = p->next->next->data;
	TEMP = p->next;
	p->next = p->next->next;
	free(TEMP);
	if (p->next->data == DeleteList_Check_num) return Status(SUCCESS);  //���
	else return Status(ERROR);
}

void TraverseList_DuL(DuLinkedList L, void(*visit)(ElemType e))
{
	while (L->next != NULL)
	{
		L = L->next;  //����
		visit(L->data);
	}
}

DuLNode* Insert_Create()  //����������ڵ�
{
	DuLNode* create_linkedList;
	create_linkedList = (DuLNode*)malloc(sizeof(DuLNode));
	create_linkedList->next = NULL;
	create_linkedList->prior = NULL;
	printf("�����������ݣ�");
	scanf_s("%d", &create_linkedList->data);
	return create_linkedList;
}

DuLNode* Insert_Search(ElemType e)
{
	DuLNode* TEMP = NULL;
	if (*L == NULL) return NULL;
	TEMP = *L;
	if (TEMP->next == NULL) return NULL;  //��������
	for (int i = 0; i < e; i++) TEMP = TEMP->next;  //Ѱ�Ҵ�����ڵ�
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
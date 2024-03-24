#include "LQueue.h" 
#include <stdio.h>
#include <malloc.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {
	Node* TEMP;
	while (Q->front)
	{
		TEMP = Q->front;
		 Q->front= Q->front->next;
		free(TEMP);
	}
	free(Q->front);
	printf("success");
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->front == NULL) return (Status)TRUE;
	return (Status)FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue* Q, void* e) {
	if (Q->front == NULL) return (Status)FALSE;
	e = Q->front->data;
	return (Status)TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {
	LQueue p;
	p = *Q;
	int count = 0;
	while (p.front != NULL)
	{
		count++;
		p.front = p.front->next;
	}
	return count;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue* Q, void* data) {
	Node* p=(Nodeptr)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	if (Q->front = NULL)
	{
		Q->front = p;
		Q->rear = p;
		return (Status)TRUE;
	}
	Q->rear->next = p;
	Q->rear = p;
	return (Status)TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
	if (Q->front == NULL) return (Status)FALSE;
	Node* TEMP;
	TEMP = Q->front;
	Q->front = Q->front->next;
	free(TEMP);
	return(Status)TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q) {
	Node* TEMP;
	while (Q->front)
	{
		TEMP = Q->front;
		Q->front = Q->front->next;
		free(TEMP);
	}
	printf("success");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	Node* p;
	if (Q->front == NULL) return (Status)FALSE;
	p = Q->front;
	while (p)
	{
		foo(p->data);
		p = p->next;
	}
	return (Status)TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void* q) {
	int SIZE;
	SIZE = sizeof(q);
	switch (SIZE)
	{
	case 1:printf("%c ", (char*)q); break;
	case 4:printf("%f ", (float*)q); break;
	}
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#include "pch.h"
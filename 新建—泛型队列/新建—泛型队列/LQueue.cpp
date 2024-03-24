#include "LQueue.h" 
#include <stdio.h>
#include <malloc.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->front == NULL) return (Status)TRUE;
	return (Status)FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e) {
	if (Q->front == NULL) return (Status)FALSE;
	e = Q->front->data;
	return (Status)TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q

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
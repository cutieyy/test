#pragma once
#ifndef _LINKQUEUE_H_
#include <iostream>
using namespace std;

typedef struct QNode {
	int data;
	struct QNode *next;
}QNode,* QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//InitQueue����һ���ն���
void InitQueue(LinkQueue &LQ)
{
	LQ.front =LQ.rear= (QueuePtr)malloc(sizeof(QNode));
	if (!LQ.front)
		exit(-1);
	LQ.front->next = NULL;
}

//DestroyQueue����һ������
void DesreoyQueue(LinkQueue &LQ)
{
	while (!LQ.front)
	{
		LQ.rear = LQ.front->next;
		free(LQ.front);
		LQ.front = LQ.rear;
	}
}

//ClearQueue �������ÿ�
void ClearQueue(LinkQueue &LQ)
{
	QueuePtr p, q;
	LQ.rear = LQ.front;
	p = LQ.front->next;
	LQ.front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		//free(q);
	}
}
//QueueEmpty�ж϶����Ƿ�Ϊ��
string QueueEmpty(LinkQueue LQ)
{
	if (LQ.front == LQ.rear)
		return "���п�";
	else
		return "���зǿ�";
}
//QueueLength���ض��г���
int QueueLength(LinkQueue LQ)
{
	int count=0;
	QueuePtr p;
	p = LQ.front;
	while (p!=LQ.rear)
	{
		count++;
		p = p->next;
	}
	return count;
}
//GetHead���ض���ͷ��Ԫ��
int GetHead(LinkQueue LQ)
{
	if (LQ.front != LQ.rear)
		return LQ.front->next->data;
}
//EnQueue�ڶ�β����Ԫ��
void EnQueue(LinkQueue &LQ, int i)
{
	QueuePtr temp;
	temp = (QueuePtr)malloc(sizeof(QueuePtr));
	temp->data = i;
	temp->next = NULL;
	LQ.rear->next = temp;
	LQ.rear = temp;
}
//DeQueue�Ӷ���ͷ��ɾ��Ԫ��
void DeQueue(LinkQueue &LQ)
{
	QueuePtr temp;
	//temp= (QueuePtr)malloc(sizeof(QNode));
	//free(LQ.front->next);
	temp = LQ.front->next;
	LQ.front->next = temp->next;
	if (LQ.rear == temp)
		LQ.rear = LQ.front;
	temp->next = NULL;
	//free(temp);
}
//QueueTraverse��������Ԫ��
void QueueTraverse(LinkQueue LQ)
{
	QueuePtr temp;
	temp = LQ.front->next;
	while (temp)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}
#endif // !_LINKQUEUE_H_

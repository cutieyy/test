#pragma once
#ifndef _SQQUEUEQ_H_
#include <iostream>
#define MAXQSIZE 100
using namespace std;


typedef struct {
	int  *base;
	int front;
	int rear;
}SqQueue;

//InitQueue����һ���ն���
void InitQueue(SqQueue &LQ)
{
	LQ.base = (int *)malloc(MAXQSIZE*sizeof(int));		
	if (!LQ.base)
		exit(-1);
	LQ.front = LQ.rear = 0;
}

//DestroyQueue����һ������
void DesreoyQueue(SqQueue &LQ)
{
	if(LQ.base)
		free(LQ.base);
	LQ.base = NULL;
	LQ.front = LQ.rear = 0;
}

//ClearQueue �������ÿ�
void ClearQueue(SqQueue &LQ)
{
	LQ.front = LQ.rear = 0;
}
//QueueEmpty�ж϶����Ƿ�Ϊ��
string QueueEmpty(SqQueue LQ)
{
	if (LQ.front == LQ.rear)
		return "���п�";
	else
		return "���зǿ�";
}
//QueueLength���ض��г���
int QueueLength(SqQueue LQ)
{
	return (LQ.rear-LQ.front+MAXQSIZE)%MAXQSIZE;
}
//GetHead���ض���ͷ��Ԫ��
int GetHead(SqQueue LQ)
{
	if (LQ.front != LQ.rear)
		return *(LQ.base+LQ.front);
}
//EnQueue�ڶ�β����Ԫ��
void EnQueue(SqQueue &LQ, int i)
{
	if ((LQ.rear + 1) % MAXQSIZE == LQ.front)
		return;
	LQ.base[LQ.rear] = i;
	LQ.rear = (LQ.rear + 1) % MAXQSIZE;
}
//DeQueue�Ӷ���ͷ��ɾ��Ԫ��
void DeQueue(SqQueue &LQ)
{
	if (LQ.front == LQ.rear)
		return;
	int temp;
	temp = LQ.base[LQ.front];
	LQ.front = (LQ.front + 1) % MAXQSIZE;
	cout << "ɾ��Ԫ�أ�" << temp << endl;
}
//QueueTraverse��������Ԫ��
void QueueTraverse(SqQueue LQ)
{
	int temp;
	temp = LQ.front;
	while (temp!=LQ.rear)
	{
		cout << LQ.base[temp] << endl;
		temp = (temp+1)%MAXQSIZE;
	}
}



#endif // !_SQQUEUEQ_H_

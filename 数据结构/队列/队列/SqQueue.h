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

//InitQueue构造一个空队列
void InitQueue(SqQueue &LQ)
{
	LQ.base = (int *)malloc(MAXQSIZE*sizeof(int));		
	if (!LQ.base)
		exit(-1);
	LQ.front = LQ.rear = 0;
}

//DestroyQueue销毁一个队列
void DesreoyQueue(SqQueue &LQ)
{
	if(LQ.base)
		free(LQ.base);
	LQ.base = NULL;
	LQ.front = LQ.rear = 0;
}

//ClearQueue 将队列置空
void ClearQueue(SqQueue &LQ)
{
	LQ.front = LQ.rear = 0;
}
//QueueEmpty判断队列是否为空
string QueueEmpty(SqQueue LQ)
{
	if (LQ.front == LQ.rear)
		return "队列空";
	else
		return "队列非空";
}
//QueueLength返回队列长度
int QueueLength(SqQueue LQ)
{
	return (LQ.rear-LQ.front+MAXQSIZE)%MAXQSIZE;
}
//GetHead返回队列头部元素
int GetHead(SqQueue LQ)
{
	if (LQ.front != LQ.rear)
		return *(LQ.base+LQ.front);
}
//EnQueue在队尾插入元素
void EnQueue(SqQueue &LQ, int i)
{
	if ((LQ.rear + 1) % MAXQSIZE == LQ.front)
		return;
	LQ.base[LQ.rear] = i;
	LQ.rear = (LQ.rear + 1) % MAXQSIZE;
}
//DeQueue从队列头部删除元素
void DeQueue(SqQueue &LQ)
{
	if (LQ.front == LQ.rear)
		return;
	int temp;
	temp = LQ.base[LQ.front];
	LQ.front = (LQ.front + 1) % MAXQSIZE;
	cout << "删除元素：" << temp << endl;
}
//QueueTraverse遍历队列元素
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

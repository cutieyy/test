#pragma once
#ifndef _STACK_H_
#include<iostream>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct {
	int *base;
	int *top;
	int stacksize;
}SqStack;
using namespace std;

//InitStack ����һ����ջ��
void InitStack(SqStack &S)
{
	S.base = (int *)malloc(sizeof(int)*STACK_INIT_SIZE);
	if (!S.base)
		exit(-1);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
//DestroyStack ����һ����ջ
void DestoryStack(SqStack &S)
{
	free(S.base);
	S.top = NULL;
	S.base = NULL;
	S.stacksize = 0;
}
//ClearStack ���ջ����
void ClearStack(SqStack &S)
{
	S.top = S.base;
}
//StackEmpty �ж�ջ�Ƿ��
int StackEmpty(SqStack S)
{
	if (S.base == S.top)
		return 1; //1��ʾջ��
	else
	{
		return 0;//0��ʾջ�ǿ�
	}
}
//StackLength ����ջ�ĳ���
int StackLength(SqStack S)
{
	return S.top - S.base;
}
//GetTop ����ջ��Ԫ��
int GetTop(SqStack S)
{
	if (S.top > S.base)
		return *(S.top - 1);
}

//Push  �����µ�Ԫ����Ϊջ��
void Push(SqStack &S, int e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (int *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(int));
		if (!S.base)
			exit(-1);
		S.top = S.base + S.stacksize;
		S.stacksize = S.stacksize + STACKINCREMENT;
	}
	*(S.top)++ = e;
}
//Pop ����ջ��Ԫ��
int Pop(SqStack &S)
{
	if (S.top == S.base)
		return -1;
	else
	{
		return *--(S.top);
	}
}
//StackTraverse ����ջ��Ԫ��
void StackTraverse(SqStack S)
{
	while (S.top > S.base)
		cout << *S.base++ << endl;
}
#endif // !_STACK_H_


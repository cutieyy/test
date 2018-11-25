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

//InitStack 构造一个空栈；
void InitStack(SqStack &S)
{
	S.base = (int *)malloc(sizeof(int)*STACK_INIT_SIZE);
	if (!S.base)
		exit(-1);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
//DestroyStack 销毁一个空栈
void DestoryStack(SqStack &S)
{
	free(S.base);
	S.top = NULL;
	S.base = NULL;
	S.stacksize = 0;
}
//ClearStack 清空栈内容
void ClearStack(SqStack &S)
{
	S.top = S.base;
}
//StackEmpty 判断栈是否空
int StackEmpty(SqStack S)
{
	if (S.base == S.top)
		return 1; //1表示栈空
	else
	{
		return 0;//0表示栈非空
	}
}
//StackLength 返回栈的长度
int StackLength(SqStack S)
{
	return S.top - S.base;
}
//GetTop 返回栈顶元素
int GetTop(SqStack S)
{
	if (S.top > S.base)
		return *(S.top - 1);
}

//Push  插入新的元素作为栈顶
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
//Pop 弹出栈顶元素
int Pop(SqStack &S)
{
	if (S.top == S.base)
		return -1;
	else
	{
		return *--(S.top);
	}
}
//StackTraverse 遍历栈内元素
void StackTraverse(SqStack S)
{
	while (S.top > S.base)
		cout << *S.base++ << endl;
}
#endif // !_STACK_H_


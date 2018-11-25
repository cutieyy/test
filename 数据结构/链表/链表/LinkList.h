#pragma once
#ifndef _LINKLIST_H_
#include<iostream>
using namespace std;

// 链表的结构体
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode,*LinkList;

//InitList初始化一个空链表
void InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if (!L)
		exit(-1);
	else
	{
		L->next = NULL;
	}
}
//DestroyList销毁一个链表
void DestroyList(LinkList &L)
{
	LinkList temp;
	while (L)
	{
		temp = L->next;
		free(L);
		L = temp;
	}
}

//ClearList将链表置空
void ClearList(LinkList L)
{
	LinkList p, temp;
	p = L->next;
	while (p)
	{
		temp = p->next;
		free(p);
		p = temp;
	}
	L->next = NULL;
}

//ListEmpty判断链表是否为空
int ListEmpty(LinkList L)
{
	if (L->next)
		return 0;//返回0，说明链表非空
	else
		return 1;//返回1.说明链表空
}

//ListLength得到链表长度
int ListLength(LinkList L)
{
	int count = 0;
	LinkList temp = L->next;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

//GetELement得到链表中的元素
int GetELement(LinkList L, int i)
{
	LinkList temp = L->next;
	int count = 1;
	while (temp&&count<i )
	{
		temp = temp->next;
		count++;
	}
	if (!temp || count > i )
		exit(-1);
	else
	{
		return temp->data;
	}
}

//LocateElement 返回第一大于（或小于）的元素
int LocateElement(LinkList L, int i)
{
	LinkList temp = L->next;
	int count = 0;
	while (temp)
	{
		count++;
		if (temp->data < i)
			return count;
		temp = temp->next;
	}
	return 0;
}

//PriorElement 返回当前节点的前驱元素
int PriorElement(LinkList L, int i)
{
	LinkList temp = L->next,q;
	while (temp->next)
	{
		q = temp->next;
		if (q->data == i)
			return temp->data;
		temp =q;
	}
	return -1;
}
//NextElement 返回当前节点的后继元素
int NextElement(LinkList L, int i)
{
	LinkList temp = L->next;
	while (temp->next)
	{		
		if (temp->data == i)
			return temp->next->data;
		temp = temp->next;
	}
	return -1;
}
//ListInsert 在链表中插入一个元素
int ListInsert(LinkList &L,int i,int element)
{
	LinkList temp = L;
	LinkList new_node;
	int count=0;
	while (temp&&count<i-1)
	{
		temp = temp->next;
		count++;
	}
	if (!temp || count > i - 1)
		return -1;
	else
	{
		new_node = (LinkList)malloc(sizeof(LNode));
		new_node->data = element;
		new_node->next = temp->next;
		temp->next = new_node;
		return 0;
	}
}
//ListDelete 在链表中删除一个元素
int ListDelete(LinkList &L, int i)
{
	LinkList temp = L;
	LinkList new_node;
	int count=0;
	while (temp->next&&count<i - 1)
	{
		temp = temp->next;
		count++;
	}
	if (!temp->next || count > i - 1)
		return -1;
	else
	{
		//new_node = (LinkList)malloc(sizeof(LNode));
		new_node=temp->next ; 
		temp->next = new_node->next;
		free(new_node);
		return 0;
	}
}
//ListTraverse 遍历链表
void ListTraverse(LinkList &L)
{
	int count = 1;
	if (L == NULL)
		exit(-1);
	LinkList temp = L->next;
	while (temp!= NULL)
	{
		cout <<count<<":"<< temp->data << endl;
		temp = temp->next;
		count++;
	}
	cout << endl;
}

//ListReverse链表倒置
void ListReverse(LinkList &L)
{
	LinkList pre = NULL;
	LinkList p = L;

	while (p)
	{
		LinkList tmpNext = p->next;
		p->next = pre;
		pre = p;
		p = tmpNext;
	}
	L = pre;
}

#endif // !_LINKLIST_H_
	
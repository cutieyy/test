#pragma once
#ifndef _BINARY_TREE_H_
#include<iostream>
#include<queue>
using namespace std;

typedef struct Binode
{
	int data;
	struct Binode *lchild;
	struct Binode *rchild;
}BiTNode, *BiTree;

//InitBiTree����һ�ÿն�����,�����˸��ڵ������
void InitBiTree(BiTree &T)
{
	T = NULL;
}

//DestroyBiTree����һ�ö�����
void DestroyBiTree(BiTree &T)
{
	if (T)
	{
		if (T->lchild != NULL)
			DestroyBiTree(T->lchild);
		if (T->rchild != NULL)
			DestroyBiTree(T->rchild);
		T = NULL;
		free(T);
		
	}
}
//CreateBiTree�����幹��һ�ö�����
void CreateBiTree(BiTree &T)
{
	T = (BiTree)malloc(sizeof(BiTNode));
	T->lchild = NULL;
	T->rchild = NULL;
}
//InsertChild���뵱ǰ�ڵ�ĺ��ӽڵ�
int InsertChild(BiTree &Node, int Value)
{
	BiTree temp = (BiTree)malloc(sizeof(BiTNode));
	temp->data = Value;
	temp->lchild = temp->rchild = NULL;
	if (Node->lchild == NULL)
	{
		Node->lchild = temp;
		return 0;
	}
	else if (Node->rchild == NULL)
	{
		Node->rchild = temp;
		return 0;
	}
	else
		return -1;		
}
//DeleteChildɾ����ǰ�ڵ�ĺ��ӽڵ�
int DeleteChild(BiTree &Node)
{
	if (Node->lchild == NULL&&Node->rchild == NULL)
	{
		free(Node);
		Node = NULL;
		return 0;
	}
	else
		return -1;
}
//ClearBiTree�����������Ϊһ�ÿ���
#define ClearBiTree DestroyBiTree
//BiTreeEmpty�ж϶������Ƿ�Ϊ����
int BiTreeEmpty(BiTree T)
{
	if (T)
		return 0;//����0�������ǿ�
	else
		return 1;//����1��������
}
//BiTreeDepth�����������
int BiTreeDepth(BiTree T)
{
	int ldepth,rdepth;
	if (!T)
		return 0;
	if (T->lchild)
		ldepth = BiTreeDepth(T->lchild);
	else
		ldepth = 0;
	if (T->rchild)
		rdepth = BiTreeDepth(T->rchild);
	else
		rdepth = 0;
	return ldepth>rdepth ? ldepth + 1 : rdepth + 1;
}

//Value����ĳ���ڵ��ֵ
int Value(BiTree Node)
{
	return Node->data;
}

//AssignΪĳ���ڵ㸳ֵ
void Assign(BiTree &Node,int value)
{
	Node->data = value;
}


BiTree Point(BiTree Head, int Node_Value)
{
	queue<BiTree> temp;
	BiTree Temp_data;
	temp.push(Head);
	while (!temp.empty())
	{
		Temp_data = temp.front();
		if (Temp_data->data == Node_Value)
			return Temp_data;
		temp.pop();
		if (Temp_data->lchild != NULL)
			temp.push(Temp_data->lchild);
		if (Temp_data->rchild != NULL)
			temp.push(Temp_data->rchild);
	}
	return NULL;
}

//Parent���طǸ��ڵ�ĸ��ڵ�
BiTree Parent(BiTree Head, int Node_Value)
{
	queue<BiTree> temp;
	BiTree Temp_data;
	temp.push(Head);
	while (!temp.empty())
	{
		Temp_data = temp.front();
		if ((Temp_data->lchild&&Temp_data->lchild->data == Node_Value)|| (Temp_data->rchild&&Temp_data->rchild->data == Node_Value))
			return Temp_data;
		temp.pop();
		if (Temp_data->lchild != NULL)
			temp.push(Temp_data->lchild);
		if (Temp_data->rchild != NULL)
			temp.push(Temp_data->rchild);
	}
	return NULL;
}

//LeftChild���ص�ǰ�ڵ������
BiTree LeftChild(BiTree Head, int Node_Value)
{
	BiTree temp;
	temp = Point(Head, Node_Value);
	if (temp&&temp->lchild)
		return temp->lchild;
	else
		return NULL;
}

//RightChild���ص�ǰ�ڵ���Һ���
BiTree RightChild(BiTree Head, int Node_Value)
{
	BiTree temp;
	temp = Point(Head, Node_Value);
	if (temp&&temp->rchild)
		return temp->rchild;
	else
		return NULL;
}

//LeftSibling���ص�ǰ�ڵ�����ֵ�
BiTree LeftSibling(BiTree Head, int Node_Value)
{
	BiTree temp;
	temp = Parent(Head, Node_Value);
	if (temp&&(temp->lchild->data!=Node_Value))
		return temp->lchild;
	else
		return NULL;
}

//RightSibling���ص�ǰ�ڵ�����ֵ�
BiTree RightSibling(BiTree Head, int Node_Value)
{
	BiTree temp;
	temp = Parent(Head, Node_Value);
	if (temp && (temp->rchild->data != Node_Value))
		return temp->rchild;
	else
		return NULL;
}

//PreOrderTraverse�������������
void PreOrderTraverse(BiTree T)
{
	if (T)
	{
		cout << T->data << "  ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
//InOrderTraverse�������������
void InOrderTraverse(BiTree T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		cout << T->data << "  ";
		InOrderTraverse(T->rchild);
	}
}
//PostOrderTraverse�������������
void PostOrderTraverse(BiTree T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data << "  ";
	}
}

//LevelOrderTraverse��α���������
void LevelOrderTraverse(BiTree T)
{
	queue<BiTree> temp;
	BiTree Temp_data;
	temp.push(T);
	while (!temp.empty())
	{
		Temp_data = temp.front();
		cout << Temp_data->data << "  " ;
		temp.pop();
		if (Temp_data->lchild != NULL)
			temp.push(Temp_data->lchild);
		if (Temp_data->rchild != NULL)
			temp.push(Temp_data->rchild);
	}
	cout << endl;
}

#endif // !_BINARY_TREE_H_

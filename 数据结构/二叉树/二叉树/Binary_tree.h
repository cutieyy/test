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

//InitBiTree构造一棵空二叉树,保留了根节点的数字
void InitBiTree(BiTree &T)
{
	T = NULL;
}

//DestroyBiTree销毁一棵二叉树
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
//CreateBiTree按定义构造一棵二叉树
void CreateBiTree(BiTree &T)
{
	T = (BiTree)malloc(sizeof(BiTNode));
	T->lchild = NULL;
	T->rchild = NULL;
}
//InsertChild插入当前节点的孩子节点
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
//DeleteChild删除当前节点的孩子节点
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
//ClearBiTree将二叉树清空为一棵空树
#define ClearBiTree DestroyBiTree
//BiTreeEmpty判断二叉树是否为空树
int BiTreeEmpty(BiTree T)
{
	if (T)
		return 0;//返回0代表树非空
	else
		return 1;//返回1代表树空
}
//BiTreeDepth返回树的深度
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

//Value返回某个节点的值
int Value(BiTree Node)
{
	return Node->data;
}

//Assign为某个节点赋值
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

//Parent返回非根节点的父节点
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

//LeftChild返回当前节点的左孩子
BiTree LeftChild(BiTree Head, int Node_Value)
{
	BiTree temp;
	temp = Point(Head, Node_Value);
	if (temp&&temp->lchild)
		return temp->lchild;
	else
		return NULL;
}

//RightChild返回当前节点的右孩子
BiTree RightChild(BiTree Head, int Node_Value)
{
	BiTree temp;
	temp = Point(Head, Node_Value);
	if (temp&&temp->rchild)
		return temp->rchild;
	else
		return NULL;
}

//LeftSibling返回当前节点的左兄弟
BiTree LeftSibling(BiTree Head, int Node_Value)
{
	BiTree temp;
	temp = Parent(Head, Node_Value);
	if (temp&&(temp->lchild->data!=Node_Value))
		return temp->lchild;
	else
		return NULL;
}

//RightSibling返回当前节点的右兄弟
BiTree RightSibling(BiTree Head, int Node_Value)
{
	BiTree temp;
	temp = Parent(Head, Node_Value);
	if (temp && (temp->rchild->data != Node_Value))
		return temp->rchild;
	else
		return NULL;
}

//PreOrderTraverse先序遍历二叉树
void PreOrderTraverse(BiTree T)
{
	if (T)
	{
		cout << T->data << "  ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
//InOrderTraverse中序遍历二叉树
void InOrderTraverse(BiTree T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		cout << T->data << "  ";
		InOrderTraverse(T->rchild);
	}
}
//PostOrderTraverse后序遍历二叉树
void PostOrderTraverse(BiTree T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data << "  ";
	}
}

//LevelOrderTraverse层次遍历二叉树
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

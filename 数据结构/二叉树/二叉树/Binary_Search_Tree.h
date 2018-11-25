#pragma once
#ifndef _BINARY_SEARCH_TREE_H_
#define MAXSIGN  10000
#include"Binary_tree.h"

//将int型整数以二进制形式输出
void TranToBinary(const int&val)
{
	for (int i = sizeof(int) - 1;i >= 0;i--)
	{
		if (val &(1 << i))
			std::cout << "1";
		else std::cout << "0";
	}
	cout << endl;
}


//插入二叉搜索树的节点
void Insert_Search_Tree(BiTree &head,int Value)
{
	BiTree T = head;
	BiTree temp = (BiTree)malloc(sizeof(BiTNode));
	temp->data = Value;
	temp->lchild = temp->rchild = NULL;	
	if (T->data==MAXSIGN)
	{
		T->data = temp->data;
		return;
	}
	while (true)
	{
		if ((T->data > Value))
		{
			if (T->lchild == NULL)
			{
				T->lchild = temp;
				return;
			}
			else
				T = T->lchild;
		}
		else
		{
			if (T->rchild == NULL)
			{
				T->rchild = temp;
				return;
			}
			else
				T = T->rchild;
		}
	}

}

//在二叉搜索树中查找
BiTree Search_Tree(BiTree T,int Value)
{
	while (true)
	{
		if (T->data == Value)
			return T;
		else
		{
			if ((T->data > Value))
				T = T->lchild;
			else
				T = T->rchild;
		}
	}
	return NULL;
}

//返回当前二叉搜索树的最大值
BiTree Max_tree(BiTree T)
{
	while (T->rchild != NULL)
		T = T->rchild;
	return T;
}
//返回当前二叉搜索树的最小值
BiTree Min_tree(BiTree T)
{
	while (T->lchild != NULL)
		T = T->lchild;
	return T;
}

//从二叉搜索树中删除某个节点
void Delete_S_Node(BiTree &T, int Value)
{
	BiTree temp,parent;
	temp=Search_Tree(T, Value);
	parent = Parent(T, Value);
	if (temp->lchild == NULL&&temp->rchild==NULL)
	{
		parent->lchild = parent->rchild = NULL;
		free(temp);
		temp = NULL;
	}
	else if (temp->lchild == NULL)
	{
		if (parent->lchild->data == temp->data)
			parent->lchild = temp->rchild;
		else
			parent->rchild = temp->rchild;
		free(temp);
		temp = NULL;
	}
	else if (temp->rchild == NULL)
	{
		if (parent->lchild->data == temp->data)
			parent->lchild = temp->lchild;
		else
			parent->rchild = temp->lchild;
		free(temp);
		temp = NULL;
	}
	else
	{
		BiTree mintemp,min_parent;
		mintemp = Min_tree(temp->rchild);
		if (mintemp->data != temp->rchild->data)
		{
			min_parent = Parent(temp->rchild, mintemp->data);
			min_parent->lchild = mintemp->rchild;
			mintemp->rchild = temp->rchild;
		}
		mintemp->lchild = temp->lchild;
		if (parent->lchild->data == temp->data)
			parent->lchild = mintemp;
		else
			parent->rchild = mintemp;
		free(temp);
		temp = NULL;
	}
}

//二叉平衡树中计算平衡因子
int Balance_Factor(BiTree T)
{
	return BiTreeDepth(T->lchild) - BiTreeDepth(T->rchild);
}

//二叉树右旋调整
void Rotating_LL(BiTree &T,BiTree Node)
{
	BiTree parent_node,temp;
	if (Node != T)
	{
		parent_node = Parent(T, Node->data);
		if (parent_node->lchild&&parent_node->lchild->data == Node->data)
			parent_node->lchild = Node->lchild;
		else
			parent_node->rchild = Node->lchild;
	}
	else
	{
		T = Node->lchild;
	}
	temp = Node->lchild;
	Node->lchild=Node->lchild->rchild;
	temp->rchild = Node;	
}

//二叉树左旋调整
void Rotating_RR(BiTree &T, BiTree Node)
{
	BiTree parent_node, temp;
	if (Node!= T)
	{
		parent_node = Parent(T, Node->data);
		if (parent_node->lchild&&parent_node->lchild->data == Node->data)
			parent_node->lchild = Node->rchild;
		else
			parent_node->rchild = Node->rchild;
	}
	else
	{
		T = Node->rchild;
	}
	temp = Node->rchild;
	Node->rchild = Node->rchild->lchild;
	temp->lchild = Node;
}
//二叉树先右旋后左旋
void Rotating_LR(BiTree &T, BiTree Node)
{
	Rotating_RR(T, Node->lchild);
	Rotating_LL(T, Node);
}
//二叉树先左旋后右旋
void Rotating_RL(BiTree &T, BiTree Node)
{
	Rotating_LL(T, Node->rchild);
	Rotating_RR(T, Node);
}
//二叉平衡树节点插入
int Insert_Balance_Tree(BiTree T, int Value)
{
	int label = 0;
	BiTree temp = (BiTree)malloc(sizeof(BiTNode));
	temp->data = Value;
	temp->lchild = temp->rchild = NULL;
	if (T->data == MAXSIGN)
	{
		T->data = temp->data;
		return label;
	}
	while (true)
	{
		if ((T->data > Value))
		{
			if (T->lchild == NULL)
			{
				T->lchild = temp;
				return label;
			}
			else
			{
				T = T->lchild;
				label=label << 1;
			}
		}
		else
		{
			if (T->rchild == NULL)
			{
				T->rchild = temp;
				label = label | 1;
				return label;
			}
			else
			{
				T = T->rchild;
				label = label | 1;
				label = label << 1;
			}
		}
	}
}
//二叉平衡树节点的插入，并调整
void Insert_B_Node(BiTree &T, int Value)
{
	int label;
	BiTree head=T;
	BiTree parent_node,node;
	label = Insert_Balance_Tree(T, Value);
	int Balance_factor;

	node = Parent(T, Value);
	T = head;
	if (node == NULL)
		return;

	while (true)
	{
			node = Parent(T, node->data);
			if (node == NULL)
				return;
			Balance_factor = Balance_Factor(node);
			if (Balance_factor == 2 || Balance_factor == -2)
			{
				label = label & 3;
				//TranToBinary(label);
				switch (label)
				{
					case 0:Rotating_LL(T, node);
						break;
					case 1:Rotating_LR(T, node);
						break;
					case 2:Rotating_RL(T, node);
						break;
					case 3:Rotating_RR(T, node);
						break;		
				}
				return;
			}
			if (Balance_factor == 0)
				return;
			label = label >> 1;
		}
}






#endif // !_BINARY_SEARCH_TREE_H_



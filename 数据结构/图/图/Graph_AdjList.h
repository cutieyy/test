#pragma once
#ifndef _GRAPH_ADJLIST_H
#include <iostream>
#include<fstream>
#include<queue>
using namespace std;
//常量定义
#define INFINITY 100000 /* 用整型最大值代替∞ */
#define MAX_VERTEX_NUM 20 /* 最大顶点个数 */
#define MAX_NAME 5 /* 顶点字符串的最大长度+1 */
#define MAX_INFO 20 /* 相关信息字符串的最大长度+1 */
typedef int VRType;
typedef char InfoType;
typedef char VertexType[MAX_NAME];
//邻接表的数据结构
typedef struct ArcNode
{
	int adjvex; /* 该弧所指向的顶点的位置 */
	struct ArcNode *nextarc; /* 指向下一条弧的指针 */
}ArcNode; /* 表结点 */
typedef struct
{
	VertexType data; /* 顶点信息 */
	ArcNode *firstarc; /* 第一个表结点的地址,指向第一条依附该顶点的弧的指针 */
}VNode, AdjList[MAX_VERTEX_NUM]; /* 头结点 */
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; /* 图的当前顶点数和弧数 */
}ALGraph;

/*---------------------基本操作-------------------------------*/

//LocateVex返回顶点在图中的位置
int LocateVex(ALGraph G, VertexType v)
{
	int i;
	for (i = 0;i<G.vexnum;++i)
		if (strcmp(v, G.vertices[i].data) == 0)
			return i;
	return -1;
}

//GreateGraph构造一个图（读取文件构造）
//文件的结构：第一行顶点数，第二行边数，接下来先顶点，后边
void CreateGraph(ALGraph &G)
{
	ArcNode *p,*q;
	VertexType va, vb;
	int i, j, k;
	ifstream in("graph.txt");
	in >> G.vexnum;
	//cout << "顶点数：" << G.vexnum<<endl;
	in >> G.arcnum;
	//cout << "边数：" << G.arcnum<<endl;

	for (i = 0;i < G.vexnum;i++)
	{
		in >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (k = 0;k < G.arcnum;k++)
	{
		in >> va >> vb;
		i = LocateVex(G, va);
		j = LocateVex(G, vb);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;

		q = (ArcNode*)malloc(sizeof(ArcNode));
		q->adjvex = i;
		q->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = q;
	}
	in.close();
}

//DestroyGraph销毁图
void DestroyGraph(ALGraph &G)
{
	ArcNode *p, *q;
	for (int i = 0;i < G.vexnum;i++)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			q = p->nextarc;
			free(p);
			p = q;
		}
	}
	G.vexnum = 0;
	G.arcnum = 0;
}

//GetVex返回顶点的值，给定顶点序号
VertexType* GetVex(ALGraph G, int i)
{
	if (i >= G.vexnum || i<0)
		exit(-1);
	return &G.vertices[i].data;
}

//PutVex对顶点重新赋值
void PutVex(ALGraph &G, VertexType v, VertexType new_v)
{
	int location;
	location = LocateVex(G, v);
	if (location < 0)
		exit(-1);
	strcpy_s(G.vertices[location].data, new_v);
}

//FirstAdjVex返回v的第一个邻接顶点
int FirstAdjVex(ALGraph G, VertexType v)
{
	int location;
	location = LocateVex(G, v);
	ArcNode *p;
	p = G.vertices[location].firstarc;
	if (p)
		return p->adjvex;
	else
		return -1;
}

//NextAdjVex返回v的下一个邻接结点
int NextAdjVex(ALGraph G, VertexType v, VertexType w)
{
	int location_v, location_w;
	location_v = LocateVex(G, v);
	location_w = LocateVex(G, w);
	ArcNode *p;
	p = G.vertices[location_v].firstarc;
	while (p&&p->adjvex != location_w)
		p = p->nextarc;
	if (!p || !p->nextarc)
		return -1;
	else
		return p->nextarc->adjvex;
}

//InsertVex插入一个顶点
void InsertVex(ALGraph &G, VertexType v)
{
	strcpy_s(G.vertices[G.vexnum].data, v);
	G.vertices[G.vexnum].firstarc = NULL;
	G.vexnum++;
}

//DeleteVex删除图中的顶点
void DeleteVex(ALGraph &G, VertexType v)
{
	int location;
	location = LocateVex(G, v);
	if (location < 0)
		return;

	ArcNode *p, *q;
	q = (ArcNode*)malloc(sizeof(ArcNode));
	p = G.vertices[location].firstarc;

	while (p)
	{
		q = p;
		p = p->nextarc;
		free(q);
		G.arcnum--;
	}

	G.vexnum--;
	for (int i = location;i < G.vexnum;i++)
		G.vertices[i] = G.vertices[i + 1];

	for (int i = 0;i < G.vexnum;i++)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			if (p->adjvex == location)
			{
				if (p == G.vertices[i].firstarc)
				{
					G.vertices[i].firstarc = p->nextarc;
					free(p);
					p = G.vertices[i].firstarc;
				}
				else
				{
					q->nextarc = p->nextarc;
					free(p);
					p = q->nextarc;
				}
			}
			else
			{
				if (p->adjvex > location)
					p->adjvex--;
				q = p;
				p = p->nextarc;
			}
		}
	}
	
}

//InsertArc插入一条弧
void InsertArc(ALGraph &G, VertexType v, VertexType w)
{
	int location1, location2;
	location1 = LocateVex(G, v);
	location2 = LocateVex(G, w);
	if (location1 < 0 || location2 < 0)
		return;
	G.arcnum++;
	ArcNode *p, *q;
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = location2;
	p->nextarc = G.vertices[location1].firstarc;
	G.vertices[location1].firstarc = p;

	q = (ArcNode*)malloc(sizeof(ArcNode));
	q->adjvex = location1;
	q->nextarc = G.vertices[location2].firstarc;
	G.vertices[location2].firstarc = q;
}

//DeleteArc删除一条弧
void DeleteArc(ALGraph &G, VertexType v, VertexType w)
{
	int location1, location2;
	location1 = LocateVex(G, v);
	location2 = LocateVex(G, w);
	if (location1 < 0 || location2 < 0)
		return;
	ArcNode *p, *q;
	p = (ArcNode*)malloc(sizeof(ArcNode));
	q = (ArcNode*)malloc(sizeof(ArcNode));
	while (p&&p->adjvex != location2)
	{
		q = p;
		p = p->nextarc;
	}

	if (p&&p->adjvex == location2)
	{
		if (p == G.vertices[location1].firstarc)
			G.vertices[location1].firstarc = p->nextarc;
		else
			q->nextarc = p->nextarc;
		free(p);
		G.arcnum--;
	}

	p = (ArcNode*)malloc(sizeof(ArcNode));
	while (p&&p->adjvex != location1)
	{
		q = p;
		p = p->nextarc;
	}
	if (p&&p->adjvex == location1)
	{
		if (p == G.vertices[location2].firstarc)
			G.vertices[location2].firstarc = p->nextarc;
		else
			q->nextarc = p->nextarc;
		free(p);
	}
}

//Display显示当前图的信息和邻接矩阵
void Display(ALGraph G)
{
	ArcNode *p;
	//int count=0;
	cout << "顶点数:" << G.vexnum << endl << "顶点为：";
	for (int i = 0;i < G.vexnum;i++)
		cout << G.vertices[i].data<< " ";
	cout << endl;
	cout << "边数:" << G.arcnum << endl << "边为："<<endl;
	for (int i = 0;i < G.vexnum;i++)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			cout << G.vertices[i].data << "---" << G.vertices[p->adjvex].data << endl;
			//count++;
			p = p->nextarc;
		}
		
	}
	//cout << count << endl;	
}

//DFSTraverse对图进行深度优先遍历
bool visited[MAX_VERTEX_NUM];
void DFS(ALGraph G, int v)
{
	VertexType w1, v1;
	int w;
	visited[v] = true;
	cout << G.vertices[v].data<< endl;
	strcpy_s(v1, *GetVex(G, v));
	for (w = FirstAdjVex(G, v1);w >= 0;)
	{
		if (!visited[w])
			DFS(G, w);
		else {
			strcpy_s(w1, *GetVex(G, w));
			w = NextAdjVex(G, v1, w1);
		}
	}
}
void DFSTraverse(ALGraph G)
{
	int v;
	for (v = 0;v < G.vexnum;v++)
		visited[v] = false;
	for (v = 0;v < G.vexnum;v++)
		if (!visited[v])
			DFS(G, v);
	cout << endl;
}

//BFSTraverse对图进行广度优先遍历
void BFSTraverse(ALGraph G)
{
	int v, u, w;
	for (v = 0;v < G.vexnum;v++)
		visited[v] = false;
	queue<int> temp;
	VertexType v1, w1;
	for (v = 0;v<G.vexnum;v++)
		if (!visited[v])
		{
			visited[v] = true;
			cout << G.vertices[v].data << endl;
			temp.push(v);
			while (temp.empty())
			{
				u = temp.front();
				temp.pop();
				strcpy_s(v1, *GetVex(G, u));
				for (w = FirstAdjVex(G, v1);w >= 0;)
				{
					if (!visited[w])
					{
						visited[w] = true;
						cout << G.vertices[v].data << endl;
						temp.push(w);
					}
					else {
						strcpy_s(w1, *GetVex(G, w));
						w = NextAdjVex(G, v1, w1);
					}
				}
			}
		}
}

#endif // !_GRAPH_ADJLIST_H

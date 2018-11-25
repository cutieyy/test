#pragma once
//此代码中涉及到的图均为无向图
#ifndef GRAPH_ADJMATRIX
//#define _CRT_SECURE_NO_WARNINGS
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
//邻接矩阵的数据结构
typedef struct
{
	VRType adj; /* 顶点关系类型。对无权图，用1(是)或0(否)表示相邻否； */
				/* 对带权图，c则为权值类型 */
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM]; /* 顶点向量 */
	AdjMatrix arcs; /* 邻接矩阵 */
	int vexnum, arcnum; /* 图的当前顶点数和弧数 */
}MGraph;
/*---------------------基本操作-------------------------------*/

//LocateVex返回顶点在图中的位置
int LocateVex(MGraph G, VertexType v)
{
	int i;
	for (i = 0;i<G.vexnum;++i)
		if (strcmp(v, G.vexs[i]) == 0)
			return i;
	return -1;
}

//GreateGraph构造一个图（读取文件构造）
//文件的结构：第一行顶点数，第二行边数，接下来先顶点，后边
void CreateGraph(MGraph &G)
{
	VertexType va, vb;
	int i, j, k;
	ifstream in("graph.txt");
	in >> G.vexnum;
	//cout << "顶点数：" << G.vexnum<<endl;
	in >> G.arcnum;
	//cout << "边数：" << G.arcnum<<endl;

	for (i = 0;i < G.vexnum;i++)
		in >> G.vexs[i];
	for(i=0;i<G.vexnum;i++)
		for (j = 0;j < G.vexnum;j++)
		{
			G.arcs[i][j].adj = 0;
		}
	for (k = 0;k < G.arcnum;k++)
	{
		in >> va >> vb;
		i = LocateVex(G, va);
		j = LocateVex(G, vb);
		G.arcs[i][j].adj=G.arcs[j][i].adj = 1;
	}
	in.close();
}

//DestroyGraph销毁图
void DestroyGraph(MGraph &G)
{
	G.vexnum = 0;
	G.arcnum = 0;
}

//GetVex返回顶点的值，给定顶点序号
VertexType* GetVex(MGraph G, int i)
{
	if (i >= G.vexnum || i<0)
		exit(-1);
	return &G.vexs[i];
}

//PutVex对顶点重新赋值
void PutVex(MGraph &G,VertexType v,VertexType new_v)
{
	int location;
	location= LocateVex(G, v);
	if (location < 0)
		exit(-1);
	strcpy_s(G.vexs[location], new_v);
}

//FirstAdjVex返回v的第一个邻接顶点
int FirstAdjVex(MGraph G, VertexType v)
{
	int location;
	location = LocateVex(G, v);
	for (int i = 0;i < G.vexnum;i++)
		if (G.arcs[location][i].adj == 1)
			return i;
	return -1;
}

//NextAdjVex返回v的下一个邻接结点
int NextAdjVex(MGraph G, VertexType v, VertexType w)
{
	int location_v, location_w;
	location_v = LocateVex(G, v);
	location_w = LocateVex(G, w);
	for (int i = location_w+1;i < G.vexnum;i++)
		if (G.arcs[location_v][i].adj == 1)
			return i;
	return -1;
}

//InsertVex插入一个顶点
void InsertVex(MGraph &G, VertexType v)
{
	int i;
	strcpy_s(G.vexs[G.vexnum], v);
	G.vexnum++;
	for (int i = 0;i < G.vexnum;i++)
	{
		G.arcs[G.vexnum - 1][i].adj = 0;
		G.arcs[i][G.vexnum - 1].adj = 0;
	}
}

//DeleteVex删除图中的顶点
void DeleteVex(MGraph &G,VertexType v)
{
	int location;
	location = LocateVex(G, v);
	if (location < 0)
		return;
	for(int i=0;i<G.vexnum;i++)
		if (G.arcs[location][i].adj == 1)
		{
			G.arcs[location][i].adj = G.arcs[i][location].adj = 0;
			G.arcnum--;
		}
	for (int j = location + 1;j < G.vexnum;j++)
		strcpy_s(G.vexs[j - 1], G.vexs[j]);
	for (int i = 0;i < G.vexnum;i++)
		for (int j = location + 1;j < G.vexnum;j++)
			G.arcs[i][j - 1] = G.arcs[i][j];
	for (int i = 0;i < G.vexnum;i++)
		for (int j = location + 1;j < G.vexnum;j++)
			G.arcs[j-1][i] = G.arcs[j][i];
	G.vexnum--;
}

//InsertArc插入一条弧
void InsertArc(MGraph &G, VertexType v, VertexType w)
{
	int location1, location2;
	location1 = LocateVex(G, v);
	location2 = LocateVex(G, w);
	if (location1 < 0 || location2 < 0)
		return;
	G.arcnum++;
	G.arcs[location1][location2].adj = G.arcs[location2][location1].adj = 1;
}

//DeleteArc插入一条弧
void DeleteArc(MGraph &G, VertexType v, VertexType w)
{
	int location1, location2;
	location1 = LocateVex(G, v);
	location2 = LocateVex(G, w);
	if (location1 < 0 || location2 < 0)
		return;
	G.arcnum--;
	G.arcs[location1][location2].adj = G.arcs[location2][location1].adj = 0;
}

//Display显示当前图的信息和邻接矩阵
void Display(MGraph G)
{
	cout << "顶点数:" << G.vexnum << endl<<"顶点为：";
	for (int i = 0;i < G.vexnum;i++)
		cout << G.vexs[i] << " ";
	cout << endl << "邻接矩阵：" << endl;
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
		{
			cout<<G.arcs[i][j].adj;
		}
		cout << endl;
	}
}

//DFSTraverse对图进行深度优先遍历
bool visited[MAX_VERTEX_NUM];
void DFS(MGraph G, int v)
{
	VertexType w1, v1;
	int w;
	visited[v] = true;
	cout << G.vexs[v] << endl;
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
void DFSTraverse(MGraph G)
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
void BFSTraverse(MGraph G)
{
	int v,u,w;
	for (v = 0;v < G.vexnum;v++)
		visited[v] = false;
	queue<int> temp;
	VertexType v1, w1;
	for(v=0;v<G.vexnum;v++)
		if (!visited[v])
		{
			visited[v] = true;
			cout << G.vexs[v] << endl;
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
						cout << G.vexs[v] << endl;
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
#endif // !GRAPH_ADJMATRIX

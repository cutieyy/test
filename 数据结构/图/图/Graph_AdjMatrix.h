#pragma once
//�˴������漰����ͼ��Ϊ����ͼ
#ifndef GRAPH_ADJMATRIX
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include<queue>
using namespace std;
//��������
#define INFINITY 100000 /* ���������ֵ����� */
#define MAX_VERTEX_NUM 20 /* ��󶥵���� */
#define MAX_NAME 5 /* �����ַ�������󳤶�+1 */
#define MAX_INFO 20 /* �����Ϣ�ַ�������󳤶�+1 */
typedef int VRType;
typedef char InfoType;
typedef char VertexType[MAX_NAME];
//�ڽӾ�������ݽṹ
typedef struct
{
	VRType adj; /* �����ϵ���͡�����Ȩͼ����1(��)��0(��)��ʾ���ڷ� */
				/* �Դ�Ȩͼ��c��ΪȨֵ���� */
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM]; /* �������� */
	AdjMatrix arcs; /* �ڽӾ��� */
	int vexnum, arcnum; /* ͼ�ĵ�ǰ�������ͻ��� */
}MGraph;
/*---------------------��������-------------------------------*/

//LocateVex���ض�����ͼ�е�λ��
int LocateVex(MGraph G, VertexType v)
{
	int i;
	for (i = 0;i<G.vexnum;++i)
		if (strcmp(v, G.vexs[i]) == 0)
			return i;
	return -1;
}

//GreateGraph����һ��ͼ����ȡ�ļ����죩
//�ļ��Ľṹ����һ�ж��������ڶ��б������������ȶ��㣬���
void CreateGraph(MGraph &G)
{
	VertexType va, vb;
	int i, j, k;
	ifstream in("graph.txt");
	in >> G.vexnum;
	//cout << "��������" << G.vexnum<<endl;
	in >> G.arcnum;
	//cout << "������" << G.arcnum<<endl;

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

//DestroyGraph����ͼ
void DestroyGraph(MGraph &G)
{
	G.vexnum = 0;
	G.arcnum = 0;
}

//GetVex���ض����ֵ�������������
VertexType* GetVex(MGraph G, int i)
{
	if (i >= G.vexnum || i<0)
		exit(-1);
	return &G.vexs[i];
}

//PutVex�Զ������¸�ֵ
void PutVex(MGraph &G,VertexType v,VertexType new_v)
{
	int location;
	location= LocateVex(G, v);
	if (location < 0)
		exit(-1);
	strcpy_s(G.vexs[location], new_v);
}

//FirstAdjVex����v�ĵ�һ���ڽӶ���
int FirstAdjVex(MGraph G, VertexType v)
{
	int location;
	location = LocateVex(G, v);
	for (int i = 0;i < G.vexnum;i++)
		if (G.arcs[location][i].adj == 1)
			return i;
	return -1;
}

//NextAdjVex����v����һ���ڽӽ��
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

//InsertVex����һ������
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

//DeleteVexɾ��ͼ�еĶ���
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

//InsertArc����һ����
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

//DeleteArc����һ����
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

//Display��ʾ��ǰͼ����Ϣ���ڽӾ���
void Display(MGraph G)
{
	cout << "������:" << G.vexnum << endl<<"����Ϊ��";
	for (int i = 0;i < G.vexnum;i++)
		cout << G.vexs[i] << " ";
	cout << endl << "�ڽӾ���" << endl;
	for (int i = 0;i < G.vexnum;i++)
	{
		for (int j = 0;j < G.vexnum;j++)
		{
			cout<<G.arcs[i][j].adj;
		}
		cout << endl;
	}
}

//DFSTraverse��ͼ����������ȱ���
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

//BFSTraverse��ͼ���й�����ȱ���
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

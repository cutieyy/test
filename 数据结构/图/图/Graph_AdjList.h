#pragma once
#ifndef _GRAPH_ADJLIST_H
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
//�ڽӱ�����ݽṹ
typedef struct ArcNode
{
	int adjvex; /* �û���ָ��Ķ����λ�� */
	struct ArcNode *nextarc; /* ָ����һ������ָ�� */
}ArcNode; /* ���� */
typedef struct
{
	VertexType data; /* ������Ϣ */
	ArcNode *firstarc; /* ��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ�� */
}VNode, AdjList[MAX_VERTEX_NUM]; /* ͷ��� */
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; /* ͼ�ĵ�ǰ�������ͻ��� */
}ALGraph;

/*---------------------��������-------------------------------*/

//LocateVex���ض�����ͼ�е�λ��
int LocateVex(ALGraph G, VertexType v)
{
	int i;
	for (i = 0;i<G.vexnum;++i)
		if (strcmp(v, G.vertices[i].data) == 0)
			return i;
	return -1;
}

//GreateGraph����һ��ͼ����ȡ�ļ����죩
//�ļ��Ľṹ����һ�ж��������ڶ��б������������ȶ��㣬���
void CreateGraph(ALGraph &G)
{
	ArcNode *p,*q;
	VertexType va, vb;
	int i, j, k;
	ifstream in("graph.txt");
	in >> G.vexnum;
	//cout << "��������" << G.vexnum<<endl;
	in >> G.arcnum;
	//cout << "������" << G.arcnum<<endl;

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

//DestroyGraph����ͼ
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

//GetVex���ض����ֵ�������������
VertexType* GetVex(ALGraph G, int i)
{
	if (i >= G.vexnum || i<0)
		exit(-1);
	return &G.vertices[i].data;
}

//PutVex�Զ������¸�ֵ
void PutVex(ALGraph &G, VertexType v, VertexType new_v)
{
	int location;
	location = LocateVex(G, v);
	if (location < 0)
		exit(-1);
	strcpy_s(G.vertices[location].data, new_v);
}

//FirstAdjVex����v�ĵ�һ���ڽӶ���
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

//NextAdjVex����v����һ���ڽӽ��
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

//InsertVex����һ������
void InsertVex(ALGraph &G, VertexType v)
{
	strcpy_s(G.vertices[G.vexnum].data, v);
	G.vertices[G.vexnum].firstarc = NULL;
	G.vexnum++;
}

//DeleteVexɾ��ͼ�еĶ���
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

//InsertArc����һ����
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

//DeleteArcɾ��һ����
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

//Display��ʾ��ǰͼ����Ϣ���ڽӾ���
void Display(ALGraph G)
{
	ArcNode *p;
	//int count=0;
	cout << "������:" << G.vexnum << endl << "����Ϊ��";
	for (int i = 0;i < G.vexnum;i++)
		cout << G.vertices[i].data<< " ";
	cout << endl;
	cout << "����:" << G.arcnum << endl << "��Ϊ��"<<endl;
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

//DFSTraverse��ͼ����������ȱ���
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

//BFSTraverse��ͼ���й�����ȱ���
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

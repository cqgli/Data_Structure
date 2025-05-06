#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../queue/queue/SqQueue.h"
#define MaxVertexNum 100
//�ڽӾ���
typedef struct {
	char vex[MaxVertexNum];//��Ŷ���
	int edge[MaxVertexNum][MaxVertexNum];//����ڽӾ���
	int vexnum, arcnum;
}MGraph;

//��
typedef struct ArcNode {
	int adjvex;//��¼�ڽӶ����λ�ã�����
	struct ArcNode* next;//ָ����һ���ߵ�ָ��
	//int info,Ȩֵ
}ArcNode;

//����
typedef struct VNode{
	char data;//��¼�������ݣ�ͷ���
	ArcNode* first;//��һ����
}VNode, AdjList[MaxVertexNum];

//�ڽӱ�
typedef struct {
	VNode vertices[MaxVertexNum];//����һ��ͷ������
	int vexnum, arcnum;//��¼����ͱߵĸ���
}ALGraph;


//�ڽӾ��󴴽�ͼ


//�ڽӱ���������
//�����ܵĶ��������ܱ���
//���������
//������������Ϣ���붥�����
//ʹÿ����ͷ�ڵ��ָ�����ʼ��ΪNULL
//�����ڽӱ�
//��������ÿ������������������
//ȷ��������������i��j�������߽ڵ�
//���˱߽ڵ�ֱ��ͼ��vi,vj��Ӧ�������������ͷ��

//�ڽӱ�������ͼ
int locate(ALGraph G,char b)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (b == G.vertices[i].data)
			return i;
	}
	return -1;
}
void CreateUDG(ALGraph& G)
{
	printf("%d,%d", &G.vexnum, &G.arcnum);
	for (int i = 0; i < G.vexnum; i++)
	{
		printf("%c",&G.vertices[i]);
		G.vertices[i].first = NULL;
	}
	for (int i = 0; i < G.arcnum; i++)
	{
		char a, b;
		printf("%c,%c", &a, &b);
		int m = locate(G,a);
		int n = locate(G,b);
		ArcNode* A = (ArcNode*)malloc(sizeof(ArcNode));
		A->adjvex = n;
		A->next = G.vertices[n].first;
		G.vertices[n].first = A;
		ArcNode* B = (ArcNode*)malloc(sizeof(ArcNode));
		B->adjvex = m;
		B->next = G.vertices[m].first;
		G.vertices[m].first = B;
	}
}

//�ڽӱ�ʵ��BFS
//����һ��visit����洢�ڵ��Ƿ��Ѿ�����
//����һ�����У�����ʵ�ֽڵ���ӣ�����
//����ýڵ�û�б����ʣ�����ӣ�
//���ڵ���ӵ�ʱ����Ҫ����δ���ʵ��ڽӽڵ���ӣ�
//�ӿ���ͼ��BFS���
int FirstNeighbor(ALGraph G,int v);//��v�ĵ�һ���ڽӵ�
int NextNeighbor(ALGraph G, int v,int w);//vΪ���㣬WΪ�ڽӵ㣬��w����һ���ڽӵ㣬���ΪNULL�򷵻�-1

bool visited[MaxVertexNum];//��ʼ��Ϊfalse
SqQueue Q;
void BFSTraverse(ALGraph G)
{
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;
	// ��ʼ������
	//��������

	InitSqQueue(Q);
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
			BFS(G, i);
	}
}
void BFS(ALGraph G,int v)
{
	//���ʽڵ�
	printf("%c ", v);
	
	//���
	EnQueue(Q, v);
	while (!is_empty(Q))
	{
		DeQueue(Q, v);
		for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
		{
			if (!visited[w])
			{
				printf("%c ", w);
				visited[w] = true;
				EnQueue(Q, w);
			}
		}
	}
}
//������ʱ�临�Ӷ�ֻ���洢��ʽ�й�
//�ڽӾ���ʵ��BFS
void BFS1(MGraph G, int i)
{
	printf("%d", i);
	visited[i] = true;
	EnQueue(Q, i);
	int v;
	while (!is_empty(Q))
	{
		DeQueue(Q, v);
		for (int w = 0; w < G.vexnum; w++)
		{
			if (visited[w] == false && G.edge[v][w] == 1)
			{
				printf("%d", w);
				visited[w] = true;
				EnQueue(Q, w);
			}
		}
	}

}


//�ڽӾ���ʵ��DFS
//����һ��visit�����Žڵ��Ƿ񱻷���
//�����ǰ�ڵ�û�з��ʣ����ʸýڵ�
//Ȼ���ҵ����ڽڵ㣬�ݹ�ִ�к���

bool visit[MaxVertexNum];
void DFSTraverse(MGraph G, int x)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		visit[i] = false;
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visit[i])
			DFS(G, i);
	}
}
void DFS(MGraph G, int v)
{
	printf("%d", v);
	visit[v] = true;
	for (int w = 0;w<G.vexnum;w++)
	{
		if (!visit[w] && G.edge[v][w] == 1)
			DFS(G, w);
	}
}
//�ڽӱ�ʵ��
void DFS1(ALGraph G, int i)
{
	printf("%d", i);
	visited[i] = true;
	for (int w = FirstNeighbor(G, i); w >= 0; w = NextNeighbor(G, i, w))
	{
		if (!visited[w])
			DFS1(G, w);
	}
}


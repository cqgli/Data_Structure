#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../queue/queue/SqQueue.h"
#define MaxVertexNum 100
//邻接矩阵
typedef struct {
	char vex[MaxVertexNum];//存放顶点
	int edge[MaxVertexNum][MaxVertexNum];//存放邻接矩阵
	int vexnum, arcnum;
}MGraph;

//边
typedef struct ArcNode {
	int adjvex;//记录邻接顶点的位置，链域
	struct ArcNode* next;//指向下一个边的指针
	//int info,权值
}ArcNode;

//顶点
typedef struct VNode{
	char data;//记录顶点内容，头结点
	ArcNode* first;//第一条边
}VNode, AdjList[MaxVertexNum];

//邻接表法
typedef struct {
	VNode vertices[MaxVertexNum];//创建一个头点数组
	int vexnum, arcnum;//记录顶点和边的个数
}ALGraph;


//邻接矩阵创建图


//邻接表创建无向网
//输入总的顶点数，总边数
//建立顶点表
//依次输入点的信息存入顶点表中
//使每个表头节点的指针域初始化为NULL
//创建邻接表
//依次输入每条边依附的两个顶点
//确定两个顶点的序号i，j，建立边节点
//将此边节点分别插图到vi,vj对应的两个边链表的头部

//邻接表创建无向图
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

//邻接表实现BFS
//创建一个visit数组存储节点是否已经访问
//创建一个队列，用于实现节点入队，出队
//如果该节点没有被访问，则入队，
//当节点出队的时候，需要将其未访问的邻接节点入队，
//队空则图的BFS完成
int FirstNeighbor(ALGraph G,int v);//找v的第一个邻接点
int NextNeighbor(ALGraph G, int v,int w);//v为顶点，W为邻接点，找w的下一个邻接点，如果为NULL则返回-1

bool visited[MaxVertexNum];//初始化为false
SqQueue Q;
void BFSTraverse(ALGraph G)
{
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;
	// 初始化队列
	//创建队列

	InitSqQueue(Q);
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
			BFS(G, i);
	}
}
void BFS(ALGraph G,int v)
{
	//访问节点
	printf("%c ", v);
	
	//入队
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
//遍历的时间复杂度只跟存储方式有关
//邻接矩阵实现BFS
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


//邻接矩阵实现DFS
//创建一个visit数组存放节点是否被访问
//如果当前节点没有访问，访问该节点
//然后找到相邻节点，递归执行函数

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
//邻接表实现
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


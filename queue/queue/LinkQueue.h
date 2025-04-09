#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct LinkNode{
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct LinkQueue{
	LinkNode* front, * rear;
}LinkQueue;

//带头结点的初始化
void InitLinkQueue(LinkQueue& Lq);

//判空
bool Is_Empty(LinkQueue Lq);

//入队,带头结点
bool En_LinkQueue(LinkQueue& Lq, int x);
//出队，带头结点
bool De_LinkQueue(LinkQueue& Lq, int& x);

//查找元素，带头结点
bool search_LinkQueue(LinkQueue& Lq, int x, LinkNode*& Q);
//打印队列
bool Print_LinkQueue(LinkQueue Lq);

//树的层次遍历
//由根节点开始，如果节点有左右节点则入队，并将此节点出队，无则直接出队

//图的广度优先遍历
//由其中一个节点开始，如果相邻节点没有被遍历则入队，然后该节点出队，直至队列为空





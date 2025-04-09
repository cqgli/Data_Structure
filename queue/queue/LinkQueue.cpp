#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkQueue.h"


//带头结点的初始化
void InitLinkQueue(LinkQueue& Lq)
{
	Lq.front = Lq.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Lq.front->next = NULL;
}

//判空
bool Is_Empty(LinkQueue Lq)
{
	if (Lq.front == Lq.rear)
	{
		return true;
	}
	return false;
}

//入队,带头结点
bool En_LinkQueue(LinkQueue& Lq, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Lq.front == Lq.rear)
	{
		Lq.front->next = s;
		Lq.rear = s;//尾指针指向第一个插入的
	}
	else
	{
		Lq.rear->next = s;
		Lq.rear = s;
	}
	return true;
}

//出队，带头结点
bool De_LinkQueue(LinkQueue& Lq, int& x)
{
	if (Is_Empty(Lq))
	{
		return false;
	}
	x = Lq.front->next->data;
	LinkNode* s = Lq.front->next;
	if (Lq.front->next == Lq.rear)//最后一个出队
	{
		Lq.front->next = NULL;
		Lq.rear = Lq.front;
	}
	else
	{
		Lq.front->next = s->next;
	}
	free(s);
	return true;
}

//查找元素，带头结点
bool search_LinkQueue(LinkQueue& Lq, int x, LinkNode*& Q)
{
	if (Is_Empty(Lq))
		return false;
	LinkNode* s = Lq.front;
	while (s->next != NULL)
	{
		if (s->next->data == x)
		{
			Q = s->next;//q需要初始化
			return true;
		}
		s = s->next;
	}
	return false;
}
//打印队列
bool Print_LinkQueue(LinkQueue Lq)
{
	if (Is_Empty(Lq))
		return false;
	LinkNode* s = Lq.front;
	while (s->next != NULL)
	{
		printf("%d ", s->next->data);
		s = s->next;
	}
	printf("\n");
	return true;
}
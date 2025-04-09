//#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
//
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct LinkNode {
//	int data;
//	struct LinkNode* next;
//}LinkNode;
//
//typedef struct LinkQueue {
//	LinkNode* front, * rear;
//}LinkQueue;
//
////不带带头结点的初始化
//void InitLinkQueue(LinkQueue& Lq)
//{
//	 Lq.rear = NULL;
//	Lq.front = NULL;
//}
//
////不带头结点的判空
//bool Is_Empty(LinkQueue& Lq)
//{
//	if (Lq.front == NULL)
//		return true;
//	return false;
//}
//
////不带头结点的入队
//bool En_LinkQueue(LinkQueue& Lq,int x)
//{
//	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
//	s->data = x;
// s->next = NULL//入队的节点next为NULL
//	if (Is_Empty(Lq))//入队注意第一个入队
//	{
//		Lq.front = s;
//		Lq.rear = s;
//	}
//	else
//	{
//		Lq.rear->next = s;
//		Lq.rear = s;
//	}
//	return true;
//}
//
////出队，注意最后一个出队
//bool De_LinkQueue(LinkQueue& Lq, int& x)
//{
//	LinkNode* s = Lq.front;
//	if (Lq.front == Lq.rear && Lq.front != NULL)
//	{
//		Lq.front = NULL;
//		Lq.rear = NULL;
//	}
//	else
//	{
//		Lq.front = s->next;
//	}
//	free(s);
//	return true;
//}
//
////查找元素
//bool search_LinkQueue(LinkQueue& Lq, int x, LinkNode*& Q)
//{
//	if (Is_Empty(Lq))
//		return false;
//	LinkNode* s = Lq.front;
//	while (s != NULL)
//	{
//		if (s->data == x)
//		{
//			Q = s;
//			return true;
//		}
//		s = s ->next;
//	}
//	return true;
//}
////打印队列
//bool Print_LinkQueue(LinkQueue Lq)
//{
//	if (Is_Empty(Lq))
//		return false;
//	LinkNode* s = Lq.front;
//	while (s != NULL)
//	{
//		printf("%d ", s->data);
//		s = s->next;
//	}
//	return false;
//}
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
////������ͷ���ĳ�ʼ��
//void InitLinkQueue(LinkQueue& Lq)
//{
//	 Lq.rear = NULL;
//	Lq.front = NULL;
//}
//
////����ͷ�����п�
//bool Is_Empty(LinkQueue& Lq)
//{
//	if (Lq.front == NULL)
//		return true;
//	return false;
//}
//
////����ͷ�������
//bool En_LinkQueue(LinkQueue& Lq,int x)
//{
//	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
//	s->data = x;
// s->next = NULL//��ӵĽڵ�nextΪNULL
//	if (Is_Empty(Lq))//���ע���һ�����
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
////���ӣ�ע�����һ������
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
////����Ԫ��
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
////��ӡ����
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
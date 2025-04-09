#define _CRT_SECURE_NO_WARNINGS 1
#include "LinkQueue.h"


//��ͷ���ĳ�ʼ��
void InitLinkQueue(LinkQueue& Lq)
{
	Lq.front = Lq.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Lq.front->next = NULL;
}

//�п�
bool Is_Empty(LinkQueue Lq)
{
	if (Lq.front == Lq.rear)
	{
		return true;
	}
	return false;
}

//���,��ͷ���
bool En_LinkQueue(LinkQueue& Lq, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Lq.front == Lq.rear)
	{
		Lq.front->next = s;
		Lq.rear = s;//βָ��ָ���һ�������
	}
	else
	{
		Lq.rear->next = s;
		Lq.rear = s;
	}
	return true;
}

//���ӣ���ͷ���
bool De_LinkQueue(LinkQueue& Lq, int& x)
{
	if (Is_Empty(Lq))
	{
		return false;
	}
	x = Lq.front->next->data;
	LinkNode* s = Lq.front->next;
	if (Lq.front->next == Lq.rear)//���һ������
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

//����Ԫ�أ���ͷ���
bool search_LinkQueue(LinkQueue& Lq, int x, LinkNode*& Q)
{
	if (Is_Empty(Lq))
		return false;
	LinkNode* s = Lq.front;
	while (s->next != NULL)
	{
		if (s->next->data == x)
		{
			Q = s->next;//q��Ҫ��ʼ��
			return true;
		}
		s = s->next;
	}
	return false;
}
//��ӡ����
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
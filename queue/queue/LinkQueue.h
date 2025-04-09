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

//��ͷ���ĳ�ʼ��
void InitLinkQueue(LinkQueue& Lq);

//�п�
bool Is_Empty(LinkQueue Lq);

//���,��ͷ���
bool En_LinkQueue(LinkQueue& Lq, int x);
//���ӣ���ͷ���
bool De_LinkQueue(LinkQueue& Lq, int& x);

//����Ԫ�أ���ͷ���
bool search_LinkQueue(LinkQueue& Lq, int x, LinkNode*& Q);
//��ӡ����
bool Print_LinkQueue(LinkQueue Lq);

//���Ĳ�α���
//�ɸ��ڵ㿪ʼ������ڵ������ҽڵ�����ӣ������˽ڵ���ӣ�����ֱ�ӳ���

//ͼ�Ĺ�����ȱ���
//������һ���ڵ㿪ʼ��������ڽڵ�û�б���������ӣ�Ȼ��ýڵ���ӣ�ֱ������Ϊ��





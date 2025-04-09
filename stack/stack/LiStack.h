#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkLNode{
	int data;
	struct LinkLNode* next;
}LiStack,*LinkStack;

//��ʼ��,����ͷ���
void InitLiStack(LinkStack& Ls);
//��ջ
void Push_LiStack(LinkStack& Ls, int x);
//��ջ
bool Pop_LiStack(LinkStack& Ls, int& x);
//����ջ��Ԫ��
bool GetPop_LiStack(LinkStack& Ls, int& x);
//�ж�ջ��
bool is_empty_LiStack(LinkStack Ls);
//��ջ������

//��ӡ��ջ
void printf_LinkStack(LinkStack& Ls);


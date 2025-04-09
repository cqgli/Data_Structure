#define _CRT_SECURE_NO_WARNINGS 1

#include "LiStack.h"
//��ʼ��,����ͷ���
void InitLiStack(LinkStack& Ls)
{
	Ls = (LiStack*)malloc(sizeof(LiStack));
	Ls->next = NULL;
}
//��ջ
void Push_LiStack(LinkStack& Ls, int x)
{
	LiStack* S = (LiStack*)malloc(sizeof(LiStack));
	S->data = x;
	S->next = Ls->next;
	Ls->next = S;
}
//��ջ
bool Pop_LiStack(LinkStack& Ls, int& x)
{
	if (Ls->next == NULL)
		return false;
	LiStack* S = Ls->next;
	Ls->next = S->next;
	x = S->data;
	free(S);
	return true;
}
//����ջ��Ԫ��
bool GetPop_LiStack(LinkStack& Ls, int& x)
{
	if (!Ls->next)
		return false;
	x = Ls->next->data;
	return true;
}
//�ж�ջ��
bool is_empty_LiStack(LinkStack Ls)
{
	if (Ls->next == NULL)
		return true;
	return false;
}
//��ջ������

//��ӡ��ջ
void printf_LinkStack(LinkStack& Ls)
{
	LiStack* S = Ls;
	while (S->next != NULL)
	{
		printf("%d ", S->next->data);
		S = S->next;
	}
	printf("\n");
}

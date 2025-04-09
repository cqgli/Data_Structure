#define _CRT_SECURE_NO_WARNINGS 1

#include "LiStack.h"
//初始化,不带头结点
void InitLiStack(LinkStack& Ls)
{
	Ls = (LiStack*)malloc(sizeof(LiStack));
	Ls->next = NULL;
}
//进栈
void Push_LiStack(LinkStack& Ls, int x)
{
	LiStack* S = (LiStack*)malloc(sizeof(LiStack));
	S->data = x;
	S->next = Ls->next;
	Ls->next = S;
}
//出栈
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
//查找栈顶元素
bool GetPop_LiStack(LinkStack& Ls, int& x)
{
	if (!Ls->next)
		return false;
	x = Ls->next->data;
	return true;
}
//判断栈空
bool is_empty_LiStack(LinkStack Ls)
{
	if (Ls->next == NULL)
		return true;
	return false;
}
//链栈不会满

//打印链栈
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

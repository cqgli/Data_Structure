#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkLNode{
	int data;
	struct LinkLNode* next;
}LiStack,*LinkStack;

//初始化,不带头结点
void InitLiStack(LinkStack& Ls);
//进栈
void Push_LiStack(LinkStack& Ls, int x);
//出栈
bool Pop_LiStack(LinkStack& Ls, int& x);
//查找栈顶元素
bool GetPop_LiStack(LinkStack& Ls, int& x);
//判断栈空
bool is_empty_LiStack(LinkStack Ls);
//链栈不会满

//打印链栈
void printf_LinkStack(LinkStack& Ls);


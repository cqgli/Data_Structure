#define _CRT_SECURE_NO_WARNINGS1
#pragma once

#include <stdio.h>
#include <stdlib.h>

#define maxsize 10
//π≤œÌ’ª
typedef struct {
	int data[maxsize];
	int top0;
	int top1;
}ShStack;

//≥ı ºªØ
void InitStack_share(ShStack& S)
{
	S.top0 = maxsize-1;
	S.top1 = 0;
}
//≈–¬˙
bool is_Sh_full(ShStack& S)
{
	if (S.top1  == S.top0)
		return true;
	return false;
}
//≈–ø’
bool is_Sh_empty(ShStack& S,int stacknum)
{
	if (stacknum == 0)
	{
		if (S.top0 == maxsize - 1)
			return true;
	}
	else if (stacknum == 1)
	{
		if (S.top1 == 0)
			return true;
	}
	return false;
}
//»Î’ª
bool Sh_push(ShStack& S, int x, int stacknum)
{
	if(is_Sh_full(S))
		return false;
	if (stacknum == 0)
	{
		S.data[S.top0] = x;
		S.top0--;
	}
	else if (stacknum == 1)
	{
		S.data[S.top1] = x;
		S.top1++;
	}
	else
		return false;
}
//≥ˆ’ª
bool Sh_Pop(ShStack& S, int& x, int stacknum)
{
	if (is_Sh_empty(S,stacknum))
		return false;
	if (stacknum == 0)
	{
		x = S.data[--S.top0];
	}
	else if (stacknum == 1)
	{
		x = S.data[++S.top1];
	}
	else
	{
		return false;
	}
	return true;
}
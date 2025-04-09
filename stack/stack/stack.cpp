#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
//初始化，不同情况的top指向不同

void InitStack(SqStack& S)
{
	S.top = -1;
}
//判空
bool is_empty(SqStack S)
{
	if (S.top == -1)
		return true;
	return false;
}
//判满
bool is_full(SqStack S)
{
	if (S.top == maxsize - 1)
		return true;
	return false;
}
//入栈
bool push(SqStack& S, int x)
{
	//先判满
	if (S.top == maxsize - 1)
		return false;
	S.top++;
	S.data[S.top] = x;
	return true;
}
//出栈
bool Pop(SqStack& S, int& x)
{
	//先判空
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	S.top--;
	return true;
}
//读取栈顶元素
bool Gettop(SqStack& S, int& x)
{
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}
//打印栈
void printf_Stack(SqStack S)
{
	int a = S.top;
	while (a != -1)
	{
		printf("%d ", S.data[a]);
		a--;
	}
	printf("\n");
}
//括号匹配
bool bracketCheck(char s[], int length)
{
	SqStack S;
	InitStack(S);

	for (int i = 0; i < length; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			if (S.top != maxsize - 1)//判满is-full
			{
				push(S, s[i]);//S.data[++S.top] = s[i];入栈

			}
			else
				return false;
		}
		else
		{
			if (S.top != -1)//判空
			{
				char TopElem;
				TopElem = S.data[S.top--];//栈顶元素出栈
				if (s[i] == ')' && TopElem != '(')
					return false;
				else if (s[i] == ']' && TopElem != '[')
					return false;
				else if (s[i] == '}' && TopElem != '{')
					return false;
			}
			else
				return false;
		}
	}
	return S.top == -1;
}
//中缀转后缀
bool infixToPostfix(char s[], int length)
{
	SqStack S;//用于存放不确定顺序的操作符
	InitStack(S);
	char L[maxsize];
	int k = 0;
	int x;
	for (int i = 0; i < length; i++)
	{
		if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '(' && s[i] != ')')
			L[k++] = s[i];
		else if (s[i] == '(')
		{
			push(S, s[i]);
			//加判断栈满
		}
		else if (s[i] == ')')
		{
			//加判断栈空
			while (S.data[S.top] != '(' && S.top != -1)
			{
				L[k++] = S.data[S.top];
				S.top--;
			}
			S.top--;//弹出左括号
		}
		else
		{
			while (S.top != -1 && precedence(S.data[S.top]) >= precedence(s[i]))
			{
				L[k++] = S.data[S.top--];
			}
			//加判断栈满
			S.data[++S.top] = s[i];//压入操作符
		}
	}
	while (S.top != -1)
	{
		L[k++] = S.data[S.top--];
	}
	L[k] = '\0';
	return true;
}
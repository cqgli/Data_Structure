#pragma once
#include <stdio.h>
#include <stdlib.h>

#define maxsize 10
//顺序栈
typedef struct {
	int data[maxsize];
	int top;
}SqStack;


//初始化，不同情况的top指向不同
//当top指向-1时入栈先加再入，出栈先出再减
//当top指向1的时候入栈先入再加，出栈先减再出
void InitStack(SqStack& S);
//判空
bool is_empty(SqStack S);
//判满
bool is_full(SqStack S);
//入栈
bool push(SqStack& S, int x);
//出栈
bool Pop(SqStack& S, int& x);
//读取栈顶元素
bool Gettop(SqStack& S, int& x);
//打印栈
void printf_Stack(SqStack S);
//括号匹配
bool bracketCheck(char s[], int length);
//优先级函数
int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}
//中缀转后缀
bool infixToPostfix(char s[], int length);
//后缀求值
bool Postfix_calculate(char s[], int length)
{
	SqStack S;//用于存放计算所用的值
	InitStack(S);

	for (int i = 0; i < length; i++)
	{
		//先对操作数压栈
		if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
		{
			S.data[++S.top] = s[i];
		}
		//遇到运算符取出两个操作数，进行运算
		else
		{
			int right = S.data[S.top--];
			int left = S.data[S.top--];
			int sum = 0;
			if (S.top < -1)
				return false;
			if (s[i] == '+')
				sum =  left + right;
			else if (s[i] == '-')
				sum =  left- right;
			else if (s[i] == '*')
				sum =  left * right;
			else if (s[i] == '/' && right!=0)
				sum =  left/ right;
			S.data[++S.top] = sum;
		}
	}
	//S.data[0]即为所求值
	return true;
}





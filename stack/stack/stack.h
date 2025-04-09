#pragma once
#include <stdio.h>
#include <stdlib.h>

#define maxsize 10
//˳��ջ
typedef struct {
	int data[maxsize];
	int top;
}SqStack;


//��ʼ������ͬ�����topָ��ͬ
//��topָ��-1ʱ��ջ�ȼ����룬��ջ�ȳ��ټ�
//��topָ��1��ʱ����ջ�����ټӣ���ջ�ȼ��ٳ�
void InitStack(SqStack& S);
//�п�
bool is_empty(SqStack S);
//����
bool is_full(SqStack S);
//��ջ
bool push(SqStack& S, int x);
//��ջ
bool Pop(SqStack& S, int& x);
//��ȡջ��Ԫ��
bool Gettop(SqStack& S, int& x);
//��ӡջ
void printf_Stack(SqStack S);
//����ƥ��
bool bracketCheck(char s[], int length);
//���ȼ�����
int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}
//��׺ת��׺
bool infixToPostfix(char s[], int length);
//��׺��ֵ
bool Postfix_calculate(char s[], int length)
{
	SqStack S;//���ڴ�ż������õ�ֵ
	InitStack(S);

	for (int i = 0; i < length; i++)
	{
		//�ȶԲ�����ѹջ
		if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
		{
			S.data[++S.top] = s[i];
		}
		//���������ȡ����������������������
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
	//S.data[0]��Ϊ����ֵ
	return true;
}





#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
//��ʼ������ͬ�����topָ��ͬ

void InitStack(SqStack& S)
{
	S.top = -1;
}
//�п�
bool is_empty(SqStack S)
{
	if (S.top == -1)
		return true;
	return false;
}
//����
bool is_full(SqStack S)
{
	if (S.top == maxsize - 1)
		return true;
	return false;
}
//��ջ
bool push(SqStack& S, int x)
{
	//������
	if (S.top == maxsize - 1)
		return false;
	S.top++;
	S.data[S.top] = x;
	return true;
}
//��ջ
bool Pop(SqStack& S, int& x)
{
	//���п�
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	S.top--;
	return true;
}
//��ȡջ��Ԫ��
bool Gettop(SqStack& S, int& x)
{
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}
//��ӡջ
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
//����ƥ��
bool bracketCheck(char s[], int length)
{
	SqStack S;
	InitStack(S);

	for (int i = 0; i < length; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			if (S.top != maxsize - 1)//����is-full
			{
				push(S, s[i]);//S.data[++S.top] = s[i];��ջ

			}
			else
				return false;
		}
		else
		{
			if (S.top != -1)//�п�
			{
				char TopElem;
				TopElem = S.data[S.top--];//ջ��Ԫ�س�ջ
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
//��׺ת��׺
bool infixToPostfix(char s[], int length)
{
	SqStack S;//���ڴ�Ų�ȷ��˳��Ĳ�����
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
			//���ж�ջ��
		}
		else if (s[i] == ')')
		{
			//���ж�ջ��
			while (S.data[S.top] != '(' && S.top != -1)
			{
				L[k++] = S.data[S.top];
				S.top--;
			}
			S.top--;//����������
		}
		else
		{
			while (S.top != -1 && precedence(S.data[S.top]) >= precedence(s[i]))
			{
				L[k++] = S.data[S.top--];
			}
			//���ж�ջ��
			S.data[++S.top] = s[i];//ѹ�������
		}
	}
	while (S.top != -1)
	{
		L[k++] = S.data[S.top--];
	}
	L[k] = '\0';
	return true;
}
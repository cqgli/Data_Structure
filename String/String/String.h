#pragma once
#include <stdio.h>

#define maxsize 255
typedef struct {
	char ch[maxsize];
	int length;
}SString;

//typedef struct {
//	char* ch;
//	int length;
//}HString;
//
//typedef struct StringNode {
//	char ch;
//	struct StringNode* next;
//}StringNode, * String;

//��ʼ��
void Init_SString(SString& S);
// ��ֵ,��t��ֵ��chars
bool StrAssign(SString& T, char s);

// ���ƣ�����S���Ƹ�T
bool StrCopy(SString& T, SString S);
// �п�
bool StrEmpty(SString S);
// �󴮳�
int StrLength(SString S);
// ���
bool ClearString(SString& S);
// ����
void DestoryString(SString& S);
// ������
bool  Concat(SString& T, SString S1, SString S2);
// ���Ӵ�
bool SubString(SString& sub, SString T, int pos, int len);
// �Ƚϴ�С
//S>T,����true��S< = T ����false
bool StrCompare(SString S, SString T);
//��λ����
int index(SString S, SString T);
//��ӡ
void Print_String(SString S);


//����ģʽƥ���㷨
int index(SString S, SString T)
{
	int i = 1, j = 1;
	if (S.length < T.length || T.length == 0)
		return -1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length)
		return i - T.length;
	return -1;
}

//KMP�㷨
int KMP(SString S, SString T, int next[])
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (j == 0 || S.ch[i] == S.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j > T.length)
		return i-T.length;
	return -1;
}





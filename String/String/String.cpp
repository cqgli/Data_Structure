#define _CRT_SECURE_NO_WARNINGS 1

#include "String.h"

//��ʼ��
void Init_SString(SString& S)
{
	S.length = 0;
}
// ��ֵ,��t��ֵ��chars
bool StrAssign(SString& T, char s)
{
	if (T.length == maxsize)
	{
		return false;
	}
	T.ch[T.length] = s;
	T.length++;
	return true;
}

// ���ƣ�����S���Ƹ�T
bool StrCopy(SString& T, SString S)
{
	if (S.length == 0 || S.length > maxsize)
		return false;
	for (int i = 0; i < S.length; i++)
	{
		T.ch[i] = S.ch[i];
	}
	T.length = S.length;
	return true;
}
// �п�
bool StrEmpty(SString S)
{
	if (S.length == 0)
		return true;
	return false;
}
// �󴮳�
int StrLength(SString S)
{
	return S.length;
}
// ���
bool ClearString(SString& S)
{
	S.length = 0;
	return true;
}
// ����
void DestoryString(SString& S)
{
	//������������Ԫ������
	for (int i = 0; i < S.length; i++)
	{
		S.ch[i] = 0;
	}
	S.length = 0;
}
// ������
bool  Concat(SString& T, SString S1, SString S2)
{
	if ((S1.length == S2.length && !S1.length) || S1.length + S2.length > maxsize)
	{
		return false;
	}
	int k = 0;
	for (int i = 0; i < S1.length; i++)
	{
		T.ch[k++] = S1.ch[i];
	}
	for (int i = 0; i < S2.length; i++)
	{
		T.ch[k++] = S2.ch[i];
	}
	T.length = k;
	return true;
}
// ���Ӵ�
bool SubString(SString& sub, SString T, int pos, int len)
{
	if (T.length == 0 || pos+len > T.length || pos <0 )
		return false;
	int k = 0;
	for (int i = pos; i < pos + len; i++)
	{
		sub.ch[k++] = T.ch[i];
	}
	sub.length = k;
	return true;
}
// �Ƚϴ�С
//S>T,����true��S< = T ����false
bool StrCompare(SString S, SString T)
{
	int min = T.length > S.length ? S.length : T.length;
	for (int i = 0; i < min; i++)
	{
		if (S.ch[i] < T.ch[i])
			return false;
		else if (S.ch[i] > T.ch[i])
			return true;
		else
			continue;
	}
	return min == S.length ? false : true;
}
//��λ����
int index(SString S, SString T)
{
	int i = 0;
	int m = S.length, n = T.length;
	if (m > n)
		return -1;
	while (i <= n - m)
	{
		int j = 0;
		for (j; j < m; j++)
		{
			if (S.ch[j] != T.ch[j + i])
				break;
			else
				continue;
		}
		if (j == m)
			return i;
		i++;
	}
	return -1;
}
//��ӡ
void Print_String(SString S)
{
	for (int i = 0; i < S.length; i++)
	{
		printf("%c ", S.ch[i]);
	}
	printf("\n");
}

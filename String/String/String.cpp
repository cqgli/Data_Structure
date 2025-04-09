#define _CRT_SECURE_NO_WARNINGS 1

#include "String.h"

//初始化
void Init_SString(SString& S)
{
	S.length = 0;
}
// 赋值,将t赋值给chars
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

// 复制，将串S复制给T
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
// 判空
bool StrEmpty(SString S)
{
	if (S.length == 0)
		return true;
	return false;
}
// 求串长
int StrLength(SString S)
{
	return S.length;
}
// 清空
bool ClearString(SString& S)
{
	S.length = 0;
	return true;
}
// 销毁
void DestoryString(SString& S)
{
	//将数组中所有元素置零
	for (int i = 0; i < S.length; i++)
	{
		S.ch[i] = 0;
	}
	S.length = 0;
}
// 串联串
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
// 求子串
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
// 比较大小
//S>T,返回true，S< = T 返回false
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
//定位操作
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
//打印
void Print_String(SString S)
{
	for (int i = 0; i < S.length; i++)
	{
		printf("%c ", S.ch[i]);
	}
	printf("\n");
}

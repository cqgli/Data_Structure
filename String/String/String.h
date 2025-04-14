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

//初始化
void Init_SString(SString& S);
// 赋值,将t赋值给chars
bool StrAssign(SString& T, char s);

// 复制，将串S复制给T
bool StrCopy(SString& T, SString S);
// 判空
bool StrEmpty(SString S);
// 求串长
int StrLength(SString S);
// 清空
bool ClearString(SString& S);
// 销毁
void DestoryString(SString& S);
// 串联串
bool  Concat(SString& T, SString S1, SString S2);
// 求子串
bool SubString(SString& sub, SString T, int pos, int len);
// 比较大小
//S>T,返回true，S< = T 返回false
bool StrCompare(SString S, SString T);
//定位操作
int index(SString S, SString T);
//打印
void Print_String(SString S);


//朴素模式匹配算法
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

//KMP算法
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





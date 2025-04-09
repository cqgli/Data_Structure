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





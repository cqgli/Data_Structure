#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"
void InitList(SqlList& L)//��̬����
{
	for (int i = 0; i < maxsize; i++)
	{
		L.data[i] = 0;
	}
	L.length = 0;
}
void InsertList(SqlList& L,int len,int a)//��̬�����µĲ���
{
	if (len <1 || len >L.length)
		return;
	if (L.length >= maxsize)
		return;
		
	for (int i = L.length; i > len; i--)
	{
		L.data[i] = L.data[i - 1];
	}
	L.data[len] = a;
	L.length = L.length + 1;
}
int DeleteList(SqlList& L, int len)//��̬�����µ�ɾ��
{
	if (len<1 || len >L.length)
	{
		return -1;
	}
	int a = L.data[len - 1];
	for (int i = len; i < L.length; i++)
	{
		L.data[i-1] = L.data[i];
	}
	L.length--;
	return a;
}
int LocateElem(SqlList L, int len)//��̬�����µİ�λ����
{
	if (len > L.length || len < 1)
	{
		return -1;
	}
	return L.data[len - 1];
}
int LocateELem(SqlList L, int e)//˳���İ�ֵ���ң�����e,����λ��
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
			return i+1;
	}
	return -1;
}
void InitList1(List& L1) // ��̬����
{
	L1.data = (int*)malloc(sizeof(int) * maxsize);
	L1.size = maxsize;
	L1.length1 = 0;
}
void InitCreaseSize(List& L1,int len)//��̬����
{
	int* p = L1.data;
	L1.data = (int*)malloc(sizeof(int) * (maxsize + len));
	for (int i = 0; i < L1.length1; i++)
	{
		L1.data[i] = p[i];
	}
	L1.size = L1.size + len;
	free(p);
}


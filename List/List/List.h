#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 10
typedef struct {
	int data[maxsize];
	int length;
}SqlList;//��̬����
typedef struct {
	int* data;
	int size;
	int length1;
}List;//��̬����

//��̬����
void InitList(SqlList& L);
//��̬�����µĲ���
void InsertList(SqlList& L, int len, int a);
//��̬�����µ�ɾ��
int DeleteList(SqlList& L, int len);
//��̬�����µİ�λ����
int LocateElem(SqlList L, int len);
//˳���İ�λ���ң�����e,����λ��
int LocateELem(SqlList L, int e);
// ��̬����
void InitList1(List& L1); 
//��̬����
void InitCreaseSize(List& L1, int len);


#pragma once
#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
//˳�����
typedef struct {
	int data[maxsize];
	int rear, front;
	int size;//�ڶ��ֶ���
	int tag;//�����ֶ���
}SqQueue;

//��ʼ��
void InitSqQueue(SqQueue& Q);

//�п�
bool is_empty(SqQueue Q);

//��һ������������һ���ռ䣬�����rearָ����Ƕ�β����һ���ռ�
bool is_full(SqQueue Q);
//�ڶ�������,�ڽṹ��������һ��size��¼�ռ�
bool is_full2(SqQueue Q);
//�������������ڽṹ���м�һ��tag��¼���һ�β���ɾ������
bool is_full3(SqQueue Q);

//���
bool EnQueue(SqQueue& Q, int x);

//����
bool DeQueue(SqQueue& Q, int& x);

//��ö�ͷԪ��
bool GetFront(SqQueue Q, int& x);

//��ö�βԪ��
bool GetRear(SqQueue Q, int& x);

//��ӡ����
bool Printf_SqQueue(SqQueue Q);


#define _CRT_SECURE_NO_WARNINGS 1
#include "SqQueue.h"

//��ʼ��
void InitSqQueue(SqQueue& Q)
{
	Q.rear = 0;
	Q.front = 0;
	Q.size = 0;
}

//�п�
bool is_empty(SqQueue Q)
{
	if (Q.front == 0 && Q.rear == 0)
	{
		return true;
	}
	/*if (Q.tag == 0 && Q.rear == Q.front)
		return true;*/ //���ֻ�ʺϵ����ֶ���
	return false;
}

//��һ������������һ���ռ䣬�����rearָ����Ƕ�β����һ���ռ�
bool is_full(SqQueue Q)
{
	if ((Q.rear + 1) % maxsize == Q.front)
		return true;
	return false;
}
//�ڶ�������,�ڽṹ��������һ��size��¼�ռ�
bool is_full2(SqQueue Q)
{
	if (Q.size == maxsize)
		return true;
	return false;
}
//�������������ڽṹ���м�һ��tag��¼���һ�β���ɾ������
bool is_full3(SqQueue Q)
{
	//tag = 0 ��ʾɾ����tag = 1��ʾ���� )
	if (Q.tag == 1 && Q.rear == Q.front)
	{
		return true;
	}
	return false;
}

//���
bool EnQueue(SqQueue& Q, int x)
{
	if (is_full(Q))
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % maxsize;
	Q.tag = 1;//�����ֶ���
	Q.size++;//�ڶ��ֶ���
	return true;
}

//����
bool DeQueue(SqQueue& Q, int& x)
{
	if (is_empty(Q))
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % maxsize;
	Q.tag = 0;//�����ֶ���
	Q.size--;//�ڶ��ֶ���
	return true;
}

//��ö�ͷԪ��
bool GetFront(SqQueue Q, int& x)
{
	if (is_empty(Q))
		return false;
	x = Q.data[Q.front];
	return true;
}

//��ö�βԪ��
bool GetRear(SqQueue Q, int& x)
{
	if (is_empty(Q))
	{
		return false;
	}
	x = Q.data[(Q.rear - 1 + maxsize) % maxsize];
	return true;
}
//��ӡ����
bool Printf_SqQueue(SqQueue Q)
{
	if (is_empty(Q))
		return false;
	int count = (Q.rear - Q.front + maxsize) % maxsize;
	for (int i = 0; i < count; i++)
	{
		int index = i + Q.front;
		printf("%d ", Q.data[index % maxsize]);
	}
	printf("\n");
	return true;
}

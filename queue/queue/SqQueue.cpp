#define _CRT_SECURE_NO_WARNINGS 1
#include "SqQueue.h"

//初始化
void InitSqQueue(SqQueue& Q)
{
	Q.rear = 0;
	Q.front = 0;
	Q.size = 0;
}

//判空
bool is_empty(SqQueue Q)
{
	if (Q.front == 0 && Q.rear == 0)
	{
		return true;
	}
	/*if (Q.tag == 0 && Q.rear == Q.front)
		return true;*/ //这段只适合第三种队列
	return false;
}

//第一种判满，牺牲一个空间，这里的rear指向的是队尾的下一个空间
bool is_full(SqQueue Q)
{
	if ((Q.rear + 1) % maxsize == Q.front)
		return true;
	return false;
}
//第二种判满,在结构体中增加一个size记录空间
bool is_full2(SqQueue Q)
{
	if (Q.size == maxsize)
		return true;
	return false;
}
//第三种判满，在结构体中加一个tag记录最后一次插入删除操作
bool is_full3(SqQueue Q)
{
	//tag = 0 表示删除。tag = 1表示插入 )
	if (Q.tag == 1 && Q.rear == Q.front)
	{
		return true;
	}
	return false;
}

//入队
bool EnQueue(SqQueue& Q, int x)
{
	if (is_full(Q))
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % maxsize;
	Q.tag = 1;//第三种队列
	Q.size++;//第二种队列
	return true;
}

//出队
bool DeQueue(SqQueue& Q, int& x)
{
	if (is_empty(Q))
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % maxsize;
	Q.tag = 0;//第三种队列
	Q.size--;//第二种队列
	return true;
}

//获得队头元素
bool GetFront(SqQueue Q, int& x)
{
	if (is_empty(Q))
		return false;
	x = Q.data[Q.front];
	return true;
}

//获得队尾元素
bool GetRear(SqQueue Q, int& x)
{
	if (is_empty(Q))
	{
		return false;
	}
	x = Q.data[(Q.rear - 1 + maxsize) % maxsize];
	return true;
}
//打印队列
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

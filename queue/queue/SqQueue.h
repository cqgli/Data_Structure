#pragma once
#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
//顺序队列
typedef struct {
	int data[maxsize];
	int rear, front;
	int size;//第二种队列
	int tag;//第三种队列
}SqQueue;

//初始化
void InitSqQueue(SqQueue& Q);

//判空
bool is_empty(SqQueue Q);

//第一种判满，牺牲一个空间，这里的rear指向的是队尾的下一个空间
bool is_full(SqQueue Q);
//第二种判满,在结构体中增加一个size记录空间
bool is_full2(SqQueue Q);
//第三种判满，在结构体中加一个tag记录最后一次插入删除操作
bool is_full3(SqQueue Q);

//入队
bool EnQueue(SqQueue& Q, int x);

//出队
bool DeQueue(SqQueue& Q, int& x);

//获得队头元素
bool GetFront(SqQueue Q, int& x);

//获得队尾元素
bool GetRear(SqQueue Q, int& x);

//打印队列
bool Printf_SqQueue(SqQueue Q);


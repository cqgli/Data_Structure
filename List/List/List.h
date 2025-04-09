#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 10
typedef struct {
	int data[maxsize];
	int length;
}SqlList;//静态分配
typedef struct {
	int* data;
	int size;
	int length1;
}List;//动态分配

//静态分配
void InitList(SqlList& L);
//静态分配下的插入
void InsertList(SqlList& L, int len, int a);
//静态分配下的删除
int DeleteList(SqlList& L, int len);
//静态分配下的按位查找
int LocateElem(SqlList L, int len);
//顺序表的按位查找，查找e,返回位序
int LocateELem(SqlList L, int e);
// 动态分配
void InitList1(List& L1); 
//动态扩容
void InitCreaseSize(List& L1, int len);


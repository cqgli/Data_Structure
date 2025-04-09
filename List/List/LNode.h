#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;//表示将结构体命名重定义为LNode,结构体指针重命名为LinkLNode

typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode, * DLinkList;

//链表的初始化函数（不带头结点）
bool InitList(LinkList& L);
//带头结点的初始化
bool InitList1(LinkList& L);
//在有头结点链表的第i个位置上插入指定元素,就是查找加后插
bool InsertList(LinkList& L, int len, int e);
//无头结点的情况
bool InsertList(LinkList& L, int len, int e);
//后插操作,在p结点之后插入s,O(1)
bool InsertNextList(LNode* p, int e);
//前叉操作，
//1.函数参数有头结点，遍历循环找到前驱结点，然后后插
//2.偷天换日
bool InsertPriorList(LNode* p, int e);
//删除第i个节点，返回e
bool DeleteList(LinkList& L, int i, int& e);
//删除指定节点
//和上面一样两种方法
bool DeleteNode(LNode* p);
//按位查找,返回第i个节点
LNode* GetElem(LinkList& L, int i);
//按值查找
LNode* LocateElem(LinkList& L, int e);
//计算链表长度
int LengthList(LinkList& L);
//尾插法建立单链表
LNode * List_TailInsert(LinkList& L);
//打印链表
bool List_Print(LinkList& L);
//头插法实现单链表
LNode* List_HeadInsert(LinkList& L);


//双链表的初始化
bool Init_DLinkList(DLinkList& L);
//双链表的后插 在p后插入s
bool Tail_DLinkInsert(DNode* p, DNode* s);
//双链表的删除p的后继结点q后继结点
void DLinkList_delete(DNode* p);
//前向遍历
//后向遍历
//按位查找
//按值查找

//初始化循环单链表
bool Init_CLinkList(LinkList& L);
//判断尾节点
bool is_tail(LinkList& L, LNode* s);
//循环双链表初始化
bool Init_CDlinkList(DLinkList& L)
{
	L = (DNode*)malloc(sizeof(DNode));
	L->prior = L;
	L->next = L;
	return true;
}
//判空,使用单双循环链表
bool is_empty_Link(LinkList& L);
//在p后插入s节点
//双链表的删除